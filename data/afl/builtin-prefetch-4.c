// Modification timestamp: 2023-08-14 14:12:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-4.c

#include <stdio.h>
#include <stdlib.h>

int arr[100];
int *ptr = &arr[20];
int arrindex = 4;
int getptrcnt = 0;
int getintcnt = 0;

int assign_arg_ptr(int *p)
{
  int *q;
  __builtin_prefetch((q = p), 0, 0);
  return q == p;
}

int assign_glob_ptr()
{
  int *q;
  __builtin_prefetch((q = ptr), 0, 0);
  return q == ptr;
}

int assign_arg_idx(int *p, int i)
{
  int j;
  __builtin_prefetch(&p[j = i], 0, 0);
  return j == i;
}

int assign_glob_idx()
{
  int j;
  __builtin_prefetch(&ptr[j = arrindex], 0, 0);
  return j == arrindex;
}

int preinc_arg_ptr(int *p)
{
  int *q;
  q = p + 1;
  __builtin_prefetch(++p, 0, 0);
  return p == q;
}

int preinc_glob_ptr()
{
  int *q;
  q = ptr + 1;
  __builtin_prefetch(++ptr, 0, 0);
  return ptr == q;
}

int postinc_arg_ptr(int *p)
{
  int *q;
  q = p + 1;
  __builtin_prefetch(p++, 0, 0);
  return p == q;
}

int postinc_glob_ptr()
{
  int *q;
  q = ptr + 1;
  __builtin_prefetch(ptr++, 0, 0);
  return ptr == q;
}

int predec_arg_ptr(int *p)
{
  int *q;
  q = p - 1;
  __builtin_prefetch(--p, 0, 0);
  return p == q;
}

int predec_glob_ptr()
{
  int *q;
  q = ptr - 1;
  __builtin_prefetch(--ptr, 0, 0);
  return ptr == q;
}

int postdec_arg_ptr(int *p)
{
  int *q;
  q = p - 1;
  __builtin_prefetch(p--, 0, 0);
  return p == q;
}

int postdec_glob_ptr()
{
  int *q;
  q = ptr - 1;
  __builtin_prefetch(ptr--, 0, 0);
  return ptr == q;
}

int preinc_arg_idx(int *p, int i)
{
  int j = i + 1;
  __builtin_prefetch(&p[++i], 0, 0);
  return i == j;
}

int preinc_glob_idx()
{
  int j = arrindex + 1;
  __builtin_prefetch(&ptr[++arrindex], 0, 0);
  return arrindex == j;
}

int postinc_arg_idx(int *p, int i)
{
  int j = i + 1;
  __builtin_prefetch(&p[i++], 0, 0);
  return i == j;
}

int postinc_glob_idx()
{
  int j = arrindex + 1;
  __builtin_prefetch(&ptr[arrindex++], 0, 0);
  return arrindex == j;
}

int predec_arg_idx(int *p, int i)
{
  int j = i - 1;
  __builtin_prefetch(&p[--i], 0, 0);
  return i == j;
}

int predec_glob_idx()
{
  int j = arrindex - 1;
  __builtin_prefetch(&ptr[--arrindex], 0, 0);
  return arrindex == j;
}

int postdec_arg_idx(int *p, int i)
{
  int j = i - 1;
  __builtin_prefetch(&p[i--], 0, 0);
  return i == j;
}

int postdec_glob_idx()
{
  int j = arrindex - 1;
  __builtin_prefetch(&ptr[arrindex--], 0, 0);
  return arrindex == j;
}

int *getptr(int *p)
{
  getptrcnt++;
  return p + 1;
}

int getint(int i)
{
  getintcnt++;
  return i + 1;
}

int funccall_arg_ptr(int *p)
{
  __builtin_prefetch(getptr(p), 0, 0);
  return getptrcnt == 1;
}

int funccall_arg_idx(int *p, int i)
{
  __builtin_prefetch(&p[getint(i)], 0, 0);
  return getintcnt == 1;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int *arg_ptr = atoi(argv[1]) + &arr[20];
  int arg_idx = atoi(argv[1]);

  if (!assign_arg_ptr(arg_ptr))
    abort();
  if (!assign_glob_ptr())
    abort();
  if (!assign_arg_idx(arg_ptr, arg_idx))
    abort();
  if (!assign_glob_idx())
    abort();
  if (!preinc_arg_ptr(arg_ptr))
    abort();
  if (!preinc_glob_ptr())
    abort();
  if (!postinc_arg_ptr(arg_ptr))
    abort();
  if (!postinc_glob_ptr())
    abort();
  if (!predec_arg_ptr(arg_ptr))
    abort();
  if (!predec_glob_ptr())
    abort();
  if (!postdec_arg_ptr(arg_ptr))
    abort();
  if (!postdec_glob_ptr())
    abort();
  if (!preinc_arg_idx(arg_ptr, arg_idx))
    abort();
  if (!preinc_glob_idx())
    abort();
  if (!postinc_arg_idx(arg_ptr, arg_idx))
    abort();
  if (!postinc_glob_idx())
    abort();
  if (!predec_arg_idx(arg_ptr, arg_idx))
    abort();
  if (!predec_glob_idx())
    abort();
  if (!postdec_arg_idx(arg_ptr, arg_idx))
    abort();
  if (!postdec_glob_idx())
    abort();
  if (!funccall_arg_ptr(arg_ptr))
    abort();
  if (!funccall_arg_idx(arg_ptr, arg_idx))
    abort();
  return 0;
}

