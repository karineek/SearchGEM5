#!/bin/bash

# Loop through each settings file
iteration=0
for settings_file in ../../Experiments/settings/settings-*.txt; do
    # Increment the iteration counter
    ((iteration++))

    echo "Processing file: $settings_file"

    # Read the values from the file
    read arg1 arg2 arg3 < "$settings_file"

    # Call the ./single_rub.sh script with the arguments
    ./compile_share_test.sh "$arg1" "$arg2" "$arg3"

    # Move all to current iteration setup
    folder="../../Experiments/CM_EXP_$iteration"
    mkdir $folder
    cp $settings_file $folder
    mv *.o $folder
    mv *.so $folder

    echo "Done processing file: $settings_file"
done
