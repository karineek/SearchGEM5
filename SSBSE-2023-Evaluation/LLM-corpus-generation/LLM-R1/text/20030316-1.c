// Modification timestamp: 2023-08-14 12:43:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030316-1.c
/* PR target/9164 */
/* The comparison operand was sign extended erraneously.  */

int
main (void)
{
    long j = 0x40000000;
    if ((unsigned int) (0x40000000 + j) < 0L)
	abort ();

    return 0;
}
