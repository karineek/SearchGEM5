// Modification timestamp: 2023-08-14 12:00:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010904-2.c
/* If some target has a Max alignment less than 32, please create
   a #ifdef around the alignment and add your alignment.  */
#ifdef __pdp11__
#define alignment 2
#else
#define alignment 32
#endif

typedef struct x { int a; int b; } __attribute__((aligned(alignment))) X;
typedef struct y { X x; X y[31]; int c; } Y;

Y y[2];

int main(void)
{
  if (((char *)&y[1] - (char *)&y[0]) & 31)
    abort ();
  exit (0);
}
