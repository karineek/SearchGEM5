// Modification timestamp: 2023-08-14 14:27:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/fprintf-2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char *tmpfname = tmpnam(0);
  FILE *f = fopen(tmpfname, "w");
  if (!f) {
    perror("fopen for writing");
    return 1;
  }

  fprintf(f, "1");
  fprintf(f, "%c", '2');
  fprintf(f, "%c%c", '3', '4');
  fprintf(f, "%s", "5");
  fprintf(f, "%s%s", "6", "7");
  fprintf(f, "%i", atoi(argv[1]));
  fprintf(f, "%.1s\n", "9x");
  fclose(f);

  f = fopen(tmpfname, "r");
  if (!f) {
    perror("fopen for reading");
    remove(tmpfname);
    return 1;
  }

  char buf[12] = "";
  if (1 != fscanf(f, "%s", buf)) {
    perror("fscanf");
    fclose(f);
    remove(tmpfname);
    return 1;
  }

  fclose(f);
  remove(tmpfname);

  if (strcmp(buf, "123456789"))
    abort();

  return 0;
}
