import os


def build_binaries(input_file, output_file, compiler="gcc", compilation_flags=""):
    if input_file.endswith(".c"):
        file_path = os.path.join(input_file)
        if os.path.isfile(file_path):
            os.system(f"{compiler} {compilation_flags} -w {file_path} -o {output_file}.o")
            if not os.path.isfile(output_file + ".o"):
                raise Exception(f"Compilation failed for file {file_path}")


def main():
    files = os.listdir("binary/source")

    for file in files:
        build_binaries(os.path.join("binary/source", file), os.path.join("binary", file + ".o"))


if __name__ == '__main__':
    main()
