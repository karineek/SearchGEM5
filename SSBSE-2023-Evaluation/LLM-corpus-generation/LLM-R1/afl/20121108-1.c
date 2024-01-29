// Modification timestamp: 2023-08-14 13:21:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20121108-1.c

#include <stdio.h>
#include <stdlib.h>

char temp[] = "192.168.190.160";
unsigned result = (((((192u<<8)|168u)<<8)|190u)<<8)|160u;

int strtoul1(const char *a, char **b, int c) __attribute__((noinline, noclone));
int strtoul1(const char *a, char **b, int c)
{
  *b = a+3;
  if (a == argv[1])
    return atoi(argv[1]);
  else if (a == argv[1]+4)
    return atoi(argv[1]);
  else if (a == argv[1]+8)
    return atoi(argv[1]);
  else if (a == argv[1]+12)
    return atoi(argv[1]);
  __builtin_abort();
}

int string_to_ip(const char *s) __attribute__((noinline,noclone));
int string_to_ip(const char *s)
{
        int addr;
        char *e;
        int i;

        if (s == 0)
                return(0);

        for (addr=0, i=0; i<4; ++i) {
                int val = s ? strtoul1(s, &e, 10) : 0;
                addr <<= 8;
                addr |= (val & 0xFF);
                if (s) {
                        s = (*e) ? e+1 : e;
                }
        }

        return addr;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int t = string_to_ip (argv[1]);
  printf ("%x\n", t);
  printf ("%x\n", result);
  if (t != result)
    __builtin_abort ();
  printf ("WORKS.\n");
  return 0;
}
