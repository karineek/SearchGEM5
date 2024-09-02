// Modification timestamp: 2023-08-14 13:55:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990525-2.c
typedef struct {
    int v[4];
} Test1;

Test1 func2();

int func1()
{
    Test1 test;
    test = func2();

    if (test.v[0] != 10)
      abort ();
    if (test.v[1] != 20)
      abort ();
    if (test.v[2] != 30)
      abort ();
    if (test.v[3] != 40)
      abort ();
}

Test1 func2()
{
    Test1 tmp;
    tmp.v[0] = 10;
    tmp.v[1] = 20;
    tmp.v[2] = 30;
    tmp.v[3] = 40;
    return tmp;
}


int main()
{
    func1();
    exit (0);
}
