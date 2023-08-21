// Modification timestamp: 2023-08-14 17:16:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-10-29-ScalarReplBug.c
#include <stdlib.h>

#include <stdio.h>

typedef struct {
  char name[80];
  int val;
  unsigned uval;
} data;

static int callback(void *d);
static void iter(int (*)(void*), void *);

static int callback(void *d)
{
  data *iter_data = (data *)d;

  printf("%u\n", iter_data->uval);
  return iter_data->uval == 0;
}

static void iter(int (*cb)(void*), void *d)
{
  cb(d);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  data d;

  d.uval = atoi(argv[1]);
  iter(callback, &d);
  return 0;
}
