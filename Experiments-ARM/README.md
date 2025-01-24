# Abstract.

We present and discuss our solution to the problem of testing software simulators, using SearchSYS to test the gem5 VLSI digital circuit simulator, employed by ARM to test their systems. In particular, we focus on the simulation of the ARM silicon chip Instruction Set Architecture (ISA).

SearchSYS can create test cases that activate bugs by combining LLMs, fuzzing, and differential testing. Using only LLM, SearchSYS identified 74 test cases that activated bugs. By incorporating fuzzing, this number increased by 93 additional bug-activating cases within 24 hours. Through differential testing, we identified 624 bugs with LLM-generated test cases and 126 with fuzzed test inputs. Out of the total number of bug-activating test cases, 4 unique bugs have been reported and acknowledged by developers. Additionally, we provided developers with a test suite and fuzzing statistics, and open-sourced SearchSYS.

We published our artifact in Zenodo https://zenodo.org/records/14724553.

To reproduce the evaluation in the paper, ensure your system meets the requirements, and then follow the instructions to reproduce the tables in the results. **Hardware requirements:** You will need an ARM machine, with 80 GB HD free space, and 72 GB RAM (for AFL++ fuzzing) or (else) 16 GB if merely running the differential testing without building gem5 with AFL++ instrumentation. 



The artifact documentation contains three sections:

Section 1: Software and hardware requirements;

Section 2: documentation of how to build the testing environment for ARM with full instructions on how to reproduce the four tables in our ICSE-SEIP 2025 paper; and

Section 3: a shortened version of the evaluation, to be run within a day or less.



We suggest starting with the shortened evaluation, after installing AFL++, gem5 and SearchSYS (Section 1, Section 2.1 - TinyLlama only, and Section 2.2). 

==

# Additional Resources.

SearchSYS tool can be downloaded here: a239d3c (for this work).

To process the fuzzed test inputs, post-fuzzing, the *.sh here can run on the output/default/queue and crash folders.

The rest are the data collected during experiments: (1) the Excel file contains the full analysis while (2) *.tar.gz are all outputs from the fuzzing stage. The LLM data is taken from here. You can follow the instructions here to install and run SearchSYS for X86.



The record here details how to run SearchSYS on ARM machines (arm64-ubuntu-2204 and Red Hat-based system).



## Cite the paper:

```
@inproceedings{Even-Mendoza:2025:ICSE-SEIP,
  author = {Karine Even-Mendoza and  Hector D. Menendez and W.B Langdon and Aidan Dakhama and Justyna Petke and Bobby R. Bruce},
  title = {{Search+LLM-based} Testing for {ARM} Simulators},
  booktitle = {2025 IEEE/ACM 47th International Conference on Software Engineering: Software Engineering in Practice (ICSE-SEIP)},
  year = {2025},
  editor = {},
  volume = {},
  number = {},
  series = {},
  pages = {},
  address = {Ottawa, Canada},
  publisher_address = {},
  month = {April 27-May 3},
  organisation = {},
  publisher = {},
  note = {https://conf.researchr.org/track/icse-2025/icse-2025-software-engineering-in-practice#Accepted-Papers},
  keywords = {Software System Simulation, SearchSYS, gem5, AFL++, Fuzzing, Fuzz Testing, Differential Testing, Search-Based Software Testing, LLM, Language Models, Ollama, CodeLlama, TinyLlama, Phi2, Llama2, Magicoder, CodeBooga, GPT-3.5-turbo, prompt engineering},
  ISBN13 = {},
  url = {https://solar.cs.ucl.ac.uk/pdf/ICSE_SEIP_2025___SearchSYS_and_ARM.pdf},
  code_url = {https://zenodo.org/records/13450472, https://zenodo.org/records/14724553},
  size = {12 pages},
  abstract = {In order to aid quality assurance of large complex hardware architectures, system simulators have been developed. However, such system simulators do not always accurately mirror what would happen on a real device. A significant challenge in testing these simulators arises from the complexity of having to model both the simulation and the infinite number of software that could be run on such a device.
Our previous work introduced SearchSYS, a testing framework for software simulators. SearchSYS leverages a large language model for initial seed C code generation, which is then compiled, and the resultant binary is fed to a fuzzer. We then use differential testing by running the outputs of fuzzing on real hardware and a system simulator to identify mismatches.
We present and discuss our solution to the problem of testing software simulators, using SearchSYS to test the gem5 VLSI digital circuit simulator, employed by ARM to test their systems. In particular, we focus on the simulation of the ARM silicon chip Instruction Set Architecture (ISA).
SearchSYS can create test cases that activate bugs by combining LLMs, fuzzing, and differential testing. Using only LLM, SearchSYS identified 74 test cases that activated bugs. By incorporating fuzzing, this number increased by 93 additional bug-activating cases within 24 hours. Through differential testing, we identified 624 bugs with LLM-generated test cases and 126 with fuzzed test inputs. Out of the total number of bug-activating test cases, 4 unique bugs have been reported and acknowledged by developers. Additionally, we provided developers with a test suite and fuzzing statistics, and open-sourced SearchSYS for initial seeds and SearchSYS code, for adjustment to ARM8v and fuzzed seeds.},
}
```
==


# Experiments.

Ensure your system meets the requirements, then follow the instructions to reproduce the tables in Section 5 (V. Results).

Hardware requirements: You will need an ARM machine, with 80 GB HD free space, and 72 GB RAM (for AFL++ fuzzing) or 16 GB else (just differential testing without building gem5 with AFL++ instrumentation).

## 1. Requirements:

### 1.1 Hardware

Hardware requirements: You will need an ARM machine, with 80 GB HD free space, and 72 GB RAM (for AFL++ fuzzing) or 16 GB else (just differential testing without building gem5 with AFL++ instrumentation).


| Requirement        | Details                                                                                  |
|--------------------|------------------------------------------------------------------------------------------|
| Processor          | ARM                                                                                      |
| HD space           | At least 80 GB of free disk space                                                        |
| RAM                |  - 72 GB (for AFL++ fuzzing)                                                             |
|                    |  - 16 GB (for differential testing without AFL++ gem5)                                   |
| Operating System   | Tested on Ubuntu and Red Hat                                                             |


