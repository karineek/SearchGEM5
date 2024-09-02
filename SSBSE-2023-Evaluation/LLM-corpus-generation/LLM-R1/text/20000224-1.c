
// Modification timestamp: 2023-08-10 16:16:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-02-24-1.c

int loop_1 = 100;
int loop_2 = 7;
int flag = 0;

int test(void) {
    int i;
    int counter = 0;

    while (loop_1 > counter) {
        if (flag & 1) {
            for (i = 0; i < loop_2; i++) {
                counter++;
            }
        }
        flag++;
    }
    return 1;
}

int main() {
    if (test() != 1)
        abort();

    exit(0);
}
