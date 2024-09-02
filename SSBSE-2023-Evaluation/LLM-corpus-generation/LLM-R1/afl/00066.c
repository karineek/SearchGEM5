// Modification timestamp: 2023-08-04 13:55:22
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00066.c

#include <stdio.h>
#include <stdlib.h>

#define A 3
#define FOO(X,Y,Z) X + Y + Z
#define SEMI ;

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <arg1> <arg2> <arg3>\n", argv[0]);
        return 1;
    }

    if(FOO(argv[1], argv[2], A) != argv[3])
	return 1 SEMI
    return FOO(argv[4],argv[5],argv[6]);
}
