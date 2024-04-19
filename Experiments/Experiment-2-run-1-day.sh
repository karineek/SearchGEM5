#!/bin/bash

# Input value
i=$1 # days 1 to 30
output=$2

# Array of data values
data=("CodeBooga" "Llama" "Magicoder" "Phi" "TinyLlama" "gpt3.5-new" "gpt3.5-old")

# Check if the directory exists
if [ ! -d "$output" ]; then
    # If it doesn't exist, create it
    mkdir "$output"
fi
# Loop through data array
for curr_data in "${data[@]}"; do
    # Without '-cmin'
    # for j in {1,5,6,7,8}; do
    #     outputCur=${output}/output-2-${curr_data}-${j}
    # 	if [ ! -d "$outputCur" ]; then
    #         mkdir $outputCur
    # 	fi
    #     outputEx=${outputCur}/${i}/
    # 	if [ ! -d "$outputEx" ]; then
    # 	    mkdir $outputEx
    # 	fi
    #     echo "sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $curr_data $j 27 /home/debian/output $i"
    #     sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $curr_data $j 27 /home/debian/output $i	&
    # done

    # With '-cmin'
    for j in {1,5,6,7,8}; do
        model=${curr_data}-cmin
	outputCur=${output}/output-2-${model}-${j}
	if [ ! -d "$outputCur" ]; then	
           mkdir $outputCur
	fi
        outputEx=${outputCur}/${i}/
	if [ ! -d "$outputEx" ]; then
	    mkdir $outputEx
	fi
	echo "sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $curr_data $j 27 /home/debian/output $i"
        sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $model $j 27 /home/debian/output $i	&
    done

	q=$(($i+1))
    for j in {1,5,6,7,8}; do
        model=${curr_data}-cmin
	outputCur=${output}/output-2-${model}-${j}
	if [ ! -d "$outputCur" ]; then	
           mkdir $outputCur
	fi
        outputEx=${outputCur}/${q}/
	if [ ! -d "$outputEx" ]; then
	    mkdir $outputEx
	fi
	echo "sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $curr_data $j 27 /home/debian/output $i"
        sudo docker run -it -v ${outputEx}:/home/debian/output/:Z aserepo exp 2 $model $j 27 /home/debian/output ${q}	&
    done
done
