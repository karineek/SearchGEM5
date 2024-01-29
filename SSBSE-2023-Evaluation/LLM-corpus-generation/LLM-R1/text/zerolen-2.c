// Modification timestamp: 2023-08-14 17:05:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/zerolen-2.c
/* { dg-skip-if "assumes absence of larger-than-word padding" { epiphany-*-* } } */
extern void abort(void);

typedef int word __attribute__((mode(word)));

struct foo
{
  word x;
  word y[0];
};

int main()
{
  if (sizeof(word) != sizeof(struct foo))
    abort();
  if (__alignof__(word) != __alignof__(struct foo))
    abort();
  return 0;
}
