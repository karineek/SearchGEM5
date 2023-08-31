#!/bin/bash
################################################
## This scripts get a folder of test-cases and
## compute their coverage using GCOV and GFAUTO
################################################
base=$1			# /home/user42
testcaseDir=$2		# where is basic.c
process_number=$3	# 5
itr=$4			# 0
gfauto=$5		# gfauto location, e.g., /home/user42/git/graphicsfuzz/gfauto
compiler=$6		# gcc or llvm?
old_version=$7		# 1 - yes, 0 - no
# $base $testcaseDir $process_number $itr $gfauto $compiler $gfauto_old_version

## Required parameters
working_folder=$base

## Init
if [[ $itr -eq 0 ]]; then
	rm -rf $working_folder/coverage_processed
	rm -rf $working_folder/coverage_gcda_files/application_run
fi

## Start evaluation
time1=$(date +"%T")
echo "EVOLUTION OF LLVM COVERAGE WHEN COMPILING PROGRAM in folder: "$testcaseDir" ("$time1")"

# Loop over compilation and coverage measurement
current_folder=`pwd`

## Read which compiler to test:
SUTexec=$working_folder"/gem5-ssbse-challenge-2023/build/X86/gem5.opt"
gem5_script="/home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py"

# Set location to record the data
mkdir -p $working_folder/coverage_gcda_files/application_run

time2=$(date +"%T")
echo "--> SIMULATING WITH "$testcaseDir" ITERATION "$itr" with compiler info. "$compilerInfo" ("$time2")"

# Run compiler and save coverage data
export GCOV_PREFIX=$working_folder/coverage_gcda_files/application_run
for testcaseFile in $testcaseDir/*.txt ; do
	echo "Coveraeg for: $testcaseFile"
	(ulimit -St 500; $SUTexec $gem5_script --isa X86 --input $testcaseFile) > basic_output.txt 2>&1
done
for testcaseFileA in $testcaseDir/id* ; do
        echo "Coveraeg for: $testcaseFileA: (ulimit -St 500; $SUTexec $gem5_script --isa X86 --input $testcaseFileA)"
        (ulimit -St 500; $SUTexec $gem5_script --isa X86 --input $testcaseFileA) > basic_output.txt 2>&1
done
unset GCOV_PREFIX

## Measure Coverage
time3=$(date +"%T")
echo "--> MEASURING COVERAGE... ("$time3")"
mkdir -p $working_folder/coverage_processed/x-$itr
mkdir -p $working_folder/coverage_processed/x-line-$itr
(
	source $gfauto/.venv/bin/activate
        build_folder=$working_folder/gem5-ssbse-challenge-2023/build/X86/
        source_folder=$working_folder/gem5-ssbse-challenge-2023/src/

	## Function coverage
	cd $working_folder/coverage_processed/x-$itr
	if [ "$old_version" == "1" ]; then
		gfauto_cov_from_gcov --out run_gcov2cov.cov $build_folder $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
	else
		echo "gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1"
		gfauto_cov_from_gcov --out run_gcov2cov.cov $build_folder --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json --gcov_functions >> gfauto.log 2>&1
	fi
        gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $build_folder >> gfauto.log 2>&1

        ## Line coverage
        cd $working_folder/coverage_processed/x-line-$itr
        if [ "$old_version" == "1" ]; then
        	gfauto_cov_from_gcov --out run_gcov2cov.cov $build_folder $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
        else
		echo "gfauto_cov_from_gcov --out run_gcov2cov.cov $working_folder/$compiler-build/ --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1"
        	gfauto_cov_from_gcov --out run_gcov2cov.cov $build_folder --gcov_prefix_dir $working_folder/coverage_gcda_files/application_run/ --num_threads 32 --gcov_uses_json >> gfauto.log 2>&1
        fi
        gfauto_cov_to_source --coverage_out cov.out --cov run_gcov2cov.cov $build_folder >> gfauto.log 2>&1
        ls -l
)
cd $current_folder

time2=$(date +"%T")
echo "DONE. RESULTS (FUNCTION) AVAILABLE IN $working_folder/coverage_processed/x-$itr for testcase <$testcaseFile> ($time2)"
echo "DONE. RESULTS (LINE) AVAILABLE IN $working_folder/coverage_processed/x-line-$itr for testcase <$testcaseFile> ($time2)"
rm a.out "basic_output.txt" ## clean at the end
