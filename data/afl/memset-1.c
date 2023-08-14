// Modification timestamp: 2023-08-14 14:37:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/memset-1.c

#include <string.h>
#include <stdlib.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof (long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY (10 * sizeof (long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof (long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
  char buf[MAX_LENGTH];
  long long align_int;
  long double align_fp;
} u;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int off, len, i;
  char *p, *q;
  char A = *argv[1];

  for (off = 0; off < MAX_OFFSET; off++) {
    for (len = 1; len < MAX_COPY; len++) {
      for (i = 0; i < MAX_LENGTH; i++)
        u.buf[i] = 'a';

      p = memset(u.buf + off, '\0', len);
      if (p != u.buf + off)
        abort();

      q = u.buf;
      for (i = 0; i < off; i++, q++) {
        if (*q != 'a')
          abort();
      }

      for (i = 0; i < len; i++, q++) {
        if (*q != '\0')
          abort();
      }

      for (i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a')
          abort();
      }

      p = memset(u.buf + off, A, len);
      if (p != u.buf + off)
        abort();

      q = u.buf;
      for (i = 0; i < off; i++, q++) {
        if (*q != 'a')
          abort();
      }

      for (i = 0; i < len; i++, q++) {
        if (*q != A)
          abort();
      }

      for (i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a')
          abort();
      }

      p = memset(u.buf + off, 'B', len);
      if (p != u.buf + off)
        abort();

      q = u.buf;
      for (i = 0; i < off; i++, q++) {
        if (*q != 'a')
          abort();
      }

      for (i = 0; i < len; i++, q++) {
        if (*q != 'B')
          abort();
      }

      for (i = 0; i < MAX_EXTRA; i++, q++) {
        if (*q != 'a')
          abort();
      }
    }
  }

  return 0;
}
