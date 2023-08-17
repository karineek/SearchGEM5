"""
USAGE: <openai_key> <prompt_file> <source_url> <debug>
"""
import os
import subprocess
import sys
import shutil
import time
import re
import openai

def save_failed_input(input_program):
    """Save the input program to a file"""
    with open(f"output/failed", "a") as f:
        f.write(input_program)


def setup_folders():
    os.makedirs("output", exist_ok=True)
    os.makedirs("output/scratch", exist_ok=True)
    os.makedirs("output/scratch/text", exist_ok=True)
    os.makedirs("output/scratch/afl", exist_ok=True)
    os.makedirs("output/scratch/compilation", exist_ok=True)
    os.makedirs("output/binary", exist_ok=True)
    os.makedirs("output/input", exist_ok=True)


def setup_files():
    shutil.copyfile('compile.py', os.path.join('output', 'compile.py'))
    shutil.copyfile('convert-to-abs-path.py', os.path.join('output', 'convert-to-abs-path.py'))


def prompt(text, preamble_text, example_array):
    return openai.ChatCompletion.create(
        model="gpt-3.5-turbo-16k",
        temperature=0.9,  # a temperature of 0.9 seems to work best
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


def extract_code(response):
    """Extract the code block from the response as well as the name associated with it"""
    content = response["choices"][0]["message"]["content"]

    content = content.replace("```cpp", "")  # Incase it includes language tags
    content = content.replace("```c", "")  # Incase it includes language tags
    content = content.replace("```", "")  # otherwise

    return content


def compile_code(code_file, output_file):
    """Compile the code and capture the output to return, as well as the return code"""
    print(f"gcc -o {output_file} {code_file} > {output_file.replace('.c', '.txt')} 2>&1")
    os.system(f"gcc -o {output_file} {code_file} > {output_file.replace('.c', '.txt')} 2>&1")
    with open(output_file.replace(".c", ".txt"), "r") as f:
        output = f.read()
    return_code = os.system(f"echo $?")
    return output, return_code


def insert_arg_format(content, src, file_name):
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime())

    return f"// Modification timestamp: {timestamp}\n// Original Source: {src}/{file_name}\n{content}"


class ArgGen:
    def __init__(self, prompt_file, openai_key, source_url, debug=False):
        self.prompt_file = prompt_file
        self.openai_key = openai_key
        self.source_url = source_url
        self.debug = debug
        self.input_programs = []
        self.extract_name()
        with open(os.path.join("arg_gen", "preamble"), "r") as f:
            self.preamble = f.read()
        with open(os.path.join("arg_gen", "example_history"), "r") as f:
            example_contents = f.read()
            example_contents = example_contents.split("REQRES")
            self.example = []
            for i in range(len(example_contents)):
                if i % 2 == 0:
                    self.example.append({'role': 'user', 'content': example_contents[i]})
                else:
                    self.example.append({'role': 'assistant', 'content': example_contents[i]})

    def extract_name(self):
        """Extract the name from the input files"""
        with open(self.prompt_file, "r") as f:
            p = f.read()
            for inp in p.split("// source: "):
                # get name and code
                if inp == "":
                    continue
                split = inp.split("\n")
                name = split[0]
                code = split[1:]
                code = "\n".join(code)

                self.input_programs.append((name, code))

    def run(self):
        """Run the program"""
        processed = os.listdir("output/scratch/afl")

        for name, code in self.input_programs:
            # check if already processed
            if name in processed:
                print(f"Skipping {name}")
                continue
            self.run_single(name, code)

        return self.input_programs

    def run_single(self, name, code):
        should_try = True
        try_count = 0
        current_example = self.example
        while should_try:
            try:
                result = prompt(code, self.preamble, current_example)
            except openai.error.ServiceUnavailableError:
                time.sleep(5)
                try_count += 1
                if try_count > 10:
                    print("Too many tries, skipping")
                    should_try = False
                    save_failed_input(name)
                continue

            prog = extract_code(result)

            # save the program
            with open(os.path.join("output", "scratch", "afl", name), "w") as f:
                f.write(insert_arg_format(prog, self.source_url, name))

            # compile the program
            output, return_code = compile_code(os.path.join("output", "scratch", "afl", name),
                                               os.path.join("output", "scratch", "compilation", name))

            # if it compiles, save the program
            if return_code == 0:
                with open(os.path.join("output", "scratch", "text", name), "w") as f:
                    f.write(insert_arg_format(code, self.source_url, name))
                should_try = False
                continue
            else:
                current_example += [{'role': 'user', 'content': code}]
                current_example += [{'role': 'assistant', 'content': prog}]
                current_example += [{'role': 'user', 'content': 'Please try again, compiling failed:\n' + output}]
                try_count += 1
                if try_count > 4:
                    print("Too many tries, skipping")
                    should_try = False
                    save_failed_input(name)
                    continue

