# SearchGEM5 - General Information
Gem5 testing project.

There are two projects:
- Main: https://github.com/gem5/gem5
- For the challenge: https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023

# Citation

*Aidan Dakhama, Karine Even-Mendoza, W.B. Langdon, Hector Menendez, and Justyna Petke (2023). SearchGEM5: Towards Reliable gem5 with Search Based Software Testing and Large Language Models. Symposium on Search Based Software Engineering (SSBSE).*

```
@inproceedings{EvenMendoza2023Gem5,
  title={SearchGEM5: Towards Reliable gem5 with Search Based Software Testing and Large Language Models},
  author={Aidan Dakhama, Karine Even-Mendoza, W.B. Langdon, Hector Menendez, and Justyna Petke},
  booktitle={Lecture Notes in Computer Science}
  year={2023},
  publisher={15th Symposium on Search Based Software Engineering (SSBSE)}
}
```

# Testing gem5

Zenodo artifact record: https://zenodo.org/records/8316685 (SSBSE 2023 Artifact).

The requirements are:
```
sudo apt-get update
sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config
sudo apt install libpng-dev libpng++-dev libhdf5-dev
sudo apt install python3-pip
```
These requirements can differ from one OS to another, see the full requirements [here](https://www.gem5.org/documentation/general_docs/building).

Getting gem5:
```
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
```
The original gem5 code is [here](https://github.com/gem5/gem5).

Building gem5:
```
cd gem5-ssbse-challenge-2023
pip install -r requirements.txt
scons build/X86/gem5.opt -j 4
```
If this ends properly, then we get:
```
...
 [     CXX] X86/mem/ruby/protocol/SequencerRequestType.cc -> .o
 [     CXX] X86/mem/ruby/protocol/SequencerStatus.cc -> .o
 [     CXX] X86/mem/ruby/protocol/SeriesRequestGeneratorStatus.cc -> .o
 [     CXX] X86/mem/ruby/protocol/TesterStatus.cc -> .o
 [     CXX] X86/mem/ruby/protocol/TransitionResult.cc -> .o
 [     CXX] X86/mem/ruby/slicc_interface/Controller.py.cc -> .o
 [SO Param] m5.objects.Controller, RubyController -> X86/python/_m5/param_RubyController.cc
 [     CXX] X86/python/_m5/param_RubyController.cc -> .o
 [     CXX] src/mem/ruby/slicc_interface/AbstractController.cc -> X86/mem/ruby/slicc_interface/AbstractController.o
 [     CXX] src/mem/ruby/slicc_interface/AbstractCacheEntry.cc -> X86/mem/ruby/slicc_interface/AbstractCacheEntry.o
 [     CXX] src/mem/ruby/slicc_interface/RubyRequest.cc -> X86/mem/ruby/slicc_interface/RubyRequest.o
 [     CXX] X86/python/m5/defines.py.cc -> .o
 [     CXX] X86/python/m5/info.py.cc -> .o
 [     CXX] src/base/date.cc -> X86/base/date.o
 [    LINK]  -> X86/gem5.opt
scons: done building targets.
```
To test if the build is working:
```
user@machine:~/gem5-ssbse-challenge-2023$ ./build/X86/gem5.opt -C
```

To run gem5 with 1 argument:
```
build/X86/gem5.opt configs/deprecated/example/se.py -c 00007.o -o "5"
```
with two arguments:
```
build/X86/gem5.opt configs/deprecated/example/se.py -c t.o -o "5 5"
```
And so on.

## LLM Code-Generation tool for gem5

We use ollama API for JAVA (ollama4j) to query test inputs to construct our corpus.

### OLLAMA API

You can download any hugging face model or use ollama ready to use models.
https://ollama.ai and https://hub.docker.com/r/ollama/ollama.

Install ollama:
```
curl https://ollama.ai/install.sh | sh
```

Check the the version of ollama:
```
ollama --version
```

### ollama models
To pull ready-to-user from ollama DB:
```
nano model2
[copy then this text into the file]
FROM phind-codellama:latest
PARAMETER num_gpu 0
[save and exit]

ollama create ollama_phi_no-gpu -f model2
```
You can find all the models here: https://ollama.ai/library.

### Hagging face model and other external models
We use a Hagging face model. To get this, you will need to run the following commands:
```
mkdir MODELS/
cd MODELS/
wget https://huggingface.co/TheBloke/deepseek-coder-6.7B-instruct-GGUF/resolve/main/deepseek-coder-6.7b-instruct.Q5_K_M.gguf
cd ..
```
We then need to create a model3 file similar to the above.

*** Please check [here](LLM-corpus-generation/README.md) for more explanations about the LLM in SearchGem5.

### Installing the LLM-based test input generator for gem5

To install this you will need [JAVA] (https://www.oracle.com/java/technologies/downloads/). 

We tested with Java-21 and Java-17. For example:
```
wget https://download.oracle.com/java/17/latest/jdk-17_linux-x64_bin.deb
sudo dpkg -i jdk-17_linux-x64_bin.deb
```
Then you will need to install Maven:
```
sudo apt update
sudo apt install maven
```
Then run:
```
mvn clean package
```
Check which .xml to use from the script folder (and copy to the main folder) depending on the JAVA version you have.

Then you can run the generator (for example):
```
java -jar target/program-generator-2.0.jar <model-name> <Pull-model?true-or-false-flag>
```

Troubleshooting with ollama. Ollama can hang or give timeouts too frequently. In such case, try to re-run the service:
```
sudo systemctl restart ollama.service
```
If this is not helping, try re-run the install script:
```
curl -fsSL https://ollama.com/install.sh | sh
```

## AFL Instrumentation of gem5

To fully instrument gem5 with AFL, copy first the scons scripts that allow afl compilation into gem5-ssbse-challenge-2023:
```
cp src/gem5-afl/SConstruct gem5-ssbse-challenge-2023/
cp src/gem5-afl/SConscript gem5-ssbse-challenge-2023/src/
```
Then install AFL++ for GCC so you can use GCC-based instrumentation of AFL for gem5. Some steps to reproduce it if your system default is GCC-11 and llvm-13:
```
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++ /usr/bin/cc
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/gcc-11 /usr/bin/cc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov

wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 13
sudo ln -s /usr/bin/llvm-config-13 /usr/bin/llvm-config

git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
make all
sudo make install 
```
Note: install should be to /usr/bin and not to /usr/local/bin.

Need then to run with different CC and CCX flags:
```
CC=afl-cc CXX=afl-c++ scons build/X86/gem5.opt -j 4 --no-cache
```
ending like this:
```
[*] Inline instrumentation at ratio of 100% in non-hardened mode.
[+] Instrumented 2327 locations (non-hardened mode, inline, ratio 100%).
[+] Instrumented 2714 locations (non-hardened mode, inline, ratio 100%).
 [     CXX] X86/python/m5/info.py.cc -> .o
afl-cc++4.08c by Michal Zalewski, Laszlo Szekeres, Marc Heuse - mode: GCC_PLUGIN-DEFAULT
afl-gcc-pass ++4.08c by <oliva@adacore.com>
[*] Inline instrumentation at ratio of 100% in non-hardened mode.
[+] Instrumented 2327 locations (non-hardened mode, inline, ratio 100%).
[+] Instrumented 4610 locations (non-hardened mode, inline, ratio 100%).
[+] Instrumented 2327 locations (non-hardened mode, inline, ratio 100%).
 [     CXX] src/base/date.cc -> X86/base/date.o
afl-cc++4.08c by Michal Zalewski, Laszlo Szekeres, Marc Heuse - mode: GCC_PLUGIN-DEFAULT
afl-gcc-pass ++4.08c by <oliva@adacore.com>
[*] Inline instrumentation at ratio of 100% in non-hardened mode.
[!] WARNING: No instrumentation targets found.
 [    LINK]  -> X86/gem5.opt
afl-cc++4.08c by Michal Zalewski, Laszlo Szekeres, Marc Heuse - mode: GCC_PLUGIN-DEFAULT
scons: done building targets.
```

Example of how to use it. Create main.c:
```
$ more main.c
#include <stdio.h>
int main ()
{
  int x = 5;int y = 5;
  printf("In the main proc. %d,%d",x,y);
  return x+y;
}
```
Then run gem5 plain (from gem5-ssbse-challenge-2023 folder):
```
build/X86/gem5.opt configs/deprecated/example/se.py -c main.o
```
Results:
```
...
**** REAL SIMULATION ****
src/sim/simulate.cc:194: info: Entering event queue @ 0.  Starting simulation...
src/sim/mem_state.cc:443: info: Increasing stack size by one page.
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
In the main proc. 5,5Exiting @ tick 176345000 because exiting with last active thread context
Simulated exit code not 0! Exit code is 10
```

To partially instrument gem5 with AFL:
TODO

### Pre-fuzzing Setup - Troubleshooting
We need to install gcc-11:
```
sudo apt-get -y install gcc-11 g++-11 cpp-11
```

We need to build AFL++ from source (v4.08c release, git commit f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58):
```
# Set env.
AFL_USE_ASAN=0

## Set gcov
sudo apt-get install gcc-11
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov

# For Cmake
sudo apt-get install libssl-dev

# Install pre-requirements
sudo apt-get install automake
sudo apt-get install python3-dev
python3 -m venv env/python
source env/python/bin/activate
pip3 install --upgrade pip
pip3 install wheel

sudo apt remove clang-10 clang-11 clang-9 clang-12
sudo rm -rf  /usr/bin/llvm-config
sudo apt autoremove

sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"
sudo chmod 777 llvm.sh
sudo ./llvm.sh 13
sudo apt-get install -y lld-13 llvm-13-dev clang-13
sudo apt-get install -y lld llvm llvm-dev clang
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
sudo apt-get install -y ninja-build cmake
sudo apt-get install -y wget git make cmake llvm gdb coreutils
sudo apt-get install gcc-11-plugin-dev
sudo apt autoremove

# Update default clang to 13
sudo update-alternatives --remove-all clang 
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-13 1300 --slave /usr/bin/clang++ clag++ /usr/bin/clang++-13
sudo update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-13 1300

# Remove olf AFL
rm -rf AFLplusplus

# Install AFL
LLVM_CONFIG=/usr/bin/llvm-config-13
#git clone https://github.com/google/AFL.git
#cd AFL
git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
AFL_USE_ASAN=0 make
sudo make install
```

We apply some edits (but not sure which one is needed for each version of AFL++):
```
git diff
diff --git a/qemu_mode/qemuafl b/qemu_mode/qemuafl
--- a/qemu_mode/qemuafl
+++ b/qemu_mode/qemuafl
@@ -1 +1 @@
-Subproject commit a1321713c7502c152dd7527555e0f8a800d55225
+Subproject commit a1321713c7502c152dd7527555e0f8a800d55225-dirty
diff --git a/src/afl-fuzz-init.c b/src/afl-fuzz-init.c
index 5a530821..0bef8400 100644
--- a/src/afl-fuzz-init.c
+++ b/src/afl-fuzz-init.c
@@ -881,7 +881,7 @@ void perform_dry_run(afl_state_t *afl) {
     q = afl->queue_buf[idx];
     if (unlikely(!q || q->disabled)) { continue; }
 
-    u8  res;
+    u8  res = 0;
     s32 fd;
 
     if (unlikely(!q->len)) {
@@ -919,6 +919,8 @@ void perform_dry_run(afl_state_t *afl) {
 
     }
 
+    SAYF("Results of dry-run %d", res);
+
     switch (res) {
 
       case FSRV_RUN_OK:
diff --git a/unicorn_mode/unicornafl b/unicorn_mode/unicornafl
--- a/unicorn_mode/unicornafl
+++ b/unicorn_mode/unicornafl
@@ -1 +1 @@
-Subproject commit f2cede37a75bbd4a9b9438f0277727b5d4620572
+Subproject commit f2cede37a75bbd4a9b9438f0277727b5d4620572-dirty
```

## Fuzzing with AFL

First, you will need to compiler the custom mutators:
```
cd src/
cd custom_mutators/
./compile_share.sh
```

You must create an input directory of C binaries (as templates of C programs). Then to run AFL:
```
mkdir experiments; cd experiments
mkdir input
mkdir binary

# copy .o files into binary
# copy .o.type files into binary
# copy .txt files into input
# Instrument gem5.opt with AFL (see instructions above)
# generate .so of our custom mutator: cm-gem5.so
...

# Runnin AFL
echo core >/proc/sys/kernel/core_pattern
AFL_DUMB_FORKSRV=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY="cm-gem5.so" afl-fuzz -m 50000 -t 99000 -i input -o output -- gem5.opt hello-custom-binary-Ex.py --isa X86 --input @@
```

We compare two versions of our custom mutators in this work. Old version:
```
cd .. 
git clone git@github.com:karineek/SearchGEM5.git
cd SearchGEM5
git checkout ssbse2023challenge

cd src/
cd custom_mutators/
./compile_share.sh

** Then copy the sets of inputs and binary, and run: **

date > afl_log_2023.txt; AFL_DUMB_FORKSRV=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY="<Full-path>/cm-gem5.so" nohup /home/ubuntu/AFLplusplus/afl-fuzz -m 50000 -t 99000 -i input -o output -- <Full-path>/gem5.opt <Full-path>/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input @@ >> afl_log_2023.txt 2>&1 &
```
and new version:
```
cd ../../ASEGem5/src/custom_mutators/
./compile_share.sh

** Then copy the sets of inputs and binary, and run: **

ubuntu@fuzzer-03:~/experiment-6$ more run-afl-new.sh
date > afl_log_2024.txt; AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_CUSTOM_MUTATOR_LIBRARY="<Full-path>/cm-gem5.so;<Full-path>/cm-gem5-bin.so;/home/ubuntu/Gem5Testing/src/custom_mutators/cm-gem5-types.so" nohup /home/ubuntu/AFLplusplus/afl-fuzz -m 50000 -t 99000 -i input -o output -- <Full-path>/gem5.opt <Full-path>/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input @@ >> afl_log_2024.txt 2>&1 &
```
Other useful flags are:
```
AFL_SHUFFLE_QUEUE=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_DUMB_FORKSRV=1 AFL_IGNORE_PROBLEMS=1 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_FAST_CAL=1
```

## Coverage with gcov
We take all test cases of gem5 and measure coverage.

### Base-line using gem5 Unittests
We build gem5 with gcov:

Getting gem5:
```
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
```
Building gem5 with gcov:
```
cd gem5-ssbse-challenge-2023
pip install -r requirements.txt
mkdir build
```
then you will need to edit X:
```
nano SConstruct
...
main = Environment(tools=[
        'default', 'git', TempFileSpawn, EnvDefaults, MakeActionTool,
        ConfigFile, AddLocalRPATH, SwitchingHeaders, TagImpliesTool, Blob
    ])

main.Tool(SCons.Tool.FindTool(['gcc', 'clang'], main))
main.Tool(SCons.Tool.FindTool(['g++', 'clang++'], main))

# ADD this line:
main.Replace(LIBS = ['gcov'], CXXFLAGS = ['-g', '-O0', '--coverage', '-ftest-coverage', '-fpro
file-arcs'], CCFLAGS = ['-g', '-O0', '--coverage', '-ftest-coverage', '-fprofile-arcs'], LINKF
LAGS = ['--coverage', '-ftest-coverage', '-fprofile-arcs'])
```
and run this:
```
export GCOV_PREFIX=$TMP_GCOV_FOLDER/coverage_gcda_files/application_run-init ## Send gcda of build to temp.
export GCOV_PREFIX_STRIP=0
export CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs'
export CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs'
export LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs'

CC=gcc-11 CXX=g++-11 CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs' scons -Q -c build/X86/gem5.opt -j 4 --no-cache

# Cleaning after build
rm -rf $TMP_GCOV_FOLDER
unset CFLAGS
unset CXXFLAGS
unset LDFLAGS
unset GCOV_PREFIX
unset GCOV_PREFIX_STRIP
```


# Process

The process contains several steps. First, we need to extract many test cases for compilers as a single big text file. We then train an LLM to do two functionalities: (i) take a code and turn it into a template and (ii) take a template and turn it into a code (with or without a specific assignment to the template's required values).

We explain later how we use it to test Gem5.

## Input Data
Get single files of C compiler benchmarking and test suites.

We construct it with the Unix command:
```
./add_filename.sh
cat *.c.x > all_tests.txt
rm *.c.x
```
the scripts and examples are in [raw_data](data/tests_raw_data).

## Training LLM to turn a concrete test case into an AFL-interface template

The idea is to take a program:
```
int
main()
{
	int x;
	
	x = 4;
	return x - 4;
}
```
from a known source, say: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00003.c
and ask the LLM model to do the following. Please create two C files from the file above. The first file, should contain no additional includes, but be documented with two additional comments: time and date, and the source of this file. The second file is similar to the first file but with the following twist. It replaces all constants in the function main, with args assignments and of course, adds any includes needed, and the comments before with date and time and the source of the original file.

ChatGPT gave us for the example above, the following two files:

Program 1 (00003.c):
```
// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00003.c

#include <stdio.h>

int main() {
    int x;

    x = 4;
    return x - 4;
}

```

and Program 2 (00003.c):
```
// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00003.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  return x - 4;
}
```

This will give us two programs to start our work.

## Cleaning the data 
Once having a corpus of programs or template programs generated automatically via LLM, we clean the data.
We remove any .c file that failed compilation of the reference platform.

## Generating a corpus of binaries
After removing all invalid programs from the input set, we use the reference machine with 
a specific version of a compiler and a set of compilation flags to generate a corpus of binaries.

We use the corpus of binaries for testing gem5.

Use this script to automate these two steps:
```
scripts % ./generate_corpus_of_binaries_and_native_logger.sh ../data/text ../data/corpusOfBinaries clang -O3 ../data/plainTextDiffTest.log
```
