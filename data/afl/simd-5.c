// Modification timestamp: 2023-08-14 16:10:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/simd-5.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef short Q __attribute__((vector_size(8)));

Q q1, q2, q3, q4;

Q w1, w2, w3, w4;
Q z1, z2, z3, z4;

volatile int dummy;

void __attribute__((__noinline__))
func0(void)
{
  dummy = 1;
}

void __attribute__((__noinline__))
func1(void)
{
  Q a, b;
  a = q1 * q2;
  b = q3 * q4;
  w1 = a;
  w2 = b;
  func0();
  w3 = a;
  w4 = b;
}

void __attribute__((__noinline__))
func2(void)
{
  Q a, b;
  a = q1 + q2;
  b = q3 - q4;
  z1 = a;
  z2 = b;
  func1();
  z3 = a;
  z4 = b;
}

int main(int argc, char *argv[])
{
  if (argc != 9)
  {
    printf("Usage: %s <q1_0> <q1_1> <q2_0> <q2_1> <q3_0> <q3_1> <q4_0> <q4_1>\n", argv[0]);
    return 1;
  }

  q1[0] = atoi(argv[1]);
  q1[1] = atoi(argv[2]);
  q2[0] = atoi(argv[3]);
  q2[1] = atoi(argv[4]);
  q3[0] = atoi(argv[5]);
  q3[1] = atoi(argv[6]);
  q4[0] = atoi(argv[7]);
  q4[1] = atoi(argv[8]);

  func2();

  if (memcmp(&w1, &w3, sizeof(Q)) != 0)
    abort();
  if (memcmp(&w2, &w4, sizeof(Q)) != 0)
    abort();
  if (memcmp(&z1, &z3, sizeof(Q)) != 0)
    abort();
  if (memcmp(&z2, &z4, sizeof(Q)) != 0)
    abort();

  return 0;
}
