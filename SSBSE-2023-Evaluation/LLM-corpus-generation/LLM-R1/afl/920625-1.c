// Modification timestamp: 2023-08-14 13:28:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920625-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct { double x, y; } point;
point pts[] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0} };

static int va1(int nargs, ...)
{
    va_list args;
    int i;
    point pi;
    va_start(args, nargs);
    for (i = 0; i < nargs; i++) {
        pi = va_arg(args, point);
        if (pts[i].x != pi.x || pts[i].y != pi.y) {
            abort();
        }
    }
    va_end(args);
}

typedef struct { int x, y; } ipoint;
ipoint ipts[] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };

static int va2(int nargs, ...)
{
    va_list args;
    int i;
    ipoint pi;
    va_start(args, nargs);
    for (i = 0; i < nargs; i++) {
        pi = va_arg(args, ipoint);
        if (ipts[i].x != pi.x || ipts[i].y != pi.y) {
            abort();
        }
    }
    va_end(args);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int value = atoi(argv[1]);

    va1(4, (point){pts[0].x + value, pts[0].y + value},
            (point){pts[1].x + value, pts[1].y + value},
            (point){pts[2].x + value, pts[2].y + value},
            (point){pts[3].x + value, pts[3].y + value});

    va2(4, (ipoint){ipts[0].x + value, ipts[0].y + value},
            (ipoint){ipts[1].x + value, ipts[1].y + value},
            (ipoint){ipts[2].x + value, ipts[2].y + value},
            (ipoint){ipts[3].x + value, ipts[3].y + value});

    return 0;
}


Note that the above program assumes that the command-line argument is a single integer value.