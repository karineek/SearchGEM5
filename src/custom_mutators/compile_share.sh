gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ /home/ubuntu/AFLplusplus/src/afl-performance.c -o afl-performance.o
gcc -c -fpic -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o tmpcm-gem5.o
#gcc -shared -Wall -O3 -I/home/ubuntu/AFLplusplus/include/ cm-gem5.c -o cm-gem5.so -fPIC
gcc -shared -o cm-gem5.so afl-performance.o tmpcm-gem5.o
