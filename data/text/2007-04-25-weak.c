// Modification timestamp: 2023-08-14 17:23:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2007-04-25-weak.c

#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
extern int test_weak () __attribute__ ((weak_import));
#else
extern int test_weak () __attribute__ ((weak));
#endif

int main(){
  int (*t)() = test_weak;
  if (t) {
    t();
    return 1;
  }
  return 0;
}
