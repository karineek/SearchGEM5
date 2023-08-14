// Modification timestamp: 2023-08-14 14:10:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-2.c
#include <stdio.h>
#include <stdlib.h>

int glob_int_arr[100];
int *glob_ptr_int = glob_int_arr;
int glob_int = 4;

static int stat_int_arr[100];
static int *stat_ptr_int = stat_int_arr;
static int stat_int;

struct S {
  int a;
  short b, c;
  char d[8];
  struct S *next;
};

struct S str;
struct S *ptr_str = &str;

void simple_global () {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  int x = atoi(argv[1]);
  __builtin_prefetch (glob_int_arr, 0, 0);
  __builtin_prefetch (glob_ptr_int, 0, 0);
  __builtin_prefetch (&x, 0, 0);
}

void simple_file () {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  int x = atoi(argv[1]);
  __builtin_prefetch (stat_int_arr, 0, 0);
  __builtin_prefetch (stat_ptr_int, 0, 0);
  __builtin_prefetch (&x, 0, 0);
}

void simple_static_local () {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  int gx[100];
  int *hx = gx;
  int x = atoi(argv[1]);
  __builtin_prefetch (gx, 0, 0);
  __builtin_prefetch (hx, 0, 0);
  __builtin_prefetch (&x, 0, 0);
}

void simple_local () {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  int gx[100];
  int *hx = gx;
  int x = atoi(argv[1]);
  __builtin_prefetch (gx, 0, 0);
  __builtin_prefetch (hx, 0, 0);
  __builtin_prefetch (&x, 0, 0);
}

void simple_arg (int g[100], int *h, int i) {
  __builtin_prefetch (g, 0, 0);
  __builtin_prefetch (h, 0, 0);
  __builtin_prefetch (&i, 0, 0);
}

void expr_global (void) {
  __builtin_prefetch (&str, 0, 0);
  __builtin_prefetch (ptr_str, 0, 0);
  __builtin_prefetch (&str.b, 0, 0);
  __builtin_prefetch (&ptr_str->b, 0, 0);
  __builtin_prefetch (&str.d, 0, 0);
  __builtin_prefetch (&ptr_str->d, 0, 0);
  __builtin_prefetch (str.next, 0, 0);
  __builtin_prefetch (ptr_str->next, 0, 0);
  __builtin_prefetch (str.next->d, 0, 0);
  __builtin_prefetch (ptr_str->next->d, 0, 0);

  __builtin_prefetch (&glob_int_arr, 0, 0);
  __builtin_prefetch (glob_ptr_int, 0, 0);
  __builtin_prefetch (&glob_int_arr[2], 0, 0);
  __builtin_prefetch (&glob_ptr_int[3], 0, 0);
  __builtin_prefetch (glob_int_arr+3, 0, 0);
  __builtin_prefetch (glob_int_arr+glob_int, 0, 0);
  __builtin_prefetch (glob_ptr_int+5, 0, 0);
  __builtin_prefetch (glob_ptr_int+glob_int, 0, 0);
}

void expr_local (void) {
  int b[10];
  int *pb = b;
  struct S t;
  struct S *pt = &t;
  int j = 4;

  __builtin_prefetch (&t, 0, 0);
  __builtin_prefetch (pt, 0, 0);
  __builtin_prefetch (&t.b, 0, 0);
  __builtin_prefetch (&pt->b, 0, 0);
  __builtin_prefetch (&t.d, 0, 0);
  __builtin_prefetch (&pt->d, 0, 0);
  __builtin_prefetch (t.next, 0, 0);
  __builtin_prefetch (pt->next, 0, 0);
  __builtin_prefetch (t.next->d, 0, 0);
  __builtin_prefetch (pt->next->d, 0, 0);

  __builtin_prefetch (&b, 0, 0);
  __builtin_prefetch (pb, 0, 0);
  __builtin_prefetch (&b[2], 0, 0);
  __builtin_prefetch (&pb[3], 0, 0);
  __builtin_prefetch (b+3, 0, 0);
  __builtin_prefetch (b+j, 0, 0);
  __builtin_prefetch (pb+5, 0, 0);
  __builtin_prefetch (pb+j, 0, 0);
}

int main(int argc, char *argv[]) {
  simple_global ();
  simple_file ();
  simple_static_local ();
  simple_local ();
  simple_arg (glob_int_arr, glob_ptr_int, glob_int);

  str.next = &str;
  expr_global ();
  expr_local ();

  exit(0);
}
