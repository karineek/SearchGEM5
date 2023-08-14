// Modification timestamp: 2023-08-14 11:53:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001031-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);
void exit(int);

void t1(int x)
{
  if (x != 4100)
    abort();
}

int t2(void)
{
  int i;
  t1((i = atoi(argv[1])) + 4);
  return i;
}

void t3(long long x)
{
  if (x != 0x80000fffULL)
    abort();
}

long long t4(void)
{
  long long i;
  t3((i = atoi(argv[2])) + 0x7fffffffULL);
  return i;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  if (t2() != atoi(argv[1]))
    abort();
  if (t4() != atoi(argv[2]))
    abort();
  exit(0);
}

Note: Make sure to compile this program with the appropriate arguments.