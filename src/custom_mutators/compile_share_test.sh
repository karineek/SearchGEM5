gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ /home/ubuntu/AFLplusplus/src/afl-performance.c -o afl-performance.o
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ utils.c -o utils.o -D TEST_CM
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5.o -D TEST_CM
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-1.o -D MUTATOR_BIN -D TEST_CM
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-2.o -D MUTATOR_ARGS -D TEST_CM
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5-3.o -D MUTATOR_TYPE -D TEST_CM
gcc -shared -o cm-gem5.so afl-performance.o utils.o tmpcm-gem5.o
gcc -shared -o cm-gem5-bin.so afl-performance.o utils.o tmpcm-gem5-1.o
gcc -shared -o cm-gem5-args.so afl-performance.o utils.o tmpcm-gem5-2.o
gcc -shared -o cm-gem5-types.so afl-performance.o utils.o tmpcm-gem5-3.o
