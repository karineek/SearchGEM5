// Modification timestamp: 2023-08-14 15:47:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68376-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

__attribute__((noinline, noclone)) int
f1 (int x)
{
  return x < atoi(argv[1]) ? ~x : x;
}

__attribute__((noinline, noclone)) int
f2 (int x)
{
  return x < atoi(argv[1]) ? x : ~x;
}

__attribute__((noinline, noclone)) int
f3 (int x)
{
  return x <= atoi(argv[1]) ? ~x : x;
}

__attribute__((noinline, noclone)) int
f4 (int x)
{
  return x <= atoi(argv[1]) ? x : ~x;
}

__attribute__((noinline, noclone)) int
f5 (int x)
{
  return x >= atoi(argv[1]) ? ~x : x;
}

__attribute__((noinline, noclone)) int
f6 (int x)
{
  return x >= atoi(argv[1]) ? x : ~x;
}

__attribute__((noinline, noclone)) int
f7 (int x)
{
  return x > atoi(argv[1]) ? ~x : x;
}

__attribute__((noinline, noclone)) int
f8 (int x)
{
  return x > atoi(argv[1]) ? x : ~x;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (f1 (5) != 5 || f1 (-5) != 4 || f1 (0) != 0)
    abort ();
  if (f2 (5) != -6 || f2 (-5) != -5 || f2 (0) != -1)
    abort ();
  if (f3 (5) != 5 || f3 (-5) != 4 || f3 (0) != -1)
    abort ();
  if (f4 (5) != -6 || f4 (-5) != -5 || f4 (0) != 0)
    abort ();
  if (f5 (5) != -6 || f5 (-5) != -5 || f5 (0) != -1)
    abort ();
  if (f6 (5) != 5 || f6 (-5) != 4 || f6 (0) != 0)
    abort ();
  if (f7 (5) != -6 || f7 (-5) != -5 || f7 (0) != 0)
    abort ();
  if (f8 (5) != 5 || f8 (-5) != 4 || f8 (0) != -1)
    abort ();
  return 0;
}

Note: I have added the argc and argv parameters to the main function as well as the necessary argument checks.