"""
USAGE: <openai_key> <prompt_file> <source_url> <debug>
"""
import os
import sys
import shutil
import time
import regex as re
from pycparser import c_parser, plyparser

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
    os.makedirs("output/scratch/ast", exist_ok=True)
    os.makedirs("output/scratch/compilation", exist_ok=True)
    os.makedirs("output/binary", exist_ok=True)
    os.makedirs("output/input", exist_ok=True)


def setup_files():
    shutil.copyfile('compile.py', os.path.join('output', 'compile.py'))
    shutil.copyfile('convert-to-abs-path.py', os.path.join('output', 'convert-to-abs-path.py'))


def prompt(text, preamble_text, example_array):
    print(f"Prompting with {text}")
    print(f"Example array: {example_array}")
    print(f"Preamble text: {preamble_text}")
    return openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        temperature=0.8,  # a temperature of 0.9 seems to work best
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

    # if the first line is an include then dont process any further
    if content.startswith("#include"):
        return content

    content = re.split(r'```(.*)\n', content)

    if len(content) < 3:
        return ""
    content = content[2]

    content = content.replace("```", "")

    return content


def compile_code(code_file, output_file):
    """Compile the code and capture the output to return, as well as the return code"""
    print(f"gcc -o {output_file} {code_file} > {output_file.replace('.c', '.txt')} 2>&1")
    os.system(f"gcc -o {output_file} {code_file} > {output_file.replace('.c', '.txt')} 2>&1")
    with open(output_file.replace(".c", ".txt"), "r") as f:
        output = f.read()
    return_code = os.system(f"echo $?")
    return output, return_code


def run_code(code_file, inputs):
    # run the code with the inputs and capture the output, as well as the return code
    # we also want to run the version with no args (need to compile too)
    # and ensure the outputs and return codes are the same
    modified_file = os.path.join("output", "scratch", "compilation", code_file)
    compile_code(os.path.join("output", "scratch", "text", code_file),
                              os.path.join("output", "scratch", "compilation", code_file + "_unmodified"))
    unmodified_file = os.path.join("output", "scratch", "compilation", code_file + "_unmodified")

    # run the unmodified version with no args
    os.system(f"./{unmodified_file} > {unmodified_file.replace('.c', 'unmodified_result.txt')} 2>&1")
    # get the return code
    return_code_unmodified = os.system(f"echo $?")

    # run the modified version with args
    print(f"./{modified_file} {inputs} > {modified_file.replace('.c', 'modified_result.txt')} 2>&1")
    os.system(f"./{modified_file} {inputs} > {modified_file.replace('.c', 'modified_result.txt')} 2>&1")
    # get the return code
    return_code_modified = os.system(f"echo $?")

    # read the outputs
    with open(unmodified_file.replace('.c', 'unmodified_result.txt'), "r") as f:
        unmodified_output = f.read()
    with open(modified_file.replace('.c', 'modified_result.txt'), "r") as f:
        modified_output = f.read()

    print(f"Unmodified output: {unmodified_output}")
    print(f"Modified output: {modified_output}")
    print(f"Unmodified return code: {return_code_unmodified}")
    print(f"Modified return code: {return_code_modified}")
    return unmodified_output, modified_output, return_code_unmodified == return_code_modified


def insert_arg_format(content, src, file_name):
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime())

    return f"// Modification timestamp: {timestamp}\n// Original Source: {src}/{file_name}\n{content}"


