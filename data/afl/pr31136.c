// Modification timestamp: 2023-08-14 14:53:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31136.c

extern void abort (void);

struct S {
  unsigned b4:4;
  unsigned b6:6;
} s;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <b6_value> <b4_value>\n", argv[0]);
    return 1;
  }

  s.b6 = atoi(argv[1]);
  s.b4 = atoi(argv[2]);
  s.b6 = s.b4;
  s.b4 = s.b6;
  
  if (s.b6 != 15)
    abort ();
  return 0;
}
