// Modification timestamp: 2023-08-14 13:49:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980505-2.c
typedef unsigned short Uint16;
typedef unsigned int Uint;

Uint f ()
{
        Uint16 token;
        Uint count;
        static Uint16 values[1] = {0x9300};

        token = values[0];
        count = token >> 8;

        return count;
}

int
main ()
{
  if (f () != 0x93)
    abort ();
  exit (0);
}
