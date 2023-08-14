// Modification timestamp: 2023-08-14 14:29:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ipa-sra-1.c
/* Trivially making sure IPA-SRA does not introduce segfaults where they should
   not be.  */

struct bovid
{
  float red;
  int green;
  void *blue;
};

static int
__attribute__((noinline))
ox (int fail, struct bovid *cow)
{
  int r;
  if (fail)
    r = cow->red;
  else
    r = 0;
  return r;
}

int main (int argc, char *argv[])
{
  int r;

  r = ox ((argc > 2000), (void *) 0);
  return r;
}
