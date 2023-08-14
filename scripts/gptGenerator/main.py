"""
USAGE:
    python main.py <prompt_file> <openai_key> <source_url> <debug>

    The training information is in preamble and example_history
    preamble is a single system message to the model explaining its behavior
    example_history is a list of user and assistant messages that the model will see as history and can use as exmaples
    you can split the user and assistant messages with the string REQRES on a new line

    An openai api key must be provided in a .env file in the same directory as this file under the name OPENAI_API_KEY
    If there is an error, you can set the DEBUG environment variable to true to see the models that are available to you
    incase you need to change the model id. The source url refers to the url preceeding each file name in the response:
    i.e. // Original Source: <source_url>/<file_name>

NOTE:
    Sometimes it fails to generate a filename as requested, if so, it will try again,
    if this also fails, it will exit with an error code of 1
"""

import os
import sys

import openai
from dotenv import load_dotenv
import time
import re

load_dotenv()

openai.api_key = os.getenv("OPENAI_API_KEY")
debug = os.getenv("DEBUG") == "true"


def setup_folders():
    """Create the folders for the text and afl files"""
    if not os.path.exists("text"):
        os.makedirs("text")

    if not os.path.exists("afl"):
        os.makedirs("afl")


def extract_code(response):
    """Extract the code block from the response as well as the name associated with it"""
    content = response["choices"][0]["message"]["content"]

    content = content.replace("```cpp", "") # Incase it includes language tags
    content = content.replace("```c", "") # Incase it includes language tags
    content = content.replace("```", "") # otherwise

    return content


def insert_format(content, src, file_name):
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.gmtime())

    return f"// Modification timestamp: {timestamp}\n// Original Source: {src}/{file_name}\n{content}"


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


def save_prompt(code, file):
    print(f"Saving to {file}")
    with open(file, "w") as f:
        f.write(code)


def save_from_prompt(text, src, file_name, preamble="", example=[]):
    response = prompt(text, preamble, example)
    prog = extract_code(response)
    save_prompt(insert_format(text, src, file_name), f"text/{file_name}")
    save_prompt(insert_format(prog, src, file_name), f"afl/{file_name}")


if __name__ == '__main__':
    if len(sys.argv) > 1:
        file = sys.argv[1]
    else:
        #file = "example_prompt"
        raise Exception("No prompt file provided")

    if len(sys.argv) > 2:
        openai.api_key = sys.argv[2]

    if len(sys.argv) > 3:
        source = sys.argv[3]

    if len(sys.argv) > 4:
        debug = sys.argv[3] == "true"

    if debug:
        models = openai.Model.list()

        for model in models["data"]:
            print(model["id"])

    with open("preamble", "r") as f:
        preamble = f.read()

    with open("example_history", "r") as f:
        exampleContents = f.read()
        exampleContents = exampleContents.split("REQRES")
        example = []
        for i in range(len(exampleContents)):
            if i % 2 == 0:
                example.append({'role': 'user', 'content': exampleContents[i]})
            else:
                example.append({'role': 'assistant', 'content': exampleContents[i]})

    with open(file, "r") as f:
        p = f.read()

    input_programs = []

    for inp in p.split("// source: "):
        # get name and code
        if inp == "":
            continue
        split = inp.split("\n")
        name = split[0]
        code = split[1:]
        code = "\n".join(code)

        input_programs.append((name, code))

    setup_folders()

    for (name, code) in input_programs:
        print(f"Generating code for {name}")
        fail_count = 0
        while fail_count < 2:
            try:
                save_from_prompt(code, source, name, preamble, example)
                break
            except Exception as e:
                print(e)
                print("Failed to generate code, trying again")
                fail_count += 1

