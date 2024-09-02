// Modification timestamp: 2023-08-14 12:46:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030626-2.c

#include <stdio.h>
#include <stdlib.h>

char buf[40];

extern int sprintf (char*, const char*, ...);
extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int l = sprintf (buf, "%s", i++ ? "string" : "other string");
  if (l != sizeof ("other string") - 1 || i != 1)
    abort ();
  return 0;
}
