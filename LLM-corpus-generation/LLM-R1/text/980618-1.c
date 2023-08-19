// Modification timestamp: 2023-08-14 13:50:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980618-1.c
void func(int, int);

int main()
{
        int x = 7;
        func(!x, !7);
	exit (0);
}

void func(int x, int y)
{
        if (x == y)
                return;
        else
                abort ();
}
