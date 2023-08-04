"""
USAGE:
    python main.py <prompt_file> <openai_key> <debug>

    The training information is in preamble and example_history
    preamble is a single system message to the model explaining its behavior
    example_history is a list of user and assistant messages that the model will see as history and can use as exmaples
    you can split the user and assistant messages with the string REQRES on a new line

    An openai api key must be provided in a .env file in the same directory as this file under the name OPENAI_API_KEY
    If there is an error, you can set the DEBUG environment variable to true to see the models that are available to you
    incase you need to change the model id

NOTE:
    Sometimes it fails to generate a filename as requested, if so, it will try again,
    if this also fails, it will exit with an error code of 1
"""

import os
import sys

import openai
from dotenv import load_dotenv
import time

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

    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
    content = content.replace("TIMESTAMP_REPLACEMENT_STRING_GPT_GENERATED", timestamp)

    program_1 = content.split("Program 1")[1].split("Program 2")[0]
    program_2 = content.split("Program 2")[1]

    code_1 = program_1.split("```")[1]
    code_2 = program_2.split("```")[1]

    name = content.split("Program 1")[1].split("```")[0].replace("(", "").replace(")", "").replace(":", "").strip()

    if name == "":
        name = content.split("Program 2")[1].split("```")[0].replace("(", "").replace(")", "").replace(":", "").strip()

    if name == "":
        print("ERROR: Could not find name of program")
        raise Exception("Could not find name of program")

    return (code_1, name), (code_2, name)


def prompt(text, preamble_text, example_array):
    return openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        temperature=0.9,    # a temperature of 0.9 seems to work best
        messages=[
            {
                'role': 'system', 'content': preamble_text
            },
            example_array[0],
            example_array[1],
            {
                'role': 'user', 'content': text
            }
        ]
    )


def save_prompt(code, file):
    print(f"Saving to {file}")
    with open(file, "w") as f:
        f.write(code)


def save_from_prompt(text, preamble="", example=[]):
    response = prompt(text, preamble, example)
    (program_1, program_2) = extract_code(response)
    save_prompt(program_1[0], f"text/{program_1[1]}")
    save_prompt(program_2[0], f"afl/{program_2[1]}")


if __name__ == '__main__':
    if len(sys.argv) > 1:
        file = sys.argv[1]
    else:
        #file = "example_prompt"
        raise Exception("No prompt file provided")

    if len(sys.argv) > 2:
        openai.api_key = sys.argv[2]

    if len(sys.argv) > 3:
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

    setup_folders()

    try:
        save_from_prompt(p, preamble, example)
    except Exception as e:
        print("Error, trying again")
        try:
            save_from_prompt(p, preamble, example)
        except Exception as e:
            print(e)
            sys.exit(1)
