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
main=/home/ubuntu/TinyLlama-test/
input=/home/ubuntu/TinyLlama-test/input
output=/home/ubuntu/TinyLlama-test/output


# Total 7200 hours

# Run a configureation script in a loop 30 times
for ((k = 1; k <= 8; k++)); do
    script_cong_k=$script$k.sh # 1-8 options

    # For each settings out of the 30.
    for ((j = 1; j <= 30; j++)); do
        cm_folders_j=CM_EXP_$j

        # Run the script in a loop 30 times
        for ((i = 1; i <= 30; i++)); do
            # Redirect the output to repeat_$i.txt and kill after 60 minutes
            $script_cong_k $cm_folders_j $afl $input $output"_"$k"_setting_"$j"_repeat_"$i 0 > "repeat_script_"$k"_setting_"$j"_repeat_"$i".txt" &

	    # Capture the process ID of the background process
    	    script_pid=$!

    	    # Sleep for 60 minutes
    	    sleep 1 #600

    	    # Kill the script after 60 minutes
     	    kill_script $script_pid
        done
    done
done

echo "Script execution completed."
