// Modification timestamp: 2023-08-18 11:36:45
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-execs/00179.c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (argc != 2) {
      printf("Usage: %s <string>\n", argv[0]);
      return 1;
   }

   char a[10];

   strcpy(a, argv[1]);
   printf("%s\n", a);

   strncpy(a, "gosh", 2);
   printf("%s\n", a);

   printf("%d\n", strcmp(a, "apple") > 0);
   printf("%d\n", strcmp(a, "goere") > 0);
   printf("%d\n", strcmp(a, "zebra") < 0);

   printf("%d\n", strlen(a));

   strcat(a, "!");
   printf("%s\n", a);

   printf("%d\n", strncmp(a, "apple", 2) > 0);
   printf("%d\n", strncmp(a, "goere", 2) == 0);
   printf("%d\n", strncmp(a, "goerg", 2) == 0);
   printf("%d\n", strncmp(a, "zebra", 2) < 0);

   printf("%s\n", strchr(a, 'o'));
   printf("%s\n", strrchr(a, 'l'));
   printf("%d\n", strrchr(a, 'x') == NULL);

   memset(&a[1], 'r', 4);
   printf("%s\n", a);

   memcpy(&a[2], a, 2);
   printf("%s\n", a);

   printf("%d\n", memcmp(a, "apple", 4) > 0);
   printf("%d\n", memcmp(a, "grgr", 4) == 0);
   printf("%d\n", memcmp(a, "zebra", 4) < 0);

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/