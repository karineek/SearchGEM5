// Modification timestamp: 2023-08-14 12:42:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030203-1.c
void f(int);
int do_layer3(int single)
{
  int stereo1;

  if(single >= 0) /* stream is stereo, but force to mono */
    stereo1 = 1;
  else
    stereo1 = 2;
  f(single);

  return stereo1;
}

extern void abort ();
int main()
{
  if (do_layer3(-1) != 2)
    abort ();
  return 0;
}

void f(int i) {}
