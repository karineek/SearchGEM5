// Modification timestamp: 2023-08-14 14:50:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr27073.c

#include <stdio.h>
#include <stdlib.h>

void __attribute__((noinline))
foo (int *p, int d1, int d2, int d3,
     short count, int s1, int s2, int s3, int s4, int s5)
{
  int n = count;
  while (n--)
    {
      *p++ = s1;
      *p++ = s2;
      *p++ = s3;
      *p++ = s4;
      *p++ = s5;
    }
}

int main(int argc, char *argv[]) {
  int x[10], i;
  
  if (argc != 12) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7> <arg8> <arg9> <arg10> <arg11> <arg12>\n", argv[0]);
    return 1;
  }
  
  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  int arg3 = atoi(argv[3]);
  int arg4 = atoi(argv[4]);
  int arg5 = atoi(argv[5]);
  int arg6 = atoi(argv[6]);
  int arg7 = atoi(argv[7]);
  int arg8 = atoi(argv[8]);
  int arg9 = atoi(argv[9]);
  int arg10 = atoi(argv[10]);
  int arg11 = atoi(argv[11]);
  int arg12 = atoi(argv[12]);

  foo (x, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
  for (i = 0; i < 10; i++)
    if (x[i] != (i % 5 + 1) * 100)
      abort ();
  exit (0);
}
