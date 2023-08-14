
// Modification timestamp: 2023-08-10 15:56:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/ConstructorDestructorAttributes.c

#include <stdio.h>

void ctor() __attribute__((constructor));

void ctor() {
   printf("Create!\n");
}
void dtor() __attribute__((destructor));

void dtor() {
   printf("Create!\n");
}

int main() { return 0; }
