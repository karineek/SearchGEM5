#!/bin/bash
base=$1

# Loop over all subfolders at the specified depth
cd $base
current=`pwd`
for folder in $base/*/*/*/*/*/input_*; do
    # List files with detailed information
    cd "$folder"
    rate=`ls -l id* | wc -l`
    location=`pwd`
    echo "$location | $rate"
    cd $current
done
