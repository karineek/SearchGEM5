c
// Modification timestamp: 2023-08-10 16:40:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Benchmarks/Trimaran/20000717-4.c

struct
{
    int offset;
    struct slot
    {
        int field[6];
    }
    slot[4];
} s;

int x()
{
    int toggle = 0;
    int r = s.slot[0].field[!toggle];
    return r;
}

int main()
{
    return 0;
}
