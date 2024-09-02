// Modification timestamp: 2023-08-14 15:50:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70602.c
/* PR tree-optimization/70602 */
/* { dg-require-effective-target int32plus } */

struct __attribute__((packed)) S
{
  int s : 1;
  int t : 20;
};

int a, b, c;

int
main ()
{
  for (; a < 1; a++)
    {
      struct S e[] = { {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9}, {0, 9}, {0, 9},
		       {0, 0}, {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9}, {0, 9},
		       {0, 9}, {0, 0}, {0, 9}, {0, 9}, {0, 9}, {0, 0}, {0, 9} };
      b = b || e[0].s;
      c = e[0].t;
    }
  return 0;
}
