// Modification timestamp: 2023-08-04 14:20:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00132.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   printf("Hello world\n");

   int Count;
   for (Count = -5; Count <= 5; Count++)
      printf("Count = %d\n", Count);

   printf("String 'hello', 'there' is '%s', '%s'\n", "hello", "there");
   printf("Character 'A' is '%c'\n", atoi(argv[1]));
   printf("Character 'a' is '%c'\n", 'a');

   return 0;
}
