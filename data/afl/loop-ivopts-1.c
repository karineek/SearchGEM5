// Modification timestamp: 2023-08-14 14:32:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-ivopts-1.c

void foo(float * x, float * t16, float * tmp);

int main(int argc, char *argv[]) {
  float x[4];
  float t16[16]={1.,2.,3.,4.,5.,6.,7.,8.,9.,
			  10.,11.,12.,13.,14.,15.,16.};
  float tmp[4]={0.,0.,0.,0.};
  foo(x, t16, tmp);
  return 0;
}

void foo (float *x, float * t16, float * tmp)
{
    int i,j,k;
    float temp;

    for (i=0; i<4; i++) {
	k = 3 - i;
	temp = t16[5*k];
	for(j=k+1; j<4; j++) {
	    tmp[k] = t16[k+  j*4] * temp;
	}
    }
    x[0] = tmp[0];
    x[1] = tmp[1];
    x[2] = tmp[2];
    x[3] = tmp[3];
}
