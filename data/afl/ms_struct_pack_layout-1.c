
// Modification timestamp: 2023-08-10 15:45:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/ms_struct_pack_layout-1.c

#include <stdio.h>

extern void abort ();

union u
{
    int a;
} __attribute__((__ms_struct__, __packed__));

struct s
{
    char c;
    union u u;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg = atoi(argv[1]);
    
    if (sizeof(struct s) != (sizeof(char) + sizeof(union u)))
        abort();

    return arg;
}
