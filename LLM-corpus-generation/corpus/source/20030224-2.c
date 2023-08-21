// Modification timestamp: 2023-08-14 12:43:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030224-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

typedef struct { short v16; } __attribute__((packed)) jint16_t;

struct node {
  jint16_t magic;
  jint16_t nodetype;
  int totlen;
} __attribute__((packed));

struct node node, *node_p = &node;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct node marker = {
    .magic = (jint16_t) {atoi(argv[1])},
    .nodetype = (jint16_t) {atoi(argv[2])},
    .totlen = node_p->totlen
  };
  if (marker.magic.v16 != atoi(argv[3]))
    abort();
  if (marker.nodetype.v16 != atoi(argv[4]))
    abort();
  return 0;
}
