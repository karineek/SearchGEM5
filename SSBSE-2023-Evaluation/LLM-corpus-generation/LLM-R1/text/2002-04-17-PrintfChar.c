// Modification timestamp: 2023-08-14 17:10:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-04-17-PrintfChar.c
/* this little micro testcase is due to lli printing out char values
 * incorrectly through printf.
 */
int printf(const char*, ...);

void printArgsNoRet(char a3, char* a5) {
  printf("'%c' '%c'\n", (int)a3, (int)*a5);
}

int main() {
  printArgsNoRet('c', "e");
  return 0;
}
