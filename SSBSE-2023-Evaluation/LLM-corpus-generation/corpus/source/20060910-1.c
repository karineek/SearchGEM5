// Modification timestamp: 2023-08-14 13:07:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060910-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct input_ty
{
  unsigned char *buffer_position;
  unsigned char *buffer_end;
};

int input_getc_complicated(struct input_ty *x) { return 0; }

int check_header(struct input_ty *deeper)
{
  unsigned len;
  for (len = 0; len < 6; len++)
    if (((deeper)->buffer_position < (deeper)->buffer_end
         ? *((deeper)->buffer_position)++
         : input_getc_complicated((deeper))) < 0)
      return 0;
  return 1;
}

struct input_ty s;
unsigned char b[6];

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s.buffer_position = argv[1];
  s.buffer_end = argv[1] + 6;
  if (!check_header(&s))
    abort();
  if (s.buffer_position != s.buffer_end)
    abort();
  return 0;
}
