
// Modification timestamp: 2023-08-10 14:46:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2003-05-02-DependentPHI.c

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  struct List *Next;
  int Data;
} List;

List Node0 = {0, 5};
List Node1 = {&Node0, 4};
List Node2 = {&Node1, 3};
List Node3 = {&Node2, 2};
List Node4 = {&Node3, 1};
List Node5 = {&Node4, 0};


int main(int argc, char *argv[]) {
    int arg = argc > 1 ? atoi(argv[1]) : -1;
    List *PrevL, *CurL;
    for (PrevL = 0, CurL = &Node5; CurL; PrevL = CurL, CurL = CurL->Next) {
	printf("%d %d\n", CurL->Data + arg, PrevL ? PrevL->Data + arg : -1);
    }
    return 0;
}
