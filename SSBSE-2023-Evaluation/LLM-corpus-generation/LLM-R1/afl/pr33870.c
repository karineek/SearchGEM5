// Modification timestamp: 2023-08-14 14:55:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33870.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef struct PgHdr PgHdr;
typedef unsigned char u8;
struct PgHdr {
  unsigned int pgno;
  PgHdr *pNextHash, *pPrevHash;
  PgHdr *pNextFree, *pPrevFree;
  PgHdr *pNextAll;
  u8 inJournal;
  short int nRef;
  PgHdr *pDirty, *pPrevDirty;
  unsigned int notUsed;
};

static inline PgHdr *merge_pagelist(PgHdr *pA, PgHdr *pB)
{
  PgHdr result;
  PgHdr *pTail;
  pTail = &result;
  while( pA && pB ){
    if( pA->pgno<pB->pgno ){
      pTail->pDirty = pA;
      pTail = pA;
      pA = pA->pDirty;
    }else{
      pTail->pDirty = pB;
      pTail = pB;
      pB = pB->pDirty;
    }
  }
  if( pA ){
    pTail->pDirty = pA;
  }else if( pB ){
    pTail->pDirty = pB;
  }else{
    pTail->pDirty = 0;
  }
  return result.pDirty;
}

PgHdr *__attribute__((noinline)) sort_pagelist(PgHdr *pIn)
{
  PgHdr *a[25], *p;
  int i;
  __builtin_memset(a, 0, sizeof(a));
  while( pIn ){
    p = pIn;
    pIn = p->pDirty;
    p->pDirty = 0;
    for(i=0; i<25 -1; i++){
      if( a[i]==0 ){
        a[i] = p;
        break;
      }else{
        p = merge_pagelist(a[i], p);
        a[i] = 0;
      }
    }
    if( i==25 -1 ){
      a[i] = merge_pagelist(a[i], p);
    }
  }
  p = a[0];
  for(i=1; i<25; i++){
    p = merge_pagelist(p, a[i]);
  }
  return p;
}

int main(int argc, char *argv[])
{
  if (argc < 5) {
    printf("Usage: %s <pgno1> <pgno2> <pgno3> <pgno4>\n", argv[0]);
    return 1;
  }

  PgHdr a[5];
  PgHdr *p;
  a[0].pgno = atoi(argv[1]);
  a[0].pDirty = &a[1];
  a[1].pgno = atoi(argv[2]);
  a[1].pDirty = &a[2];
  a[2].pgno = atoi(argv[3]);
  a[2].pDirty = &a[3];
  a[3].pgno = atoi(argv[4]);
  a[3].pDirty = 0;
  p = sort_pagelist(&a[0]);
  if (p->pDirty == p)
    abort ();
  return 0;
}
