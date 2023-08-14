
// Modification timestamp: 2023-08-10 15:51:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/C/2003-05-14-initialize-string.c

extern int printf(const char *str, ...);

int main() {
    char title[] = "foo and stuff\n";
    printf("%s", title);
    return 0;
}
