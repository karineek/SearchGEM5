// Modification timestamp: 2023-08-14 13:55:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990524-1.c

#include <stdio.h>
#include <stdlib.h>

void loop (char * pz, char * pzDta)
{
    for (;;) {
        switch (*(pz++) = *(pzDta++)) {
        case 0:
	        goto loopDone2;

	    case '"':
	    case '\\':
	        pz[-1]  = '\\';
            *(pz++) = pzDta[-1];
	    }
    } loopDone2:;
}

int main(int argc, char *argv[]) {
    char a[] = {argv[1][0], argv[1][1], argv[1][2], argv[1][3], argv[1][4], '\0'};
    char b[] = {argv[2][0], argv[2][1], argv[2][2], argv[2][3], argv[2][4], '\0'};

    loop(a, b);
    exit(0);
}
