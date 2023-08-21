
// Modification timestamp: 2023-08-10 16:32:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000422-1.c

#include <stdlib.h>

int ops[13] =
{
  11, 12, 46, 3, 2, 2, 3, 2, 1, 3, 2, 1, 2
};

int correct[13] =
{
  46, 12, 11, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1
};

int num = 13;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int ops[13] =
  {
    atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1]), atoi(argv[1])
  };

  int i;

  for (i = 0; i < num; i++)
    {
      int j;

      for (j = num - 1; j > i; j--)
        {
          if (ops[j-1] < ops[j])
            {
              int op = ops[j];
              ops[j] = ops[j-1];
              ops[j-1] = op;
            }
        }
    }


  for (i = 0; i < num; i++)
    if (ops[i] != correct[i])
      abort ();

  exit (0);
}
