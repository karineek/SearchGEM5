// Modification timestamp: 2023-08-14 17:16:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-10-13-SwitchTest.c

#include <stdio.h>

int main(int argc, const char **argv) {
   switch (argc) {
   default:
     printf("GOOD\n");
     return 0;
   case atoi(argv[1]):
   case atoi(argv[2]):
   case atoi(argv[3]):
     printf("BAD\n");
     return 1;
   }
}
