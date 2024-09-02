#!/bin/bash

# Check if a folder name was provided
if [ -z "$1" ]; then
  echo "Usage: $0 <folder_name>"
  exit 1
fi
FOLDER_NAME=$1

# Loop over the different versions
for version in 1 5 6 7 8; do
  # Remove the existing folder and copy the new version
  cd ../../../experiment/
  rm -rf $FOLDER_NAME
  cp -r ${FOLDER_NAME}_orig/output-2-${FOLDER_NAME}-${version}/$FOLDER_NAME .

  # Navigate to the script directory and run the test
  cd ../ASEGem5/scripts/bugs/
  ./1-run-diff-test.sh /home/ubuntu/experiment/$FOLDER_NAME/input_fuzzed/ > ${FOLDER_NAME}_10_${version}.log 2>&1
  # Append the log file name to the report
  echo "=== ${FOLDER_NAME}_10_${version}.log" >> report-diff.log
done
