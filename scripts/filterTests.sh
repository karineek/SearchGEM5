#!/bin/bash
tests_in=$1
tests_out=$2
bin=$3
script=$4
# For example:
# ./filterTests_SSBSE2023.sh /home/ubuntu/sets/gpt3.5-old/sort/data/ /home/ubuntu/sets/gpt3.5-old/sort/data_out/ /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py

test_cases_folder=$tests_out/input/  # write all tests here
test_data=$tests_out/binary/ # Write data of tests here
mkdir -p "$test_cases_folder"
mkdir -p "$test_data"

i=0
j=0
for file in "$tests_in"/*.txt; do
    if [ -f "$file" ]; then
	echo "=================================================================================="
        exec_command_o=$(head -1 "$file")

        # Prepend test_in folder to file name
	exec_command="(ulimit -St 50; $bin $script --isa X86 --input $file > /dev/null 2>&1); echo \$?"
	echo "$exec_command" > run.sh
	chmod 777 run.sh
	exit_status=`./run.sh`
        if [ "$exit_status" -eq 0 ]; then
                cp $file $test_cases_folder
		cp $exec_command_o $test_data

		type_filename="${exec_command_o%.c.o}.c.type"
		cp $type_filename $test_data
		i=$((i+1))
        else
		echo " >>> FAILED $file"
            	j=$((j+1))
        fi
    fi
done
echo "Done. Failed $j. Succ $i"
