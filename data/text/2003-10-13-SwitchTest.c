
// Modification timestamp: 2023-08-10 15:08:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/Shifts/2003-10-13-SwitchTest.c

#include <stdio.h>

int main(int argc, const char **argv) {
   switch (argc) {
   default:
     printf("GOOD\n");
     return 0;
   case 100:
   case 101:
   case 1023:
     printf("BAD\n");
     return 1;
   }
}
