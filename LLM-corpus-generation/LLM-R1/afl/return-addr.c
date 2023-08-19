// Modification timestamp: 2023-08-14 16:07:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/return-addr.c

#include <stdio.h>
#include <stdlib.h>

#define NOIPA __attribute__ ((noclone, noinline, noipa))

NOIPA char* get_max_2 (char *p)
{
  return p + 1;
}

NOIPA char* get_max_3 (char *p, char *q)
{
  return p < q ? q + 1 : p + 1;
}

NOIPA char* get_min_2 (char *p)
{
  return p - 1;
}

NOIPA char* get_min_3 (char *p, char *q)
{
  return p < q ? p - 1 : q - 1;
}

NOIPA void* test_max_2 (void)
{
  char c;

  char *p = get_max_2 (&c);

  void *q = p > &c ? p : &c;  /* MAX_EXPR */
  return q;
}

NOIPA void* test_max_3 (void)
{
  char c;
  char d;

  char *p = get_max_3 (&c, &d);

  void *q = p < &c ? &c < &d ? &d : &c : p;
  return q;
}

NOIPA void* test_min_2 (void)
{
  char c;

  char *p = get_min_2 (&c);

  void *q = p < &c ? p : &c;  /* MIN_EXPR" */
  return q;
}

NOIPA void* test_min_3 (void)
{
  char c;
  char d;

  char *p = get_min_3 (&c, &d);

  void *q = p > &c ? &c > &d ? &d : &c : p;
  return q;
}

NOIPA void* test_min_3_phi (int i)
{
  char a, b;

  char *p0 = &a;
  char *p1 = &b;
  char *p2 = get_min_3 (&a, &b);
  char *p3 = get_min_3 (&a, &b);

  char *p4 = p2 < p0 ? p2 : p0;
  char *p5 = p3 < p1 ? p3 : p1;

  printf("%p %p %p %p\n", p2, p3, p4, p5);

  if (i == 1)
    return p4;
  else
    return p5;
}

int main ()
{
  NOIPA void* result1 = test_max_2 ();
  NOIPA void* result2 = test_max_3 ();
  NOIPA void* result3 = test_min_2 ();
  NOIPA void* result4 = test_min_3 ();
  NOIPA void* result5 = test_min_3_phi (0);

  return 0;
}
