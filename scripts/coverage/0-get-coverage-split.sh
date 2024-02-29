#!/bin/bash
base=$1                         # /home/user42
testcaseDir=$2                  # where is basic.c
process_number=$3               # 5
itr=$4                          # 0
gfauto=$5                       # gfauto location, e.g., /home/user42/git/graphicsfuzz/gfauto
output_table_file_func=$6       # Where to dump the results (table of the results per file int the working_folder
output_table_file_line=$7       # Where to dump the results (table of the results per file int the working_folder
output_report=$8                # Where to print the summary report to
compiler=gcc-11                 # llvm or gcc?
gfauto_old_version=0            # Is old or new version of gfauto
working_folder=$base            # the llvm or gcc installation we will measure coverage for
# ./0-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv

## Print inputs:
echo "base:=$base"
echo "testcaseDir:=$testcaseDir"
echo "process_number:=$process_number"
echo "itr:=$itr"
echo "gfauto:=$gfauto"
echo "output_table_file_func:=$output_table_file_func"
echo "output_table_file_line:=$output_table_file_line"
echo "output_report:=$output_report"
echo "compiler:=$compiler"
echo "gfauto_old_version:=$gfauto_old_version"
echo "working_folder:=$working_folder"

# Execute the first script
./1-wrapper-get-coverage-cont.sh $1 $2/folder1 $3 $4 $5 $6 $7 $8

# Loop to execute the second script nine times
for ((i=2; i<=10; i++)); do
    ./1-wrapper-get-coverage-cont.sh $1 $2/folder$i $3 $4 $5 $6 $7 $8
done
