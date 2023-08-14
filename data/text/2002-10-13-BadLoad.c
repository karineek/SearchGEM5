
// Modification timestamp: 2023-08-10 14:45:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-10-13-BadLoad.c

unsigned long window_size = 0x10000;

unsigned test() {
    return (unsigned)window_size;
}

extern int printf(const char *str, ...);

int main() {
    printf("%d\n", test());
    return 0;
}
