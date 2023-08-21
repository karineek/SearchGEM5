// Modification timestamp: 2023-08-10 16:15:07
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

void big(long long u) { }

void doit(unsigned int a,unsigned int b,char *id)
{
  big(*id);
  big(a);
  big(b);
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <a> <b> <id>\n", argv[0]);
    return 1;
  }
  
  unsigned int a = atoi(argv[1]);
  unsigned int b = atoi(argv[2]);
  char *id = argv[3];

  doit(a, b, id);
  
  return 0;
}
