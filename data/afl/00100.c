
// Modification timestamp: 2023-08-04 14:10:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00100.c

#include <stdio.h>
#include <stdlib.h>

int foo(void) {
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
  
    return foo();
}
