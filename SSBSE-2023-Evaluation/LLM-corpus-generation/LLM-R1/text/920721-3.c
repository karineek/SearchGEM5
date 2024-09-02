// Modification timestamp: 2023-08-14 13:28:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-3.c
static inline fu (unsigned short data)
{
  return data;
}
ru(i)
{
   if(fu(i++)!=5)abort();
   if(fu(++i)!=7)abort();
}
static inline fs (signed short data)
{
  return data;
}
rs(i)
{
   if(fs(i++)!=5)abort();
   if(fs(++i)!=7)abort();
}


main()
{
  ru(5);
  rs(5);
  exit(0);
}
