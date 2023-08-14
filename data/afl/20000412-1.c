
// Modification timestamp: 2023-08-10 16:19:47
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdlib.h>

short int i = -1;
const char * const wordlist[207];

const char * const *
foo(void)
{
  register const char * const *wordptr = &wordlist[207u + i];
  return wordptr;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  if (foo() != &wordlist[x])
    abort();
  exit(0);
}
