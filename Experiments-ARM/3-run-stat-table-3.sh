#!/bin/bash
experimentsFolder=$1

cd $experimentsFolder

# List of directories to process
directories=(
  "CodeBooga-cmin"
  "gpt3.5-new-cmin"
  "gpt3.5-old-cmin"
  "Llama-cmin"
  "Magicoder-cmin"
  "Phi-cmin"
  "TinyLlama-cmin"
)

subfolders=(
  "output-r_1/default/crashes"
  "output-r_1/default/hangs"
  "output-r_1/default/queue"
  "output-r_2/default/crashes"
  "output-r_2/default/hangs"
  "output-r_2/default/queue"
  "output-r_3/default/crashes"
  "output-r_3/default/hangs"
  "output-r_3/default/queue"
  "output-r_4/default/crashes"
  "output-r_4/default/hangs"
  "output-r_4/default/queue"
  "output-r_5/default/crashes"
  "output-r_5/default/hangs"
  "output-r_5/default/queue"
)

# Iterate over each directory and calculate the adjusted file count
for dir in "${directories[@]}"; do
  if [ -d "$dir/input" ]; then
    count=$(( $(ls -l "$dir/input/" | wc -l) - 1 ))
    echo "Initial Corpus Size: $count (Directory: $dir/input)"

    for sub in "${subfolders[@]}"; do
        count=`ls -l $dir/$sub* | grep -a "id:" | wc -l`
        #echo "ls -l $dir/$sub* | grep -a \"id:\" | wc -l"
        echo "Initial Corpus Size: $count (Directory: $dir/$sub)"
    done
    echo "---------------------------------"
  else
    echo "Directory: $dir/input does not exist."
    echo "---------------------------------"
  fi
done
