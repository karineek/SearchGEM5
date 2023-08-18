// Modification timestamp: 2023-08-14 17:05:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/zerolen-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

union iso_directory_record {
  char carr[4];
  struct {
    unsigned char name_len[1];
    char name[0];
  } u;
} entry;

void set(union iso_directory_record *);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union iso_directory_record *de;
  de = &entry;
  set(de);

  if (de->u.name_len[0] == atoi(argv[1]) && de->u.name[0] == '\0')
    exit(0);
  else
    abort();
}

void set(union iso_directory_record *p) {
  p->carr[0] = atoi(argv[2]);
  p->carr[1] = '\0';
  return;
}
