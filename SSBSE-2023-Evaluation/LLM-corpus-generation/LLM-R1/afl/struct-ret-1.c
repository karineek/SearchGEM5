// Modification timestamp: 2023-08-14 16:53:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ret-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char out[100];

typedef struct { double d; int i[3]; } B;
typedef struct { char c[sizeof(argv[1])],c1; } X;

char c1 = argv[1][0];
char c2 = atoi(argv[2]);
char c3 = atoi(argv[3]);
char c4 = atoi(argv[4]);
char c5 = atoi(argv[5]);

double d1 = atof(argv[6]);
double d2 = atof(argv[7]);
double d3 = atof(argv[8]);
double d4 = atof(argv[9]);
double d5 = atof(argv[10]);
double d6 = atof(argv[11]);
double d7 = atof(argv[12]);
double d8 = atof(argv[13]);
double d9 = atof(argv[14]);

B B1 = {atof(argv[15]),{atoi(argv[16]),atoi(argv[17]),atoi(argv[18])}};
B B2 = {atof(argv[19]),{atoi(argv[20]),atoi(argv[21]),atoi(argv[22])}};
X X1 = {argv[23], argv[24][0]};
X X2 = {argv[25], argv[26][0]};
X X3 = {argv[27], argv[28][0]};

X f (B a, char b, double c, B d)
{
  static X xr = {"return val", 'R'};
  X r;
  r = xr;
  r.c1 = b;
  sprintf (out, "X f(B,char,double,B):({%g,{%d,%d,%d}},'%c',%g,{%g,{%d,%d,%d}})",
	   a.d, a.i[0], a.i[1], a.i[2], b, c, d.d, d.i[0], d.i[1], d.i[2]);
  return r;
}

X (*fp) (B, char, double, B) = &f;

int main(int argc, char *argv[]) {
  X Xr;
  char tmp[100];

  Xr = f (B1, c2, d3, B2);
  strcpy (tmp, out);
  Xr.c[0] = Xr.c1 = '\0';
  Xr = (*fp) (B1, c2, d3, B2);
  if (strcmp (tmp, out))
    abort ();

  exit (0);
}
