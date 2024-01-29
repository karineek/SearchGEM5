// Modification timestamp: 2023-08-14 12:00:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010910-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void) {
    printf("Test case failed.\n");
    exit(1);
}

struct epic_rx_desc
{
  unsigned int next;
};

struct epic_private
{
  struct epic_rx_desc *rx_ring;
  unsigned int rx_skbuff[5];
};

static void epic_init_ring(struct epic_private *ep)
{
  int i;

  for (i = 0; i < 5; i++)
  {
    ep->rx_ring[i].next = atoi(argv[i+1]);
    ep->rx_skbuff[i] = 0;
  }
  ep->rx_ring[i-1].next = atoi(argv[6]);
}

static int check_rx_ring[5] = { 12,14,16,18,10 };

int main(int argc, char *argv[]) {
  if (argc != 7) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6>\n", argv[0]);
    return 1;
  }

  struct epic_private ep;
  struct epic_rx_desc rx_ring[5];
  int i;

  for (i=0;i<5;i++)
  {
    rx_ring[i].next=0;
    ep.rx_skbuff[i]=5;
  }

  ep.rx_ring=rx_ring;
  epic_init_ring(&ep);

  for (i=0;i<5;i++)
  {
    if ( rx_ring[i].next != check_rx_ring[i] ) abort();
    if ( ep.rx_skbuff[i] != 0 ) abort();
  }
  return 0;
}
