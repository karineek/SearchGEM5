// Modification timestamp: 2023-08-14 14:26:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/enum-1.c

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  END = -1,
  EMPTY = (1 << 8 ),
  BACKREF,
  BEGLINE,
  ENDLINE,
  BEGWORD,
  ENDWORD,
  LIMWORD,
  NOTLIMWORD,
  QMARK,
  STAR,
  PLUS,
  REPMN,
  CAT,
  OR,
  ORTOP,
  LPAREN,
  RPAREN,
  CSET
} token;

static token tok;

static int atom(int tok)
{
  if ((tok >= 0 && tok < (1 << 8 )) || tok >= CSET || tok == BACKREF
      || tok == BEGLINE || tok == ENDLINE || tok == BEGWORD
      || tok == ENDWORD || tok == LIMWORD || tok == NOTLIMWORD)
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  tok = atoi(argv[1]);
  if (atom(tok) != 1)
    abort();
  exit(0);
}
