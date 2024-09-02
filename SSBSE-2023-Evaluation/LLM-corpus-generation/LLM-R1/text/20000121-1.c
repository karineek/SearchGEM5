
// Modification timestamp: 2023-08-10 16:15:07
// Original Source: https://github.com/llvm/llvm-test-suite

void big(long long u) { }

void doit(unsigned int a,unsigned int b,char *id)
{
  big(*id);
  big(a);
  big(b);
}

int main(void)
{
  doit(1,1,"\n");
  return 0;
}
