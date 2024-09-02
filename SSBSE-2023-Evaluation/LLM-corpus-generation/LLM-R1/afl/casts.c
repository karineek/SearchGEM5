// Modification timestamp: 2023-08-14 17:35:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//casts.c


#include <stdlib.h>
#include <stdio.h>

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#include <inttypes.h>
#ifndef PRId64
#define PRId64 "lld"
#define PRIu64 "llu"
#define PRIx64 "llx"
#endif

static int64_t lls[] = {
  123ULL, -1LL, -14LL, 14, 1ULL << 63, 0
};

int
main(int argc, char** argv)
{
  if (argc < 5) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  int8_t        C, c1;
  uint8_t       uc1;

  short         S, s1;
  unsigned short us1;

  int           i1, i;
  unsigned      ui1;

  int64_t       L, l1;
  uint64_t      ul1;

  float         F;
  double        D;

  /* input values */
  C = (char)  atoi(argv[1]);
  S = (short) atoi(argv[2]);
  L = (int64_t) atoll(argv[3]);

  /* Test integer to integer conversions */
  uc1 = (uint8_t) C;
  us1 = (unsigned short) C;
  ui1 = (unsigned int) C;
  ul1 = (uint64_t) C;

  s1  = (short) C;
  i1  = (int) C;
  l1  = (int64_t) C;

  printf("\nCHAR             C = '%c' (%d)\t\t(0x%x)\n", C, C, C);
  printf("char to short   s1 = %d\t\t(0x%x)\n", s1, s1);
  printf("char to int     i1 = %d\t\t(0x%x)\n", i1, i1);
  printf("char to int64_t l1 = %"PRId64"\t\t(0x%"PRIx64")\n", l1, l1);

  printf("\nchar to ubyte  uc1 = %u\t\t(0x%x)\n", uc1, uc1);
  printf("char to ushort us1 = %u\t\t(0x%x)\n", us1, us1);
  printf("char to uint   ui1 = %u\t\t(0x%x)\n", ui1, ui1);
  printf("char to uint64_t ul1 = %"PRIu64"\t\t(0x%"PRIx64")\n", ul1, ul1);

  uc1 = (uint8_t) S;
  us1 = (unsigned short) S;
  ui1 = (unsigned int) S;
  ul1 = (uint64_t) S;

  c1  = (int8_t) S;
  i1  = (int) S;
  l1  = (int64_t) S;

  printf("\n\nSHORT            S = %d\t\t(0x%x)\n", S, S);
  printf("short to byte    c1 = %d\t\t(0x%x)\n", c1, c1);
  printf("short to int     i1 = %d\t\t(0x%x)\n", i1, i1);
  printf("short to int64_t l1 = %"PRId64"\t\t(0x%"PRIx64")\n", l1, l1);

  printf("\nshort to ubyte  uc1 = %u\t\t(0x%x)\n", uc1, uc1);
  printf("short to ushort us1 = %u\t\t(0x%x)\n", us1, us1);
  printf("short to uint   ui1 = %u\t\t(0x%x)\n", ui1, ui1);
  printf("short to uint64_t ul1 = %"PRIu64"\t\t(0x%"PRIx64")\n", ul1, ul1);

  uc1 = (unsigned char) L;
  c1  = (int8_t) L;
  s1  = (short) L;
  us1 = (unsigned short) L;
  i1  = (int) L;
  ui1 = (unsigned int) L;
  ul1 = (uint64_t) L;

  printf("\n\nLONG            L = %"PRId64"\t\t(0x%"PRIx64")\n", L, L);
  printf("long to byte    c1 = %d\t\t(0x%x)\n", c1, c1);
  printf("long to short   s1 = %d\t\t(0x%x)\n", s1, s1);
  printf("long to int     i1 = %d\t\t(0x%x)\n", i1, i1);

  printf("\nlong to ubyte  uc1 = %u\t\t(0x%x)\n", uc1, uc1);
  printf("long to ushort us1 = %u\t\t(0x%x)\n", us1, us1);
  printf("long to uint   ui1 = %u\t\t(0x%x)\n", ui1, ui1);
  printf("long to uint64_t ul1 = %"PRIu64"\t\t(0x%"PRIx64")\n", ul1, ul1);

  /* Test floating-point to integer conversions */
  F = (float)  atof(argv[4]);
  D =          atof(argv[5]);

  us1 = (unsigned short) F;
  ui1 = (unsigned int) F;
  ul1 = (uint64_t) F;

  s1  = (short) F;
  i1  = (int) F;
  l1  = (int64_t) F;

  printf("\n\nFLOAT            F = %f\n", F);
  printf("float to short   s1 = %d\t\t(0x%x)\n", s1, s1);
  printf("float to int     i1 = %d\t\t(0x%x)\n", i1, i1);

  printf("float to ushort us1 = %u\t\t(0x%x)\n", us1, us1);
  printf("float to uint   ui1 = %u\t\t(0x%x)\n", ui1, ui1);
  printf("float to uint64_t ul1 = %"PRIu64"\t\t(0x%"PRIx64")\n", ul1, ul1);

  us1 = (unsigned short) D;
  ui1 = (unsigned int) D;
  ul1 = (uint64_t) D;

  s1  = (short) D;
  i1  = (int) D;
  l1  = (int64_t) D;

  printf("\n\nDOUBLE            D = %f\n", D);
  printf("double to short   s1 = %d\t\t(0x%x)\n", s1, s1);
  printf("double to int     i1 = %d\t\t(0x%x)\n", i1, i1);
  printf("double to int64_t l1 = %"PRId64"\t\t(0x%"PRIx64")\n", l1, l1);

  printf("double to ushort us1 = %u\t\t(0x%x)\n", us1, us1);
  printf("double to uint   ui1 = %u\t\t(0x%x)\n", ui1, ui1);
  printf("double to uint64_t ul1 = %"PRIu64"\t\t(0x%"PRIx64")\n", ul1, ul1);

  for (i = 0; lls[i]; ++i) {
    printf("double <- int64_t %"PRId64" = %f\n", lls[i], (double)lls[i]);
    printf("double <- uint64_t %"PRIu64" = %f\n",
           (uint64_t)lls[i], (double)(uint64_t)lls[i]);
  }

  return 0;
}
