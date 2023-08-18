// Modification timestamp: 2023-08-14 12:50:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031204-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long u32;

u32 in_aton(const char* x)
{
    return 0x0a0b0c0d;
}

u32 root_nfs_parse_addr(char *name)
{
    u32 addr;
    int octets = 0;
    char *cp, *cq;

    cp = cq = name;
    while (octets < 4) {
        while (*cp >= '0' && *cp <= '9')
            cp++;
        if (cp == cq || cp - cq > 3)
            break;
        if (*cp == '.' || octets == 3)
            octets++;
        if (octets < 4)
            cp++;
        cq = cp;
    }

    if (octets == 4 && (*cp == ':' || *cp == '\0')) {
        if (*cp == ':')
            *cp++ = '\0';
        addr = in_aton(name);
        strcpy(name, cp);
    } else
        addr = (-1);

    return addr;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <address>\n", argv[0]);
        return 1;
    }

    static char addr[64];
    strcpy(addr, argv[1]);

    u32 result = root_nfs_parse_addr(addr);
    if (result != 0x0a0b0c0d) { abort(); }
    return 0;
}
