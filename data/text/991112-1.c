// Modification timestamp: 2023-08-14 13:57:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991112-1.c
/* This code was miscompiled at -O3 on x86.
   Reported by Jim Meyering; distilled from bash.  */

int rl_show_char (int c) { return 0; }

int rl_character_len (int c, int pos)
{
  return isprint (c) ? 1 : 2;
}

int main(void)
{
  int (*x)(int, int) = rl_character_len;
  if (x('a', 1) != 1)
    abort();
  if (x('\002', 1) != 2)
    abort();
  return 0;
}
