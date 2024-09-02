// Modification timestamp: 2023-08-14 13:48:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980223.c
typedef struct { char *addr; long type; } object;

object bar (object blah)
{
  abort();
}

object foo (object x, object y)
{
  object z = *(object*)(x.addr);
  if (z.type & 64)
    {
      y = *(object*)(z.addr+sizeof(object));
      z = *(object*)(z.addr);
      if (z.type & 64)
        y = bar(y);
    }
  return y;
}

int nil;
object cons1[2] = { {(char *) &nil, 0}, {(char *) &nil, 0} };
object cons2[2] = { {(char *) &cons1, 64}, {(char *) &nil, 0} };

main()
{
  object x = {(char *) &cons2, 64};
  object y = {(char *) &nil, 0};
  object three = foo(x,y);
  return 0;
}
