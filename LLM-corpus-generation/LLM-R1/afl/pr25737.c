// Modification timestamp: 2023-08-14 14:49:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr25737.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

struct delay_block {
  struct delay_block *succ;
};

static struct delay_block Timer_Queue;

struct delay_block* time_enqueue (struct delay_block *d)
{
  struct delay_block *q = Timer_Queue.succ;
  d->succ =  (void *)0;
  return Timer_Queue.succ;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  Timer_Queue.succ = &Timer_Queue;
  if (time_enqueue (&Timer_Queue) != (void*)0)
    abort ();
  return 0;
}
