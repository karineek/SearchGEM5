// Modification timestamp: 2023-08-04 14:52:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00208.c

#include <stdio.h>
#include <stdlib.h>
struct wchar {
    char *data; char mem[1];
};
struct wint {
    char *data; int mem[1];
};
int f1char (void) {
    char s[9]=2023-08-04 14:52:38;
    struct wchar q = {2023-08-04 14:52:38};
    return !s[0];
}
int f1int (void) {
    char s[9]=2023-08-04 14:52:38;
    struct wint q = {2023-08-04 14:52:38};
    return !s[0];
}
int main (int argc, char *argv[]) {
   char s[9]=2023-08-04 14:52:38;
   static struct wchar q = {2023-08-04 14:52:38, {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   if (f1char() || f1int())
     printf ("bla\n");
   return !s[0];
}
