// Modification timestamp: 2023-08-14 13:33:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930408-1.c

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  e0,
  e1
} E;

struct {
  E eval;
} s;

void p() {
  abort();
}

void f() {
  switch (s.eval) {
    case e0:
      p();
  }
}

int main(int argc, char *argv[]) {
  s.eval = e1;
  f();
  exit(0);
}

