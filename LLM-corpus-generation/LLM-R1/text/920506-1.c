// Modification timestamp: 2023-08-14 13:27:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920506-1.c
int l[]={0,1};
main(){int*p=l;switch(*p++){case 0:exit(0);case 1:break;case 2:break;case 3:case 4:break;}abort();}
