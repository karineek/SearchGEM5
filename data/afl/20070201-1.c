// Modification timestamp: 2023-08-14 13:08:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070201-1.c

#include <stdio.h>
#include <stdlib.h>

extern int sprintf (char *, const char *, ...);
extern void abort (void);

char *
foo (char *buf, char *p)
{
  sprintf (buf, "%s", p++);
  return p;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char buf[6];
  if (foo (buf, &buf[2]) != &buf[3])
    abort ();
  return 0;
}


or


#include <stdio.h>

extern int sprintf (char *, const char *, ...);
extern void abort (void);

char *
foo (char *buf, char *p)
{
  sprintf (buf, "%s", p++);
  return p;
}

int
main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  char buf[6];
  if (foo (buf, argv[1]) != argv[2])
    abort ();
  return 0;
}


Please note that the second version assumes that you pass the values as command-line arguments when running the program.