### 1.2 Software and Packages:
- GCC-11
- wget, zip, unzip (any version)
- LLVM-13+ (we tested with LLVM-13, but any newer version should be okay)
- Python3 (tested with Python 3.8 and 3.10)
- Other packages:
```
sudo apt-get update
sudo apt-get upgrade
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get -y install gcc-11 g++-11 cpp-11 wget lsb-release gnupg software-properties-common
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/bin/cc
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/gcc-11 /usr/bin/cc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov
wget https://apt.llvm.org/llvm.sh
sudo chmod +x llvm.sh
sudo ./llvm.sh 13
sudo ln -s /usr/bin/llvm-config-13 /usr/bin/llvm-config
sudo apt-get install -y lld-13 llvm-13-dev clang-13
sudo apt-get install -y lld llvm llvm-dev clang
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
sudo apt-get install -y ninja-build cmake
sudo apt-get install -y git make cmake llvm gdb coreutils
sudo apt-get install -y gcc-11-plugin-dev
sudo apt -y autoremove
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-13 1300 --slave /usr/bin/clang++ clang++ /usr/bin/clang++-13 
sudo update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-13 1300
LLVM_CONFIG=/usr/bin/llvm-config-13
```

We attached all installed packages in installed_karl.log (Red Hat-based system) and installed_m400.log  (Ubuntu/Unix, arm64-ubuntu-2204).





## 2. Reproduce ICSE-SEIP 2025 Evaluation:

This section contains the full instructions for running SearchSYS on ARM. We include further explanations on how to customise the evaluation or run part of it. This is the full version, you can use the shortened version in Section 3. This evaluation should take around 40 days to reproduce: 7 initial corpora, each fuzzed with AFL++ five times (5 repeats of the fuzzing campaign), and then around 2-3 days for differential testing of the initial corpora and the same for each repetition (and we had 5 repeats of the fuzzing campaign). 

To reproduce the experiments follow these commands (Unix system):
```
## CREATE A NEW USER (you can also use your own user but then you will need to amend /home/debian and debian, accordingly) ##
sudo adduser debian
# if needed run:
# sudo passwd debian
# and set some simple password
sudo usermod -aG sudo debian
sudo mkdir -p /home/debian
sudo usermod -d /home/debian debian
su - debian

## GET DATA - 7 set of LLM-generated C programs ##
cd /home/debian
wget "https://zenodo.org/records/10999115/files/LLM_test_inputs-4FuzzExp2.zip" # Get the data
unzip -n LLM_test_inputs-4FuzzExp2.zip -d /home/debian/experiment
cd /home/debian/experiment/ 
sed -i "s:/home/ubuntu/experiment-7/:/home/debian/experiment/:g" */input/*.txt
cat /home/debian/experiment/TinyLlama-cmin/input/test_input_574567374417673.txt

YOU WILL NEED TO COPY ALL SCRIPTS OF THIS ARTIFACT INTO /home/debian
cd /home/debian
wget "https://zenodo.org/records/14721385/files/1-run-diff-test.sh" 
wget "https://zenodo.org/records/14721385/files/2-test-input.sh"
wget "https://zenodo.org/records/14721385/files/run_AFL_loop_v6.sh"
wget "https://zenodo.org/records/14721385/files/Experiment-ARM-24h.sh"
```

We will explain in the next sections when to run each. There is a shorter version of the experiments in Section 3.


### 2.1 Create Initial Data Seedds for ARM Machine:

```
## COMPILE BINARIES - build the test binaries and tailor the paths in the seeds ##

_This includes the entire generated corpus, and so some compilations will fail, but this is expected_

### Model CodeBooga ###
cd /home/debian/experiment/CodeBooga  
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done 
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf CodeBooga-cmin/binary
cp -r CodeBooga/binary CodeBooga-cmin/binary
cd /home/debian/experiment/CodeBooga-cmin/input
sed -i 's\/CodeBooga/\/CodeBooga-cmin/\g' *txt

### Model Llama ###
cd /home/debian/experiment/Llama  
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf Llama-cmin/binary
cp -r Llama/binary Llama-cmin/binary
cd /home/debian/experiment/Llama-cmin/input
sed -i 's\/Llama/\/Llama-cmin/\g' *txt

### Model Magicoder ###
cd /home/debian/experiment/Magicoder
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf Magicoder-cmin/binary
cp -r Magicoder/binary Magicoder-cmin/binary
cd /home/debian/experiment/Magicoder-cmin/input
sed -i 's\/Magicoder/\/Magicoder-cmin/\g' *txt

### Model TinyLlama ###
cd /home/debian/experiment/TinyLlama
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf TinyLlama-cmin/binary
cp -r TinyLlama/binary TinyLlama-cmin/binary
cd /home/debian/experiment/TinyLlama-cmin/input
sed -i 's\/TinyLlama/\/TinyLlama-cmin/\g' *txt

### Model Phi ###
cd /home/debian/experiment/Phi 
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf Phi-cmin/binary
cp -r Phi/binary Phi-cmin/binary
cd /home/debian/experiment/Phi-cmin/input
sed -i 's\/Phi/\/Phi-cmin/\g' *txt

### Model gpt3.5-new ###
cd /home/debian/experiment/gpt3.5-new  
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf gpt3.5-new-cmin/binary
cp -r gpt3.5-new/binary gpt3.5-new-cmin/binary
cd /home/debian/experiment/gpt3.5-new-cmin/input
sed -i 's\/gpt3.5-new/\/gpt3.5-new-cmin/\g' *txt

### Model gpt3.5-old ###
cd /home/debian/experiment/gpt3.5-old
for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
rm  binary/fuzz_* || true
rm  .DS_Store || true
cd /home/debian/experiment/
rm -rf gpt3.5-old-cmin/binary
cp -r gpt3.5-old/binary gpt3.5-old-cmin/binary
cd /home/debian/experiment/gpt3.5-old-cmin/input
sed -i 's\/gpt3.5-old/\/gpt3.5-old-cmin/\g' *txt
```

At this point all data for fuzzing is ready. You need now to get SearchSYS and build the SUT (gem5) from source.





### 2.2 Build the tools:

We first build AFL with some customisation:

```
## GET AFL++ SearchSYS ##
cd /home/debian 
git clone https://github.com/karineek/SearchGEM5.git 
git clone https://github.com/AFLplusplus/AFLplusplus.git 
cd AFLplusplus 
git checkout f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58 
cp ../SearchGEM5/src/gem5-afl/afl-fuzz-init.c src/afl-fuzz-init.c 
AFL_USE_ASAN=0 make 

### The compilation shall state that it is ARM architecture: ### 
 
debian@node0:~/AFLplusplus$ AFL_USE_ASAN=0 make 
[*] Compiling AFL++ for OS Linux on ARCH aarch64 
[+] ZLIB detected [!] Note: skipping x86 compilation checks (AFL_NO_X86 set). 
[+] shmat seems to be working. [+] Python 3.8.10 support seems to be working. 
[+] Everything seems to be working, ready to compile 
... 
```


