// Modification timestamp: 2023-08-14 12:43:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030307-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int fcntl_lock(int fd, int op, long long offset, long long count, int type);

int vfswrap_lock(char *fsp, int fd, int op, long long offset, long long count, int type)
{
  return fcntl_lock(fd, op, offset, count, type);
}

int fcntl_lock(int fd, int op, long long offset, long long count, int type)
{
  return type;
}

int main(int argc, char *argv[]) {
  if (argc != 7) {
    printf("Usage: %s <fsp> <fd> <op> <offset> <count> <type>\n", argv[0]);
    return 1;
  }

  char *fsp = argv[1];
  int fd = atoi(argv[2]);
  int op = atoi(argv[3]);
  long long offset = atoll(argv[4]);
  long long count = atoll(argv[5]);
  int type = atoi(argv[6]);

  if (vfswrap_lock(fsp, fd, op, offset, count, type) != type) {
    abort();
  }

  return 0;
}
