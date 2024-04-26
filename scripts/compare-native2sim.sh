#!/bin/bash

## MAIN ##
file=$1

if [ -r "$file" ]; then
        echo ">> Test $file"

        # Read the first two lines of the file and concatenate them into one line
        first_two_lines=$(head -n 2 "$file" | tr '\n' ' ')

	# Check before
	 echo "=================== A ================="
        (ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0") > results-A.txt 2>&1
	 echo "=================== B ================="
        (ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0") > results-B.txt 2>&1

	# Check if deterministic res.
	diff  results-A.txt results-B.txt
        if [ $? -eq 0 ]; then

	        # Execute the concatenated line as a command using command substitution
		echo "=================== 1 ================="
        	(ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0")

		echo "=================== 2 ================="
        	(ulimit -St 50 -Sf 90000; /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input $file)
	else
		echo "Results are non-det. Not a bug"
	fi
fi