then you need to check that AFL is built correctly:

```
Build Summary:
[+] afl-fuzz and supporting tools successfully built
[+] LLVM basic mode successfully built
[+] LLVM mode successfully built
[+] LLVM LTO mode successfully built
[+] gcc_mode successfully built
```

Then build gem5 with AFL++ instrumentation:

```
cd /home/debian
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
cd /home/debian/gem5-ssbse-challenge-2023
cp ../SearchGEM5/src/gem5-afl/SConstruct .
cp ../SearchGEM5/src/gem5-afl/SConscript src/

# If needed install:
sudo apt install python3-pip
sudo apt install scons protobuf-compiler libhdf5-dev libgoogle-perftools-dev libsystemc-dev

# Then install the requirements for gem5:
pip install -r requirements.txt

# And build gem5 with AFL++ instrumentation:
CC=/home/debian/AFLplusplus/afl-cc CXX=/home/debian/AFLplusplus/afl-c++ LINK=/home/debian/AFLplusplus/afl-c++ \
   scons build/ARM/gem5.opt -j 4
# Then test if built:
./build/ARM/gem5.opt -C
```

During the configuration, you need to see it built for ARM, hence (1) make sure you use build/ARM not X86, and check the configuration log to see that the right architecture has been properly selected for the build. Executing gem5.opt should give you the following message: (or something similar)

```
debian@node0:~/gem5-ssbse-challenge-2023$ ./build/ARM/gem5.opt -C
Please see individual files for details of the license on each file.
The preferred license can be found in LICENSE.

All files in this distribution (other than in the ext directory) have
licenses based on the BSD or MIT licenses.  Some files in the ext
directory are GNU LGPL.  No other licenses are found in this
distribution.

Beyond the BSD license, some files include the following clarification
of the license as required by the copyright holder:

    The license below extends only to copyright in the software and
    shall not be construed as granting a license to any other
    intellectual property including but not limited to intellectual
    property relating to a hardware implementation of the
    functionality of the software licensed hereunder.  You may use the
    software subject to the license terms below provided that you
    ensure that this notice is replicated unmodified and in its
    entirety in all distributions of the software, modified or
    unmodified, in source code or in binary form.

The copyright holders include (not counting the ext directory):

Copyright (c) 2000-2011 The Regents of The University of Michigan
Copyright (c) 1990,1993-1995,2007-2010 The Hewlett-Packard Development Company
Copyright (c) 1999-2009,2011 Mark D. Hill and David A. Wood
Copyright (c) 2009-2011 ARM Limited
Copyright (c) 2008-2009 Princeton University
Copyright (c) 2007 MIPS Technologies, Inc.
Copyright (c) 2009-2011 Advanced Micro Devices, Inc.
Copyright (c) 2009 The University of Edinburgh
Copyright (c) 2007-2008 The Florida State University
Copyright (c) 2010 Massachusetts Institute of Technology
Copyright (c) 1990-1993 The Regents of the University of California
Copyright (c) 2006-2009 Nathan Binkert
Copyright (c) 2001 The NetBSD Foundation, Inc.
Copyright (c) 2010-2011 Gabe Black
Copyright (c) 1994 Adam Glass
Copyright (c) 1990-1992 MIPS Computer Systems, Inc.
Copyright (c) 2004 Richard J. Wagner
Copyright (c) 2000 Computer Engineering and Communication Networks Lab
Copyright (c) 2001 Eric Jackson
Copyright (c) 1990 Hewlett-Packard Development Company
Copyright (c) 1994-1996 Carnegie-Mellon University.
Copyright (c) 1993-1994 Christopher G. Demetriou
Copyright (c) 1997-2002 Makoto Matsumoto and Takuji Nishimura
Copyright (c) 1998,2001 Manuel Bouyer.
Copyright (c) 2016-2017 Google Inc.
```

Last step: compile the custom mutators:
```
cd /home/debian/SearchGEM5/src/custom_mutators/
AFL_HOME=/home/debian/AFLplusplus
sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" compile_share_test.sh
sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" compile_share.sh 
./compile_share.sh 17 84 66
```

You will get a warning from AFL++ headers, there is nothing to do about it, if you wish you can edit the AFL++ headers and fix it:

```
/home/debian/AFLplusplus/src/afl-performance.c: In function ‘get_binary_hash’:
/home/debian/AFLplusplus/src/afl-performance.c:103:17: warning: pointer targets in passing argument 1 of ‘open’ differ in signedness [-Wpointer-sign]
  103 |   int fd = open(fn, O_RDONLY);
      |                 ^~
      |                 |
      |                 u8 * {aka unsigned char *}
In file included from /usr/aarch64-linux-gnu/include/fcntl.h:301,
                 from /home/debian/AFLplusplus/include/afl-fuzz.h:58,
                 from /home/debian/AFLplusplus/src/afl-performance.c:2:
/usr/aarch64-linux-gnu/include/bits/fcntl2.h:41:19: note: expected ‘const char *’ but argument is of type ‘u8 *’ {aka ‘unsigned char *’}
   41 | open (const char *__path, int __oflag, ...)
      |       ~~~~~~~~~~~~^~~~~~
/home/debian/AFLplusplus/src/afl-performance.c: In function ‘sha1_hex’:
/home/debian/AFLplusplus/src/afl-performance.c:407:10: warning: pointer targets in returning ‘u8 *’ {aka ‘unsigned char *’} from a function with return type ‘char *’ differ in signedness [-Wpointer-sign]
  407 |   return hex;
      |          ^~~
```

At this point, we have the tools up and the experimental data ready for fuzzing and testing.





### 2.3 Differential Testing of Input Corpus Seeds (Section V.A. & Table II):

Testing is usually against the most recent version. To get gem5 built from tree, run this code:
```
cd /home/debian
git clone https://github.com/gem5/gem5.git
cd gem5
pip install -r requirements.txt
scons build/ARM/gem5.opt -j 4
cd /home/debian
```

To run a single test:
```
/home/debian/gem5/build/ARM/gem5.opt /home/debian/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input /home/debian/experiment/CodeBooga-cmin/input/test_input_645596930837886.txt
```

You can try different test inputs by changing the file after the --input. To run a single comparison between native and simulation, you run:
```
./2-test-input.sh /home/debian/experiment/CodeBooga-cmin/input/test_input_645596930837886.txt
```

