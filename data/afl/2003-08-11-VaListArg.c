// Modification timestamp: 2023-08-14 17:15:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-08-11-VaListArg.c

#include <stdio.h>
#include <stdarg.h>

/* 5 bytes. */
typedef struct DWordS_struct {
  int i;
  char c;
} DWordS;

/* 12 bytes if d is 4-byte aligned; 16 bytes if d is 8-byte aligned. */
typedef struct QuadWordS_struct {
  int i;
  double d;
} QuadWordS;

/* 20 bytes if d is 4-byte aligned; 28 bytes if d is 8-byte aligned
 * (assuming pointer size is 4 bytes and 8 bytes respectively). */
typedef struct LargeS_struct {
  int i;
  double d;
  DWordS *ptr;
  int j;
} LargeS;

void test(char *fmt, int argc, char *argv[]) {
  int d;
  char c, *s;
  DWordS dw;
  QuadWordS qw;
  LargeS ls;

  int argIndex = 1;
  while (*fmt) {
    switch (*fmt++) {
      case 's': /* string */
        s = argv[argIndex++];
        printf("string %s\n", s);
        break;
      case 'i': /* int */
        d = atoi(argv[argIndex++]);
        printf("int %d\n", d);
        break;
      case 'd':
        printf("double %f\n", atof(argv[argIndex++]));
        break;
      case 'l':
        printf("long long %lld\n", atoll(argv[argIndex++]));
        break;
      case 'c': /* char */
        c = argv[argIndex++][0];
        printf("char %c\n", c);
        break;
      case 'D':
        dw.i = atoi(argv[argIndex++]);
        dw.c = argv[argIndex++][0];
        printf("DWord { %d, %c }\n", dw.i, dw.c);
        break;
      case 'Q':
        qw.i = atoi(argv[argIndex++]);
        qw.d = atof(argv[argIndex++]);
        printf("QuadWord { %d, %f }\n", qw.i, qw.d);
        break;
      case 'L':
        ls.i = atoi(argv[argIndex++]);
        ls.d = atof(argv[argIndex++]);
        ls.ptr = (DWordS *)atoll(argv[argIndex++]);
        ls.j = atoi(argv[argIndex++]);
        printf("LargeS { %d, %f, 0x%d, %d }\n", ls.i, ls.d, ls.ptr != NULL, ls.j);
        break;
    }
  }
}

void testVaListArg(int argc, char *argv[], char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  test(fmt, argc, argv);
  va_end(ap);
}

void testVaCopyArg(int argc, char *argv[], char *fmt, ...) {
  va_list ap, aq;
  va_start(ap, fmt);
  va_copy(aq, ap); /* test va_copy */
  test(fmt, argc, argv);
  va_end(aq);
  va_end(ap);
}

int main(int argc, char *argv[]) {
  DWordS dw = {18, 'a'};
  QuadWordS qw = {19, 20.0};
  LargeS ls = {21, 22.0, &dw, 23};

  testVaListArg(argc, argv, "ssiciiiiis", "abc", "def", "-123", "a", "123", "6", "7", "8", "9", "10 args done!");
  testVaCopyArg(argc, argv, "ssiciiiiis", "abc", "def", "-123", "a", "123", "6", "7", "8", "9", "10 args done!");

  /* test promotion & 64-bit types */
  testVaListArg(argc, argv, "ddil", "1.0", "2.0", "32764", "12345677823423");
  testVaCopyArg(argc, argv, "ddil", "1.0", "2.0", "32764", "12345677823423");

  /* test passing structs by value to varargs */
  char dwi[12], dwc[12];
  sprintf(dwi, "%d", dw.i);
  sprintf(dwc, "%c", dw.c);
  char qwi[12], qwd[12];
  sprintf(qwi, "%d", qw.i);
  sprintf(qwd, "%f", qw.d);
  char lsi[12], lsd[12], lsptr[12], lsj[12];
  sprintf(lsi, "%d", ls.i);
  sprintf(lsd, "%f", ls.d);
  sprintf(lsptr, "%lld", (long long)ls.ptr);
  sprintf(lsj, "%d", ls.j);

  testVaListArg(argc, argv, "DQL", dwi, dwc, qwi, qwd, lsi, lsd, lsptr, lsj);
  testVaCopyArg(argc, argv, "DQL", dwi, dwc, qwi, qwd, lsi, lsd, lsptr, lsj);

  return 0;
}

Please note that the command line arguments `argv` are passed to the main function as parameters, and `argc` is the count of those arguments. To compile and run the code, you can use the following command:


gcc filename.c -o output
./output <arguments>
