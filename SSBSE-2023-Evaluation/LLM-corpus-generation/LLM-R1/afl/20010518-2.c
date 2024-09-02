// Modification timestamp: 2023-08-14 11:59:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010518-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char b0;
  char b1;
  char b2;
  char b3;
  char b4;
  char b5;
} __attribute__ ((packed)) b_struct;


typedef struct
{
  short a;
  long b;
  short c;
  short d;
  b_struct e;
} __attribute__ ((packed)) a_struct;


int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile a_struct *a;
  volatile a_struct b;

  a = &b;
  *a = (a_struct){atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
  a->e.b4 = *argv[5];

  if (a->a != atoi(argv[1]) || a->b != atoi(argv[2]) || a->c != atoi(argv[3]) || a->d != atoi(argv[4]) || a->e.b4 != *argv[5])
    abort ();

  exit (0);
}

Please make sure to input 5 additional arguments in the command line when running the program.