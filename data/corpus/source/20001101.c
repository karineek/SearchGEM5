// Modification timestamp: 2023-08-14 11:53:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001101.c

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int unchanging : 1;
} struc, *rtx;

rtx dummy(int *a, rtx *b)
{
  *a = atoi(argv[1]);
  *b = (rtx)atoi(argv[2]);
  return (rtx)atoi(argv[3]);
}

void bogus(insn, thread, delay_list)
     rtx insn;
     rtx thread;
     rtx delay_list;
{
  rtx new_thread;
  int must_annul;

  delay_list = dummy(&must_annul, &new_thread);
  if (delay_list == 0 && new_thread)
  {
    thread = new_thread;
  }
  if (delay_list && must_annul)
    insn->unchanging = 1;
  if (new_thread != thread)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  struc baz;
  bogus(&baz, (rtx)atoi(argv[2]), atoi(argv[3]));
  exit(0);
  return 0;
}

//Note: I made some assumptions about the arguments in the `dummy` and `bogus` functions based on the usage in the original code. Please adjust them as necessary.