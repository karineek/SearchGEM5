// Modification timestamp: 2023-08-14 14:23:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divcmp-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int test1(int x)
{
  return x/10 == 2;
}

int test1u(unsigned int x)
{
  return x/10U == 2;
}

int test2(int x)
{
  return x/10 == 0;
}

int test2u(unsigned int x)
{
  return x/10U == 0;
}

int test3(int x)
{
  return x/10 != 2;
}

int test3u(unsigned int x)
{
  return x/10U != 2;
}

int test4(int x)
{
  return x/10 != 0;
}

int test4u(unsigned int x)
{
  return x/10U != 0;
}

int test5(int x)
{
  return x/10 < 2;
}

int test5u(unsigned int x)
{
  return x/10U < 2;
}

int test6(int x)
{
  return x/10 < 0;
}

int test7(int x)
{
  return x/10  <= 2;
}

int test7u(unsigned int x)
{
  return x/10U <= 2;
}

int test8(int x)
{
  return x/10 <= 0;
}

int test8u(unsigned int x)
{
  return x/10U <= 0;
}

int test9(int x)
{
  return x/10 > 2;
}

int test9u(unsigned int x)
{
  return x/10U > 2;
}

int test10(int x)
{
  return x/10 > 0;
}

int test10u(unsigned int x)
{
  return x/10U > 0;
}

int test11(int x)
{
  return x/10 >= 2;
}

int test11u(unsigned int x)
{
  return x/10U >= 2;
}

int test12(int x)
{
  return x/10 >= 0;
}


