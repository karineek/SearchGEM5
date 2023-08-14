
// Modification timestamp: 2023-08-10 15:27:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/Programs/single-source/2007-04-25-weak.c

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
