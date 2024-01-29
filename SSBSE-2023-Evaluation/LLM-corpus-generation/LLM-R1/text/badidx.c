// Modification timestamp: 2023-08-14 17:33:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//badidx.c
/* -*- mode: c -*-
 * $Id$
 * http://www.bagley.org/~doug/shootout/
 *
 * this program is modified from:
 *   http://cm.bell-labs.com/cm/cs/who/bwk/interps/pap.html
 * Timing Trials, or, the Trials of Timing: Experiments with Scripting
 * and User-Interface Languages</a> by Brian W. Kernighan and
 * Christopher J. Van Wyk.
 *
 * I added free() to deallocate memory.
 */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    int i, n = ((argc == 2) ? atoi(argv[1]) : 1);
    int *y = (int *) calloc(n, sizeof(int));
    for (i=0; i < n; i++)
      y[i] = i*i;
    printf("%d\n", y[n-1]);
    return(0);
}