To run the whole process for a folder, and then check the results later, you run the differential testing script:
```
./1-run-diff-test.sh /home/debian/experiment/CodeBooga-cmin/input > LLM-diff-testing-CodeBooga.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Llama-cmin/input > LLM-diff-testing-Llama.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Magicoder-cmin/input > LLM-diff-testing-Magicoder.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Phi-cmin/input > LLM-diff-testing-Phi.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/TinyLlama-cmin/input > LLM-diff-testing-TinyLlama.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/gpt3.5-new-cmin/input > LLM-diff-testing-gpt3.5-new.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/gpt3.5-old-cmin/input > LLM-diff-testing-gpt3.5-old.log 2>&1
```
==> This will give the results for Table II (page 7) after manual analysis of the logs.

These logs will later flag any issue found in ARM native vs simulation, e.g.:

Simulation run: 
```
Global frequency set at 1000000000000 ticks per second
warn: No dot file generated. Please install pydot to generate the dot file and pdf.
src/mem/dram_interface.cc:690: warn: DRAM device capacity (8192 Mbytes) does not match the address range assigned (32 Mbytes)
src/base/statistics.hh:279: warn: One of the stats is a legacy stat. Legacy stat is a stat that does not belong to any statistics::Group. Legacy stat is deprecated.
src/base/remote_gdb.cc:418: warn: Sockets disabled, not accepting gdb connections
gem5 Simulator System.  https://www.gem5.org
gem5 is copyrighted software; use the --copyright option for details.

gem5 version 24.0.0.1
gem5 compiled Sep  5 2024 16:37:09
gem5 started Oct  9 2024 09:30:14
gem5 executing on karl.cs.ucl.ac.uk, pid 2528401
command line: /home/kevenmen/gem5/build/ARM/gem5.opt /home/kevenmen/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input /home/kevenmen/experiment-7/CodeBooga-cmin/output-r_5/default/queue/id:000003,time:0,execs:0,orig:id:000918,src:000589+000058,time:55938499,execs:11247,op:cm-gem5c-types.so,pos:0

info: Standard input is not a terminal, disabling listeners.
src/sim/simulate.cc:199: info: Entering event queue @ 0.  Starting simulation...
src/arch/arm/insts/pseudo.cc:174: warn:         instruction 'bti' unimplemented
src/sim/mem_state.cc:448: info: Increasing stack size by one page.
src/base/loader/symtab.cc:95: warn: Cannot insert a new symbol table due to name collisions. Adding prefix to each symbol's name can resolve this issue.
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/base/loader/symtab.cc:95: warn: Cannot insert a new symbol table due to name collisions. Adding prefix to each symbol's name can resolve this issue.
src/sim/syscall_emul.cc:74: warn: ignoring syscall set_robust_list(...)
src/sim/syscall_emul.cc:85: warn: ignoring syscall rseq(...)
      (further warnings will be suppressed)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
" is neither a letter nor a digit
H is a letter
e is a letter
l is a letter
l is a letter
o is a letter
1 is a digit
2 is a digit
3 is a digit
" is neither a letter nor a digit
Exiting @ tick 5367044250 because exiting with last active thread context.
```
vs the native run:
```
" is neither a letter nor a digit
H is a letter
e is a letter
l is a letter
l is a letter
o is a letter
1 is a digit
2 is a digit
3 is a digit
" is neither a letter nor a digit
```
In this case, but are giving the same output and hence on bug exposed.




### 2.4 Fuzzing with AFL++ and SearchSYS Custom Mutators (Section V.B. & Table III):

You can run a single execution that way:
```
# Define:
cm_path="/home/debian/SearchGEM5/src/custom_mutators"
corpus_folder="/home/debian/experiment/gpt3.5-old-cmin/"
execgem5=/home/debian/gem5-ssbse-challenge-2023/build/ARM/gem5.opt

# Run AFL
AFL_NO_AFFINITY=1 AFL_SHUFFLE_QUEUE=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_FAST_CAL=1 AFL_IGNORE_PROBLEMS=1 \
   AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_BIN_CHECK=1 AFL_MAP_SIZE=1200000 \
   AFL_CUSTOM_MUTATOR_LIBRARY="$cm_path/cm-gem5c.so;$cm_path/cm-gem5c-bin.so;$cm_path/cm-gem5c-types.so" \
   /home/debian/AFLplusplus/afl-fuzz -m 50000 -t 99000 -i $corpus_folder/input/  -o $corpus_folder/output-fuzzed/ -- $execgem5 \
   /home/debian/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input @@
```

You need then to check the custom mutators loaded okay:
```
[+] Enabled environment variable AFL_IGNORE_PROBLEMS with value 1
[+] Enabled environment variable AFL_FAST_CAL with value 1
[+] Enabled environment variable AFL_CUSTOM_MUTATOR_LIBRARY with value /home/debian/SearchGEM5/src/custom_mutators/cm-gem5c.so;/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-bin.so;/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-types.so
[+] Enabled environment variable AFL_SKIP_BIN_CHECK with value 1
[+] Enabled environment variable AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES with value 1
[+] Enabled environment variable AFL_DUMB_FORKSRV with value 1
[+] Enabled environment variable AFL_NO_AFFINITY with value 1
[+] Enabled environment variable AFL_CUSTOM_MUTATOR_ONLY with value 1
afl-fuzz++4.31a based on afl by Michal Zalewski and a large online community
...
[*] Loading custom mutator library from '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c.so'...
[+] Found 'afl_custom_mutator'.
[+] Found 'afl_custom_fuzz_count'.
...
[+] Custom mutator '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c.so' installed successfully.
[*] Loading custom mutator library from '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-bin.so'...
[+] Found 'afl_custom_mutator'.
[+] Found 'afl_custom_fuzz_count'.
...
[+] Custom mutator '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-bin.so' installed successfully.
[*] Loading custom mutator library from '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-types.so'...
[+] Found 'afl_custom_mutator'.
[+] Found 'afl_custom_fuzz_count'.
[*] optional symbol 'afl_custom_post_process' not found.
[*] optional symbol 'afl_custom_init_trim' not found.
[*] optional symbol 'afl_custom_trim' not found.
[*] optional symbol 'afl_custom_post_trim' not found.
[*] optional symbol 'afl_custom_havoc_mutation' not found.
[*] optional symbol 'afl_custom_havoc_mutation_probability' not found.
[*] optional symbol 'afl_custom_queue_get' not found.
[*] optional symbol 'afl_custom_splice_optout' not found.
[*] optional symbol 'afl_custom_fuzz_send' not found.
[*] optional symbol 'afl_custom_post_run' not found.
[*] optional symbol 'afl_custom_queue_new_entry' not found
[*] optional symbol 'afl_custom_describe' not found.
[+] Custom mutator '/home/debian/SearchGEM5/src/custom_mutators/cm-gem5c-types.so' installed successfully.
```

