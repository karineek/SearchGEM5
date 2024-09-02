// Modification timestamp: 2023-08-14 16:59:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-21.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef __GNUC__
#define __attribute__(x)
#endif

static void __attribute__ ((__format__ (__printf__, 1, 2)))
doit (const char *s, ...)
{
  va_list *ap_array[3], **ap_ptr = ap_array;

  ap_array[0] = malloc (sizeof(va_list));
  ap_array[1] = NULL;
  ap_array[2] = malloc (sizeof(va_list));

  va_start (*ap_array[0], s);
  vprintf (s, **ap_ptr);
  /* Increment the va_list pointer once.  */
  va_end (**ap_ptr++);

  /* Increment the va_list pointer a second time.  */
  ap_ptr++;

  va_start (*ap_array[2], s);
  /* If we failed to increment ap_ptr twice, then the parameter passed
     in here will dereference NULL and should cause a crash.  */
  vprintf (s, **ap_ptr);
  va_end (**ap_ptr);

  /* Just in case, If *ap_ptr is NULL abort anyway.  */
  if (*ap_ptr == 0)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  doit("%s", argv[1]);
  exit(0);
}
