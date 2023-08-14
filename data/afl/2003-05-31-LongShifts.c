
// Modification timestamp: 2023-08-10 14:50:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2003-05-31-LongShifts.c

#include <stdio.h>
#include <stdlib.h>

void Test(long long Val, int Amt) {
  printf("0x%llx op %d:\n", Val, Amt);
  printf("  ashr: 0x%llx\n  lshr: 0x%llx\n  shl: 0x%llx\n", Val >> Amt,
         (unsigned long long)Val >> Amt, Val << Amt);
}

volatile struct {
  long long A;  int V;
} Vals[] = {
  { 123, 4},
  { 123, 34},
  {-4, 4},
  {-5, 34},
  { -6000000000LL, 4},
  { -6000000000LL, 34},
  {  6000000000LL, 4},
  {  6000000000LL, 34}
};

int main(int argc, char**argv) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long long Val = atoll(argv[1]);
  int Amt = atoi(argv[2]);

  Test(Val, Amt);
  
  return 0;
}
