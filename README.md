# Gem5Testing
Gem5 testing project.

# gem5 instrumentation

The requirements are:
```
sudo apt-get update
sudo apt-get install build-essential git m4 scons zlib1g zlib1g-dev \
                     libprotobuf-dev protobuf-compiler libprotoc-dev \
                     libgoogle-perftools-dev python3-dev python3-six \
                     python-is-python3
```

Getting gem5:
```
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
```

Building gem5:
```
cd gem5-ssbse-challenge-2023
scons -jX build/<target architecture>/gem5.opt
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
