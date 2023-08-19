// Modification timestamp: 2023-08-14 15:17:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49161.c

#include <stdio.h>
#include <stdlib.h>

int c;

void bar (int x)
{
  if (x != c++)
    abort ();
}

void foo (int x)
{
  switch (x)
  {
    case 3: goto l1;
    case 4: goto l2;
    case 6: goto l3;
    default: return;
  }
  
l1:
  goto l4;
l2:
  goto l4;
l3:
  bar (-1);
  
l4:
  bar (0);
  
  if (x != 4)
    bar (1);
    
  if (x != 3)
    bar (-1);
    
  bar (2);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  
  foo (x);
  
  if (c != 3)
    abort ();
    
  return 0;
}

