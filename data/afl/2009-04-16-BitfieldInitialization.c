c
// Modification timestamp: 2023-08-10 15:29:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Regression/C/2009-04-16-BitfieldInitialization.c

#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("1: %d, %d\n", t1.info, t1.u.id);
  printf("2: %f, %d, %d\n", t2.info, t2.x, t2.Y);
  printf("3: %d %s\n", t3.A, t3.C);
  printf("4: %f %d %f\n", (double)t4.x, t4.y, (double)t4.z);
  printf("5: %d %d %d\n", t5.x, t5.y, t5.z);
  printf("5a: %d %d\n", t5a.x, t5a.y);
  printf("5b: %d %d\n", t5b.x, t5b.y);
  printf("6: %Lf %d\n", t6.x, t6.y);
  printf("7: %d %d %d %d\n", t7.x, t7.y, t7.q, t7.z);
  printf("7a: %d %d %d\n", t7a.x, t7a.y, t7a.q);
  printf("8: %d %d\n", t8.what, t8.type);
  printf("9: %d %d\n", t9.b, t9.c);
  printf("10: %d\n", *t10.b);
  return 0;
}
