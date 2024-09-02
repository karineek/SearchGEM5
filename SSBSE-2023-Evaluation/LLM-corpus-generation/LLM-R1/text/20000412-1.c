
// Modification timestamp: 2023-08-10 16:19:47
// Original Source: https://github.com/llvm/llvm-test-suite

short int i = -1;
const char * const wordlist[207];

const char * const *
foo(void)
{
  register const char * const *wordptr = &wordlist[207u + i];
  return wordptr;
}

int main() {
  if (foo() != &wordlist[206])
    abort();
  exit(0);
}
