// Modification timestamp: 2023-08-14 13:26:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-3.c
/* { dg-require-effective-target label_values } */

int tab[9];
execute(oip, ip)
     unsigned short *oip, *ip;
{
  int x = 0;
  int *xp = tab;
base:
  x++;
  if (x == 4)
    {
      *xp = 0;
      return;
    }
  *xp++ = ip - oip;
  goto *(&&base + *ip++);
}

main()
{
  unsigned short ip[10];
  int i;
  for (i = 0; i < 10; i++)
    ip[i] = 0;
  execute(ip, ip);
  if (tab[0] != 0 || tab[1] != 1 || tab[2] != 2 || tab[3] != 0)
    abort();
  exit(0);
}
