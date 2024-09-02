// Modification timestamp: 2023-08-14 12:37:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021111-1.c

extern void abort (void);
extern void exit (int);

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type, int i);

int aim_callhandler(int sess, int conn, unsigned short family, unsigned short type, int i)
{
  if (!conn)
    return 0;

  if (type == 0xffff)
    {
      return 0;
    }

  if (i >= 1)
    abort ();

  i++;
  return aim_callhandler(sess, conn, family, (unsigned short) 0xffff, i);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int sess = atoi(argv[1]);
  int conn = atoi(argv[2]);
  unsigned short family = atoi(argv[3]);
  unsigned short type = atoi(argv[4]);
  int i = 0;

  aim_callhandler(sess, conn, family, type, i);
  exit (0);
}
