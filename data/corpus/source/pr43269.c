// Modification timestamp: 2023-08-14 15:11:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43269.c

#include <stdio.h>
#include <stdlib.h>

int g_21;
int g_211;
int g_261;

static void __attribute__((noinline,noclone))
func_32 (int b, int* g_21, int* g_211, int* g_261)
{
  if (b) {
lbl_370:
      *g_21 = 1;
  }

  for (*g_261 = -1; *g_261 > -2; (*g_261)--) {
      if (*g_211 + 1) {
	  return;
      } else {
	  *g_21 = 1;
	  goto lbl_370;
      }
  }
}

extern void abort (void);

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[1]);
  func_32(b, &g_21, &g_211, &g_261);
  if (g_261 != -1)
    abort ();
  return 0;
}

//Note: I added the additional arguments to `func_32` for the global variables `g_21`, `g_211`, `g_261`.