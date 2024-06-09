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
        # cp binary/*.txt input_fuzzed/
        for file in binary/*.txt; do
    	    cp "$file" input_fuzzed/
	done
        cp output_*/default/queue/id* input_fuzzed/
        cp output_*/default/crashes/id* input_fuzzed/
        cp output_*/default/hangs/id* input_fuzzed/
        cd input_fuzzed/
	b=`find . -type f | wc -l`
	fdupes -dN . > ../command_output.txt 2>&1
	a=`find . -type f | wc -l`
	rm test_input_*
	f=`find . -type f | wc -l`
	cd ../..
        statsAFL=`grep "Test case count :" repeat_script*.txt | cut -d':' -f2 | sed 's/\x1B\[[0-9;]*m//g'`
	statsAFLready=`echo $statsAFL | sed 's:favored,:|:g' | sed 's:variable,:|:g' | sed 's:ignored,:|:g' | sed 's:total:|:g'`
	echo "Exec path | $execLocation | $b | $a | $f |$statsAFLready"
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

# Check if the location argument is provided
if [ -z "$location" ]; then
    echo "Usage: $0 <location>"
    exit 1
fi

# Check if the provided location is a directory
if [ ! -d "$location" ]; then
    echo "Error: '$location' is not a directory"
    exit 1
fi

# Start traversing from the provided location with depth 1
traverse_folders "$location" 1
