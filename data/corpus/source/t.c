// Modification timestamp: 2023-08-02 14:30:00

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int x = a * b;
  printf("%d\n", x);
  return 0;
}
