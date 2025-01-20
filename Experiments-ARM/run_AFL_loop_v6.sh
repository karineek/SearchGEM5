# Three custom mutators (SSBSE’s one, Types and Bin) with custom counters function.

# USE FULL PATHS
cm_path=$1   # E.G. "/home/ubuntu/ASEGem5/src/custom_mutators/"
afl=$2       # E.G. /home/ubuntu/AFLplusplus/afl-fuzz
input=$3     # E.G. /home/ubuntu/TinyLlama-test/input
output=$4    # E.G. /home/ubuntu/TinyLlama-test/output
resume=$5    # 0 - new run, 1 - resume
execgem5=$6  # /home/kevenmen/gem5-ssbse-challenge-2023/build/ARM/gem5.opt

date
# Check if an argument is provided
if [ $# -le 4 ]; then
    echo "Please provide custom mutator path, afl path, input and output folders, and a value (0 or 1) as a command-line argument."
    exit 1
fi

if [ "$resume" -eq 1 ]; then
    # Resume fuzzing
    AFL_NO_AFFINITY=1 AFL_SHUFFLE_QUEUE=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_FAST_CAL=1 AFL_IGNORE_PROBLEMS=1 AFL_AUTORESUME=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \
AFL_SKIP_BIN_CHECK=1 AFL_MAP_SIZE=1200000 AFL_CUSTOM_MUTATOR_LIBRARY="$cm_path/cm-gem5c.so;$cm_path/cm-gem5c-bin.so;$cm_path/cm-gem5c-types.so" \
$afl -m 50000 -t 99000 -i $input -o $output -- $execgem5 \
/home/kevenmen/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input @@
else
    # Starts a new fuzzing
    AFL_NO_AFFINITY=1 AFL_SHUFFLE_QUEUE=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_FAST_CAL=1 AFL_IGNORE_PROBLEMS=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \
AFL_SKIP_BIN_CHECK=1 AFL_MAP_SIZE=1200000 AFL_CUSTOM_MUTATOR_LIBRARY="$cm_path/cm-gem5c.so;$cm_path/cm-gem5c-bin.so;$cm_path/cm-gem5c-types.so" \
$afl -m 50000 -t 99000 -i $input -o $output -- $execgem5 \
/home/kevenmen/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input @@
fi
echo "==End Fuzzing round, script 6=="
date
echo "cm_path=$1; afl=$2; input=$3; output=$4; resume=$5;"
