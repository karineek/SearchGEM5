// Modification timestamp: 2023-08-14 13:27:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-9.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long proc1(){return 1LL;}
long long proc2(){return 0x12345678LL;}
long long proc3(){return 0xaabbccdd12345678LL;}
long long proc4(){return -1LL;}
long long proc5(){return 0xaabbccddLL;}

void print_longlong(long long x, char *buf) {
  unsigned long l;
  l = (x >> 32) & 0xffffffff;
  if (l != 0)
    sprintf(buf, "%lx%08.lx", l, ((unsigned long)x & 0xffffffff));
  else
    sprintf(buf, "%lx", ((unsigned long)x & 0xffffffff));
}

int main(int argc, char *argv[]) {
  char buf[100];
  print_longlong(proc1(), buf);
  if (strcmp("1", buf)) abort();
  print_longlong(proc2(), buf);
  if (strcmp("12345678", buf)) abort();
  print_longlong(proc3(), buf);
  if (strcmp("aabbccdd12345678", buf)) abort();
  print_longlong(proc4(), buf);
  if (strcmp("ffffffffffffffff", buf)) abort();
  print_longlong(proc5(), buf);
  if (strcmp("aabbccdd", buf)) abort();
  
  exit(0);
}

