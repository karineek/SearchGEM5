// Modification timestamp: 2023-08-14 15:01:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38048-2.c

extern void abort(void);

static int inv_J(int a[][2])
{
    int i, j;
    int det = 0.0;
    for (j = 0; j < 2; ++j)
        det += a[j][0] + a[j][1];
    return det;
}

int foo(int a_0_0, int a_0_1, int a_1_0, int a_1_1)
{
    int mat[2][2];
    mat[0][0] = a_0_0;
    mat[0][1] = a_0_1;
    mat[1][0] = a_1_0;
    mat[1][1] = a_1_1;
    return inv_J(mat);
}

int main()
{
    if (foo(1, 2, 4, 8) != 15)
        abort();
    return 0;
}

