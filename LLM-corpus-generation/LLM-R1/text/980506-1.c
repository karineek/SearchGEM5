// Modification timestamp: 2023-08-14 13:49:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-1.c
struct decision
{
  char enforce_mode;
  struct decision *next;
};


static void
clear_modes (p)
     register struct decision *p;
{
  goto blah;

foo:
  p->enforce_mode = 0;
blah:
  if (p)
    goto foo;
}

main()
{
  struct decision *p = 0;
  clear_modes (p);
  exit (0);
}
