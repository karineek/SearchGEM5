
// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2000-05-19-2.c

#include <stdlib.h>

int main(int argc, char *argv[]) {
    long x;
  
    if(argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atol(argv[1]);

    long b = (x != -1L);

    if (b)
        abort();

    exit(0);
}
