#!/bin/bash
tests_in=$1
tests_out=$2

test_cases_folder=$tests_out/tests  # write all tests here
test_source=$tests_out/source # Write source of tests here
test_data=$tests_out/binary # Write data of tests here
# Create the test_cases folder if it doesn't exist

mkdir -p "$test_cases_folder"
mkdir -p "$test_source"
mkdir -p "$test_data"

for file in "$tests_in"/*.c.txt; do
    if [ -f "$file" ]; then
        exec_command=$(head -1 "$file")
        inputs=$(tail -1 "$file")

        # Prepend test_in folder to file name
        exec_command="$tests_in/$exec_command"

        file_name="${file%.*}"
        file_name="${file_name%.*}"

        if [ -x "$exec_command" ]; then
            echo "Running: $exec_command with inputs: $inputs"
            IFS=' ' read -r -a input_array <<< "$inputs"
            "$exec_command" "${input_array[@]}"
            exit_status=$?

            if [ "$exit_status" -eq 0 ]; then
                echo "Command successful. Copying $file to $test_cases_folder"
                cp "$file" "$test_cases_folder"

                echo "Copying ${file_name}.c.type to $test_cases_folder"
                cp "${file_name}.c.type" "$test_cases_folder"

                echo "Copying ${file_name}.c to $test_source"
                cp "${file_name}.c" "$test_source"
            else
                echo "Error: Command exited with status $exit_status"
            fi

        else
            echo "Error: $exec_command either not found or doesn't have execute permissions. Skipping."
        fi
    fi
done
