# ./compile_n_run_1_mutation.sh /home/ubuntu/experiment-2/inputs/t.txt /home/ubuntu/experiment-2/binary/t.c.o.o /home/ubuntu/experiment-2/binary/t.c.o.o.types /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt 

txt=$1
binary=$2
types=$3
gem5=$4

echo " "
echo "============================================================================================"
echo ">> Running test $txt with binary $binary and types $types"
cat -n $txt
cat -n $types

echo "Checking test: "
./check_folders_integrity.sh $1 $2 $3

current_folder=`pwd`
cd ../..
gem5_script=`pwd`"/hello-custom-binary-Ex.py"
echo ">> Using gem5 script: $gem5_script"
cd $current_folder

echo ">> Try to run it with gem5 before mutation. Path: <$gem5>"
$gem5 $gem5_script --isa X86 --input $txt
echo ">> END =================================================="

echo ">> Compiling the custom mutator in folder <$current_folder>"
gcc -w -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o main_cm-gem5.o -D DEBUG_CM -D TEST_CM

echo ">> running 1 step of the mutation"
txt_contents=$(<"$txt")
./main_cm-gem5.o "$txt_contents"