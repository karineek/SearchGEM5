#!/bin/bash
#./1-wrapper-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv
op=$1	 # Which option?
model=$2 # Phi, CodeBooga, Llama, Magicoder, TinyLlama, gpt3.5-new, and gpt3.5-old and with -min extention.
copy=$3  # 1 to 10, for the repeat. 0 if llm or sliced.

# Fix parameters:
home=/home/debian
gfauto=$home/graphicsfuzz/gfauto/
data=$home/experiment/$model/
mnt=/mnt/shared/

# docker run -it -v /home/ubuntu/phi-cmin/part-1/output-2-Phi-cmin-1/10/Phi-cmin/:/mnt/shared eab7d0167a93
rm -rf $home/coverage_gcda_files $home/coverage_processed
if [ "$op" = "init" ]; then
	exp=$data/input/
        mkdir -p $data
        cp -r $mnt/input $data
        cp -r $mnt/binary $data
	./1-wrapper-get-coverage.sh $home $exp 0 5 $gfauto func-gem5-llm-$model.csv lines-gem5-llm-$model.csv report-gem5-llm-$model.csv > report-gem5-llm-$model.log
        tar -czvf $model-gcov-0.tar.gz $home/coverage_gcda_files $home/coverage_processed *.csv *.log > llm_coverage_output_tar.txt 2>&1
        cp  $model-gcov-0.tar.gz $mnt
        cp  *.csv $mnt
elif [ "$1" = "cont" ]; then
	exp=$data/input_fuzzed
        mkdir -p $data
        cp -r $mnt/input_fuzzed/ $data
        cp -r $mnt/binary $data
        cp $mnt/$model-gcov-0.tar.gz $home
        current=`pwd`
        cd $home
        tar -xf $model-gcov-0.tar.gz
        cd $current
	./1-wrapper-get-coverage-cont.sh $home $exp 1 5 $gfauto func-gem5-afl-$copy-$model.csv lines-gem5-afl-$copy-$model.csv report-gem5-afl-$copy-$model.csv > report-gem5-afl-$copy-$model.log
        tar -czvf $model-gcov-afl-$copy.tar.gz $home/coverage_gcda_files $home/coverage_processed *.csv *.log > afl_coverage_output_tar.txt 2>&1
        cp  $model-gcov-afl-$copy.tar.gz $mnt
        cp  *.csv $mnt
elif [ "$op" = "sliced" ]; then
	exp=$home/experiment/$model/split/
	# TODO
	./0-get-coverage.sh /home/ubuntu/gem5-cov/ /home/ubuntu/gem5-cov/data/gem5-afl-fuzz-cov/data/sliced/seg_5/ 0 5 /home/ubuntu/graphicsfuzz/gfauto/ func-gem5-afl-5.csv lines-gem5-afl-5.csv report-gem5-afl-5.csv
else
	bash
fi

# Full models list
# ================
# - CodeBooga
# - Llama
# - Magicoder
# - Phi
# - TinyLlama
# - gpt3.5-new
# - gpt3.5-old
# - CodeBooga-cmin
# - Llama-cmin
# - Magicoder-cmin
# - Phi-cmin
# - TinyLlama-cmin
# - gpt3.5-new-cmin
# - gpt3.5-old-cmin

# - run Init run: docker run -dt -v /home/ubuntu/phi-cmin/part-1/output-2-Phi-cmin-1/10/Phi-cmin/:/mnt/shared dockerfile init Phi-cmin 10
