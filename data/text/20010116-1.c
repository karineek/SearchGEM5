// Modification timestamp: 2023-08-14 11:55:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010116-1.c
/* Distilled from optimization/863.  */

extern void abort (void);
extern void exit (int);
extern void ok (int);

typedef struct
{
  int x, y, z;
} Data;

void find (Data *first, Data *last)
{
  int i;
  for (i = (last - first) >> 2; i > 0; --i)
    ok(i);
  abort ();
}

void ok(int i)
{
  if (i != 1)
    abort ();
  exit (0);
}

int
main ()
{
  Data DataList[4];
  find (DataList + 0, DataList + 4);
}
