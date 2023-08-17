import os
import sys


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 convert-to-abs-path.py <inputs-dir>")
        sys.exit(1)

    inputs_dir = sys.argv[1]
    if not os.path.isabs(inputs_dir):
        inputs_dir = os.path.join(os.getcwd(), inputs_dir)

    for filename in os.listdir(os.path.join(inputs_dir, 'inputs')):
        with open(os.path.join(inputs_dir, 'inputs', filename), 'r') as f:
            file_content = f.read()
            path = file_content.split(' ')[0]
            file_content = os.path.join(inputs_dir, 'binary', path) + ' ' + file_content[len(path) + 1:]
            with open(os.path.join(inputs_dir, 'inputs', filename), 'w') as f:
                f.write(file_content)


if __name__ == '__main__':
    main()
