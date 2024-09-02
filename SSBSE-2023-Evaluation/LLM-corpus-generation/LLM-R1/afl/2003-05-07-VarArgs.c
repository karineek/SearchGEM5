// Modification timestamp: 2023-08-14 17:12:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-07-VarArgs.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* 5 bytes. */
typedef struct DWordS_struct { int i; char c; } DWordS;

/* 12 bytes if d is 4-byte aligned; 16 bytes if d is 8-byte aligned. */
typedef struct QuadWordS_struct { int i; double d; } QuadWordS;

/* 20 bytes if d is 4-byte aligned; 28 bytes if d is 8-byte aligned
 * (assuming pointer size is 4 bytes and 8 bytes respectively). */
typedef struct LargeS_struct { int i; double d; DWordS* ptr; int j; } LargeS;

void test(int argc, char *argv[]) {
  va_list ap, aq;
  int d;
  char c, *s;
  DWordS dw;
  QuadWordS qw;
  LargeS ls;

  va_start(ap, argc);

  va_copy(aq, ap);    /* test va_copy */
  va_end(aq);

  int idx = 1;
  while (idx < argc) {
    char *fmt = argv[idx++];
    while (*fmt)
      switch(*fmt++) {
        case 's':           /* string */
          s = argv[idx++];
          printf("string %s\n", s);
          break;
        case 'i':           /* int */
          d = atoi(argv[idx++]);
          printf("int %d\n", d);
          break;
        case 'd':
          printf("double %f\n", atof(argv[idx++]));
          break;
        case 'l':
          printf("long long %lld\n", atoll(argv[idx++]));
          break;
        case 'c':           /* char */
          /* need a cast here since va_arg only
             takes fully promoted types */
          c = (char) atoi(argv[idx++]);
          printf("char %c\n", c);
          break;
        case 'D':
          dw.i = atoi(argv[idx++]);
          dw.c = (char) atoi(argv[idx++]);
          printf("DWord { %d, %c }\n", dw.i, dw.c);
          break;
        case 'Q':
          qw.i = atoi(argv[idx++]);
          qw.d = atof(argv[idx++]);
          printf("QuadWord { %d, %f }\n", qw.i, qw.d);
          break;
        case 'L':
          ls.i = atoi(argv[idx++]);
          ls.d = atof(argv[idx++]);
          ls.ptr = NULL;
          if (atoi(argv[idx++])) {
            dw.i = atoi(argv[idx++]);
            dw.c = (char) atoi(argv[idx++]);
            ls.ptr = &dw;
          }
          ls.j = atoi(argv[idx++]);
          printf("LargeS { %d, %f, 0x%d, %d }\n", ls.i, ls.d, ls.ptr != 0, ls.j);
          break;
      }
  }
  va_end(ap);
}

int main(int argc, char *argv[]) {
  DWordS dw = { 18, 'a' };
  QuadWordS qw = { 19, 20.0 };
  LargeS ls = { 21, 22.0, &dw, 23 };

  test(argc, argv);

  /* test promotion & 64-bit types */
  test(9, (char *[]){"ddil", "1.0", "2.0f", "32764", "12345677823423"});

  /* test passing structs by value to varargs */
  test(4, (char *[]){"DQL", "18", "97", "19", "20.0", "21", "22.0", "1", "23", "10 args done!"});

  return 0;
}
