// Modification timestamp: 2023-08-14 13:52:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990127-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
extern void exit (int);

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int a, b, c;
  int *pa, *pb, *pc;
  int **ppa, **ppb, **ppc;
  int i, j, k, x, y, z;

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  pa = &a; pb = &b; pc = &c;
  ppa = &pa; ppb = &pb; ppc = &pc;
  x = atoi(argv[4]); y = atoi(argv[5]); z = atoi(argv[6]);

  for(i=0;i<10;i++){
    if( pa == &a ) pa = &b;
    else pa = &a;
    while( (*pa)-- ){
      x++;
      if( (*pa) < atoi(argv[7]) ) break;
      else pa = &b;
    }
    x++;
    pa = &b;
  }

  if ((*pa) != atoi(argv[8]) || (*pb) != atoi(argv[9]) || x != atoi(argv[10]))
    abort ();

  exit (0);
}
