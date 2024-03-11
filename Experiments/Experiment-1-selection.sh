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

# Run a single experiment
run_experiment_k() {
    k=$1 # Which version to run

    script_cong_k=$script$k.sh # 1,5 options

    # For each setting out of the 30.
    for ((j = 1; j <= 30; j++)); do
        cm_folders_j=CM_EXP_$j

        # Run the script in a loop 30 times
        for ((i = 1; i <= 30; i++)); do

            # Redirect the output to repeat_$i.txt and kill after 60 minutes
	    output_folder=$output"_"$k"_setting_"$j"_repeat_"$i
            logger="repeat_script_"$k"_setting_"$j"_repeat_"$i".txt"
            $script_cong_k $cm_folders_j $afl $input $output_folder 0 > $logger &

	    # Capture the process ID of the background process
    	    script_pid=$!

    	    # Sleep for 60 minutes
    	    sleep 2 # 3600

    	    # Kill the script after 60 minutes
     	    kill_script $script_pid
        done
    done
}

# Assuming run_me.sh is in the current directory
script="./run_AFL_loop_v" #run_AFL_loop_v1.sh

afl=/home/ubuntu/AFLplusplus/afl-fuzz
main=/home/ubuntu/TinyLlama-test/
input=/home/ubuntu/TinyLlama-test/input
output=/home/ubuntu/TinyLlama-test/output


# Total 7200 hours

# Run a configuration script in a loop 30 times
run_experiment_k(2) # No need to save but requires counters
run_experiment_k(6) # No need to save but requires counters

echo "Script execution completed."
