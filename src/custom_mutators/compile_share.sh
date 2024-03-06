all=$1
bin=$2
args=$1
type=$3

# General objects
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ /home/ubuntu/AFLplusplus/src/afl-performance.c -o afl-performance.o
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ utils.c -o utils.o

# Create objects - plain functionality
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5.o
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-1.o -D MUTATOR_BIN
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-2.o -D MUTATOR_ARGS
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-3.o -D MUTATOR_TYPE
gcc -shared -o cm-gem5.so afl-performance.o utils.o tmpcm-gem5.o
gcc -shared -o cm-gem5-bin.so afl-performance.o utils.o tmpcm-gem5-1.o
gcc -shared -o cm-gem5-args.so afl-performance.o utils.o tmpcm-gem5-2.o
gcc -shared -o cm-gem5-types.so afl-performance.o utils.o tmpcm-gem5-3.o

# Create objects with SAVE func of the test inputs
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-save.o  -D SAVE_ALL
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-save1.o -D SAVE_ALL -D MUTATOR_BIN
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-save2.o -D SAVE_ALL -D MUTATOR_ARGS
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-save3.o -D SAVE_ALL -D MUTATOR_TYPE
gcc -shared -o cm-gem5-save.so afl-performance.o utils.o tmpcm-gem5-save.o
gcc -shared -o cm-gem5-save-bin.so afl-performance.o utils.o tmpcm-gem5-save1.o
gcc -shared -o cm-gem5-save-args.so afl-performance.o utils.o tmpcm-gem5-save2.o
gcc -shared -o cm-gem5-save-types.so afl-performance.o utils.o tmpcm-gem5-save3.o


# Create objects - plain functionality
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c.o -D COUNTER_ALL=$all
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-1.o -D MUTATOR_BIN  -D COUNTER_BIN=$bin
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-2.o -D MUTATOR_ARGS -D COUNTER_ARGS=$args
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-3.o -D MUTATOR_TYPE -D COUNTER_TYPE=$type
gcc -shared -o cm-gem5c.so afl-performance.o utils.o tmpcm-gem5c.o
gcc -shared -o cm-gem5c-bin.so afl-performance.o utils.o tmpcm-gem5c-1.o
gcc -shared -o cm-gem5c-args.so afl-performance.o utils.o tmpcm-gem5c-2.o
gcc -shared -o cm-gem5c-types.so afl-performance.o utils.o tmpcm-gem5c-3.o

# Create objects with SAVE func of the test inputs
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-save.o  -D SAVE_ALL -D COUNTER_ALL=$all
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-save1.o -D SAVE_ALL -D MUTATOR_BIN 	-D COUNTER_BIN=$bin
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-save2.o -D SAVE_ALL -D MUTATOR_ARGS -D COUNTER_ARGS=$args
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5c-save3.o -D SAVE_ALL -D MUTATOR_TYPE -D COUNTER_TYPE=$type
gcc -shared -o cm-gem5c-save.so afl-performance.o utils.o tmpcm-gem5c-save.o
gcc -shared -o cm-gem5c-save-bin.so afl-performance.o utils.o tmpcm-gem5c-save1.o
gcc -shared -o cm-gem5c-save-args.so afl-performance.o utils.o tmpcm-gem5c-save2.o
gcc -shared -o cm-gem5c-save-types.so afl-performance.o utils.o tmpcm-gem5c-save3.o

#define USE_CUSTOM_FUZZ_COUNT 1   // Override custom count fuzz function
#define COUNTER_ALL 1             // for the value the function return counter fuzz - for the general custom mutator
#define COUNTER_BIN 1             // Same as above but for binary mutator
#define COUNTER_ARGS 1            // Same as above but for argument mutator
#define COUNTER_TYPE 1            // Same as above but for type mutator
#define SAVE_ALL 0                // Save all fuzzed corpus
