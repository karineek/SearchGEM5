// Modification timestamp: 2023-08-14 13:26:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-3.c

#include <stdio.h>
#include <stdlib.h>

int tab[9];

void execute(unsigned short *oip, unsigned short *ip) {
  int x = 0;
  int *xp = tab;
base:
  x++;
  if (x == 4) {
    *xp = 0;
    return;
  }
  *xp++ = ip - oip;
  goto *(&&base + *ip++);
}

int main(int argc, char *argv[]) {
  unsigned short ip[10];
  int i;
  for (i = 0; i < 10; i++)
    ip[i] = atoi(argv[i+1]);
  execute(ip, ip);
  if (tab[0] != 0 || tab[1] != 1 || tab[2] != 2 || tab[3] != 0) {
    abort();
  }
  exit(0);
}

Note: In the `main` function, the `argv` values are assigned directly to `ip` array. Make sure to pass the correct number of arguments when running the program.