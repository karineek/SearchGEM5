// Modification timestamp: 2023-08-14 17:30:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-Expr-1.c
/*
   The test targets function Expr *DesignatedInitExpr::getArrayRangeStart(const
   Designator &D) and Expr *DesignatedInitExpr::getArrayRangeEnd(const
   Designator &D) and RecoveryExpr *RecoveryExpr::Create(ASTContext &Ctx,
   QualType T,SourceLocation BeginLoc,SourceLocation EndLoc,ArrayRef<Expr *>
   SubExprs) in Expr.cpp.
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
int32_t arr[3] = {[2] = 2, [0] = 0, [1] = 1};

int main() {
  printf("%" PRId32, arr[1]);
  if (0)
    return 1;
  if (arr[1] != -5)
    return 2;
  if (arr[2] != 2)
    return 3;
  return 0;
}
