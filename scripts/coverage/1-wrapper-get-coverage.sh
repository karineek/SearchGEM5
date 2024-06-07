#!/bin/bash
base=$1				# /home/user42
testcaseDir=$2			# where is basic.c
itr=$3				# 1
gfauto=$4			# gfauto location, e.g., /home/user42/git/graphicsfuzz/gfauto
output_table_file_func=$5	# Where to dump the results (table of the results per file int the working_folder
output_table_file_line=$6	# Where to dump the results (table of the results per file int the working_folder
output_report=$7		# Where to print the summary report to
compiler=gcc-11                 # llvm or gcc?
gfauto_old_version=0  		# Is old or new version of gfauto
working_folder=$base            # the llvm or gcc installation we will measure coverage for
## E.g., ./1-wrapper-get-coverage.sh
## Print inputs:
echo "base:=$base"
echo "testcaseDir:=$testcaseDir"
echo "itr:=$itr"
echo "gfauto:=$gfauto"
echo "output_table_file_func:=$output_table_file_func"
echo "output_table_file_line:=$output_table_file_line"
echo "output_report:=$output_report"
echo "compiler:=$compiler"
echo "gfauto_old_version:=$gfauto_old_version"
echo "working_folder:=$working_folder"

## Cleaning:
rm -f $output_table_file_func $output_table_file_line $output_report

## Compute the coverage from gcov files
echo "Compute coverage"
./3-compute-coverage_DIR_gfauto.sh $base $testcaseDir $itr $gfauto $compiler $gfauto_old_version

## Add total of files in cov reports
files_no=`ls -l $testcaseDir | wc -l`
echo ">> Total of files in coverage report: $files_no" >> $output_report

## Report for function coverage
echo "Get statistics for functions"
cov_func=$working_folder/coverage_processed/x-$itr/cov.out/
./4-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_func" $output_table_file_func >> $output_report

## Report for line coverage
echo "Get statistics for lines"
cov_line=$working_folder/coverage_processed/x-line-$itr/cov.out/
./4-gen-statistic-gcov-diff-tab_gfauto.sh "$cov_line" $output_table_file_line >> $output_report

cp $output_table_file_func $output_table_file_line $output_report $working_folder/coverage_processed/
