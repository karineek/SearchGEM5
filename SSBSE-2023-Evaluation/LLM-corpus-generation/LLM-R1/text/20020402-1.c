// Modification timestamp: 2023-08-14 12:12:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020402-1.c
/* derived from PR c/2100 */

extern void abort ();
extern void exit (int);

#define SMALL_N  2
#define NUM_ELEM 4

int main(void)
{
  int listElem[NUM_ELEM]={30,2,10,5};
  int listSmall[SMALL_N];
  int i, j;
  int posGreatest=-1, greatest=-1;

  for (i=0; i<SMALL_N; i++) {
    listSmall[i] = listElem[i];
    if (listElem[i] > greatest) {
      posGreatest = i;
      greatest = listElem[i];
    }
  }

  for (i=SMALL_N; i<NUM_ELEM; i++) {
    if (listElem[i] < greatest) {
      listSmall[posGreatest] = listElem[i];
      posGreatest = 0;
      greatest = listSmall[0];
      for (j=1; j<SMALL_N; j++)
	if (listSmall[j] > greatest) {
	  posGreatest = j;
	  greatest = listSmall[j];
	}
    }
  }

  if (listSmall[0] != 5 || listSmall[1] != 2)
    abort ();
  exit (0);
}
