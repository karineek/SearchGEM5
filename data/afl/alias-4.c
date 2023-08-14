// Modification timestamp: 2023-08-14 13:59:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-4.c

int a = 1;
extern int b;
int c = 1;
extern int d;
int main(int argc) {
    int *p;
    int *q;
    if (argc) {
        p = &a;
        q = &b;
    }
    else {
        p = &c;
        q = &d;
    }
    *p = 1;
    *q = 2;
    if (*p == 1)
        abort();
    return 0;
}
