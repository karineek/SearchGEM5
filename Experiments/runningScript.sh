#!/bin/bash
#The script eithers perform the filtering or the running process.

if [ "$1" -eq 0 ]; then
	#Run the filtering process
	/home/debian/ASEGem5/scripts/filterTests.sh /home/debian/experiment/input/ /home/debian/experiment/output/  /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py

else
	# k - script 1-8
	# j - configuration of counters 1-30 (Experiment 1 does selection, Experiment 2 uses only the winner
	# i - repeatition number
	# model - name of the folder of the data (e.g. Phi or TinyLlama)
	model=$2
	k=$3
	j=$4
	if [ "$1" -eq 1 ]; then
		./Experiment-1-selection.sh /home/debian/experiment/$model $k $j
	else
		i=$5
		./Experiment-2-24hruns.sh /home/debian/experiment/$model $j $k $i
	fi
## Run AFL
#AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_MAP_SIZE=1200000 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY='/home/debian/ASEGem5/src/custom_mutators/cm-gem5.so' timeout 24h /home/debian/AFLplusplus/afl-fuzz  -m 50000 -t 99000 -i /home/debian/experiment/output/input/ -o /home/debian/experiment/outputFuzzing_$1 /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt 
# /home/debian/ASEGem5/hello-custom-binary-Ex.py  --isa X86 --input @@

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
