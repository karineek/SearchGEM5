// Modification timestamp: 2023-08-14 13:55:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990531-1.c
   unsigned long bad(int reg, unsigned long inWord)
   {
       union {
           unsigned long word;
           unsigned char byte[4];
       } data;

       data.word = inWord;
       data.byte[reg] = 0;

       return data.word;
   }

main()
{
  /* XXX This test could be generalized.  */
  if (sizeof (long) != 4)
    exit (0);

  if (bad (0, 0xdeadbeef) == 0xdeadbeef)
    abort ();
  exit (0);
}
