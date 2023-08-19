// Modification timestamp: 2023-08-14 15:12:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43835.c

#include <stdio.h>
#include <stdlib.h>

struct PMC {
    unsigned flags;
};

typedef struct Pcc_cell
{
    struct PMC *p;
    long bla;
    long type;
} Pcc_cell;

extern void abort ();
extern void Parrot_gc_mark_PMC_alive_fun(int * interp, struct PMC *pmc)
     __attribute__((noinline));

void Parrot_gc_mark_PMC_alive_fun (int * interp, struct PMC *pmc)
{
  abort ();
}

static void mark_cell(int * interp, Pcc_cell *c)
        __attribute__((__nonnull__(1)))
        __attribute__((__nonnull__(2)))
        __attribute__((noinline));

static void
mark_cell(int * interp, Pcc_cell *c)
{
    if (c->type == 4 && c->p
		&& !(c->p->flags & (1 << 18)))
        Parrot_gc_mark_PMC_alive_fun(interp, c->p);
}

void foo(int * interp, Pcc_cell *c);

void
foo(int * interp, Pcc_cell *c)
{
    mark_cell(interp, c);
}

int main(int argc, char *argv[]) {
    int i;

    if (argc != 4) {
        printf("Usage: %s <p_flags> <c_bla> <c_type>\n", argv[0]);
        return 1;
    }

    struct PMC *p = (struct PMC *)malloc(sizeof(struct PMC));
    p->flags = atoi(argv[1]);

    Pcc_cell c;
    c.p = p;
    c.bla = atoi(argv[2]);
    c.type = atoi(argv[3]);

    foo(&i, &c);

    free(p);
    return 0;
}
