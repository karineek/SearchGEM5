#!/bin/bash

## MAIN ##
path=$1

# Loop through each txt file in the current directory
for file in $path/*; do
    # Check if the file exists and is readable
    if [ -r "$file" ]; then
        echo ">> Test $file"

        # Read the first two lines of the file and concatenate them into one line
        first_two_lines=$(head -n 2 "$file" | tr '\n' ' ')

        # Execute the concatenated line as a command using command substitution
        (ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0") > results-1.txt 2>&1
        exit_status=$?

        (ulimit -St 50 -Sf 90000; /home/debian/gem5/build/ARM/gem5.opt /home/debian/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input $file) > results-2.txt 2>&1
        exit_status_sim=$?
        grep -e " fatal: " -e"panic condition" -e "unimplemented" -e"Assertion" -e "invalid instruction executed" -e "unmapped address" -e"Assertion"  -e"occurred: fault" -e"invalid instruction executed" results-2.txt
	echo "exit_status $exit_status and exit_status_sim $exit_status_sim"
        head -n 2 "$file"

     	if [ $exit_status_sim -eq 0 ]; then
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
    echo "====================================================================" 
    echo " "

    echo "====================================================================" >> all_details.log
    cat results-2.txt >> all_details.log
    cat results-1.txt >> all_details.log
done
