// Modification timestamp: 2023-08-14 11:52:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001011-1.c
extern void abort(void);
extern int strcmp(const char *, const char *);

int foo(const char *a)
{
    return strcmp(a, "main");
}

int main(void)
{
    if(foo(__FUNCTION__))
        abort();
    return 0;
}
