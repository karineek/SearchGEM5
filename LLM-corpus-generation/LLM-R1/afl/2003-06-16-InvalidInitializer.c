// Modification timestamp: 2023-08-14 17:32:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-06-16-InvalidInitializer.c


#include <stdio.h>

typedef struct {
    char *auth_pwfile;
    int x;
} auth_config_rec;

void *Ptr = &((auth_config_rec*)0)->x;

int main(int argc, char *argv[]) {
    return 0;
}
