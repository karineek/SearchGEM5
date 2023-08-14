// Modification timestamp: 2023-08-14 13:52:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990211-1.c
/* Copyright (C) 1999 Free Software Foundation, Inc.
  Contributed by Nathan Sidwell 20 Jan 1999 <nathan@acm.org> */

/* check range combining boolean operations work */

extern void abort();

#define N 77

void func(int i)
{
  /* fold-const does some clever things with range tests. Make sure
     we get (some of) them right */

  /* these must fail, regardless of the value of i */
  if ((i < 0) && (i >= 0))
    abort();
  if ((i > 0) && (i <= 0))
    abort();
  if ((i >= 0) && (i < 0))
    abort();
  if ((i <= 0) && (i > 0))
    abort();

  if ((i < N) && (i >= N))
    abort();
  if ((i > N) && (i <= N))
    abort();
  if ((i >= N) && (i < N))
    abort();
  if ((i <= N) && (i > N))
    abort();

  /* these must pass, regardless of the value of i */
  if (! ((i < 0) || (i >= 0)))
    abort();
  if (! ((i > 0) || (i <= 0)))
    abort();
  if (! ((i >= 0) || (i < 0)))
    abort();
  if (! ((i <= 0) || (i > 0)))
    abort();

  if (! ((i < N) || (i >= N)))
    abort();
  if (! ((i > N) || (i <= N)))
    abort();
  if (! ((i >= N) || (i < N)))
    abort();
  if (! ((i <= N) || (i > N)))
    abort();

  return;
}

int main()
{
  func(0);
  func(1);
  return 0;
}
