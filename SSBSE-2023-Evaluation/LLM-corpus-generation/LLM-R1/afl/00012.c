// Modification timestamp: 2023-08-03 10:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00012.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) { 
        printf("Usage: %s <value_1> <value_2> <value_3>\n", argv[0]); 
        return 1; 
    } 
    return (atoi(argv[1]) + atoi(argv[2])) * atoi(argv[3]) - 8; 
}
