// Modification timestamp: 2023-08-14 13:19:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20111208-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __SIZE_TYPE__ size_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;

void *memcpy(void *__restrict __dest, const void *__restrict __src, size_t __n) __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
size_t strlen(const char *__s) __attribute__((__nothrow__)) __attribute__((__pure__)) __attribute__((__nonnull__(1)));
void abort(void);

int a;

static void __attribute__((noinline, noclone)) do_something(int item)
{
    a = item;
}

int pack_unpack(char *s, char *p)
{
    char *send, *pend;
    char type;
    int integer_size;

    send = s + strlen(s);
    pend = p + strlen(p);

    while (p < pend)
    {
        type = *p++;

        switch (type)
        {
        case 's':
            integer_size = 2;
            goto unpack_integer;

        case 'l':
            integer_size = 4;
            goto unpack_integer;

        unpack_integer:
            switch (integer_size)
            {
            case 2:
            {
                union
                {
                    int16_t i;
                    char a[sizeof(int16_t)];
                } v;
                memcpy(v.a, s, sizeof(int16_t));
                s += sizeof(int16_t);
                do_something(v.i);
            }
            break;

            case 4:
            {
                union
                {
                    int32_t i;
                    char a[sizeof(int32_t)];
                } v;
                memcpy(v.a, s, sizeof(int32_t));
                s += sizeof(int32_t);
                do_something(v.i);
            }
            break;
            }
            break;
        }
    }
    return (int)*s;
}

int main(void)
{
    if (argc != 2)
    {
        printf("Usage: %s <s_value> <p_value>\n", argv[0]);
        return 1;
    }

    int n = pack_unpack(argv[1], argv[2]);
    if (n != 0)
        abort();
    return 0;
}
