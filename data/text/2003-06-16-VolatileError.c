c
// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Regression/C/2003-06-16-VolatileError.c

/* This crashes the CFE.  */
extern int volatile test;
int volatile test = 0;

int main() { 
    return 0; 
}
