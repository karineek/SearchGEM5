// Modification timestamp: 2023-08-14 13:55:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990525-1.c
struct blah {
    int m1, m2;
};

void die(struct blah arg)
{
    int i ;
    struct blah buf[1];

    for (i = 0; i < 1 ; buf[i++] = arg)
        ;
    if (buf[0].m1 != 1) {
        abort ();
    }
}

int main()
{
    struct blah s = { 1, 2 };

    die(s);
    exit (0);
}
