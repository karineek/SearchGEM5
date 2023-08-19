// Modification timestamp: 2023-08-14 14:56:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34176.c

typedef __SIZE_TYPE__ size_t;
typedef unsigned int index_ty;
typedef index_ty *index_list_ty;

struct mult_index
{
  index_ty index;
  unsigned int count;
};

struct mult_index_list
{
  struct mult_index *item;
  size_t nitems;
  size_t nitems_max;

  struct mult_index *item2;
  size_t nitems2_max;
};

int __attribute__((noinline))
hash_find_entry (size_t *result, int argc, char *argv[])
{
    *result = atoi(argv[1]);
    return 0;
}

extern void abort(void);

struct mult_index *__attribute__((noinline))
foo(size_t n, int argc, char *argv[])
{
    static int count = 0;
    if (count++ > 0)
        abort();
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    size_t nitems = 0;

    for (;;)
    {
        size_t list;

        hash_find_entry(&list, argc, argv);
        {
            size_t len2 = list;
            struct mult_index *destptr;
            struct mult_index *dest;
            size_t new_max = nitems + len2;

            if (new_max != len2)
                break;
            dest = foo(new_max, argc, argv);

            destptr = dest;
            while (len2--)
                destptr++;

            nitems = destptr - dest;
        }
    }

    return 0;
}
