// Modification timestamp: 2023-08-14 16:14:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-1.c
typedef struct
{
  short s __attribute__ ((aligned(2), packed));
  double d __attribute__ ((aligned(2), packed));
} TRIAL;

int
check (TRIAL *t)
{
  if (t->s != 1 || t->d != 16.0)
    return 1;
  return 0;
}

main ()
{
  TRIAL trial;

  trial.s = 1;
  trial.d = 16.0;

  if (check (&trial) != 0)
    abort ();
  exit (0);
}
