#!/bin/bash

# Function to recursively iterate over all folders
# Arguments:
#   $1: The path to the current folder
#   $2: The current depth
traverse_folders() {
    local current_folder="$1"
    local depth="$2"

    # Terminate recursion if depth exceeds 3
    if [ "$depth" -gt 3 ]; then
        cd $current_folder
        execLocation=`pwd`
        mkdir input_fuzzed
        cp input/*.txt input_fuzzed/
        sleep 120
        cp binary/*.txt input_fuzzed/
        cp output_*/default/queue/id* input_fuzzed/
        cp output_*/default/crashes/id* input_fuzzed/
        cp output_*/default/hangs/id* input_fuzzed/
        cd input_fuzzed/
        b=`find . -type f | wc -l`
        fdupes -dN . > command_output.txt 2>&1
        a=`find . -type f | wc -l`
        rm test_input_*
        f=`find . -type f | wc -l`
        cd ../..
        statsAFL=`grep "Test case count :" repeat_script*.txt | cut -d':' -f2`
        echo "Exec path | $execLocation | $b | $a | $f |$statsAFL"
        cd $currLocation
        return
    fi

    # Iterate over all folders in the current directory
    for folder in "$current_folder"/*/; do
        # Check if the item is a directory
        if [ -d "$folder" ]; then
            # Recursively call the function for each subfolder
            traverse_folders "$folder" "$((depth + 1))"
        fi
    done
}

# Get the location from the command line argument
location="$1"
currLocation=`pwd`
