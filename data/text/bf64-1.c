// Modification timestamp: 2023-08-14 14:06:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf64-1.c
/* { dg-xfail-if "ABI specifies bitfields cannot exceed 32 bits" { mcore-*-* } } */
struct tmp
{
  long long int pad : 12;
  long long int field : 52;
};

struct tmp2
{
  long long int field : 52;
  long long int pad : 12;
};

struct tmp
sub (struct tmp tmp)
{
  tmp.field |= 0x0008765412345678LL;
  return tmp;
}

struct tmp2
sub2 (struct tmp2 tmp2)
{
  tmp2.field |= 0x0008765412345678LL;
  return tmp2;
}

main()
{
  struct tmp tmp = {0x123, 0xFFF000FFF000FLL};
  struct tmp2 tmp2 = {0xFFF000FFF000FLL, 0x123};

  tmp = sub (tmp);
  tmp2 = sub2 (tmp2);

  if (tmp.pad != 0x123 || tmp.field != 0xFFFFFF541FFF567FLL)
    abort ();
  if (tmp2.pad != 0x123 || tmp2.field != 0xFFFFFF541FFF567FLL)
    abort ();
  exit (0);
}
