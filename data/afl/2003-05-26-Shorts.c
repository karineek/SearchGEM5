// Modification timestamp: 2023-08-14 17:13:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-26-Shorts.c

#include <stdio.h>

unsigned long long getL(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        exit(1);
    }
    unsigned long long ul = strtoull(argv[1], NULL, 0);
    return ul;
}

int main(int argc, char *argv[]) {
    unsigned long long UL = getL(argc, argv);
    long long L = (long long)UL;

    unsigned int ui = (unsigned int)UL;
    int i = (int)UL;

    unsigned short us = (unsigned short)UL;
    short s = (short)UL;

    unsigned char ub = (unsigned char)UL;
    signed char b = (signed char)UL;

    printf("   ui = %u (0x%x)\t\tUL-ui = %lld (0x%llx)\n", ui, ui, UL - ui, UL - ui);
    printf("ui*ui = %u (0x%x)\t  UL/ui = %lld (0x%llx)\n\n", (unsigned int)ui * ui, (unsigned int)ui * ui, UL / ui, UL / ui);

    printf("    i = %d (0x%x)\tL-i = %lld (0x%llx)\n", i, i, L - i, L - i);
    printf(" i* i = %d (0x%x)\tL/ i = %lld (0x%llx)\n\n", (int)i * i, (int)i * i, L / i, L / i);

    printf("us    = %u (0x%x)\t\tUL-us = %lld (0x%llx)\n", us, us, UL - us, UL - us);
    printf("us*us = %u (0x%x)\t  UL/us = %lld (0x%llx)\n\n", (unsigned short)us * us, (unsigned short)us * us, UL / us, UL / us);

    printf(" s    = %d (0x%x)\tL-s = %lld (0x%llx)\n", s, s, L - s, L - s);
    printf(" s* s = %d (0x%x)\tL/ s = %lld (0x%llx)\n\n", (short)s * s, (short)s * s, L / s, L / s);

    printf("ub    = %u (0x%x)\t\tUL-ub = %lld (0x%llx)\n", ub, ub, UL - ub, UL - ub);
    printf("ub*ub = %u (0x%x)\t\tUL/ub = %lld (0x%llx)\n\n", (unsigned char)ub * ub, (unsigned char)ub * ub, UL / ub, UL / ub);

    printf(" b    = %d (0x%x)\t\tL-b = %lld (0x%llx)\n", b, b, L - b, L - b);
    printf(" b* b = %d (0x%x)\t\t\tL/b = %lld (0x%llx)\n\n", (signed char)b * b, (signed char)b * b, L / b, L / b);

    unsigned int uiprod = (ui + 1u) * (ui + 1u) - (unsigned int)(ui << 2) - (unsigned int)1u;
    unsigned short usprod = (us + 1u) * (us + 1u) - (unsigned short)(us << 2) - (unsigned short)1u;
    unsigned char ubprod = (ub + 1u) * (ub + 1u) - (unsigned char)(ub << 2) - (unsigned char)1u;

    int iprod = (i + 1) * (i + 1) - (int)(i << 2) - (int)1;
    short sprod = (s + 1) * (s + 1) - (short)(s << 2) - (short)1;
    signed char bprod = (b + 1) * (b + 1) - (char)(b << 2) - (char)1;

    unsigned int uidiv = (unsigned int)(UL / ui) * (unsigned int)(UL / ui);
    unsigned short usdiv = (unsigned short)(UL / us) * (unsigned short)(UL / us);
    unsigned char ubdiv = (unsigned char)(UL / ub) * (unsigned char)(UL / ub);

    int idiv = (int)(L / i) * (int)(L / i);
    short sdiv = (short)(L / s) * (short)(L / s);
    signed char bdiv = (signed char)(L / b) * (signed char)(L / b);

    printf("\n");
    printf("uiprod = %u (0x%x)\t  uidiv = %u (0x%x)\n\n", uiprod, uiprod, uidiv, uidiv);

    printf("usprod = %u (0x%x)\t  usdiv = %u (0x%x)\n\n", usprod, usprod, usdiv, usdiv);

    printf("ubprod = %u (0x%x)\t  ubdiv = %u (0x%x)\n\n", ubprod, ubprod, ubdiv, ubdiv);

    printf(" iprod = %u (0x%x)\t   idiv = %u (0x%x)\n\n", iprod, iprod, idiv, idiv);

    printf(" sprod = %u (0x%x)\t   sdiv = %u (0x%x)\n\n", sprod, sprod, sdiv, sdiv);

    printf(" bprod = %u (0x%x)\t   bdiv = %u (0x%x)\n\n", bprod, bprod, bdiv, bdiv);

    return 0;
}
