// Modification timestamp: 2023-08-14 17:24:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2010-05-24-BitfieldTest.c
#include <stdio.h>
#include <stdlib.h>

/* From Radar 7980096.  Test case by Shantonu Sen! */
#include <assert.h>

typedef union {
    struct {
        unsigned long long        count                   :8;
        unsigned long long        mcg_ctl_p               :1;
    }          bits;
    unsigned long long   u64;
} ia32_mcg_cap_t;

int main(int argc, char *argv[]) {
    unsigned long long ctl_p;
    ia32_mcg_cap_t   ia32_mcg_cap;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    ia32_mcg_cap.u64 = atoi(argv[1]);

    ctl_p = ia32_mcg_cap.bits.mcg_ctl_p;
    assert(ctl_p == 0);

    return 0;
}
