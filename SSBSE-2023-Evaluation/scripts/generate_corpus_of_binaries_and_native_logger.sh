folder=$1      # Input folder with C files
folder_bin=$2  # Output folder to create corpus of binaries
compiler=$3    # Compiler
options=$4     # Compilation flags
logger=$5      # Logger for differential testing

touch $logger
mkdir $folder_bin

# Build and produe reference log
for file in $folder/*.c; do
    if [[ -f "$file" ]]; then
        filename=$(basename "$file")
        $compiler $options -w $file -o $folder_bin/$filename.o
        echo ">> $filename.o" >> $logger
        ./$folder_bin/$filename.o >> $logger 2>&1
        echo $? >> $logger
    fi
done
echo ">> DONE."

