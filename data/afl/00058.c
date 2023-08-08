// Modification timestamp: 2023-08-04 13:51:32
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00058.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char * s;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    s = argv[1];
    if(s[0] != 'a') return 1;
    if(s[1] != 'b') return 2;
    if(s[2] != 'c') return 3;
    if(s[3] != 'd') return 4;
    if(s[4] != 'e') return 5;
    if(s[5] != 'f') return 6;
    if(s[6] != 0) return 7;

    return 0;
}
