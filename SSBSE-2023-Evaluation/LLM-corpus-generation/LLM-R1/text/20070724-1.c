// Modification timestamp: 2023-08-14 13:09:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070724-1.c
void abort (void);

static unsigned char magic[] = "\235";
static unsigned char value = '\235';

int main()
{
  if (value != magic[0])
    abort ();
  return 0;
}
