// Modification timestamp: 2023-08-14 12:37:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021111-1.c
/* Origin: PR c/8467 */

extern void abort (void);
extern void exit (int);

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type);

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type)
{
  static int i = 0;

  if (!conn)
    return 0;

  if (type == 0xffff)
    {
      return 0;
    }

  if (i >= 1)
    abort ();

  i++;
  return aim_callhandler(sess, conn, family, (unsigned short) 0xffff);
}

int main (void)
{
  aim_callhandler (0, 1, 0, 0);
  exit (0);
}
