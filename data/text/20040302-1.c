// Modification timestamp: 2023-08-14 12:51:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040302-1.c
/* { dg-require-effective-target label_values } */
int code[]={0,0,0,0,1};

void foo(int x) {
  volatile int b;
  b = 0xffffffff;
}

void bar(int *pc) {
  static const void *l[] = {&&lab0, &&end};

  foo(0);
  goto *l[*pc];
 lab0:
  foo(0);
  pc++;
  goto *l[*pc];
 end:
  return;
}

int main() {
  bar(code);
  return 0;
}
