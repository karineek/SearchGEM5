// Modification timestamp: 2023-08-14 13:42:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950628-1.c
typedef struct
{
  char hours, day, month;
  short year;
} T;

T g (void)
{
  T now;

  now.hours = 1;
  now.day = 2;
  now.month = 3;
  now.year = 4;
  return now;
}

T f (void)
{
  T virk;

  virk = g ();
  return virk;
}

main ()
{
  if (f ().hours != 1 || f ().day != 2 || f ().month != 3 || f ().year != 4)
    abort ();
  exit (0);
}
