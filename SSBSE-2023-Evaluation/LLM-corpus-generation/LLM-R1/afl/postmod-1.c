// Modification timestamp: 2023-08-14 14:42:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/postmod-1.c

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_ARRAY(A) float array##A[0x10]
#define DECLARE_COUNTER(A) float counter##A = 0
#define DECLARE_POINTER(A) float *pointer##A = array##A + x
#define BEFORE(A) counter##A += *pointer##A, pointer##A += 3
#define AFTER(A) counter##A += pointer##A[x]
#define INIT_ARRAY(A) array##A[1] = 1.0f, array##A[5] = 2.0f
#define CHECK_ARRAY(A) exit_code |= (counter##A != 3.0f)
#define MANY(A) A (0), A (1), A (2), A (3), A (4), A (5)
#define INIT_VOLATILE(A) addend##A = vol
#define ADD_VOLATILE(A) vol += addend##A
#define MANY2(A) A (0), A (1), A (2), A (3), A (4)

float MANY (DECLARE_ARRAY);
float MANY (DECLARE_COUNTER);

volatile int stop = 1;
volatile int vol;

void __attribute__((noinline))
foo (int x)
{
  float MANY (DECLARE_POINTER);
  int i;

  do
    {
      MANY (BEFORE);
      MANY (AFTER);
      {
        int MANY2 (INIT_VOLATILE);
        for (i = 0; i < 10; i++)
          MANY2 (ADD_VOLATILE);
      }
    }
  while (!stop);
}

int
main (void)
{
  int exit_code = 0;

  MANY (INIT_ARRAY);
  foo (1);
  MANY (CHECK_ARRAY);
  return exit_code;
}
