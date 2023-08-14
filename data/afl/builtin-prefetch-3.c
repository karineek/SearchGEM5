// Modification timestamp: 2023-08-14 14:11:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-3.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  int a;
  short b, c;
  char d[8];
  struct S *next;
};

void simple_vol_global(volatile int *glob_vol_int_arr, int *volatile glob_vol_ptr_int, volatile int *glob_ptr_vol_int, volatile int *volatile glob_vol_ptr_vol_int, volatile int *glob_vol_int) {
  __builtin_prefetch(glob_vol_int_arr, 0, 0);
  __builtin_prefetch(glob_vol_ptr_int, 0, 0);
  __builtin_prefetch(glob_ptr_vol_int, 0, 0);
  __builtin_prefetch(glob_vol_ptr_vol_int, 0, 0);
  __builtin_prefetch(glob_vol_int, 0, 0);
}

void simple_vol_file(volatile int *stat_vol_int_arr, int *volatile stat_vol_ptr_int, volatile int *stat_ptr_vol_int, volatile int *volatile stat_vol_ptr_vol_int, volatile int *stat_vol_int) {
  __builtin_prefetch(stat_vol_int_arr, 0, 0);
  __builtin_prefetch(stat_vol_ptr_int, 0, 0);
  __builtin_prefetch(stat_ptr_vol_int, 0, 0);
  __builtin_prefetch(stat_vol_ptr_vol_int, 0, 0);
  __builtin_prefetch(stat_vol_int, 0, 0);
}

void expr_vol_global(struct S *vol_str, struct S *volatile *vol_ptr_str, volatile struct S **ptr_vol_str, volatile struct S **volatile vol_ptr_vol_str) {
  __builtin_prefetch(vol_str, 0, 0);
  __builtin_prefetch(*vol_ptr_str, 0, 0);
  __builtin_prefetch(*ptr_vol_str, 0, 0);
  __builtin_prefetch(*vol_ptr_vol_str, 0, 0);
  __builtin_prefetch(&vol_str->b, 0, 0);
  __builtin_prefetch(&(*vol_ptr_str)->b, 0, 0);
  __builtin_prefetch(&(*ptr_vol_str)->b, 0, 0);
  __builtin_prefetch(&(*vol_ptr_vol_str)->b, 0, 0);
  __builtin_prefetch(&vol_str->d, 0, 0);
  __builtin_prefetch(&(*vol_ptr_str)->d, 0, 0);
  __builtin_prefetch(&(*ptr_vol_str)->d, 0, 0);
  __builtin_prefetch(&(*vol_ptr_vol_str)->d, 0, 0);
  __builtin_prefetch(vol_str->next, 0, 0);
  __builtin_prefetch((*vol_ptr_str)->next, 0, 0);
  __builtin_prefetch((*ptr_vol_str)->next, 0, 0);
  __builtin_prefetch((*vol_ptr_vol_str)->next, 0, 0);
  __builtin_prefetch(vol_str->next->d, 0, 0);
  __builtin_prefetch((*vol_ptr_str)->next->d, 0, 0);
  __builtin_prefetch((*ptr_vol_str)->next->d, 0, 0);
  __builtin_prefetch((*vol_ptr_vol_str)->next->d, 0, 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile int glob_int_arr[100];
  int glob_int = atoi(argv[1]);
  volatile int glob_vol_int_arr[100];
  int *volatile glob_vol_ptr_int = glob_int_arr;
  volatile int *glob_ptr_vol_int = glob_vol_int_arr;
  volatile int *volatile glob_vol_ptr_vol_int = glob_vol_int_arr;
  volatile int glob_vol_int;

  static int stat_int_arr[100];
  static volatile int stat_vol_int_arr[100];
  static int *volatile stat_vol_ptr_int = stat_int_arr;
  static volatile int *stat_ptr_vol_int = stat_vol_int_arr;
  static volatile int *volatile stat_vol_ptr_vol_int = stat_vol_int_arr;
  static volatile int stat_vol_int;

  struct S str;
  volatile struct S vol_str;
  struct S *volatile vol_ptr_str = &str;
  volatile struct S *ptr_vol_str = &vol_str;
  volatile struct S *volatile vol_ptr_vol_str = &vol_str;

  simple_vol_global(glob_vol_int_arr, glob_vol_ptr_int, glob_ptr_vol_int, glob_vol_ptr_vol_int, &glob_vol_int);
  simple_vol_file(stat_vol_int_arr, stat_vol_ptr_int, stat_ptr_vol_int, stat_vol_ptr_vol_int, &stat_vol_int);

  str.next = &str;
  vol_str.next = &str;
  expr_vol_global(&vol_str, &vol_ptr_str, &ptr_vol_str, &vol_ptr_vol_str);

  return 0;
}
