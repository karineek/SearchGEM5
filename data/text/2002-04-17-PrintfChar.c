
// Modification timestamp: 2023-08-10 14:40:10
// Original Source: https://github.com/llvm/llvm-test-suite

int printf(const char*, ...);

void printArgsNoRet(char a3, char* a5) {
  printf("'%c' '%c'\n", (int)a3, (int)*a5);
}

int main() {
  printArgsNoRet('c', "e");
  return 0;
}
