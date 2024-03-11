# Assuming run_me.sh is in the current directory
script="./run_AFL_loop_v" #run_AFL_loop_v1.sh

afl=/home/ubuntu/AFLplusplus/afl-fuzz
input=/home/ubuntu/TinyLlama-test/input
output=/home/ubuntu/TinyLlama-test/output

# Run a configureation script in a loop 30 times
for ((k = 1; k <= 30; k++)); do
    script_cong_k=$script$k.sh
    cm_folders=CM_EXP_$k
    # Run the script in a loop 30 times
    for ((i = 1; i <= 30; i++)); do
        # Redirect the output to repeat_$i.txt and kill after 60 minutes
        timeout 1s $script_cong_k $cm_folders $afl $input $output$k 0 > "repeat_$i.txt"
    done
done

echo "Script execution completed."
