#!/bin/bash
testsin=$1
testsout=$2

test_cases_folder=$testsout/tests  # write all tests here
test_data=$testsout/binary # Write data of tests here
# Create the test_cases folder if it doesn't exist

mkdir -p "$test_cases_folder"

for file in *.c.txt; do
    if [ -f "$file" ]; then
        exec_command=$(head -1 "$file")
        inputs=$(tail -1 "$file")

        if [ -x "$exec_command" ]; then
            echo "Running: $exec_command with inputs: $inputs"
            eval "$exec_command" <<< "$inputs"
            exit_status=$
            
            if [ "$exit_status" -eq 0 ]; then
                echo "Command successful. Copying $file to $test_cases_folder"
                cp "$file" "$test_cases_folder"
            else
                echo "Error: Command exited with status $exit_status"
            fi
        else
            echo "Error: $exec_command either not found or doesn't have execute permissions. Skipping."
        fi
    fi
done
