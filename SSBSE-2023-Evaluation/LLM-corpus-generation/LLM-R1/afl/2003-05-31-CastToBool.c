// Modification timestamp: 2023-08-14 17:13:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-31-CastToBool.c

#include <stdio.h>

void testCastOps(int y) {
  printf("y = %d, (y == 2 || y == 0) == %d\n",
         y, ((_Bool) (y == atoi(argv[2]))) || ((_Bool) (y == atoi(argv[3]))));
  printf("y = %d, (y > 2 || y < 5) == %d\n",
         y, ((_Bool) (y < atoi(argv[4])))) && ((_Bool) (y > atoi(argv[5]))));
  printf("y = %d, (y ^ 2 ^ ~y) == %d\n",
         y, (_Bool) (y ^ atoi(argv[6])) ^ (~atoi(argv[7]))));
}

void testBool(_Bool X) {
  printf("%d\n", X);
}

void testByte(char X) {
  printf("%d ", X);
  testBool(X != atoi(argv[8]));
}

void testShort(short X) {
  printf("%d ", X);
  testBool(X != atoi(argv[9]));
}

void testInt(int X) {
  printf("%d ", X);
  testBool(X != atoi(argv[10]));
}

void testLong(long long X) {
  printf("%lld ", X);
  testBool(X != atoi(argv[11]));
}

int main(int argc, char *argv[]) {
  if (argc != 12) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7> <arg8> <arg9> <arg10> <arg11>\n", argv[0]);
    return 1;
  }

  testByte(atoi(argv[1]));
  testByte(atoi(argv[2]));
  testShort(atoi(argv[3]));
  testShort(atoi(argv[4]));
  testInt(atoi(argv[5]));
  testInt(atoi(argv[6]));
  testLong(atoi(argv[7]));
  testLong(atoi(argv[8]));
  testLong(atoi(argv[9]));
  testLong(atoi(argv[10]));
  testCastOps(atoi(argv[11]));
  return 0;
}
