
#include <stdio.h>
#include <stdlib.h>

int Array[];
int Array[32];
int Foo;            /* If writing to the wrong "Array", this will get clobbered */

int main(int argc, char *argv[]) {
    unsigned i;
    for (i = 0; i != 32; ++i)
        Array[i] = 5;

    printf("%d\n", Foo);
    return 0;
}
