**Describe the bug**
A clear and concise description of what the bug is.

A program generated with binary fuzzing led to a different behaviour between native X86 and gem5 X86 simulation.

**TODO**


**Affects version**
State which version of gem5 this bug was found in. If on the develop branch state the Commit revision ID you are working.

I tested with two versions:
 - gem5 version 23.0.0.1--SSBSE Challeng Track and 
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
clang-16 -O3 program.c -o program.c.o.clang
```
The original program is:
```
```
We then flipped several bits during fuzzing **TODO HECTOR ADD THE CODE YOU GOT**
```
```

3. Create an input file **test.txt** with the following data:
```
program.c.o.clang
0 0 0
```
**TODO - KEM add input**

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
**TODO: need to add output**

```shell
#Terminal output here#
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

