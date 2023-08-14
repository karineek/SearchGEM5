// Modification timestamp: 2023-08-14 13:34:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930603-3.c
f (b, c)
     unsigned char *b;
     int c;
{
  unsigned long v = 0;
  switch (c)
    {
    case 'd':
      v = ((unsigned long)b[0] << 8) + b[1];
      v >>= 9;
      break;

    case 'k':
      v = b[3] >> 4;
      break;

    default:
      abort ();
    }

  return v;
}
main ()
{
  char buf[4];
  buf[0] = 170; buf[1] = 5;
  if (f (buf, 'd') != 85)
    abort ();
  exit (0);
}
