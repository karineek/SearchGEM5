// Modification timestamp: 2023-08-14 13:33:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930513-1.c
/* { dg-additional-options "-Wl,-u,_printf_float" { target newlib_nano_io } } */

#include <stdio.h>
char buf[2];

f (fp)
     int (*fp)(char *, const char *, ...);
{
  (*fp)(buf, "%.0f", 5.0);
}

main ()
{
  f (&sprintf);
  if (buf[0] != '5' || buf[1] != 0)
    abort ();
  exit (0);
}
