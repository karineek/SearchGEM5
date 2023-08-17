#!/bin/bash

# Define the paths to the folders
txt_file=$1
so_file=$2
types_file=$3

# Get the base name of the .so file without the extension
#base_name=$(basename "$so_file" .c.o.o)
#base_name_without_folder="${base_name##*/}"

# Construct the corresponding .txt file path
#txt_file="$txt_folder/$base_name_without_folder.txt"

# Check if the .txt file exists
if [ -e "$txt_file" ]; then
######### Fine TEXT file ##################
        txt_contents=$(<"$txt_file")
        eval "( ulimit -St 50 -Sf 4000 ; "$txt_contents") > output1.txt 2>&1"
        res=`echo $?`
        if [[ $res -gt 0 ]] ; then
	    echo ">> DIAGNOSIS - FAILED: ($res) $so_file $txt_file"
        else
            txt_content_short=$(echo "$txt_contents" | cut -d ' ' -f 1)
	    eval "( ulimit -St 50 -Sf 4000 ; "$txt_contents_short") > output2.txt 2>&1"
	    res=`echo $?`
            if [[ $res -eq 0 ]] ; then
		diff "output1.txt" "output2.txt" > deletemeres.txt
		# Check the exit code of the diff command
		if [ $? -eq 0 ]; then
		    echo ">> DIAGNOSIS - FAILED-SAME: ($res) $so_file $txt_file"
		fi
	   fi
        fi
################### CHECK types
       types2=$so_file".types"
       if [ -e "$types_file" ]; then
           if [ -e "$types2" ]; then
                echo ">> Type file found. Use <$types2>."
           else
		echo ">> DIAGNOSIS - TYPE FILE has invalid name <$types_file> but should be <$types2>."
           fi
       else
	   echo ">> DIAGNOSIS - TYPE FILE is missing <$types_file>."
       fi
else
    echo ">> DIAGNOSIS: Missing $txt_file file for $so_file"
fi
# DONE.
