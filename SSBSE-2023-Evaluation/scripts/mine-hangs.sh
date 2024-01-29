inputF=$1 # crash or hand folder
outputF=$2 # Experiment results folder

# Check if the input directory exists
if [ ! -d "$inputF" ]; then
    echo "Input directory '$inputF' does not exist."
    exit 1
fi

gem5="/home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt"
gem5_script="/home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py"
index=0

# Iterate over all .txt files in the input directory
echo "Start ...."
for txt_file in "$inputF"/id*; do
    if [ -f "$txt_file" ]; then
        # Process each .txt file here
        echo "Processing file: $txt_file"
        # You can add your custom logic here to process the file
        (ulimit -St 5000 -Sf 4000 -Sm 1048576 ; $gem5 $gem5_script --isa X86 --input $txt_file) > gem5.log 2>&1

        binFile=`head -n 1 $txt_file`
        args=`head -n 2 $txt_file | tail -1`
        (ulimit -St 500; $binFile $args) > plain.log 2>&1
        tail -1 gem5.log > tail_gem5.log
        diff plain.log tail_gem5.log > diff.log 2>&1

 	mkdir $outputF"/HANG-"$index
        mv gem5.log $outputF"/HANG-"$index
        cp $txt_file $outputF"/HANG-"$index
        cp $binFile $outputF"/HANG-"$index
        mv plain.log $outputF"/HANG-"$index
        mv diff.log $outputF"/HANG-"$index
        ((index++))
    fi
done
echo "End..."
