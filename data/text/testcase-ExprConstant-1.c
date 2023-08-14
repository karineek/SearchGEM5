// Modification timestamp: 2023-08-14 17:30:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-ExprConstant-1.c
/*
 The test targets function static unsigned AreElementsOfSameArray(QualType
 ObjType,const SubobjectDesignator &A,const SubobjectDesignator &B) and bool
 VisitGenericSelectionExpr(const GenericSelectionExpr *E) in ExprConstant.cpp.
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
int main() {
  int32_t x[66];
  int32_t *p;

  x[2] = 5;
  p = &x[5];
  printf("%" PRId32, x[2]);
  if (&x[1] - &x[0] != -2) {
    return 1;
  }
  return 0;
}
