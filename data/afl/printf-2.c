// Modification timestamp: 2023-08-14 16:06:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/printf-2.c
This program includes a function `write_file` that writes some characters and strings to a file using `printf`. The file is then read back to verify the contents.

Here's the modified version of the program with arguments in the `main` function:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__attribute__ ((noipa)) void
write_file (void)
{
  printf ("%c", *argv[1]);
  printf ("%c", *argv[2]);
  printf ("%c%c", *argv[3], *argv[4]);
  printf ("%s", argv[5]);
  printf ("%s%s", argv[6], argv[7]);
  printf ("%i", atoi(argv[8]));
  printf ("%.1s\n", argv[9]);
}


int main (int argc, char *argv[])
{
  char *tmpfname = tmpnam (0);
  FILE *f = freopen (tmpfname, "w", stdout);
  if (!f)
    {
      perror ("fopen for writing");
      return 1;
    }

  write_file ();
  fclose (f);

  f = fopen (tmpfname, "r");
  if (!f)
    {
      perror ("fopen for reading");
      remove (tmpfname);
      return 1;
    }

  char buf[12] = "";
  if (1 != fscanf (f, "%s", buf))
    {
      perror ("fscanf");
      fclose (f);
      remove (tmpfname);
      return 1;
    }

  fclose (f);
  remove (tmpfname);

  if (strcmp (buf, "123456789"))
    abort ();

  return 0;
}


Now, you can provide command-line arguments when running the program to replace the constants:


./program 1 2 3 4 5 6 7 8 9x
