// Modification timestamp: 2023-08-14 13:30:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921016-1.c
main()
{
int j=1081;
struct
{
signed int m:11;
}l;
if((l.m=j)==j)abort();
exit(0);
}
