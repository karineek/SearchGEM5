c
// Modification timestamp: 2023-08-10 16:18:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/ASC_Sequoia/20000314-3.c

extern void abort(void);

static char arg0[] = "arg0";
static char arg1[] = "arg1";

static void attr_rtx(char *, char *);
static char *attr_string(char *);
static void attr_eq(char *, char *);

static void attr_rtx(char *varg0, char *varg1)
{
    if (varg0 != arg0)
        abort();

    if (varg1 != arg1)
        abort();

    return;
}

static void attr_eq(name, value)
    char *name, *value;
{
    return attr_rtx(attr_string(name),
                    attr_string(value));
}

static char *attr_string(str)
    char *str;
{
    return str;
}

int main()
{
    attr_eq(arg0, arg1);
    exit(0);
}
