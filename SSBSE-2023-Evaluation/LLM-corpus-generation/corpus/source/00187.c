// Modification timestamp: 2023-08-18 11:43:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-execs/00187.c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
   }

   FILE *f = fopen(argv[1], "w");
   fwrite("hello\nhello\n", 1, 12, f);
   fclose(f);

   char freddy[7];
   f = fopen(argv[1], "r");
   if (fread(freddy, 1, 6, f) != 6)
      printf("couldn't read %s\n", argv[1]);

   freddy[6] = '\0';
   fclose(f);

   printf("%s", freddy);

   int InChar;
   char ShowChar;
   f = fopen(argv[1], "r");
   while ( (InChar = fgetc(f)) != EOF)
   {
      ShowChar = InChar;
      if (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen(argv[1], "r");
   while ( (InChar = getc(f)) != EOF)
   {
      ShowChar = InChar;
      if (ShowChar < ' ')
         ShowChar = '.';

      printf("ch: %d '%c'\n", InChar, ShowChar);
   }
   fclose(f);

   f = fopen(argv[1], "r");
   while (fgets(freddy, sizeof(freddy), f) != NULL)
      printf("x: %s", freddy);

   fclose(f);

   return 0;
}