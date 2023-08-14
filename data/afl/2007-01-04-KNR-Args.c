
// Modification timestamp: 2023-08-10 15:26:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2007-01-04-KNR-Args.c

#include <stdio.h>

p1 (c, f1, s, d1, i, f2, l, d2)
char c; float f1; short s; double d1; int i; float f2; long l; double d2;
{
  printf("%c %f %d %f %d %f %d %f\n", c, f1, s, d1,i, f2, l, d2);
}

void p2 (char c, float f1, short s, double d1, int i, float f2, long l, double d2)
{
  printf("%c %f %d %f %d %f %d %f\n", c, f1, s, d1,i, f2, l, d2);
}

int main(int argc, const char *argv[]) {
  char c_arg = 'a';
  float f1_arg = 4.0;
  short s_arg = 1;
  double d1_arg = 5.0;
  int i_arg = 2;
  float f2_arg = 4.0;
  long l_arg = 3;
  double d2_arg = 5.0;
  
  p1 (c_arg, f1_arg, s_arg, d1_arg, i_arg, f2_arg, l_arg, d2_arg);
  p2 (c_arg, f1_arg, s_arg, d1_arg, i_arg, f2_arg, l_arg, d2_arg);
  return 0;
}
