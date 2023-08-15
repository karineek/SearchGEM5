"""
USAGE: python3 generate-test-files.py <input-dir> <output-dir>

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


def main():
    if len(sys.argv) != 3:
        print("Usage: python3 generate-test-files.py <input-dir> <output-dir>")
        sys.exit(1)
    input_dir = sys.argv[1]
    if not os.path.isabs(input_dir):
        input_dir = os.path.join(os.getcwd(), input_dir)

    output_dir = sys.argv[2]
    if not os.path.isabs(output_dir):
        output_dir = os.path.join(os.getcwd(), output_dir)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    print(f'Using input directory {input_dir}')
    print(f'Using output directory {output_dir}')

    files = get_all_files(input_dir)
    print(f'Found {len(files)} files')

    for (i, filename) in enumerate(files):
        print(f'Generating for {filename}')
        try:
            generate_for_file(input_dir, output_dir, filename, i)
        except Exception as e:
            print(f'Failed to generate for {filename}, saving to failed.txt, either manually fix or use gpt script '
                  f'(yet to be implemented)')
            with open('failed.txt', 'a') as f:
                f.write(filename + '\n')
            continue


if __name__ == "__main__":
    main()
