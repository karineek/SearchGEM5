// Modification timestamp: 2023-08-14 14:58:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35800.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int stab_xcoff_builtin_type(int typenum) {
  const char *name;
  if (typenum >= 0 || typenum < -34) {
    return 0;
  }
  switch (-typenum) {
    case 1:
      name = "int";
      break;
    case 2:
      name = "char";
      break;
    case 3:
      name = "short";
      break;
    case 4:
      name = "long";
      break;
    case 5:
      name = "unsigned char";
      break;
    case 6:
      name = "signed char";
      break;
    case 7:
      name = "unsigned short";
      break;
    case 8:
      name = "unsigned int";
      break;
    case 9:
      name = "unsigned";
      break;
    case 10:
      name = "unsigned long";
      break;
    case 11:
      name = "void";
      break;
    case 12:
      name = "float";
      break;
    case 13:
      name = "double";
      break;
    case 14:
      name = "long double";
      break;
    case 15:
      name = "integer";
      break;
    case 16:
      name = "boolean";
      break;
    case 17:
      name = "short real";
      break;
    case 18:
      name = "real";
      break;
    case 19:
      name = "stringptr";
      break;
    case 20:
      name = "character";
      break;
    case 21:
      name = "logical*1";
      break;
    case 22:
      name = "logical*2";
      break;
    case 23:
      name = "logical*4";
      break;
    case 24:
      name = "logical";
      break;
    case 25:
      name = "complex";
      break;
    case 26:
      name = "double complex";
      break;
    case 27:
      name = "integer*1";
      break;
    case 28:
      name = "integer*2";
      break;
    case 29:
      name = "integer*4";
      break;
    case 30:
      name = "wchar";
      break;
    case 31:
      name = "long long";
      break;
    case 32:
      name = "unsigned long long";
      break;
    case 33:
      name = "logical*8";
      break;
    case 34:
      name = "integer*8";
      break;
    default:
      name = "";
      break;
  }
  return name[0];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  if (stab_xcoff_builtin_type(atoi(argv[1])) != 0)
    abort();
  if (stab_xcoff_builtin_type(-1) != 'i')
    abort();
  if (stab_xcoff_builtin_type(-2) != 's')
    abort();
  if (stab_xcoff_builtin_type(-3) != 's')
    abort();
  for (i = -4; i >= -34; --i)
    if (stab_xcoff_builtin_type(i) != 'i')
      abort();
  if (stab_xcoff_builtin_type(-35) != 0)
    abort();
  return 0;
}

