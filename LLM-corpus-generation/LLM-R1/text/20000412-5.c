c
// Modification timestamp: 2023-08-10 16:30:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/OpenMP/20000412-5.c

int main( void ) {
    struct {
        int node;
        int type;
    } lastglob[1] = { { 0   , 1  } };

    if (lastglob[0].node != 0 || lastglob[0].type != 1)
        abort ();
    exit (0);
}
