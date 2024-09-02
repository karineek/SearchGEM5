// Modification timestamp: 2023-08-14 12:47:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030715-1.c

#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *, const char *);
int ap_standalone;

const char *ap_check_cmd_context(void *a, int b)
{
    return 0;
}

const char *server_type(void *a, void *b, char *arg)
{
    const char *err = ap_check_cmd_context(a, 0x01 | 0x02 | 0x04 | 0x08 | 0x10);
    if (err)
        return err;

    int argc = 4;
    char *argv[4] = {"./a.out", "0", "0", arg};
    int x = atoi(argv[1]);

    if (!strcmp(arg, "inetd"))
        ap_standalone = 0;
    else if (!strcmp(arg, "standalone"))
        ap_standalone = 1;
    else
        return "ServerType must be either 'inetd' or 'standalone'";

    return 0;
}

int main()
{
    int argc = 1;
    char *argv[1] = {"./a.out"};
    server_type(0, 0, argv[argc]);
    return 0;
}
