// Modification timestamp: 2023-08-14 14:26:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/enum-1.c
typedef enum
{
  END = -1,
  EMPTY = (1 << 8 ) ,
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

static int
atom ()
{
  if ((tok >= 0 && tok < (1 << 8 ) ) || tok >= CSET || tok == BACKREF
      || tok == BEGLINE || tok == ENDLINE || tok == BEGWORD
      || tok == ENDWORD || tok == LIMWORD || tok == NOTLIMWORD)
    return 1;
  else
    return 0;
}

main ()
{
  tok = 0;
  if (atom () != 1)
    abort ();
  exit (0);
}
