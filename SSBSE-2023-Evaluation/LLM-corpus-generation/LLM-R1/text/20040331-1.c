// Modification timestamp: 2023-08-14 12:52:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040331-1.c
/* PR c++/14755 */
extern void abort (void);
extern void exit (int);

int
main (void)
{
#if __INT_MAX__ >= 2147483647
  struct { int count: 31; } s = { 0 };
  while (s.count--)
    abort ();
#elif __INT_MAX__ >= 32767
  struct { int count: 15; } s = { 0 };
  while (s.count--)
    abort ();
#else
  /* Don't bother because __INT_MAX__ is too small.  */
#endif
  exit (0);
}
