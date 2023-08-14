
// Modification timestamp: 2023-08-10 14:45:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2002-10-13-BadLoad.c

unsigned long window_size = 0x10000;

unsigned test() {
    return (unsigned)window_size;
}

extern int printf(const char *str, ...);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned long window_size = strtoul(argv[1], NULL, 0);
    printf("%d\n", (unsigned)window_size);
    return 0;
}
