#!/bin/bash

# Define the paths to the folders
txt_file=$1
so_file=$2
types_file=$3

# Check if the .txt file exists
if [ -e "$txt_file" ]; then
######### Fine TEXT file ##################
        txt_contents=$(<"$txt_file")
        eval "( ulimit -St 50 -Sf 4000 ; "$txt_contents") > output1.txt 2>&1"
        res=`echo $?`
        if [[ $res -gt 0 ]] ; then
	    echo ">> DIAGNOSIS - FAILED: ($res) $so_file $txt_file"
         else
	    eval "( ulimit -St 50 -Sf 4000 ; "$so_file") > output2.txt 2>&1"
	    res=`echo $?`
	    if [[ $res -eq 0 ]] ; then
		diff "output1.txt" "output2.txt" > deletemeres.txt
		# Check the exit code of the diff command
		count=`cat deletemeres.txt | wc -l`
		if [ $count -gt 0 ]; then
		    echo ">> Binay file: OK"
		else
		    echo ">> DIAGNOSIS - FAILED-SAME: ($res,$count) $so_file $txt_file"
		fi
	   else
		echo ">> Binay file: OK"
	   fi
        fi
################### CHECK types
       types2=$so_file".types"
       if [ -e "$types_file" ]; then
           if [ -e "$types2" ]; then
                echo ">> Type file: OK"
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
