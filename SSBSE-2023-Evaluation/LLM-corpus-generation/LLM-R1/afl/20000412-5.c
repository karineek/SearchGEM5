c
// Modification timestamp: 2023-08-10 16:30:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/OpenMP/20000412-5.c

#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct {
        int node;
        int type;
    } lastglob[1];

    if (argc != 3) {
        printf("Usage: %s <node> <type>\n", argv[0]);
        return 1;
    }

    lastglob[0].node = atoi(argv[1]);
    lastglob[0].type = atoi(argv[2]);

    if (lastglob[0].node != 0 || lastglob[0].type != 1)
        abort ();
    exit (0);
}
