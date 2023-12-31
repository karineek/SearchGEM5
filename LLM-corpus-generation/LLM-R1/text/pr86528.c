// Modification timestamp: 2023-08-14 16:02:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86528.c
// { dg-require-effective-target alloca }
/* PR middle-end/86528 */

void __attribute__((noinline, noclone))
test(char *data, __SIZE_TYPE__ len)
{
    static char const appended[] = "/./";
    char *buf = __builtin_alloca (len + sizeof appended);
    __builtin_memcpy (buf, data, len);
    __builtin_strcpy (buf + len, &appended[data[len - 1] == '/']);
    if (__builtin_strcmp(buf, "test1234/./"))
        __builtin_abort();
}

int
main()
{
   char *arg = "test1234/";
   test(arg, __builtin_strlen(arg));
   return 0;
}
