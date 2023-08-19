// Modification timestamp: 2023-08-14 15:12:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43987.c

#include <stdio.h>
#include <stdlib.h>

char B[256 * sizeof(void *)];
typedef void *FILE;
typedef struct globals {
    int c;
    FILE *l;
} __attribute__((may_alias)) T;
void add_input_file(FILE *file)
{
  (*(T*)&B).l[0] = file;
}
extern void abort (void);
int main(int argc, char *argv[])
{
  FILE x;
  (*(T*)&B).l = &x;
  add_input_file((void *)atoi(argv[1]));
  if ((*(T*)&B).l[0] != (void *)atoi(argv[2]))
    abort ();
  return 0;
}
