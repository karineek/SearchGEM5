intput=$1
output=$2
mutators=$3
script=$4
gem5_opt=$5
afl=$6
# nohup ./run-afl.sh gpt3.5-old/input/ output/ "/home/ubuntu/SearchGEM5/src/custom_mutators/cm-gem5.so" 
#   /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
#   /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/AFLplusplus/afl-fuzz >> afl.logger.txt 2>&1 &
#
# nohup ./run-afl.sh gpt3.5-old/input/ output/ 
#   "/home/ubuntu/SearchGEM5/src/custom_mutators/cm-gem5.so;/home/ubuntu/Gem5Testing/src/custom_mutators/cm-gem5-bin.so;/home/ubuntu/Gem5Testing/src/custom_mutators/cm-gem5-types.so"
#   /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
#   /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/AFLplusplus/afl-fuzz >> afl.logger.txt 2>&1 &

echo ">> Start fuzzing"
date
AFL_DUMB_FORKSRV=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY=$mutators $afl -m 50000 -t 99000 -i $intput -o $output -- $gem5_opt $script --isa X86 --input @@
date
echo ">> END fuzzing"
