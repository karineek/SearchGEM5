// Modification timestamp: 2023-08-14 13:42:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950628-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char hours, day, month;
  short year;
} T;

T g(char hours, char day, char month, short year) {
  T now;

  now.hours = hours;
  now.day = day;
  now.month = month;
  now.year = year;
  return now;
}

T f() {
  T virk;

  virk = g(1, 2, 3, 4);
  return virk;
}

int main(int argc, char *argv[]) {
  T result = f();
  
  if (result.hours != 1 || result.day != 2 || result.month != 3 || result.year != 4) {
    abort();
  }
  
  exit(0);
}
