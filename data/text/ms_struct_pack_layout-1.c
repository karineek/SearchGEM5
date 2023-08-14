
// Modification timestamp: 2023-08-10 15:45:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/ms_struct_pack_layout-1.c

extern void abort ();

union u
{
    int a;
} __attribute__((__ms_struct__, __packed__));

struct s
{
    char c;
    union u u;
};

int main(void) {
    if (sizeof(struct s) != (sizeof(char) + sizeof(union u)))
        abort();

    return 0;
}
