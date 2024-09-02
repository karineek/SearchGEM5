// Modification timestamp: 2023-08-04 14:02:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00084.c

#define ARGS(...) __VA_ARGS__

int none()
{
    return 0;
}

int one(int a)
{
    if (a != 1)
        return 1;

    return 0;
}

int two(int a, int b)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;

    return 0;
}

int three(int a, int b, int c)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;
    if (c != 3)
        return 1;

    return 0;
}

int main()
{
    if (none())
        return 1;
    if (one(1))
        return 2;
    if (two(1, 2))
        return 3;
    if (three(1, 2, 3))
        return 4;
    return 0;
}