and if it uploaded okay, you will see this screen in the interactive mode:
```
[*] Attempting dry run with 'id:000441,time:0,execs:0,orig:zero-struct-2.txt'...
[!] WARNING: instability detected during calibration
    len = 67, map size = 41474, exec speed = 3356882 us, hash = fef2b4ed27f2d5fe
Results of dry-run 0[!] WARNING: Instrumentation output varies across runs.
[!] WARNING: Skipped 1 test cases (0.23%) due to timeouts or crashes.
[+] All test cases processed.
[!] WARNING: The target binary is pretty slow! See docs/fuzzing_in_depth.md#i-improve-the-speed
[!] WARNING: Some test cases look useless. Consider using a smaller set.
[!] WARNING: You probably have far too many input files! Consider trimming down.
[+] Here are some useful stats:

    Test case count : 64 favored, 255 variable, 5 ignored, 442 total
       Bitmap range : 27891 to 42022 bits (average: 41556.14 bits)
        Exec timing : 1.21M to 44.6M us (average: 4.30M us)

[*] -t option specified. We'll use an exec timeout of 99000 ms.
[+] All set and ready to roll!


 AFL ++4.31a {default} (...ssbse-challenge-2023/build/ARM/gem5.opt) [explore] 
┌─ process timing ────────────────────────────────────┬─ overall results ────┐
│        run time : 0 days, 2 hrs, 39 min, 26 sec     │  cycles done : 0     │
│   last new find : 0 days, 0 hrs, 6 min, 46 sec      │ corpus count : 575   │
│last saved crash : 0 days, 0 hrs, 11 min, 21 sec     │saved crashes : 40    │
│ last saved hang : none seen yet                     │  saved hangs : 0     │
├─ cycle progress ─────────────────────┬─ map coverage┴──────────────────────┤
│  now processing : 46.0 (8.0%)        │    map density : 3.79% / 4.10%      │
│  runs timed out : 0 (0.00%)          │ count coverage : 1.57 bits/tuple    │
├─ stage progress ─────────────────────┼─ findings in depth ─────────────────┤
│  now trying : cm-gem5c-types.so      │ favored items : 86 (14.96%)         │
│ stage execs : 63/66 (95.45%)         │  new edges on : 119 (20.70%)        │
│ total execs : 5744                   │ total crashes : 144 (40 saved)      │
│  exec speed : 0.18/sec (zzzz...)     │  total tmouts : 0 (0 saved)         │
├─ fuzzing strategy yields ────────────┴─────────────┬─ item geometry ───────┤
│   bit flips : disabled (custom-mutator-only mode)  │    levels : 6         │
│  byte flips : disabled (custom-mutator-only mode)  │   pending : 555       │
│ arithmetics : disabled (custom-mutator-only mode)  │  pend fav : 77        │
│  known ints : disabled (custom-mutator-only mode)  │ own finds : 133       │
│  dictionary : n/a                                  │  imported : 0         │
│havoc/splice : 0/0, 0/0                             │ stability : 100.00%   │
│py/custom/rq : unused, 150/858, unused, unused      ├───────────────────────┘
│    trim/eff : 5.90%/361, disabled                  │             [cpu: 12%]
└─ strategy: explore ────────── state: in progress ──┘[!] WARNING: >>-6A Odd size of register is: 75, 8
```


Non-interactive mode and full run: The results in the paper are created with batch runs. We need to run each repeat for all initial corpora to get the full results for Table III:
```
# Repeat 1
./Experiment-ARM-24h.sh CodeBooga-cmin 1
./Experiment-ARM-24h.sh gpt3.5-new-cmin 1
./Experiment-ARM-24h.sh gpt3.5-old-cmin 1
./Experiment-ARM-24h.sh Llama-cmin 1
./Experiment-ARM-24h.sh Magicoder-cmin 1
./Experiment-ARM-24h.sh Phi-cmin 1
./Experiment-ARM-24h.sh TinyLlama-cmin 1

# Repeat 3
./Experiment-ARM-24h.sh CodeBooga-cmin 3
./Experiment-ARM-24h.sh gpt3.5-new-cmin 3
./Experiment-ARM-24h.sh gpt3.5-old-cmin 3
./Experiment-ARM-24h.sh Llama-cmin 3
./Experiment-ARM-24h.sh Magicoder-cmin 3
./Experiment-ARM-24h.sh Phi-cmin 3
./Experiment-ARM-24h.sh TinyLlama-cmin 3

# Repeat 4
./Experiment-ARM-24h.sh CodeBooga-cmin 1
./Experiment-ARM-24h.sh gpt3.5-new-cmin 1
./Experiment-ARM-24h.sh gpt3.5-old-cmin 1
./Experiment-ARM-24h.sh Llama-cmin 1
./Experiment-ARM-24h.sh Magicoder-cmin 1
./Experiment-ARM-24h.sh Phi-cmin 1
./Experiment-ARM-24h.sh TinyLlama-cmin 1

# Repeat 4
./Experiment-ARM-24h.sh CodeBooga-cmin 4
./Experiment-ARM-24h.sh gpt3.5-new-cmin 4
./Experiment-ARM-24h.sh gpt3.5-old-cmin 4
./Experiment-ARM-24h.sh Llama-cmin 4
./Experiment-ARM-24h.sh Magicoder-cmin 4
./Experiment-ARM-24h.sh Phi-cmin 4
./Experiment-ARM-24h.sh TinyLlama-cmin 4

# Repeat 5
./Experiment-ARM-24h.sh CodeBooga-cmin 5
./Experiment-ARM-24h.sh gpt3.5-new-cmin 5
./Experiment-ARM-24h.sh gpt3.5-old-cmin 5
./Experiment-ARM-24h.sh Llama-cmin 5
./Experiment-ARM-24h.sh Magicoder-cmin 5
./Experiment-ARM-24h.sh Phi-cmin 5
./Experiment-ARM-24h.sh TinyLlama-cmin 5
```
From each output folder, we analysed the size of queue, crash and hang folders. Further statistics are in fuzzer_stats file. These scripts ensure the run for 24 hours per repeat and input corpus.