int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  if (test1(atoi(argv[1])) != 0)
    abort ();
  if (test1(atoi(argv[2])) != 1)
    abort ();
  if (test1(atoi(argv[3])) != 1)
    abort ();
  if (test1(atoi(argv[4])) != 0)
    abort ();

  if (test1u(atoi(argv[5])) != 0)
    abort ();
  if (test1u(atoi(argv[6])) != 1)
    abort ();
  if (test1u(atoi(argv[7])) != 1)
    abort ();
  if (test1u(atoi(argv[8])) != 0)
    abort ();

  if (test2(atoi(argv[9])) != 1)
    abort ();
  if (test2(atoi(argv[10])) != 1)
    abort ();
  if (test2(atoi(argv[11])) != 0)
    abort ();
  if (test2(atoi(argv[12])) != 1)
    abort ();
  if (test2(atoi(argv[13])) != 1)
    abort ();
  if (test2(atoi(argv[14])) != 0)
    abort ();

  if (test2u(atoi(argv[15])) != 1)
    abort ();
  if (test2u(atoi(argv[16])) != 1)
    abort ();
  if (test2u(atoi(argv[17])) != 0)
    abort ();
  if (test2u(atoi(argv[18])) != 0)
    abort ();
  if (test2u(atoi(argv[19])) != 0)
    abort ();
  if (test2u(atoi(argv[20])) != 0)
    abort ();

  if (test3(atoi(argv[21])) != 1)
    abort ();
  if (test3(atoi(argv[22])) != 0)
    abort ();
  if (test3(atoi(argv[23])) != 0)
    abort ();
  if (test3(atoi(argv[24])) != 1)
    abort ();

  if (test3u(atoi(argv[25])) != 1)
    abort ();
  if (test3u(atoi(argv[26])) != 0)
    abort ();
  if (test3u(atoi(argv[27])) != 0)
    abort ();
  if (test3u(atoi(argv[28])) != 1)
    abort ();

  if (test4(atoi(argv[29])) != 0)
    abort ();
  if (test4(atoi(argv[30])) != 0)
    abort ();
  if (test4(atoi(argv[31])) != 1)
    abort ();
  if (test4(atoi(argv[32])) != 0)
    abort ();
  if (test4(atoi(argv[33])) != 0)
    abort ();
  if (test4(atoi(argv[34])) != 1)
    abort ();

  if (test4u(atoi(argv[35])) != 0)
    abort ();
  if (test4u(atoi(argv[36])) != 0)
    abort ();
  if (test4u(atoi(argv[37])) != 1)
    abort ();
  if (test4u(atoi(argv[38])) != 1)
    abort ();
  if (test4u(atoi(argv[39])) != 1)
    abort ();
  if (test4u(atoi(argv[40])) != 1)
    abort ();

  if (test5(atoi(argv[41])) != 1)
    abort ();
  if (test5(atoi(argv[42])) != 0)
    abort ();
  if (test5(atoi(argv[43])) != 0)
    abort ();
  if (test5(atoi(argv[44])) != 0)
    abort ();

  if (test5u(atoi(argv[45])) != 1)
    abort ();
  if (test5u(atoi(argv[46])) != 0)
    abort ();
  if (test5u(atoi(argv[47])) != 0)
    abort ();
  if (test5u(atoi(argv[48])) != 0)
    abort ();

  if (test6(atoi(argv[49])) != 0)
    abort ();
  if (test6(atoi(argv[50])) != 0)
    abort ();
  if (test6(atoi(argv[51])) != 0)
    abort ();
  if (test6(atoi(argv[52])) != 0)
    abort ();
  if (test6(atoi(argv[53])) != 0)
    abort ();
  if (test6(atoi(argv[54])) != 1)
    abort ();

  if (test7(atoi(argv[55])) != 1)
    abort ();
  if (test7(atoi(argv[56])) != 1)
    abort ();
  if (test7(atoi(argv[57])) != 1)
    abort ();
  if (test7(atoi(argv[58])) != 0)
    abort ();

  if (test7u(atoi(argv[59])) != 1)
    abort ();
  if (test7u(atoi(argv[60])) != 1)
    abort ();
  if (test7u(atoi(argv[61])) != 1)
    abort ();
  if (test7u(atoi(argv[62])) != 0)
    abort ();

  if (test8(atoi(argv[63])) != 1)
    abort ();
  if (test8(atoi(argv[64])) != 1)
    abort ();
  if (test8(atoi(argv[65])) != 0)
    abort ();
  if (test8(atoi(argv[66])) != 1)
    abort ();
  if (test8(atoi(argv[67])) != 1)
    abort ();
  if (test8(atoi(argv[68])) != 1)
    abort ();

  if (test8u(atoi(argv[69])) != 1)
    abort ();
  if (test8u(atoi(argv[70])) != 1)
    abort ();
  if (test8u(atoi(argv[71])) != 0)
    abort ();
  if (test8u(atoi(argv[72])) != 0)
    abort ();
  if (test8u(atoi(argv[73])) != 0)
    abort ();
  if (test8u(atoi(argv[74])) != 0)
    abort ();

  if (test9(atoi(argv[75])) != 0)
    abort ();
  if (test9(atoi(argv[76])) != 0)
    abort ();
  if (test9(atoi(argv[77])) != 0)
    abort ();
  if (test9(atoi(argv[78])) != 1)
    abort ();

  if (test9u(atoi(argv[79])) != 0)
    abort ();
  if (test9u(atoi(argv[80])) != 0)
    abort ();
  if (test9u(atoi(argv[81])) != 0)
    abort ();
  if (test9u(atoi(argv[82])) != 1)
    abort ();

  if (test10(atoi(argv[83])) != 0)
    abort ();
  if (test10(atoi(argv[84])) != 0)
    abort ();
  if (test10(atoi(argv[85])) != 1)
    abort ();
  if (test10(atoi(argv[86])) != 0)
    abort ();
  if (test10(atoi(argv[87])) != 0)
    abort ();
  if (test10(atoi(argv[88])) != 0)
    abort ();

  if (test10u(atoi(argv[89])) != 0)
    abort ();
  if (test10u(atoi(argv[90])) != 0)
    abort ();
  if (test10u(atoi(argv[91])) != 1)
    abort ();
  if (test10u(atoi(argv[92])) != 1)
    abort ();
  if (test10u(atoi(argv[93])) != 1)
    abort ();
  if (test10u(atoi(argv[94])) != 1)
    abort ();

  if (test11(atoi(argv[95])) != 0)
    abort ();
  if (test11(atoi(argv[96])) != 1)
    abort ();
  if (test11(atoi(argv[97])) != 1)
    abort ();
  if (test11(atoi(argv[98])) != 1)
    abort ();

  if (test11u(atoi(argv[99])) != 0)
    abort ();
  if (test11u(atoi(argv[100])) != 1)
    abort ();
  if (test11u(atoi(argv[101])) != 1)
    abort ();
  if (test11u(atoi(argv[102])) != 1)
    abort ();

  if (test12(atoi(argv[103])) != 1)
    abort ();
  if (test12(atoi(argv[104])) != 1)
    abort ();
  if (test12(atoi(argv[105])) != 1)
    abort ();
  if (test12(atoi(argv[106])) != 1)
    abort ();
  if (test12(atoi(argv[107])) != 1)
    abort ();
  if (test12(atoi(argv[108])) != 0)
    abort ();

  return 0;
}
