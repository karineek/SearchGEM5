#!/bin/bash

# Input value
i=$1 # days 1 to 30
container=$2 # container hash

# Array of data values
data=("CodeBooga" "Llama" "Magicoder" "Phi" "TinyLlama" "gpt3.5-new" "gpt3.5-old")

# Loop through data array
for curr_data in "${data[@]}"; do
    # Without '-cmin'
    for j in {1,5,6,7,8}; do
        output="output-2-"$curr_data"-"$j
        mkdir $output
        outputEx="./"$output
        echo "docker run -dt $container exp 2 $curr_data $j 27 $i $outputEx"
        docker run -dt $container exp 2 $curr_data $j 27 $i $outputEx
    done

    # With '-cmin'
    for j in {1,5,6,7,8}; do
        model=$curr_data"-cmin"
        output="output-2-"$model"-"$j
        mkdir $output
        outputEx="./"$output
        echo "docker run -dt $container exp 2 $model $j 27 $i $outputEx"
        docker run -dt $container exp 2 $model $j 27 $i $outputEx
    done
done
