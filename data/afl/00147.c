
// Modification timestamp: 2023-08-04 14:24:32
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00147.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int arr[3] = {[2] = atoi(argv[1]), [0] = atoi(argv[2]), [1] = atoi(argv[3])};

	if(arr[0] != 0)
		return 1;
	if(arr[1] != 1)
		return 2;
	if(arr[2] != 2)
		return 3;
	return 0;
}
