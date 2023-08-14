// Modification timestamp: 2023-08-14 13:27:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-6.c

#include <stdio.h>
#include <stdlib.h>

long long unsigned str2llu(char *str) {
  long long unsigned acc;
  int d;
  acc = *str++ - '0';
  for (;;) {
    d = *str++;
    if (d == '\0')
      break;
    d -= '0';
    acc = acc * 10 + d;
  }

  return acc;
}

long unsigned sqrtllu(long long unsigned t) {
  long long unsigned s;
  long long unsigned b;

  for (b = 0, s = t; b++, (s >>= 1) != 0;)
    ;

  s = 1LL << (b >> 1);

  if (b & 1)
    s += s >> 1;

  do {
    b = t / s;
    s = (s + b) >> 1;
  } while (b < s);

  return s;
}

int plist(long long unsigned p0, long long unsigned p1, long long unsigned *tab) {
  long long unsigned p;
  long unsigned d;
  long unsigned s;
  long long unsigned *xp = tab;

  for (p = p0; p <= p1; p += 2) {
    s = sqrtllu(p);

    for (d = 3; d <= s; d += 2) {
      long long unsigned q = p % d;
      if (q == 0)
        goto not_prime;
    }

    *xp++ = p;
  not_prime:;
  }
  *xp = 0;
  return xp - tab;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <p>\n", argv[0]);
    return 1;
  }

  long long tab[10];
  int nprimes;
  long long unsigned p0 = str2llu("1234111111");
  long long unsigned p1 = str2llu(argv[1]);
  nprimes = plist(p0, p1, tab);

  if (tab[0] != 1234111117LL || tab[1] != 1234111121LL || tab[2] != 1234111127LL || tab[3] != 0)
    abort();

  exit(0);
}
