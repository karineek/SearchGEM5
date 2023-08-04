#!/bin/bash

for file in *.c; do
    [ -f "$file" ] || continue  # Skip if it's not a file
    filename=$(basename "$file")
    echo "// source: $file" > $file.x
    cat $file >> $file.x
done
