// Modification timestamp: 2023-08-14 13:49:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-3.c
unsigned char lookup_table [257];

static int
build_lookup (pattern)
     unsigned char *pattern;
{
  int m;

  m = strlen (pattern) - 1;

  memset (lookup_table, ++m, 257);
  return m;
}

int main(argc, argv)
     int argc;
     char **argv;
{
  if (build_lookup ("bind") != 4)
    abort ();
  else
    exit (0);
}
