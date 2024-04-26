#!/bin/bash

## MAIN ##
file=$1

if [ -r "$file" ]; then
        echo ">> Test $file"

        # Read the first two lines of the file and concatenate them into one line
        first_two_lines=$(head -n 2 "$file" | tr '\n' ' ')

        # Execute the concatenated line as a command using command substitution
        echo "=================== 1 ================="
        (ulimit -St 50 -Sf 90000; $first_two_lines <<< "0 0 0 0 0 0")

        echo "=================== 2 ================="
        (ulimit -St 50 -Sf 90000; /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input $file)
fi
