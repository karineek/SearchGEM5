#!/bin/bash
#The script eithers perform the filtering or the running process.

if [ "$1" = "filter" ]; then 
#Run the filtering process
/home/debian/ASEGem5/scripts/filterTests.sh /home/debian/experiment/input/ /home/debian/experiment/output/  /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py

elif [ "$1" = "min" ]; then
AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_MAP_SIZE=1200000 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY='/home/debian/ASEGem5/src/custom_mutators/cm-gem5.so' timeout 24h /home/debian/AFLplusplus/afl-cmin  -m 50000 -t 99000 -i /home/debian/input/input -o /home/debian/output /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py  --isa X86 --input @@
    
else
    ## Run AFL
    bash
#AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_MAP_SIZE=1200000 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY='/home/debian/ASEGem5/src/custom_mutators/cm-gem5.so' timeout 24h /home/debian/AFLplusplus/afl-fuzz  -m 50000 -t 99000 -i /home/debian/experiment/output/input/ -o /home/debian/experiment/outputFuzzing_$1 /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py  --isa X86 --input @@
fi
