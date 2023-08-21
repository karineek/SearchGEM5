//c
// Modification timestamp: 2023-08-10 16:37:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000706-2.c

extern void abort(void);
extern void exit(int);

struct baz {
    int a, b, c, d, e;
};

void bar(struct baz *x, int f, int g, int h, int i, int j)
{
    if (x->a != 1 || x->b != 2 || x->c != 3 || x->d != 4 || x->e != 5 ||
        f != 6 || g != 7 || h != 8 || i != 9 || j != 10)
        abort();
}

void foo(char *z, struct baz x, char *y)
{
    bar(&x, 6, 7, 8, 9, 10);
}

int main(int argc, char *argv[])
{
    struct baz x;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x.a = atoi(argv[1]);
    x.b = 2;
    x.c = 3;
    x.d = 4;
    x.e = 5;
    foo((char *)0, x, (char *)0);
    exit(0);
}
