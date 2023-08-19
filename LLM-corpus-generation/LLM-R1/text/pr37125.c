// Modification timestamp: 2023-08-14 14:59:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37125.c
extern void abort (void);

static inline unsigned int
mod_rhs(int rhs)
{
  if (rhs == 0) return 1;
  return rhs;
}

void func_44 (unsigned int p_45);
void func_44 (unsigned int p_45)
{
  if (!((p_45 * -9) % mod_rhs (-9))) {
      abort();
  }
}

int main (void)
{
  func_44 (2);
  return 0;
}
