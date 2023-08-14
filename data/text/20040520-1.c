// Modification timestamp: 2023-08-14 12:54:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040520-1.c
/* PR 15454 */

void abort ();
int main () {
        int foo;
        int bar (void)
        {
                int baz = 0;
                if (foo!=45)
                        baz = foo;
                return baz;
        }
        foo = 1;
        if (!bar ())
                abort ();
        return 0;
}
