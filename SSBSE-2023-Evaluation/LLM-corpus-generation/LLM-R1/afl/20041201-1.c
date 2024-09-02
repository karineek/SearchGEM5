// Modification timestamp: 2023-08-14 13:00:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041201-1.c

#include <stdio.h>
#include <complex.h>

typedef struct { _Complex char a; _Complex char b; } Scc2;

int checkScc2(Scc2 s);

int main(void) {
  Scc2 s;
  
  if (argc != 5) {
    printf("Usage: %s <a_re> <a_im> <b_re> <b_im>\n", argv[0]);
    return 1;
  }
  
  s.a = atof(argv[1]) + atof(argv[2]) * I;
  s.b = atof(argv[3]) + atof(argv[4]) * I;
  
  return checkScc2(s);
}

int checkScc2(Scc2 s) {
  return s.a != 1 + 2 * I || s.b != 3 + 4 * I;
}
