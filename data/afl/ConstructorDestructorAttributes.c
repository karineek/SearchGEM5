
// Modification timestamp: 2023-08-10 15:56:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/ConstructorDestructorAttributes.c

#include <stdio.h>
#include <stdlib.h>

void ctor() __attribute__((constructor));

void ctor() {
   printf("Create!\n");
}
void dtor() __attribute__((destructor));

void dtor() {
   printf("Create!\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  return 0;
}
