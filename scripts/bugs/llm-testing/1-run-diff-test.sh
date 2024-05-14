#!/bin/bash

## MAIN ##
path=$1

# Loop through each txt file in the current directory
for file in $path/*.txt; do
    # Check if the file exists and is readable
    if [ -r "$file" ]; then
        echo ">> Test $file"

        # Read the first two lines of the file and concatenate them into one line
        first_two_lines=$(head -n 2 "$file" | tr '\n' ' ')

        # Execute the concatenated line as a command using command substitution
        (ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0") > results-1.txt 2>&1
        exit_status=$?

        (ulimit -St 50 -Sf 90000; /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input $file) > results-2.txt 2>&1
	if [ $? -eq 0 ]; then
		# Check if output is the same:
                # Check if the contents of file1 are present in file2
		if grep -qF "$(cat "results-1.txt")" "results-2.txt"; then
    			echo "File-1 contents are present in File-2" # SKIP
		else
			# Test otherwise:
        		if [ $exit_status -eq 0 ]; then
				echo "DIFF TESTING"
				echo "DIFF TESTING - different results: $file" >> report-diff.log
			else
				grep -e"Opening file failed: No such file or directory" -e"Error: Could not open 0 for reading." results-2.txt
				if [ $? -ne 0 ]; then
					echo ">> False simulation: Simulation OK, NATIVE error"
					echo ">> False simulation: Simulation OK, NATIVE error: $file" >> report-diff.log
				else
					echo ">> Both failed. Skip." # SKIP
				fi
			fi
		fi
	else
		if [ $exit_status -eq 0 ]; then
                        echo ">> False simulation: Simulation error, NATIVE OK"
			echo ">> False simulation: Simulation error, NATIVE OK: $file" >> report-diff.log
                else
                        echo ">> Both failed. Skip." # SKIP
                fi
        fi
    else
        echo "Error: $file is not readable or does not exist."
    fi

    #echo "====================================================================" >> log.log
    #cat results-2.txt >> log.log
    #cat results-1.txt >> log.log
done
