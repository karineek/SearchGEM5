// Modification timestamp: 2023-08-14 13:55:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990524-1.c
char a[] = "12345";
char b[] = "12345";

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

  if (a - pz != b - pzDta)
    abort ();
}

main()
{
  loop (a, b);
  exit (0);
}
