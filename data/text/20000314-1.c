
// Modification timestamp: 2023-08-10 16:17:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/20000314-1.c

int main()
{
  long winds = 0;

  while (winds != 0) {
    if (*(char *) winds)
      break;
  }

  if (winds == 0 || winds != 0 || *(char *) winds)
    exit(0);

  abort();
}
