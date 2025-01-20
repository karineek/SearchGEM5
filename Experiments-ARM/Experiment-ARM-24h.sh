#!/bin/bash
# Function to kill script and its child processes
kill_script() {
    local parent_pid=$1

    # Get all child processes of the parent PID
    child_pids=$(pgrep -P $parent_pid)

    # Kill the parent and all its children
    pkill -TERM -P $parent_pid

    # Wait for processes to be killed
    sleep 5

    # Forcefully kill any remaining processes
    pkill -KILL -P $parent_pid
}

model=$1
round=$2
ver=$3


#cm_path=$1   # E.G. "/home/ubuntu/ASEGem5/src/custom_mutators/"
#afl=$2       # E.G. /home/ubuntu/AFLplusplus/afl-fuzz
#input=$3     # E.G. /home/ubuntu/TinyLlama-test/input
#output=$4    # E.G. /home/ubuntu/TinyLlama-test/output
#resume=$5    # 0 - new run, 1 - resume
#execgem5=$6  # /home/kevenmen/gem5-ssbse-challenge-2023/build/ARM/gem5.opt

./run_AFL_loop_v6.sh /home/kevenmen/SearchGEM5/src/custom_mutators/ /home/kevenmen/AFLplusplus/afl-fuzz /home/kevenmen/experiment-7/$model-cmin/input/ \
	/home/kevenmen/experiment-7/$model-cmin/output-r_$round 0 /home/kevenmen/ver$ver/gem5-ssbse-challenge-2023/build/ARM/gem5.opt > afl-$round-$model.txt 2>&1 &

# Capture the process ID of the background process
script_pid=$!

# Sleep for 24 hours
sleep 86400

# Kill the script after 60 minutes
kill_script $script_pid
