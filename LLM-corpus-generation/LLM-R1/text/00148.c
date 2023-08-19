// Modification timestamp: 2023-08-04 14:24:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00148.c

struct S {int a; int b;};
struct S arr[2] = {[1] = {3, 4}, [0] = {1, 2}};

int main() {
    if(arr[0].a != 1)
        return 1;
    if(arr[0].b != 2)
        return 2;
    if(arr[1].a != 3)
        return 3;
    if(arr[1].b != 4)
        return 4;
    return 0;
}
