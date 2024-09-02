// Modification timestamp: 2023-08-14 12:42:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030216-1.c

void link_error (void);
const double one;

int main(int argc, char *argv[]) {
#ifdef __OPTIMIZE__
  if ((int) one != 1)
    link_error ();
#endif
  return 0;
}

Note that since the constant `one` is not assigned a value in the original code, we declare it without an initializer.