class TestFilesGen:
    def __init__(self, code, name, debug=False):
        self.code = code
        self.name = name
        with open(os.path.join("output", "scratch", "afl", name), "r") as f:
            self.content = f.read()
        with open(os.path.join("output", "scratch", "text", name), "r") as f:
            self.original_content = f.read()

        self.debug = debug

    def run(self):
        print(f"Running {self.name}")
        # Remove the comments from the original and modified files
        original_content = re.sub(r'\/\*((.|\n)*)*\*\/', '', self.original_content)
        modified_content = re.sub(r'\/\*((.|\n)*)*\*\/', '', self.content)
        # also remove // comments
        original_content = re.sub(r'\/\/.*\n', '', original_content)
        modified_content = re.sub(r'\/\/.*\n', '', modified_content)

        # remove extern directives
        original_content = re.sub(r'extern .*\n;', '', original_content)
        modified_content = re.sub(r'extern .*\n;', '', modified_content)

        # remove import directives
        original_content = re.sub(r'#include .*\n', '', original_content)
        original_content = re.sub(r'#define .*\n', '', original_content)
        original_content = re.sub(r'#undefine .*\n', '', original_content)
        original_content = re.sub(r'#pragma once .*\n', '', original_content)
        modified_content = re.sub(r'#include .*\n', '', modified_content)
        modified_content = re.sub(r'#define .*\n', '', modified_content)
        modified_content = re.sub(r'#undefine .*\n', '', modified_content)
        modified_content = re.sub(r'#pragma once .*\n', '', modified_content)

        original_content = re.sub(r'#if(def|ndef|)? .*((.|\n)*)#endif', '', original_content)
        modified_content = re.sub(r'#if(def|ndef|)? .*((.|\n)*)#endif', '', modified_content)

        try:
            parser = c_parser.CParser()
            original_ast = parser.parse(original_content, filename='<none>')
            modified_ast = parser.parse(modified_content, filename='<none>')
        except plyparser.ParseError as e:
            print("Parse error, skipping")
            print(e)
            return
        except AssertionError as e:
            print("Assertion error, skipping")
            print(e)
            return


        # save the ASTs to files
        with open(os.path.join('output', 'scratch', 'ast', self.name + '_original_ast.txt'), 'w') as f:
            f.write(str(original_ast))

        with open(os.path.join('output', 'scratch', 'ast', self.name + '_modified_ast.txt'), 'w') as f:
            f.write(str(modified_ast))

        # run diff
        os.system(f"diff {os.path.join('output', 'scratch', 'ast', self.name + '_original_ast.txt')} "
                  f"{os.path.join('output', 'scratch', 'ast', self.name + '_modified_ast.txt')} > "
                  f"{os.path.join('output', 'scratch', 'ast', self.name + '_diff.txt')}")

        # read diff
        with open(os.path.join('output', 'scratch', 'ast', self.name + '_diff.txt'), 'r') as f:
            diff = f.read()

            def parse_diff_blocks(diff_text):
                identifier_regex = r'(?<!\d)(\d+(?:,\d+)?[acd]\d+(?:,\d+)?)(?!\d)'
                diff_blocks = re.split(identifier_regex, diff_text)
                # remove the identifier regex matches
                diff_blocks = [x for x in diff_blocks if not re.match(identifier_regex, x)]
                # remove empty strings and None
                diff_blocks = [x for x in diff_blocks if x]
                # strip whitespace
                diff_blocks = [x.strip() for x in diff_blocks]

                return diff_blocks

            diff_blocks = parse_diff_blocks(diff)

            args = []

            for block in diff_blocks:
                if "ExprList(exprs=[ArrayRef(name=ID(name='argv'" in block:
                    # split by add or sub
                    try:
                        result = block.split("---\n")
                        sub = result[0]
                        add = result[1]
                    except IndexError:
                        print("Could not split block")
                        continue

                    # check if its a pair we care about (containing an array ref to argv)
                    if "ArrayRef(name=ID(name='argv'" in add:
                        index_regex = r"\[ArrayRef\(name=ID\(name='argv'\s*\n>\s*\),\n>\s*subscript=Constant\(type='int',\s*\n>\s*value='(\d+)'"
                        index = re.search(index_regex, add)
                        i = None
                        if index:
                            i = index.group(1)
                        else:
                            print("could not find index")

                        # get the value and type of the constant
                        value_regex = r"Constant\(type='(\w+)',\s*\n<\s*value='(\w+)'"
                        value = re.search(value_regex, sub)
                        v = None
                        t = None
                        if value:
                            v = value.group(2)
                            t = value.group(1)
                        else:
                            print("could not find value")

                        if i and v and t:
                            args.append((i, t, v))
                        else:
                            print("could not find either index or value")

            with open(os.path.join("output", "binary", self.name + ".o.types"), "w") as f:
                if args:
                    for arg in args:
                        f.write(arg[1] + " ")

            with open(os.path.join("output", "input", self.name.replace(".c", ".txt")), "w") as f:
                f.write(self.name + "\n")
                if args:
                    args.sort(key=lambda x: int(x[0]))

                    for arg in args:
                        f.write(arg[2] + " ")


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

    def run_single(self, name, code):
        should_try = True
        try_count = 0
        current_example = self.example
        while should_try:
            time.sleep(1)
            try:
                result = prompt(code, self.preamble, current_example)
                if self.debug:
                    print("Result: \n ", result)
            except openai.error.ServiceUnavailableError:
                time.sleep(5)
                try_count += 1
                if try_count > 10:
                    print("Too many tries, skipping")
                    should_try = False
                    save_failed_input(name)
                continue

            prog = extract_code(result)
            if self.debug:
                print("Program: \n", prog)

            # save the program
            with open(os.path.join("output", "scratch", "afl", name), "w") as f:
                if self.debug:
                    print("Saving to: ", os.path.join("output", "scratch", "afl", name))
                f.write(insert_arg_format(prog, self.source_url, name))

            # compile the program
            output, return_code = compile_code(os.path.join("output", "scratch", "afl", name),
                                               os.path.join("output", "scratch", "compilation", name))

            if self.debug:
                print("Compilation output: ", output)
                print("Compilation return code: ", return_code)

            # if it compiles, get the args, and try to run it
            if return_code == 0:
                with open(os.path.join("output", "scratch", "text", name), "w") as f:
                    f.write(insert_arg_format(code, self.source_url, name))

                if self.debug:
                    print("getting args")

                test_gen = TestFilesGen(code, name, self.debug)
                test_gen.run()

                if self.debug:
                    print("running code")

                if os.path.exists(os.path.join("output", "input", name.replace(".c", ".txt"))):
                    with open(os.path.join("output", "input", name.replace(".c", ".txt")), "r") as f:
                        input_file = f.read()
                        input_file = input_file.split("\n")
                        input_file = input_file[1]
                        unmodified_output, modified_output, return_code_success = run_code(name, input_file)
                        if not (return_code_success and unmodified_output == modified_output):
                            print("Output does not match, trying again")
                            print("Output: ", modified_output)
                            print("Expected: ", unmodified_output)
                            current_example += [{'role': 'user', 'content': code}]
                            current_example += [{'role': 'assistant', 'content': prog}]
                            current_example += [{'role': 'user', 'content': 'Please try again, '
                                                                            'output does not match the expected\n' +
                                                                            'here\'s the output yours produced: '
                                                                            + modified_output
                                                                            + '\nhere\'s the output we expected: '
                                                                            +  unmodified_output}]
                            try_count += 1
                            if try_count > 2:       # It loves to just apologise each time messing with the parsing
                                                    # so best to not waste too long on it
                                print("Too many tries, skipping")
                                should_try = False
                                save_failed_input(name)
                            continue

                print("Success!")
                should_try = False
                continue
            else:
                print("Compilation failed, trying again")
                current_example += [{'role': 'user', 'content': code}]
                current_example += [{'role': 'assistant', 'content': prog}]
                current_example += [{'role': 'user', 'content': 'Please try again, compiling failed:\n' + output}]
                try_count += 1
                if try_count > 4:
                    print("Too many tries, skipping")
                    should_try = False
                    save_failed_input(name)
                    continue


def main():
    # get args
    if len(sys.argv) < 3:
        print("Usage: python3 test_file_gen.py <prompt> <key> <source> [--debug]")
        sys.exit(1)

    key = sys.argv[1]
    prompt = sys.argv[2]
    source = sys.argv[3]
    debug = True

    openai.api_key = key

    setup_folders()
    setup_files()

    arg_gen = ArgGen(prompt, key, source, debug)
    arg_gen.run()


if __name__ == "__main__":
    main()