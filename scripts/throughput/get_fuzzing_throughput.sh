#!/bin/bash

# Loop over all subfolders at the specified depth
current=`pwd`
for folder in */*/*/*/*/input_*; do
    # List files with detailed information
    cd "$folder"
    rate=`ls -l id* | wc -l`
    fuzzproxy=`ls -l fuzz* | wc -l`
    location=`pwd`
    echo "$folder,$rate,$fuzzproxy" | sed 's:/:,:g'
    cd $current
done
