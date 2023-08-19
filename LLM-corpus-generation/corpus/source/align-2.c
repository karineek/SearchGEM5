// Modification timestamp: 2023-08-14 13:59:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-2.c

#include <stdio.h>
#include <stdlib.h>

struct a_short { char c; short s; } s_c_s;
struct a_int { char c ; int i; } s_c_i;
struct b_int { short s; int i; } s_s_i;
struct a_float { char c; float f; } s_c_f;
struct b_float { short s; float f; } s_s_f;
struct a_double { char c; double d; } s_c_d;
struct b_double { short s; double d; } s_s_d;
struct c_double { int i; double d; } s_i_d;
struct d_double { float f; double d; } s_f_d;
struct a_ldouble { char c; long double ld; } s_c_ld;
struct b_ldouble { short s; long double ld; } s_s_ld;
struct c_ldouble { int i; long double ld; } s_i_ld;
struct d_ldouble { float f; long double ld; } s_f_ld;
struct e_ldouble { double d; long double ld; } s_d_ld;

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  s_c_s.c = 'a';
  s_c_s.s = 13;
  s_c_i.c = 'b';
  s_c_i.i = 14;
  s_s_i.s = 15;
  s_s_i.i = 16;
  s_c_f.c = 'c';
  s_c_f.f = 17.0;
  s_s_f.s = 18;
  s_s_f.f = 19.0;
  s_c_d.c = 'd';
  s_c_d.d = 20.0;
  s_s_d.s = 21;
  s_s_d.d = 22.0;
  s_i_d.i = 23;
  s_i_d.d = 24.0;
  s_f_d.f = 25.0;
  s_f_d.d = 26.0;
  s_c_ld.c = 'e';
  s_c_ld.ld = 27.0;
  s_s_ld.s = 28;
  s_s_ld.ld = 29.0;
  s_i_ld.i = 30;
  s_i_ld.ld = 31.0;
  s_f_ld.f = 32.0;
  s_f_ld.ld = 33.0;
  s_d_ld.d = 34.0;
  s_d_ld.ld = 35.0;

  if (s_c_s.c != 'a') abort ();
  if (s_c_s.s != 13) abort ();
  if (s_c_i.c != 'b') abort ();
  if (s_c_i.i != 14) abort ();
  if (s_s_i.s != 15) abort ();
  if (s_s_i.i != 16) abort ();
  if (s_c_f.c != 'c') abort ();
  if (s_c_f.f != 17.0) abort ();
  if (s_s_f.s != 18) abort ();
  if (s_s_f.f != 19.0) abort ();
  if (s_c_d.c != 'd') abort ();
  if (s_c_d.d != 20.0) abort ();
  if (s_s_d.s != 21) abort ();
  if (s_s_d.d != 22.0) abort ();
  if (s_i_d.i != 23) abort ();
  if (s_i_d.d != 24.0) abort ();
  if (s_f_d.f != 25.0) abort ();
  if (s_f_d.d != 26.0) abort ();
  if (s_c_ld.c != 'e') abort ();
  if (s_c_ld.ld != 27.0) abort ();
  if (s_s_ld.s != 28) abort ();
  if (s_s_ld.ld != 29.0) abort ();
  if (s_i_ld.i != 30) abort ();
  if (s_i_ld.ld != 31.0) abort ();
  if (s_f_ld.f != 32.0) abort ();
  if (s_f_ld.ld != 33.0) abort ();
  if (s_d_ld.d != 34.0) abort ();
  if (s_d_ld.ld != 35.0) abort ();

  return 0;
}