class TestFilesGen:
    class GPTException(Exception):
        pass

    def convert_to_valid_type(self, type_string):
        print(f"Converting {type_string} to valid type")
        if type_string == 'int' or type_string == 'INT' or type_string == 'int32' or type_string == 'INT32':
            return 'INT32'
        elif (type_string == 'uint32' or type_string == 'UINT32' or type_string == 'uint'
              or type_string == 'UINT' or type_string == 'unsigned int' or type_string == 'UNSIGNED INT'):
            return 'UINT32'
        elif (type_string == 'short' or type_string == 'SHORT' or type_string == 'short int'
              or type_string == 'SHORT INT' or type_string == 'short int' or type_string == 'SHORT INT'):
            return 'SHORT'
        elif (type_string == 'ushort' or type_string == 'USHORT' or type_string == 'unsigned short'
              or type_string == 'UNSIGNED SHORT' or type_string == 'unsigned short int' or type_string == 'UNSIGNED SHORT INT'):
            return 'USHORT'
        elif type_string == 'double' or type_string == 'DOUBLE':
            return 'DOUBLE'
        elif type_string == 'float' or type_string == 'FLOAT':
            return 'FLOAT'
        elif type_string == 'char' or type_string == 'CHAR' or type_string == 'CHAR*' or type_string == 'CHAR*_STAR':
            return 'CHAR'
        elif (type_string == 'uchar' or type_string == 'UCHAR' or type_string == 'unsigned char'
              or type_string == 'UNSIGNED CHAR'):
            return 'UCHAR'
        elif type_string == 'long' or type_string == 'LONG':
            return 'LONG'
        elif (type_string == 'ulong' or type_string == 'ULONG' or type_string == 'unsigned long'
              or type_string == 'UNSIGNED LONG'):
            return 'ULONG'
        elif type_string == 'string' or type_string == 'STRING':
            return 'STRING'
        else:
            raise self.GPTException(f"Invalid type string: {type_string}")

    def extract_response(self, response):
        content = response["choices"][0]["message"]["content"]

        arg_types = content.split(" ")
        arg_types = [self.convert_to_valid_type(arg_type.strip()
                                                ) for arg_type in arg_types]

        return arg_types

    def __init__(self, code, name, openai_key, debug=False):
        self.code = code
        self.name = name
        with open(os.path.join("output", "scratch", "afl", name), "r") as f:
            self.content = f.read()

        self.openai_key = openai_key
        self.debug = debug
        with open(os.path.join("test_file_gen", "preamble"), "r") as f:
            self.preamble = f.read()
        with open(os.path.join("test_file_gen", "example_history"), "r") as f:
            example_contents = f.read()
            example_contents = example_contents.split("REQRES")
            self.example = []
            for i in range(len(example_contents)):
                if i % 2 == 0:
                    self.example.append({'role': 'user', 'content': example_contents[i]})
                else:
                    self.example.append({'role': 'assistant', 'content': example_contents[i]})

        with open(os.path.join("default_arg", "preamble"), "r") as f:
            self.arg_preamble = f.read()
        with open(os.path.join("default_arg", "example_history"), "r") as f:
            example_contents = f.read()
            example_contents = example_contents.split("REQRES")
            self.arg_example = []
            for i in range(len(example_contents)):
                if i % 2 == 0:
                    self.arg_example.append({'role': 'user', 'content': example_contents[i]})
                else:
                    self.arg_example.append({'role': 'assistant', 'content': example_contents[i]})

    def get_number_of_arguments(self):
        pattern = r'if \(argc != (\d+)\) {'
        match = re.search(pattern, self.content)
        if match:
            return int(match.group(1)) - 1
        else:
            return None  # Could not find number of arguments

    def get_type_of_arguments(self, arg_index):
        lines = self.content.split('\n')
        pattern = r'argv\[' + str(arg_index) + r'\]'
        for line in lines:
            match = re.search(pattern, self.content)
            if match:
                # Check for integer usage
                if re.search(r'\batoi\s*\(', line):
                    return 'INT32'
                # Check for floating-point usage
                elif re.search(r'\batof\s*\(', line):
                    return 'FLOAT'
                # Check for character usage
                elif re.search(r'\bargv[' + str(arg_index) + r']\[\d+]\b', line):
                    return 'CHAR'
                # Check for long usage
                elif re.search(r'\batol\s*\(|\batoll\s*\(', line):
                    return 'LONG'
                # check for string usage
                elif re.search(r'= \bargv[' + str(arg_index) + r']\b', line):
                    return 'STRING'
                else:
                    return None
        else:
            return None

    def get_default_arg_values(self):
        # #If reverting back to this version, remember to add type_string to the function arguments and change its call
        # if (type_string == 'INT32' or type_string == 'LONG' or type_string == 'UINT32' or type_string == 'ULONG'
        #         or type_string == 'SHORT' or type_string == 'USHORT' or type_string == 'UCHAR'):
        #     return '0'
        # elif type_string == 'FLOAT' or type_string == 'DOUBLE':
        #     return '0.0'
        # elif type_string == 'CHAR':
        #     return 'A'
        # elif type_string == 'STRING':
        #     return 'stringValue'
        # else:
        #     raise Exception('Unknown type string')
        with open(os.path.join("output", "scratch", "text", self.name), "r") as f:
            original = f.read()
        with open(os.path.join("output", "scratch", "afl", self.name), "r") as f:
            afl = f.read()

        result = prompt(original + afl, self.arg_preamble, self.arg_example)
        result = result["choices"][0]["message"]["content"]
        result = result.split(" ")
        result = [arg.strip() for arg in result]

        return result

    def generate_from_gpt(self, attempts=3):
        fail_count = 0
        while fail_count < attempts:
            if fail_count > 0:
                print(f'Retrying {self.name} ({fail_count} of {attempts})')
            try:
                arg_types = self.extract_response(prompt(self.content, self.preamble, self.example))
                return arg_types
            except openai.error.ServiceUnavailableError:
                time.sleep(5)
            except TestFilesGen.GPTException as e:
                fail_count += 1
                print(f'Attempt {fail_count} failed for {self.name}: {e}')
        save_failed_input(self.name)

    def test(self, args):
        """Run the afl compiled version with suggested arguments, if it crashes, return False"""
        try:
            print(f"Running {self.name} with {args}")
            subprocess.check_call([os.path.join("output", "scratch", "compilation", self.name), *args], shell=True)
            return True
        except subprocess.CalledProcessError:

            return False

    def run(self):
        should_try = True
        while should_try:
            num_args = self.get_number_of_arguments()
            if num_args is None:
                # This is fine, means there's no constants
                return
            arg_types = []
            for i in range(num_args):
                result = self.get_type_of_arguments(i)
                if result is not None:
                    arg_types.append(result)
                else:
                    # something went wrong, must fall back to gpt
                    arg_types = self.generate_from_gpt()

            # save the files:
            with open(os.path.join("output", "binary", self.name + ".o.types"), "w") as f:
                if arg_types is not None:
                    for arg in arg_types:
                        f.write(arg + " ")

            with open(os.path.join("output", "input", self.name.replace(".c", ".txt")), "w") as f:
                f.write(self.name + "\n")
                # get the default values
                args = self.get_default_arg_values()
                for arg in args:
                    f.write(arg + " ")

            # test it, if it fails, try again
            should_try = not self.test(args)

            if should_try:
                print(f"Test failed for {self.name}, trying again")



def main():
    # get args
    if len(sys.argv) < 3:
        print("Usage: python3 test_file_gen.py <prompt> <key> <source> [--debug]")
        sys.exit(1)

    key = sys.argv[1]
    prompt = sys.argv[2]
    source = sys.argv[3]
    debug = False

    openai.api_key = key

    setup_folders()
    setup_files()

    arg_gen = ArgGen(prompt, key, source, debug)
    input_programs = arg_gen.run()

    for (name, code) in input_programs:
        test_gen = TestFilesGen(code, name, key, debug)
        test_gen.run()


if __name__ == "__main__":
    main()
