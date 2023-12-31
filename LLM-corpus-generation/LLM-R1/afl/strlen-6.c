// Modification timestamp: 2023-08-14 16:51:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strlen-6.c

#include <stdio.h>
#include <stdlib.h>

extern __SIZE_TYPE__ strlen(const char *);

unsigned nfails;

#define A(expr, N)                            \
  do {                                         \
    const char *_s = (expr);                   \
    unsigned _n = strlen(_s);                  \
    ((_n == N)                                  \
         ? 0                                     \
         : (__builtin_printf("line %i: strlen ((%s) = (\"%s\"))" \
                             " == %u failed\n", \
                             __LINE__, #expr, _s, N), \
            ++nfails));                          \
  } while (0)

volatile int i0 = 0;

const char ca[2][3] = {"12"};
const char cb[2][3] = {{'1', '2', '3',}, {'4'}};

char va[2][3] = {"123"};
char vb[2][3] = {{'1', '2', '3',}, {'4', '5'}};

const char *s = "123456";

static void test_binary_cond_expr_global(void)
{
    A(i0 ? "1" : ca[0], 2);
    A(i0 ? ca[0] : "123", 3);

    A(i0 ? "1" : cb[0], 4);
    A(i0 ? cb[0] : "12", 2);

    A(i0 ? "1" : va[0], 3);
    A(i0 ? va[0] : "1234", 4);

    A(i0 ? "1" : vb[0], 5);
    A(i0 ? vb[0] : "12", 2);
}

static void test_binary_cond_expr_local(void)
{
    const char lca[2][3] = {"12"};
    const char lcb[2][3] = {{'1', '2', '3',}, {'4'}};

    char lva[2][3] = {"123"};
    char lvb[2][3] = {{'1', '2', '3',}, {'4', '5'}};

    A(i0 ? "1" : lca[0], 2);
    A(i0 ? lca[0] : "123", 3);

    A(i0 ? "1" : lcb[0], 4);
    A(i0 ? lcb[0] : "12", 2);

    A(i0 ? "1" : lva[0], 3);
    A(i0 ? lva[0] : "1234", 4);

    A(i0 ? "1" : lvb[0], 5);
    A(i0 ? lvb[0] : "12", 2);
}

static void test_ternary_cond_expr(void)
{
    A(i0 == 0 ? s : i0 == 1 ? vb[0] : "123", 6);
    A(i0 == 0 ? vb[0] : i0 == 1 ? s : "123", 5);
    A(i0 == 0 ? "123" : i0 == 1 ? s : vb[0], 3);
}

const char (*pca)[3] = &ca[0];
const char (*pcb)[3] = &cb[0];

char (*pva)[3] = &va[0];
char (*pvb)[3] = &vb[0];

static void test_binary_cond_expr_arrayptr(void)
{
    A(i0 ? *pca : *pcb, 4);
    A(i0 ? *pcb : *pca, 2);

    A(i0 ? *pva : *pvb, 5);
    A(i0 ? *pvb : *pva, 3);
}

int main(void)
{
    test_binary_cond_expr_global();
    test_binary_cond_expr_local();

    test_ternary_cond_expr();
    test_binary_cond_expr_arrayptr();

    if (nfails)
        __builtin_abort();
}
