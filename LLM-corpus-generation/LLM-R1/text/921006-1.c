// Modification timestamp: 2023-08-14 13:30:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921006-1.c
/* REPRODUCED:RUN:SIGNAL MACHINE:i386 OPTIONS:-O */
main()
{
if(strcmp("X","")<0)abort();
exit(0);
}
