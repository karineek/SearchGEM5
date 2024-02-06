**Describe the bug**
A clear and concise description of what the bug is.

A program with a loop that should be optimised with -O3, hangs when the input is getting near INT_MIN, with other less negative values gem5 simulation ends within a seconds. I created the program binary with GCC-11 -O3 and Clang-16 -O3, which led to the same result. Native run ends within one second regardless of how near the input is to INT_MIN.

I tried with -2147483648, -2147483647 and -2147483640 and got the hang, but with -214748364 the simulation ended within seconds. The native run was never affected and all four inputs ended within one second. 

**Affects version**
State which version of gem5 this bug was found in. If on the develop branch state the Commit revision ID you are working.

I tested with two versions:
 - gem5 version 23.0.0.1--SSBSE Challeng Track and 
 - gem5 version 23.1.0.0, commit: commit bae34876780dfb2bc22b9151bfda1d39ee80cfb1
Both got the same behaviour. X68 machine, arc during simulation also X86. 

**gem5 Modifications**
If you have modified gem5 in some way please state, to the best of your ability, how it has been modified.
No, but I used the script hello-custom-binary-Ex.py from https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023,

**To Reproduce**
Steps to reproduce the behavior. Please assume starting from a clean repository:

1. Compile gem5 with command:
```
git clone https://github.com/gem5/gem5.git
cd gem5/
pip install -r requirements.txt
scons build/X86/gem5.opt -j 4
```
Say that the compilation is done here: /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt (just for the rest of the commands).

2. Create a binary file:
```
clang-16 -O3 program.c -o program.c.o.clang
```
The program is:
```
// Modification timestamp: 2023-08-14 15:46:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68249.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c, g, k, l, m, n;
char h;

void fn1(char* a1, char* a2, int *a3, int *a4, int *a5, int *a6, int *a7, int *a8) {
  int b = *a1;
  int c = *a2;
  int l = *a3;
  int n = *a4;
  int m = *a5;
  int g = *a6;
  int k = *a7;

  for (; k; k++) {
    m = b || c < 0 || c > 1 ? : c;
    g = l = n || m < 0 || (m > 1) > 1 >> m ? : 1 << m;
  }
  l = b + 1;
  for (; b < 1; b++) {
    h = a + 1;
  }
  *a1 = b;
  *a2 = c;
  *a3 = l;
  *a4 = n;
  *a5 = m;
  *a6 = g;
  *a7 = k;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  char j;

  for (; a < 1; a++) {
    fn1(&h, &j, &b, &c, &l, &n, &m, &k);
    if (h)
      j = h;
    if (j > c)
      g = 0;
  }

  if (h != 1)
    __builtin_abort();

  return 0;
}
```

3. Create an input file **test.txt** with the following data:
```
program.c.o.clang
-2147483640 
```

4. Execute the simulation with hello-custom-binary-Ex.py script
```
/home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt hello-custom-binary-Ex.py --isa X86 --input test.txt
```

If possible, please include the Python configuration script used and state clearly any parameters passed.
The script **hello-custom-binary-Ex.py** is: https://github.com/karineek/SearchGEM5/blob/main/hello-custom-binary-Ex.py
with Python 3.8.10.

**Terminal Output**
If applicable, add the terminal output here. If long, only include the relevant lines.
Please put the terminal output in code blocks. I.e.:

Running it without and then with gem5
```
Sat Jan 20 11:26:47 GMT 2024
./pr68249.c.o.clang -2147483648
Sat Jan 20 11:26:48 GMT 2024
/home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input text11
gem5 Simulator System.  https://www.gem5.org
gem5 is copyrighted software; use the --copyright option for details.

gem5 version 23.1.0.0
gem5 compiled Jan 17 2024 12:20:35
gem5 started Jan 20 2024 07:59:59
gem5 executing on fuzzer-03, pid 670994
command line: /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input text11

Global frequency set at 1000000000000 ticks per second
warn: No dot file generated. Please install pydot to generate the dot file and pdf.
src/mem/dram_interface.cc:690: warn: DRAM device capacity (8192 Mbytes) does not match the address range assigned (32 Mbytes)
src/base/statistics.hh:279: warn: One of the stats is a legacy stat. Legacy stat is a stat that does not belong to any statistics::Group. Legacy stat is deprecated.
board.remote_gdb: Listening for connections on port 7000
src/sim/simulate.cc:199: info: Entering event queue @ 0.  Starting simulation...
src/sim/mem_state.cc:448: info: Increasing stack size by one page.
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
^CExiting @ tick 186652568982500 because user interrupt received.
Sat Jan 20 11:16:52 GMT 2024
```
** I stopped the run after +3 hours. 


**Expected behavior**
Should end within several seconds at most.

**Host Operating System**
Ubuntu 20.04, x86_64-pc-linux-gnu

**Host ISA**
X86

**Compiler used**
GCC-11 with scons:
```
$$ cc --version
cc (Ubuntu 11.4.0-2ubuntu1~20.04) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
and
```
$$ scons -v
/usr/bin/scons:104: DeprecationWarning: pkg_resources is deprecated as an API. See https://setuptools.pypa.io/en/latest/pkg_resources.html
  import pkg_resources
SCons by Steven Knight et al.:
	script: v3.1.2.bee7caf9defd6e108fc2998a2520ddb36a967691, 2019-12-17 02:07:09, by bdeegan on octodog
	engine: v3.1.2.bee7caf9defd6e108fc2998a2520ddb36a967691, 2019-12-17 02:07:09, by bdeegan on octodog
	engine path: ['/usr/lib/scons/SCons']
Copyright (c) 2001 - 2019 The SCons Foundation
```

**Additional information**
Add any other information which does not fit in the previous sections but may be of use in fixing this bug.
