import os
import sys
from time import time
from shlex import quote

from openai import OpenAI


def query_jar(jar_file: str, type_of_query: str, query: str | None = None) -> str:
    """
    This function will query the class file with the given query and return the result
    """
    if query is None:
        # We are querying for a type of query
        print(f"java -jar {jar_file} QueryGenerator {type_of_query}")
        result = os.popen(f"java -jar {jar_file} QueryGenerator {type_of_query}").read()
    else:
        # We are querying for a specific query
        print(f"java -jar {jar_file} QueryGenerator {type_of_query} {quote(query)}")
        result = os.popen(f"java -jar {jar_file} QueryGenerator {type_of_query} {quote(query)}").read()
    return result


def generate_filename() -> str:
    return "test_input_" + str(int(time())) + ".c"


def write_to_file(file: str, content: str):
    with open(file, "w") as f:
        f.write(content)


def generate_obj(file_name, obj_name):
    print(f"gcc -O3 {file_name} -o {obj_name}")
    os.system(f"gcc -O3 {file_name} -o {obj_name}")


def save_results(program: str, call_line: str, args_type: str):
    try:
        file_name_c = generate_filename()
        file_name_obj = file_name_c + ".o"
        file_name_type = file_name_c + ".type"
        file_name_input = file_name_c + ".txt"

        write_to_file(file_name_c, program)

        generate_obj(file_name_c, file_name_obj)

        test_args = file_name_obj + "\n" + call_line
        write_to_file(file_name_input, test_args)

        write_to_file(file_name_type, args_type)
    except Exception as e:
        print(f"Error: {e}")


class GPTProgramGenerator:
    def __init__(self, file: str, client: OpenAI):
        self.jar_path = file
        self.client = client
        self.system_prompt = query_jar(file, "0")
        self.history = []

    def add_to_history(self, prompt: str, response: str):
        if len(self.history) > 5:
            self.history.pop(0)
        self.history.append({
            'role': 'user', 'content': prompt
        })
        self.history.append({
            'role': 'assistant', 'content': response
        })

    def prompt(self, prompt_text: str) -> str:
        try:
            result = self.client.chat.completions.create(
                model="gpt-3.5-turbo-16k",
                messages=[
                    {
                        'role': 'system', 'content': self.system_prompt
                    },
                    *self.history,
                    {
                        'role': 'user', 'content': prompt_text
                    }
                ]
            )

            self.add_to_history(prompt_text, result.choices[0].message.content)

            return result.choices[0].message.content
        except Exception as e:
            print(f"Error: {e}")
            return ""

    def generate_program(self):
        query = query_jar(self.jar_path, "1")
        print(f"Prompting GPT-3 with: \n{query}")
        result = self.prompt(query)
        print(f"Received response: {result}")
        result = query_jar(self.jar_path, "2", result)

        try:
            types = result.split("\n")[0]
            call_line = result.split("\n")[1]
            program = "\n".join(result.split("\n")[2:])

            print(f"Generated program: \n{program}")
            print(f"Types: {types}")
            print(f"Call line: {call_line}")

            save_results(program, call_line, types)
        except IndexError:
            print("Error: failed to parse response")
            return

    def run(self):
        while True:
            self.generate_program()
            break


if __name__ == "__main__":
    args = sys.argv

    # We expect a jar file location (default to ./QueryGenerator.jar)
    if len(args) < 2:
        # Check if the jar file exists
        if not os.path.exists("./QueryGenerator.jar"):
            print("Error: No jar file found at ./QueryGenerator.jar")
            print("Usage: python3 ProgramGenerator.py <path_to_jar_file>")
            sys.exit(1)
        else:
            jar = "./QueryGenerator.jar"
    else:
        jar = args[1]

    key = os.environ.get("OPENAI_API_KEY")

    if not key:
        print("Error: No OpenAI API key found")
        print("Please set the OPENAI_API_KEY environment variable to your OpenAI API key")
        sys.exit(1)

    gpt = GPTProgramGenerator(jar, OpenAI(api_key=key))

    gpt.run()
