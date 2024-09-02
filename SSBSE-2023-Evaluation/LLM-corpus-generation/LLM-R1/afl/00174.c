// Modification timestamp: 2023-08-04 14:32:21
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00174.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
   // variables
   float a = atof(argv[1]) + atof(argv[2]);
   printf("%f\n", a);

   // infix operators
   printf("%f\n", atof(argv[1]) + atof(argv[2]));
   printf("%f\n", atof(argv[1]) - atof(argv[2]));
   printf("%f\n", atof(argv[1]) * atof(argv[2]));
   printf("%f\n", atof(argv[1]) / atof(argv[2]));

   // comparison operators
   printf("%d %d %d %d %d %d\n", atof(argv[1]) < atof(argv[2]), atof(argv[1]) <= atof(argv[2]), atof(argv[1]) == atof(argv[2]), atof(argv[1]) >= atof(argv[2]), atof(argv[1]) > atof(argv[2]), atof(argv[1]) != atof(argv[2]));
   printf("%d %d %d %d %d %d\n", atof(argv[1]) < atof(argv[1]), atof(argv[1]) <= atof(argv[1]), atof(argv[1]) == atof(argv[1]), atof(argv[1]) >= atof(argv[1]), atof(argv[1]) > atof(argv[1]), atof(argv[1]) != atof(argv[1]));
   printf("%d %d %d %d %d %d\n", atof(argv[2]) < atof(argv[1]), atof(argv[2]) <= atof(argv[1]), atof(argv[2]) == atof(argv[1]), atof(argv[2]) >= atof(argv[1]), atof(argv[2]) > atof(argv[1]), atof(argv[2]) != atof(argv[1]));

   // assignment operators
   a = atof(argv[1]);
   a += atof(argv[2]);
   printf("%f\n", a);

   a = atof(argv[1]);
   a -= atof(argv[2]);
   printf("%f\n", a);

   a = atof(argv[1]);
   a *= atof(argv[2]);
   printf("%f\n", a);

   a = atof(argv[1]);
   a /= atof(argv[2]);
   printf("%f\n", a);

   // prefix operators
   printf("%f\n", +atof(argv[1]));
   printf("%f\n", -atof(argv[1]));

   // type coercion
   a = atof(argv[1]);
   printf("%f\n", a);
   printf("%f\n", sin(atof(argv[1])));

   return 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/
