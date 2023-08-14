
// Modification timestamp: 2023-08-10 14:40:10
// Original Source: https://github.com/llvm/llvm-test-suite

int printf(const char*, ...);

void printArgsNoRet(char a3, char* a5) {
  printf("'%c' '%c'\n", (int)a3, (int)*a5);
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <char> <char>\n", argv[0]);
    return 1;
  }

  char a3 = *argv[1];
  char* a5 = argv[2];

  printArgsNoRet(a3, a5);
  return 0;
}
