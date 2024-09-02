// Modification timestamp: 2023-08-14 13:05:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051113-1.c

#include <stdio.h>
#include <stdlib.h>

extern void *malloc(__SIZE_TYPE__);
extern void *memset(void *, int, __SIZE_TYPE__);

typedef struct {
  short a;
  unsigned short b;
  unsigned short c;
  unsigned long long Count;
  long long Count2;
} __attribute__((packed)) Struct1;

typedef struct {
  short a;
  unsigned short b;
  unsigned short c;
  unsigned long long d;
  long long e;
  long long f;
} __attribute__((packed)) Struct2;

typedef union {
  Struct1 a;
  Struct2 b;
} Union;

typedef struct {
  int Count;
  Union List[0];
} __attribute__((packed)) Struct3;

unsigned long long Sum(Struct3 *instrs) __attribute__((noinline));
unsigned long long Sum(Struct3 *instrs) {
  unsigned long long count = 0;
  int i;

  for (i = 0; i < instrs->Count; i++) {
    count += instrs->List[i].a.Count;
  }
  return count;
}

long long Sum2(Struct3 *instrs) __attribute__((noinline));
long long Sum2(Struct3 *instrs) {
  long long count = 0;
  int i;

  for (i = 0; i < instrs->Count; i++) {
    count += instrs->List[i].a.Count2;
  }
  return count;
}

int main(int argc, char *argv[]) {
  Struct3 *p = (Struct3 *)malloc(sizeof(int) + 3 * sizeof(Union));
  memset(p, 0, sizeof(int) + 3 * sizeof(Union));
  p->Count = 3;
  p->List[0].a.Count = atoi(argv[1]);
  p->List[1].a.Count = atoi(argv[2]);
  p->List[2].a.Count = strtoull(argv[3], NULL, 0);
  p->List[0].a.Count2 = atoi(argv[4]);
  p->List[1].a.Count2 = atoi(argv[5]);
  p->List[2].a.Count2 = strtoll(argv[6], NULL, 0);

  if (Sum(p) != p->List[0].a.Count + p->List[1].a.Count + p->List[2].a.Count)
    abort();
  if (Sum2(p) != p->List[0].a.Count2 + p->List[1].a.Count2 + p->List[2].a.Count2)
    abort();

  return 0;
}
