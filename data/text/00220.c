
// Modification timestamp: 2023-08-04 15:04:01
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00220.c

#include <stdio.h>
#include <wchar.h>

int main() {
    wchar_t s[] = L"hello$$你好¢¢世界€€world";
    wchar_t *p;
    for (p = s; *p; p++) printf("%04X ", (unsigned) *p);
    printf("\n");
    return 0;
}
