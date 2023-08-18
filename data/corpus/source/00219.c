// Modification timestamp: 2023-08-18 11:50:10
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-execs/00219.c
#include <stdio.h>

const int a = 0;

struct a_type {
	int a;
};

struct b_type {
	int a;
};

int a_f()
{
	return 20;
}

int b_f()
{
	return 10;
}

typedef int (*fptr)(int);
int foo(int i)
{
  return i;
}

typedef int int_type1;

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, int: 123);

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

	int i = 0;
	signed long int l = 2;
	struct b_type titi;
	const int * const ptr;
	const char *ti;
	int_type1 i2;

	i = _Generic(a, int: a_f, const int: b_f)();
	printf("%d\n", i);
	i = _Generic(a, int: a_f() / 2, const int: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, int *:1, int * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, struct a_type:1, struct b_type:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, char: 1, int : 0);
	printf("%d\n", i);
	i = _Generic(a, char:1, int[4]:2, default:5);
