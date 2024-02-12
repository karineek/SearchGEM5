**Describe the bug**
A clear and concise description of what the bug is.

A program generated with binary fuzzing led to a different behaviour between native X86 and gem5 X86 simulation. 
In such a way that the simulator failed to replicate the problematic behaviour observed in the native environment.

**Affects version**
State which version of gem5 this bug was found in. If on the develop branch state the Commit revision ID you are working.

I tested with two versions:
 - gem5 version 23.0.0.1--SSBSE Challeng Track;
 - gem5 version 23.1.0.0, commit: commit bae34876780dfb2bc22b9151bfda1d39ee80cfb1; and
 - gem5 version 23.1.0.0, commit: commit **TODO HECTOR ADD YOUR VERSION**
Both got the same behaviour. X68 machine, arc during simulation also X86.


**gem5 Modifications**
If you have modified gem5 in some way please state, to the best of your ability, how it has been modified.

No, but I used the script hello-custom-binary-Ex.py from https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.

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
gcc-11 -O3 2020-01-06-coverage-006.c -o 2020-01-06-coverage-006.c.o.gcc
```
The original program is (2020-01-06-coverage-006.c):
```
// Modification timestamp: 2023-08-14 17:25:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-006.c
#include <stdlib.h>

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#pragma pack(1)

struct s {
  int : 28;
  unsigned : 17;
  unsigned a : 25;
} b;

volatile int32_t c;
int32_t x;

void d(int32_t val_1, int32_t val_2) {
  if (8 < b.a)
    x = val_2;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <val_1> <val_2> <val_3>\n", argv[0]);
    return 1;
  }

  int32_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);
  int32_t val_3 = atoi(argv[3]);

  x = val_3;
  c = val_2;
  b.a = val_1;
  d(val_1, val_2);

  printf("b.a = %u\n", b.a);
  printf("c = %" PRIi32 "\n", c);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
```
We then flipped several bits during fuzzing **TODO HECTOR ADD THE CODE YOU GOT after lifting**
```
```

3. Create two input files **test*.txt** with the following data:
```
nano test-orig.txt
2020-01-06-coverage-006.c.o.gcc
0 0 0
** save **

nano test-fuzzed.txt
fuzz_1692558568787306293.c.o
0 0 0
** save **
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

Running it without and then with gem5 of the original (not fuzzed file) works well:
```shell
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-2-18-Aug-2023-X86/Q/BUG-1534$ /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt ../../../../hello-custom-binary-Ex.py --isa X86 --input test-orig.txt 
gem5 Simulator System.  https://www.gem5.org
gem5 is copyrighted software; use the --copyright option for details.

gem5 version 23.1.0.0
gem5 compiled Jan 17 2024 12:20:35
gem5 started Feb  6 2024 13:20:07
gem5 executing on fuzzer-03, pid 44076
command line: /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt ../../../../hello-custom-binary-Ex.py --isa X86 --input test-orig.txt

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
b.a = 0
c = 0
x = 0
Exiting @ tick 11670352965 because exiting with last active thread context.

ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-2-18-Aug-2023-X86/Q/BUG-1534$ ./a.out 0 0 0
b.a = 0
c = 0
x = 0
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-2-18-Aug-2023-X86/Q/BUG-1534$ 
```

However, with the modifications during fuzzing of the binary, it masks the errors (and thus, the invalid memory access cannot be detected via simulation only).
```
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-2-18-Aug-2023-X86/Q/BUG-1534$ /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt ../../../../hello-custom-binary-Ex.py --isa X86 --input test-fuzzed.txt 
gem5 Simulator System.  https://www.gem5.org
gem5 is copyrighted software; use the --copyright option for details.

gem5 version 23.1.0.0
gem5 compiled Jan 17 2024 12:20:35
gem5 started Feb  6 2024 13:21:40
gem5 executing on fuzzer-03, pid 44102
command line: /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt ../../../../hello-custom-binary-Ex.py --isa X86 --input test-fuzzed.txt

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
b.a = 0
c = 0
x = 0
Exiting @ tick 11672214435 because exiting with last active thread context.

ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-2-18-Aug-2023-X86/Q/BUG-1534$ ./fuzz_1692558568787306293.c.o 0 0 0
b.a = 0
c = 21860
x = 0
```

**Expected behavior**
Should have the same behaviour as the native X86 **TODO: Hector add why it is important**

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

