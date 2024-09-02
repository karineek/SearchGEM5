// Modification timestamp: 2023-08-04 13:52:39
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00062.c

#ifdef FOO
	XXX
#ifdef BAR
	XXX
#endif
	XXX
#endif

#define FOO 1

#ifdef FOO

#ifdef FOO
int x = 0;
#endif

int main()
{
	return x;
}
#endif
