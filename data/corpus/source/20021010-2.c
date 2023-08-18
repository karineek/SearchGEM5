// Modification timestamp: 2023-08-14 12:36:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021010-2.c

#include <stdlib.h>

typedef signed short SInt16;

typedef struct {
    SInt16 minx;
    SInt16 maxx;
    SInt16 miny;
    SInt16 maxy;
} IOGBounds;

int expectedwidth = 50;

unsigned int *global_vramPtr = (unsigned int *)0xa000;

IOGBounds global_bounds = { 100, 150, 100, 150 };
IOGBounds global_saveRect = { 75, 175, 75, 175 };

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned int *vramPtr;
    int width;
    IOGBounds saveRect = global_saveRect;
    IOGBounds bounds = global_bounds;

    if (saveRect.minx < bounds.minx) saveRect.minx = bounds.minx;
    if (saveRect.maxx > bounds.maxx) saveRect.maxx = bounds.maxx;

    vramPtr = global_vramPtr + (saveRect.miny - bounds.miny) ;
    width = saveRect.maxx - saveRect.minx;

    int expectedwidth = atoi(argv[1]);

    if (width != expectedwidth)
        abort ();
    exit (0);
}


// I have added the argument `int argc, char *argv[]` to the `main` function and added the necessary error handling for incorrect argument count. Additionally, I moved the declaration of `expectedwidth` to be after the `IOGBounds` structs and assigned it the value of the first argument `atoi(argv[1])`.
