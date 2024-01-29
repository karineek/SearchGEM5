// Modification timestamp: 2023-08-14 16:14:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    short s __attribute__ ((aligned(2), packed));
    double d __attribute__ ((aligned(2), packed));
} TRIAL;

int check(TRIAL *t) {
    if (t->s != atoi(argv[1]) || t->d != atof(argv[2])) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <s> <d>\n", argv[0]);
        return 1;
    }

    TRIAL trial;

    trial.s = atoi(argv[1]);
    trial.d = atof(argv[2]);

    if (check(&trial) != 0) {
        abort();
    }
    exit(0);
}
