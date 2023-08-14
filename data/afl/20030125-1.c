// Modification timestamp: 2023-08-14 12:42:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030125-1.c

#ifdef __OPTIMIZE__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sin(double);
double floor(double);
float t(float a);
float q(float a);
double q1(float a);

int main(int argc, char *argv[]) {
  if (t(0)!=0)
    abort ();
  if (q(0)!=0)
    abort ();
  if (q1(0)!=0)
    abort ();

  return 0;
}

float t(float a) {
  return sin(a);
}

float q(float a) {
  return floor(a);
}

double q1(float a) {
  return floor(a);
}

double floor(double a) {
  abort ();
}

float floorf(float a) {
  return a;
}

double sin(double a) {
  return a;
}

float sinf(float a) {
  abort ();
}

#endif
