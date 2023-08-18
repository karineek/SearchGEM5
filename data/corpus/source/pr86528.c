// Modification timestamp: 2023-08-14 16:02:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86528.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __attribute__((noinline, noclone))
test(char *data, __SIZE_TYPE__ len)
{
    if (len + sizeof(char) <= len) {
        printf("Buffer overflow detected!\n");
        return;
    }
    static char const appended[] = "/./";
    char *buf = (char*)malloc(len + sizeof appended);
    if (buf == NULL) {
        printf("Failed to allocate memory!\n");
        return;
    }
    memcpy(buf, data, len);
    strcpy(buf + len, &appended[data[len - 1] == '/']);
    if (strcmp(buf, "test1234/./"))
        abort();
    free(buf);
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char *arg = argv[1];
    test(arg, strlen(arg));
    return 0;
}
