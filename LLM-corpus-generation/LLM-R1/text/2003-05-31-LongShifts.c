// Modification timestamp: 2023-08-14 17:13:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-31-LongShifts.c
extern int printf(const char *str, ...);

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
  for (argc--; argc < sizeof(Vals)/sizeof(Vals[0]); ++argc)
    Test(Vals[argc].A, Vals[argc].V);
  return 0;
}
