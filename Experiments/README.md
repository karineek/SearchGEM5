# Experiments

## LLM-based test case generation

TODO

## Filtering Non-crashing Tests

We test per test if it crashes AFL++, and discard it if so. Otherwise, AFL++ will request to do so:
```
[-] Oops, the program crashed with one of the test cases provided. There are 

  several possible explanations: 

  
  - The test case causes known crashes under normal working conditions. If 

   so, please remove it. The fuzzer should be seeded with interesting 

   inputs - but not ones that cause an outright crash. 

  
  - The current memory limit (48.8 GB) is too low for this program, causing 

   it to die due to OOM when parsing valid files. To fix this, try 

   bumping it up with the -m setting in the command line. If in doubt, 

   try something along the lines of: 

   ( ulimit -Sd $[49999 << 10]; /path/to/binary [...] <testcase ) 

   Tip: you can use https://jwilk.net/software/recidivm to 

   estimate the required amount of virtual memory for the binary. Also, 

   if you are using ASAN, set '-m 0'. 

  - In QEMU persistent mode the selected address(es) for the loop are not 

   properly cleaning up variables and memory. Try adding 

   AFL_QEMU_PERSISTENT_GPR=1 or select better addresses in the binary. 

  - Least likely, there is a horrible bug in the fuzzer. If other options 

   fail, poke the Awesome Fuzzing Discord for troubleshooting tips. 
```

Run this script to filter test inputs crashing gem5 even before fuzzing fuzzing.
```
 ./../scripts/filterTests.sh <raw-data> <output> gem5.opt hello-custom-binary-Ex.py
```

## Prepare to Fuzz

You need to select a set, and copy it to a folder dedicated to the experiment. Then run:
```
tar -xvf  gpt3.5-old.tar.gz 
cd gpt3.5-old/
cd input/
sed -i "s:/home/ubuntu/sets/gpt3.5-old/sort/data:/home/ubuntu/experiment-7/gpt3.5-old/binary:g" *.txt
```

## Fuzzing

To fuzz with AFL++ using any of the input sets (generated via LLM):
TODO

To fuzz with the mutators from SSBSE2023 version:
TODO
