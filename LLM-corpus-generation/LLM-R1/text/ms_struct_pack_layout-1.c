// Modification timestamp: 2023-08-14 17:29:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct_pack_layout-1.c
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

int main (void)
{
  if (sizeof (struct s) != (sizeof (char) + sizeof (union u)))
    abort ();

  return 0;
}
