// Modification timestamp: 2023-08-14 13:40:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941031-1.c
typedef long mpt;

int
f (mpt us, mpt vs)
{
  long aus;
  long avs;

  aus = us >= 0 ? us : -us;
  avs = vs >= 0 ? vs : -vs;

  if (aus < avs)
    {
      long t = aus;
      aus = avs;
      avs = aus;
    }

  return avs;
}

main ()
{
  if (f ((mpt) 3, (mpt) 17) != 17)
    abort ();
  exit (0);
}
