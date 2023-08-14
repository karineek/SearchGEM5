// Modification timestamp: 2023-08-14 15:57:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82388.c

#include <stdio.h>

// Define the struct A
struct A { 
  int b; 
  int c; 
  int d; 
} e;

// Define the function foo
struct A foo(void) {
  struct A h[30] = {{0,0,0}};
  return h[29];
}

int main(void) {
  e = foo();
  return e.b;
}
