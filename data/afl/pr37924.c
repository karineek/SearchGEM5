// Modification timestamp: 2023-08-14 15:00:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37924.c

extern void abort(void);

signed char a;
unsigned char b;

int test1(signed char a) {
  int c = -1;
  return ((unsigned int)(a ^ c)) >> 9;
}

int test2(unsigned char b) {
  int c = -1;
  return ((unsigned int)(b ^ c)) >> 9;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char a = atoi(argv[1]);
  unsigned char b = atoi(argv[2]);

  a = 0;
  if (test1(a) != (-1U >> 9))
    abort();
  a = 0x40;
  if (test1(a) != (-1U >> 9))
    abort();
  a = 0x80;
  if (test1(a) != (a < 0) ? 0 : (-1U >> 9))
    abort();
  a = 0xff;
  if (test1(a) != (a < 0) ? 0 : (-1U >> 9))
    abort();
  b = 0;
  if (test2(b) != (-1U >> 9))
    abort();
  b = 0x40;
  if (test2(b) != (-1U >> 9))
    abort();
  b = 0x80;
  if (test2(b) != (-1U >> 9))
    abort();
  b = 0xff;
  if (test2(b) != (-1U >> 9))
    abort();
  return 0;
}
