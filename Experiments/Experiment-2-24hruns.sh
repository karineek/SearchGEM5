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

# Assuming run_me.sh is in the current directory
script="./run_AFL_loop_v" #run_AFL_loop_v1.sh

afl=/home/ubuntu/AFLplusplus/afl-fuzz
ASE=$1
main=$2 	# Which LLM data now?
settings_no=$3 	# The winner of Experiment 1: 1-30 value.
script_k=$4  	# 8,1,5,6,7, and if time allows 2,3,4.
repeat_i=$5 	# Which repeat i=1-30, but we do now 1-10
outputALL=$6    # Output shared out

# Total 1920 hours - per LLM set
# j - configuration
# k - is the script version 1-8
# i - repetition
# main - LLM set

input=$main/input	# AFL input
output=$main/output	# AFL output
j=$settings_no 		# j (We use only the winning settings)
k=$script_k		# k
i=$repeat_i		# i

# Run a configuration script in a loop 30 times
#for ((k = 1; k <= 8; k++)); do
    script_cong_k=$script$k.sh # 1-8 options
    cm_folders_j=$ASE/CM_EXP_$j
    echo "Using settings: $cm_folders_j"

    # Run the script in a loop 30 times
    #for ((i = 1; i <= 10; i++)); do
        # Redirect the output to repeat_$i.txt and kill after 60 minutes
        $script_cong_k $cm_folders_j $afl $input $output"_"$k"_setting_"$j"_repeat_"$i 0 > "repeat_script_"$k"_setting_"$j"_repeat_"$i".txt" &

        # Capture the process ID of the background process
        script_pid=$!

        # Sleep for 24 hours
        sleep 86400

        # Kill the script after 60 minutes
        kill_script $script_pid
    #done
#done

# Copying All data
cp -r $main $outputALL
cp repeat_script_* $outputALL/
