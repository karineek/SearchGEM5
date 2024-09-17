// Modification timestamp: 2023-08-14 14:59:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36339.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef unsigned long my_uintptr_t;

int check_a(my_uintptr_t tagged_ptr);

int __attribute__((noinline)) try_a(my_uintptr_t x)
{
    my_uintptr_t heap[2];
    my_uintptr_t *hp = heap;

    hp[0] = x;
    hp[1] = 0;
    return check_a((my_uintptr_t)(void*)((char *)hp + 1));
}

int __attribute__((noinline)) check_a(my_uintptr_t tagged_ptr)
{
    my_uintptr_t *hp = (my_uintptr_t *)(void *)((char *)tagged_ptr - 1);

    if (hp[0] == atoi(argv[1]) && hp[1] == atoi(argv[2])) // Replace constants with argv assignments
        return 0;
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }
    
    if (try_a(atoi(argv[1])) < 0) // Replace constant with argv assignment
        abort();
    return 0;
}