
// Modification timestamp: 2023-08-10 16:31:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000412-6.c

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

unsigned bug (unsigned short value, unsigned short *buffer,unsigned short *bufend);

unsigned short buf[] = {1, 4, 16, 64, 256};
int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value> <buffer_size> <bufend_size>\n", argv[0]);
    return 1;
  }

  unsigned short value = atoi(argv[1]);
  unsigned short buffer_size = atoi(argv[2]);
  unsigned short bufend_size = atoi(argv[3]);
  unsigned short *buffer = malloc(buffer_size * sizeof(unsigned short));
  unsigned short *bufend = malloc(bufend_size * sizeof(unsigned short));
  
  if (buffer == NULL || bufend == NULL) {
    printf("Failed to allocate memory\n");
    return 1;
  }

  // Initialize buffer and bufend
  for (int i = 0; i < buffer_size; i++) {
    buffer[i] = i + 1;
  }

  for (int i = 0; i < bufend_size; i++) {
    bufend[i] = i + 1;
  }
  
  if (bug (value, buffer, bufend) != 491)
    abort ();

  free(buffer);
  free(bufend);
  exit (0);
}

unsigned bug (unsigned short value, unsigned short *buffer, unsigned short *bufend) {
  unsigned short *tmp;

  for (tmp = buffer; tmp < bufend; tmp++)
    value -= *tmp;

  return value;
}
