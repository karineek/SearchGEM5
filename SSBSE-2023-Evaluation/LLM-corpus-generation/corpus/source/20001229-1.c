// Modification timestamp: 2023-08-14 11:55:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001229-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(char *a, char *b) { }

void showinfo(int argc, char *argv[])
{
    char uname[33] = "", tty[38] = "/dev/";
    foo(uname, tty);
}

int main(int argc, char *argv[])
{
#ifdef __alpha__
#ifdef __linux__
    unsigned int buf[2];
    buf[0] = SSIN_UACPROC;
    buf[1] = UAC_SIGBUS | UAC_NOPRINT;
    setsysinfo(SSI_NVPAIRS, buf, 1, 0, 0, 0);
#endif
#endif

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    showinfo(argc, argv);
    exit(0);
}
