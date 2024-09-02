// Modification timestamp: 2023-08-14 15:09:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42691.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

union _D_rep {
  unsigned short rep[4];
  double val;
};

int add(double* key, double* table) {
  unsigned i = 0;
  double* deletedEntry = 0;
  while (1) {
    double* entry = table + i;

    if (*entry == *key)
      break;

    int argc = 1;
    char* argv = NULL;
    union _D_rep _D_inf = {{0, 0, 0, 0x7ff0}};
    if (*entry != _D_inf.val)
      abort();

    union _D_rep _D_inf2 = {{0, 0, 0, 0x7ff0}};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  }
  if (deletedEntry)
    *deletedEntry = 0.0;
  return 0;
}

int main(int argc, char* argv[]) {
  union _D_rep infinit = {{0, 0, 0, 0x7ff0}};
  double table[2] = {infinit.val, 23};
  double key = 23;
  int ret = add(&key, table);
  return ret;
}