Note that, as fuzzing is random, the results in Table III can be slightly different between two repeats of the same initial corpus. 





### 2.5 Differential Testing of Fuzzed Corpus Seeds (Section V.B. & Table IV):

We use the same scripts here as in Section 2.3, but with the output fuzzed folders:
```
# In the paper we analysed repeat 5, but you can change it to any:
./1-run-diff-test.sh /home/debian/experiment/CodeBooga-cmin/output-r_5/default/queue > Fuzzed-diff-testing-CodeBooga-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Llama-cmin/output-r_5/default/queue > Fuzzed-diff-testing-Llama-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Magicoder-cmin/output-r_5/default/queue > Fuzzed-diff-testing-Magicoder-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/Phi-cmin/output-r_5/default/queue > Fuzzed-diff-testing-Phi-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/TinyLlama-cmin/output-r_5/default/queue > Fuzzed-diff-testing-TinyLlama-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/gpt3.5-new-cmin/output-r_5/default/queue > Fuzzed-diff-testing-gpt3.5-new-5.log 2>&1
./1-run-diff-test.sh /home/debian/experiment/gpt3.5-old-cmin/output-r_5/default/queue > Fuzzed-diff-testing-gpt3.5-old-5.log 2>&1
```
The analysis here and identify the bugs are done manually and require a system simulator expert.





## 3. Reproduce ICSE-SEIP 2025 Evaluation - Shorter Version and Statistics from Dataset:

Available: the source code is at https://github.com/karineek/SearchGEM5/tree/main with the extra scripts for ARM and the instructions fully documented in this Zenodo Record in Sections 1 and 2. We added code.zip to this publicly accessible archival Zenodo record to meet the availability requirements. 

Functional: The artifact associated with the research are documented fully in sections 2.3, 2.4 and 2.5. Due to its time requirements, we present a shorter version in this section with additional scripts to allow easy quick reproduction of the shorter version's results. We added expected results to help validate the results and noted where the results can be different (e.g. when fuzzing for 2 hours instead of 24 hours).

Reusable: Section 2 and the documentation at https://github.com/karineek/SearchGEM5/tree/main allow customisation to other targets and editing/adding to the code of SearchSYS. We attached a copy of the GitHub repository here, to ensure the documentation and code are in a single place.



### 3.1 Table I - Shortened Version

We added the tokens from the GitHub of SearchSYS into four files and filtered out duplicate tokens.

To reproduce the counters of Table I:
```
wget "https://zenodo.org/records/14724553/files/TABLE-1.zip" # Get the data and scripts
unzip TABLE-1.zip
cd TABLE-1
./table-1.sh
```

This should give you:
```
$ ./table-1.sh 
>> Token-1 Examples
ID_1.log:1:"Scalar Optimizations", 
ID_1.log:2:"Dead Code Elimination", 
ID_1.log:3:"Constant Folding", 
>> Token-2 Examples
ID_2.log:32:"Sema", 
ID_2.log:33:"Serialization", 
ID_2.log:34:"Parse", 
ID_2.log:35:"Lex", 
ID_2.log:36:"AST",
>> Token-3 Examples
ID_3.log:86:"C Program to Sort an Array using Merge Sort",
ID_3.log:58:"Calendar Year in Different Formats", 
ID_3.log:176:"input include several arguments", 
>> Token-4 Examples
ID_4.log:   343:AND operators,
ID_4.log:   779:cimagl function,
ID_4.log:  1132:EOF,
ID_4.log:  1915:locale,
ID_4.log:  2328:pow,
ID_4.log:  2614:SCNiMAX,
      26 ID_1.log
      36 ID_2.log
     192 ID_3.log
    3480 ID_4.log
    3734 total
```

### 3.2 Table II and Table IV- Shortened Version

We run differential testing to only one of the sets, A, as it is the smallest (and hence should finish quickly). We can then reproduce the table for B-G by using the logs in the Excel file.

You will need two scripts for this stage:
```
cd /home/debian/
wget "https://zenodo.org/records/14724553/files/1-run-diff-test.sh" 
wget "https://zenodo.org/records/14724553/files/2-test-input.sh"
wget "https://zenodo.org/records/14724553/files/ICSE-SEIP-Bugs-READY.xlsx" ICSE-SEIP-Bugs-READY.xlsx" 
chmod 777 1-run-diff-test.sh
chmod 777 2-test-input.sh
```
We need the newest version of gem5 and compare it to native run. If you have not yet built gem5, run:
```
cd /home/debian
git clone https://github.com/gem5/gem5.git
cd gem5
pip install -r requirements.txt
scons build/ARM/gem5.opt -j 4
cd /home/debian
```
To run a single test:
```
/home/debian/gem5/build/ARM/gem5.opt /home/debian/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input /home/debian/experiment/CodeBooga-cmin/input/test_input_645596930837886.txt
```
You can try different test inputs by changing the file after the --input. To run a single comparison between native and simulation, you run:
```
./2-test-input.sh /home/debian/experiment/CodeBooga-cmin/input/test_input_645596930837886.txt
```
We start with running differential testing on set A:
```
nohup ./1-run-diff-test.sh /home/debian/experiment/TinyLlama-cmin/input > LLM-diff-testing-TinyLlama.log 2>&1 &
nohup ./1-run-diff-test.sh /home/debian/experiment/TinyLlama-cmin/output-r_5/default/queue > AFL-diff-testing-TinyLlama.log 2>&1 &
```
Then we analyse this manually, as not every failure to simulate a binary is a bug (it can be that the fuzzing corrupted the binary, and the expected behaviour is NOT to run the simulation successfully). However, you can "grep" the error strings, as some of the errors will likely manifest during the fuzzing.



### 3.3 Table III - Shortened Version

We will do the following: run fuzzing for 1 hour with corpus TinyLlama and check there are results in the queue to see that the fuzzing generated some files. We can reproduce the table from the logs (the full experiments here shall take 24x5x7 hours, which is beyond the expectation of artifact evaluation).

