// Modification timestamp: 2023-08-14 13:13:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080222-1.c
extern void abort (void);

struct container
{
  unsigned char data[1];
};

unsigned char space[6] = {1, 2, 3, 4, 5, 6};

int
foo (struct container *p)
{
  return p->data[4];
}

int
main ()
{
  if (foo ((struct container *) space) != 5)
    abort ();
  return 0;
}
