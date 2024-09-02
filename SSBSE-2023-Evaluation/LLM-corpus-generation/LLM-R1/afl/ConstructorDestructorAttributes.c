// Modification timestamp: 2023-08-14 17:33:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//ConstructorDestructorAttributes.c

#include <stdio.h>

void ctor(int argc, char *argv[]) __attribute__((constructor));

void ctor(int argc, char *argv[]) {
   printf("Create!\n");
}
void dtor() __attribute__((destructor));

void dtor() {
   printf("Create!\n");
}

int main(int argc, char *argv[]) { return 0; }