```
# Define:
cd /home/debian/
cm_path="/home/debian/SearchGEM5/src/custom_mutators"
corpus_folder="/home/debian/experiment/TinyLlama-cmin/"
execgem5=/home/debian/gem5-ssbse-challenge-2023/build/ARM/gem5.opt

# Run AFL
AFL_NO_AFFINITY=1 AFL_SHUFFLE_QUEUE=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_FAST_CAL=1 AFL_IGNORE_PROBLEMS=1 \
   AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_BIN_CHECK=1 AFL_MAP_SIZE=1200000 \
   AFL_CUSTOM_MUTATOR_LIBRARY="$cm_path/cm-gem5c.so;$cm_path/cm-gem5c-bin.so;$cm_path/cm-gem5c-types.so" \
   /home/debian/AFLplusplus/afl-fuzz -m 50000 -t 99000 -i $corpus_folder/input/  -o $corpus_folder/output-fuzzed/ -- $execgem5 \
   /home/debian/SearchGEM5/hello-custom-binary-Ex.py --isa ARM --input @@
```
You should get the same interface as in 2.4 with version:
```
AFL ++4.31a {default} (...ssbse-challenge-2023/build/ARM/gem5.opt) [explore]... 
```

Then to reproduce the numbers, you can mine the logs of the original fuzzing campaign. 

You will need one script for this stage:
```
cd /home/debian/
wget "https://zenodo.org/records/14724553/files/3-run-stat-table-3.sh" 
chmod 777 3-run-stat-table-3.sh
and the logs:
mkdir experiments-prev
cd experiments-prev
wget "https://zenodo.org/records/14724553/files/round-1-output.tar.gz"
wget "https://zenodo.org/records/14724553/files/round-2-output.tar.gz"
wget "https://zenodo.org/records/14724553/files/round-3-output.tar.gz"
wget "https://zenodo.org/records/14724553/files/round-4-output.tar.gz"
wget "https://zenodo.org/records/14724553/files/round-5-output.tar.gz" 
```

Then run:
```
tar -xf round-1-output.tar.gz
tar -xf round-2-output.tar.gz
tar -xf round-3-output.tar.gz
tar -xf round-4-output.tar.gz
tar -xf round-5-output.tar.gz
./3-run-stat-table-3.sh experiments-prev
```

