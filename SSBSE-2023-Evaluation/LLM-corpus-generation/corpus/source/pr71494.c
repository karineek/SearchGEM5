// Modification timestamp: 2023-08-14 15:51:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71494.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    void *label = &&out;
    int i = 0;
    
    void test(void)
    {
        label = &&out2;
        goto *label;
        out2:
        i++;
    }
    
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    goto *label;
    
    out:
    i += 2;
    test();
    
    if (i != 3)
        __builtin_abort();
    
    return 0;
}


//Note: Since the original code does not have any constants or string literals in the main function, there are no substitutions to be made.