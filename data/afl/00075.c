
// Modification timestamp: 2023-08-04 13:59:16
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00075.c

#include <stdio.h>
#include <stdlib.h>

#if (-2) != -2
#error fail
#endif

#if (0 || 0) != 0
#error fail
#endif

#if (1 || 0) != 1
#error fail
#endif

#if (1 || 1) != 1
#error fail
#endif

#if (0 && 0) != 0
#error fail
#endif

#if (1 && 0) != 0
#error fail
#endif

#if (0 && 1) != 0
#error fail
#endif

#if (1 && 1) != 1
#error fail
#endif

#if (0xf0 | 1) != 0xf1
#error fail
#endif

#if (0xf0 & 1) != 0
#error fail
#endif

#if (0xf0 & 0x1f) != 0x10
#error fail
#endif

#if (1 ^ 1) != 0
#error fail
#endif

#if (1 == 1) != 1
#error fail
#endif

#if (1 == 0) != 0
#error fail
#endif

#if (1 != 1) != 0
#error fail
#endif

#if (0 != 1) != 1
#error fail
#endif

#if (0 > 1) != 0
#error fail
#endif

#if (0 < 1) != 1
#error fail
#endif

#if (0 > -1) != 1
#error fail
#endif

#if (0 < -1) != 0
#error fail
#endif

#if (0 >= 1) != 0
#error fail
#endif

#if (0 <= 1) != 1
#error fail
#endif

#if (0 >= -1) != 1
#error fail
#endif

#if (0 <= -1) != 0
#error fail
#endif

#if (0 < 0) != 0
#error fail
#endif

#if (0 <= 0) != 1
#error fail
#endif

#if (0 > 0) != 0
#error fail
#endif

#if (0 >= 0) != 1
#error fail
#endif

#if (1 << 1) != 2
#error fail
#endif

#if (2 >> 1) != 1
#error fail
#endif

#if (2 + 1) != 3
#error fail
#endif

#if (2 - 3) != -1
#error fail
#endif

#if (2 * 3) != 6
#error fail
#endif

#if (6 / 3) != 2
#error fail
#endif

#if (7 % 3) != 1
#error fail
#endif

#if (2+2*3+2) != 10
#error fail
#endif

#if ((2+2)*(3+2)) != 20
#error fail
#endif

#if (2 + 2 + 2 + 2 == 2 + 2 * 3) != 1
#error fail
#endif

#if (0 ? 1 : 3) != 3
#error fail
#endif

#if (1 ? 3 : 1) != 3
#error fail
#endif

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <value>\n", argv[0]);
		return 1;
	}

	int x = atoi(argv[1]);
	return 0;
}
