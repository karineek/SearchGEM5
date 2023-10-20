#asan="-fsanitize=address -fsanitize-address-use-after-scope"
msan="-fsanitize=memory"
ubsan="-fsanitize=undefined"
clang-12 -w -O3 $asan $msan $ubsan -I/home/ubuntu/AFLplusplus/include/ utils.c cm-gem5.c test-main.c -o main_cm-gem5.o -D DEBUG_CM
./main_cm-gem5.o