This should print:
```
$ ./3-stat-table-3.sh 
Initial Corpus Size: 612 (Directory: CodeBooga-cmin/input)
Initial Corpus Size: 17 (Directory: CodeBooga-cmin/output-r_1/default/crashes)
Initial Corpus Size: 17 (Directory: CodeBooga-cmin/output-r_1/default/hangs)
Initial Corpus Size: 905 (Directory: CodeBooga-cmin/output-r_1/default/queue)
Initial Corpus Size: 3 (Directory: CodeBooga-cmin/output-r_2/default/crashes)
Initial Corpus Size: 23 (Directory: CodeBooga-cmin/output-r_2/default/hangs)
Initial Corpus Size: 685 (Directory: CodeBooga-cmin/output-r_2/default/queue)
Initial Corpus Size: 12 (Directory: CodeBooga-cmin/output-r_3/default/crashes)
Initial Corpus Size: 3 (Directory: CodeBooga-cmin/output-r_3/default/hangs)
Initial Corpus Size: 842 (Directory: CodeBooga-cmin/output-r_3/default/queue)
Initial Corpus Size: 7 (Directory: CodeBooga-cmin/output-r_4/default/crashes)
Initial Corpus Size: 11 (Directory: CodeBooga-cmin/output-r_4/default/hangs)
Initial Corpus Size: 728 (Directory: CodeBooga-cmin/output-r_4/default/queue)
Initial Corpus Size: 17 (Directory: CodeBooga-cmin/output-r_5/default/crashes)
Initial Corpus Size: 12 (Directory: CodeBooga-cmin/output-r_5/default/hangs)
Initial Corpus Size: 922 (Directory: CodeBooga-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 703 (Directory: gpt3.5-new-cmin/input)
Initial Corpus Size: 10 (Directory: gpt3.5-new-cmin/output-r_1/default/crashes)
Initial Corpus Size: 2 (Directory: gpt3.5-new-cmin/output-r_1/default/hangs)
Initial Corpus Size: 839 (Directory: gpt3.5-new-cmin/output-r_1/default/queue)
Initial Corpus Size: 11 (Directory: gpt3.5-new-cmin/output-r_2/default/crashes)
Initial Corpus Size: 8 (Directory: gpt3.5-new-cmin/output-r_2/default/hangs)
Initial Corpus Size: 898 (Directory: gpt3.5-new-cmin/output-r_2/default/queue)
Initial Corpus Size: 14 (Directory: gpt3.5-new-cmin/output-r_3/default/crashes)
Initial Corpus Size: 9 (Directory: gpt3.5-new-cmin/output-r_3/default/hangs)
Initial Corpus Size: 877 (Directory: gpt3.5-new-cmin/output-r_3/default/queue)
Initial Corpus Size: 12 (Directory: gpt3.5-new-cmin/output-r_4/default/crashes)
Initial Corpus Size: 5 (Directory: gpt3.5-new-cmin/output-r_4/default/hangs)
Initial Corpus Size: 855 (Directory: gpt3.5-new-cmin/output-r_4/default/queue)
Initial Corpus Size: 11 (Directory: gpt3.5-new-cmin/output-r_5/default/crashes)
Initial Corpus Size: 11 (Directory: gpt3.5-new-cmin/output-r_5/default/hangs)
Initial Corpus Size: 886 (Directory: gpt3.5-new-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 442 (Directory: gpt3.5-old-cmin/input)
Initial Corpus Size: 43 (Directory: gpt3.5-old-cmin/output-r_1/default/crashes)
Initial Corpus Size: 2 (Directory: gpt3.5-old-cmin/output-r_1/default/hangs)
Initial Corpus Size: 964 (Directory: gpt3.5-old-cmin/output-r_1/default/queue)
Initial Corpus Size: 52 (Directory: gpt3.5-old-cmin/output-r_2/default/crashes)
Initial Corpus Size: 5 (Directory: gpt3.5-old-cmin/output-r_2/default/hangs)
Initial Corpus Size: 988 (Directory: gpt3.5-old-cmin/output-r_2/default/queue)
Initial Corpus Size: 57 (Directory: gpt3.5-old-cmin/output-r_3/default/crashes)
Initial Corpus Size: 6 (Directory: gpt3.5-old-cmin/output-r_3/default/hangs)
Initial Corpus Size: 934 (Directory: gpt3.5-old-cmin/output-r_3/default/queue)
Initial Corpus Size: 49 (Directory: gpt3.5-old-cmin/output-r_4/default/crashes)
Initial Corpus Size: 0 (Directory: gpt3.5-old-cmin/output-r_4/default/hangs)
Initial Corpus Size: 891 (Directory: gpt3.5-old-cmin/output-r_4/default/queue)
Initial Corpus Size: 47 (Directory: gpt3.5-old-cmin/output-r_5/default/crashes)
Initial Corpus Size: 1 (Directory: gpt3.5-old-cmin/output-r_5/default/hangs)
Initial Corpus Size: 957 (Directory: gpt3.5-old-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 613 (Directory: Llama-cmin/input)
Initial Corpus Size: 25 (Directory: Llama-cmin/output-r_1/default/crashes)
Initial Corpus Size: 11 (Directory: Llama-cmin/output-r_1/default/hangs)
Initial Corpus Size: 1014 (Directory: Llama-cmin/output-r_1/default/queue)
Initial Corpus Size: 19 (Directory: Llama-cmin/output-r_2/default/crashes)
Initial Corpus Size: 19 (Directory: Llama-cmin/output-r_2/default/hangs)
Initial Corpus Size: 939 (Directory: Llama-cmin/output-r_2/default/queue)
Initial Corpus Size: 7 (Directory: Llama-cmin/output-r_3/default/crashes)
Initial Corpus Size: 14 (Directory: Llama-cmin/output-r_3/default/hangs)
Initial Corpus Size: 929 (Directory: Llama-cmin/output-r_3/default/queue)
Initial Corpus Size: 15 (Directory: Llama-cmin/output-r_4/default/crashes)
Initial Corpus Size: 18 (Directory: Llama-cmin/output-r_4/default/hangs)
Initial Corpus Size: 857 (Directory: Llama-cmin/output-r_4/default/queue)
Initial Corpus Size: 16 (Directory: Llama-cmin/output-r_5/default/crashes)
Initial Corpus Size: 18 (Directory: Llama-cmin/output-r_5/default/hangs)
Initial Corpus Size: 909 (Directory: Llama-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 719 (Directory: Magicoder-cmin/input)
Initial Corpus Size: 14 (Directory: Magicoder-cmin/output-r_1/default/crashes)
Initial Corpus Size: 8 (Directory: Magicoder-cmin/output-r_1/default/hangs)
Initial Corpus Size: 1012 (Directory: Magicoder-cmin/output-r_1/default/queue)
Initial Corpus Size: 17 (Directory: Magicoder-cmin/output-r_2/default/crashes)
Initial Corpus Size: 13 (Directory: Magicoder-cmin/output-r_2/default/hangs)
Initial Corpus Size: 1010 (Directory: Magicoder-cmin/output-r_2/default/queue)
Initial Corpus Size: 15 (Directory: Magicoder-cmin/output-r_3/default/crashes)
Initial Corpus Size: 13 (Directory: Magicoder-cmin/output-r_3/default/hangs)
Initial Corpus Size: 974 (Directory: Magicoder-cmin/output-r_3/default/queue)
Initial Corpus Size: 11 (Directory: Magicoder-cmin/output-r_4/default/crashes)
Initial Corpus Size: 8 (Directory: Magicoder-cmin/output-r_4/default/hangs)
Initial Corpus Size: 958 (Directory: Magicoder-cmin/output-r_4/default/queue)
Initial Corpus Size: 13 (Directory: Magicoder-cmin/output-r_5/default/crashes)
Initial Corpus Size: 13 (Directory: Magicoder-cmin/output-r_5/default/hangs)
Initial Corpus Size: 896 (Directory: Magicoder-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 366 (Directory: Phi-cmin/input)
Initial Corpus Size: 18 (Directory: Phi-cmin/output-r_1/default/crashes)
Initial Corpus Size: 16 (Directory: Phi-cmin/output-r_1/default/hangs)
Initial Corpus Size: 707 (Directory: Phi-cmin/output-r_1/default/queue)
Initial Corpus Size: 13 (Directory: Phi-cmin/output-r_2/default/crashes)
Initial Corpus Size: 26 (Directory: Phi-cmin/output-r_2/default/hangs)
Initial Corpus Size: 707 (Directory: Phi-cmin/output-r_2/default/queue)
Initial Corpus Size: 18 (Directory: Phi-cmin/output-r_3/default/crashes)
Initial Corpus Size: 18 (Directory: Phi-cmin/output-r_3/default/hangs)
Initial Corpus Size: 704 (Directory: Phi-cmin/output-r_3/default/queue)
Initial Corpus Size: 12 (Directory: Phi-cmin/output-r_4/default/crashes)
Initial Corpus Size: 18 (Directory: Phi-cmin/output-r_4/default/hangs)
Initial Corpus Size: 568 (Directory: Phi-cmin/output-r_4/default/queue)
Initial Corpus Size: 16 (Directory: Phi-cmin/output-r_5/default/crashes)
Initial Corpus Size: 10 (Directory: Phi-cmin/output-r_5/default/hangs)
Initial Corpus Size: 721 (Directory: Phi-cmin/output-r_5/default/queue)
---------------------------------
Initial Corpus Size: 206 (Directory: TinyLlama-cmin/input)
Initial Corpus Size: 24 (Directory: TinyLlama-cmin/output-r_1/default/crashes)
Initial Corpus Size: 9 (Directory: TinyLlama-cmin/output-r_1/default/hangs)
Initial Corpus Size: 770 (Directory: TinyLlama-cmin/output-r_1/default/queue)
Initial Corpus Size: 36 (Directory: TinyLlama-cmin/output-r_2/default/crashes)
Initial Corpus Size: 9 (Directory: TinyLlama-cmin/output-r_2/default/hangs)
Initial Corpus Size: 802 (Directory: TinyLlama-cmin/output-r_2/default/queue)
Initial Corpus Size: 34 (Directory: TinyLlama-cmin/output-r_3/default/crashes)
Initial Corpus Size: 12 (Directory: TinyLlama-cmin/output-r_3/default/hangs)
Initial Corpus Size: 748 (Directory: TinyLlama-cmin/output-r_3/default/queue)
Initial Corpus Size: 29 (Directory: TinyLlama-cmin/output-r_4/default/crashes)
Initial Corpus Size: 11 (Directory: TinyLlama-cmin/output-r_4/default/hangs)
Initial Corpus Size: 783 (Directory: TinyLlama-cmin/output-r_4/default/queue)
Initial Corpus Size: 31 (Directory: TinyLlama-cmin/output-r_5/default/crashes)
Initial Corpus Size: 9 (Directory: TinyLlama-cmin/output-r_5/default/hangs)
Initial Corpus Size: 634 (Directory: TinyLlama-cmin/output-r_5/default/queue)
---------------------------------
```
==
