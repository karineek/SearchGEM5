"""
USAGE: python3 generate-test-files.py <input-dir> <output-dir> <openai-key>

Generates two files for each file in <input-dir>:
    1. <file_index>.txt (contains the input for afl)
    2. <file_index>.types (contains the types of the arguments for afl)

Generates an additional file called failed.txt which contains the names of the files for which the generation failed.
These will then be able to be fixed manually, or fed into another script which will attempt to fix them automatically
using gpt-3.
"""


import os
import sys
import re
import time

import openai


class GPTException(Exception):
    pass


def get_gpt_files():
    preamble = ""
    example = []

    with open("preamble", "r") as f:
        preamble = f.read()

    with open("example_history", "r") as f:
        example_contents = f.read()
        example_contents = example_contents.split("REQRES")
        example = []
        for i in range(len(example_contents)):
            if i % 2 == 0:
                example.append({'role': 'user', 'content': example_contents[i]})
            else:
                example.append({'role': 'assistant', 'content': example_contents[i]})

    return preamble, example


def prompt(text, preamble_text, example_array):
    return openai.ChatCompletion.create(
        model="gpt-3.5-turbo-16k",
        temperature=0.9,    # a temperature of 0.9 seems to work best
        messages=[
            {
                'role': 'system', 'content': preamble_text
            },
            *example_array,
            {
                'role': 'user', 'content': text
            }
        ]
    )


def convert_to_valid_type(type_string):
    if type_string == 'int' or type_string == 'INT' or type_string == 'int32' or type_string == 'INT32':
        return 'INT32'
    elif type_string == 'float' or type_string == 'FLOAT':
        return 'FLOAT'
    elif type_string == 'char' or type_string == 'CHAR' or type_string == 'CHAR*' or type_string == 'CHAR*_STAR':
        return 'CHAR'
    elif type_string == 'long' or type_string == 'LONG':
        return 'LONG'
    elif type_string == 'string' or type_string == 'STRING':
        return 'STRING'
    else:
        raise GPTException(f"Invalid type string: {type_string}")


def extract_response(response):
    content = response["choices"][0]["message"]["content"]
    # first line is the number of arguments
    # second line is the types of the arguments
    lines = content.split('\n')

    # trim blank lines
    lines = [line for line in lines if line.strip()]

    if len(lines) < 2:
        raise GPTException(f"Invalid response: {content}")

    if lines[0] == '0':
        return 0, []

    try:
        num_args = int(lines[0])
    except ValueError:
        raise GPTException(f"Invalid number of arguments: {lines[0]}, response: {content}")

    arg_types = lines[1].split(' ')
    # convert to valid types i.e. int -> INT32 and INT -> INT32 and int32 -> INT32 etc
    for i in range(num_args):
        try:
            arg_types[i] = convert_to_valid_type(arg_types[i])
        except IndexError:
            raise GPTException(f"Invalid number of arguments: {lines[0]}, response: {content}")

    return num_args, arg_types


def get_all_files(input_dir):
    files = []
    for filename in os.listdir(input_dir):
        if os.path.isfile(os.path.join(input_dir, filename)):
            files.append(filename)

    return files


def get_file_contents(directory, filename):
    with open(os.path.join(directory, filename), 'r') as f:
        return f.read()


def from_type_string_to_initial_value(type_string):
    if type_string == 'INT32':
        return '0'
    elif type_string == 'FLOAT':
        return '0.0'
    elif type_string == 'CHAR':
        return 'A'
    elif type_string == 'LONG':
        return '0'
    elif type_string == 'STRING':
        return 'stringValue'
    else:
        raise Exception('Unknown type string')


def write_files(directory, file_path, file_index, num_args, arg_types):
    # Write to <file_index>.txt
    with open(os.path.join(directory, str(file_index) + '.txt'), 'w') as f:
        f.write(file_path)
        for i in range(num_args):
            f.write(' ' + from_type_string_to_initial_value(arg_types[i]))
        f.write('\n')

    # Write to <file_index>.types
    with open(os.path.join(directory, str(file_index) + '.types'), 'w') as f:
        f.write('BINARY ')
        for i in range(num_args):
            f.write(arg_types[i] + ' ')
        f.write('\n')


