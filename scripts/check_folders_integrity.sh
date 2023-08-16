#!/bin/bash

# Define the paths to the folders
so_folder=$1
txt_folder=$2

# Loop through each .so file in the binaries folder
for so_file in "$so_folder"/*.c.o.o; do
    # Get the base name of the .so file without the extension
    base_name=$(basename "$so_file" .c.o.o)
    base_name_without_folder="${base_name##*/}"

    # Construct the corresponding .txt file path
    txt_file="$txt_folder/$base_name_without_folder.txt"

    # Check if the .txt file exists
    if [ -e "$txt_file" ]; then
        # ALL good
        txt_contents=$(<"$txt_file")
        eval "( ulimit -St 50 -Sf 4000 ; "$txt_contents") > output1.txt 2>&1"
        res=`echo $?`
        if [[ $res -gt 0 ]] ; then
	    echo ">> FAILED: ($res) $so_file $txt_file"
            rm $so_file
	    rm $txt_file
        else
            txt_content_short=$(echo "$txt_contents" | cut -d ' ' -f 1)
	    eval "( ulimit -St 50 -Sf 4000 ; "$txt_contents_short") > output2.txt 2>&1"
	    res=`echo $?`
            if [[ $res -eq 0 ]] ; then
		diff "output1.txt" "output2.txt"
		# Check the exit code of the diff command
		if [ $? -eq 0 ]; then
		    echo ">> FAILED-SAME: ($res) $so_file $txt_file"
		    rm $so_file
		    rm $txt_file
		fi
            fi
        fi
    else
        echo "Missing $txt_file file for $so_file"
	rm $so_file
    fi
done





