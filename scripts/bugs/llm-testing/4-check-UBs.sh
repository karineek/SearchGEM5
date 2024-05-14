c_file=$1 # Full path
arguments=$2

clang-12 $c_file -fsanitize=undefined -O1 -g -o test-1
clang-12 $c_file -fsanitize=address -g -o test-2
clang-12 $c_file -fsanitize=undefined -O1 -g -o test-3

echo "$c_file.o" > $c_file.txt
echo "$arguments" >> $c_file.txt
cat $c_file.txt

gcc -O3 $c_file -o $c_file.o

echo "Sanitizers==========================="
./test-1 $arguments
echo $?
./test-2 $arguments
echo $?
./test-3 $arguments
echo $?

echo "Native=============================="
./$c_file.o $arguments
echo $?

echo "Simulation=========================="
./gem5/build/X86/gem5.opt /home/ubuntu/ASEGem5/hello-custom-binary-Ex.py --isa X86 --input $c_file.txt
echo $?

echo "Simulation==========================OLD"
/home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/ASEGem5/hello-custom-binary-Ex.py --isa X86 --input $c_file.txt
echo $?