def get_number_of_arguments(file_contents):
    pattern = r'if \(argc != (\d+)\) {'
    match = re.search(pattern, file_contents)
    if match:
        return int(match.group(1)) - 1
    else:
        return None     # Could not find number of arguments


def get_type_of_arguments(file_contents, arg_index):
    lines = file_contents.split('\n')
    pattern = r'argv\[' + str(arg_index) + r'\]'
    for line in lines:
        match = re.search(pattern, file_contents)
        if match:
            # Check for integer usage
            if re.search(r'\batoi\s*\(', line):
                return 'INT32'
            # Check for floating-point usage
            elif re.search(r'\batof\s*\(', line):
                return 'FLOAT'
            # Check for character usage
            elif re.search(r'\bargv\[' + str(arg_index) + r'\]\[\d+\]\b', line):
                return 'CHAR'
            # Check for long usage
            elif re.search(r'\batol\s*\(|\batoll\s*\(', line):
                return 'LONG'
            # check for string usage
            elif re.search(r'= \bargv\[' + str(arg_index) + r'\]\b', line):
                return 'STRING'
    else:
        return None     # Could not find type of argument


def generate_for_file(input_directory, output_directory, filename, file_index):
    file_content = get_file_contents(input_directory, filename)
    num_args = get_number_of_arguments(file_content)
    if num_args is None:
        print(f'Could not find number of arguments for {filename}')
        raise Exception('Could not find number of arguments')
    arg_types = []
    for i in range(num_args):
        type = get_type_of_arguments(file_content, i + 1)
        if type is None:
            print(f'Could not find type of argument {i} for {filename}')
            raise Exception('Could not find type of argument')
        arg_types.append(type)

    write_files(output_directory, os.path.join(input_directory, filename), file_index, num_args, arg_types)


def generate_from_gpt(input_directory, output_directory, filename, file_index, preamble, example, attempts=3):
    fail_count = 0
    while fail_count < attempts:
        if fail_count > 0:
            print(f'Retrying {filename} ({fail_count} of {attempts})')
        try:
            arg_count, arg_types = extract_response(prompt(get_file_contents(input_directory, filename),
                                                           preamble, example))
            write_files(output_directory, os.path.join(input_directory, filename), file_index, arg_count, arg_types)
            return
        except GPTException as e:
            fail_count += 1
            print(f'Attempt {fail_count} failed for {filename}: {e}')
        except openai.error.ServiceUnavailableError:
            time.sleep(5)
    with open('../../data/failed-inputs.txt', 'a') as f:
        f.write(filename + '\n')


def main():
    if len(sys.argv) < 3:
        print("Usage: python3 generate-test-files.py <input-dir> <output-dir> <openai-api-key>")
        sys.exit(1)
    input_dir = sys.argv[1]
    if not os.path.isabs(input_dir):
        input_dir = os.path.join(os.getcwd(), input_dir)

    output_dir = sys.argv[2]
    if not os.path.isabs(output_dir):
        output_dir = os.path.join(os.getcwd(), output_dir)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    openai.api_key = sys.argv[3]

    print(f'Using input directory {input_dir}')
    print(f'Using output directory {output_dir}')

    files = get_all_files(input_dir)
    print(f'Found {len(files)} files')

    preamble, example = get_gpt_files()

    for (i, filename) in enumerate(files):
        print(f'Generating for {filename}')
        try:
            generate_for_file(input_dir, output_dir, filename, i)
        except Exception as e:
            if openai.api_key is None:
                print(f'Failed to generate for {filename}, saving to failed.txt, provide an openai api key to retry')
                with open('../../data/failed-inputs.txt', 'a') as f:
                    f.write(filename + '\n')
                continue
            else:
                print(f'Failed to generate for {filename}, trying with openai')

                generate_from_gpt(input_dir, output_dir, filename, i, preamble, example)


if __name__ == "__main__":
    main()
