// Modification timestamp: 2023-08-04 14:25:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00152.c

#undef  line
#define line 1000

#line line
#if 1000 != __LINE__
	#error "  # line line" not work as expected
#endif

int main() {
    return 0;
}
