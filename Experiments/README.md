# Experiments

## LLM-based test case generation

TODO

## Preparing folders to be AFL-READY

After generating the data, we need to prepare the test inputs to be ready to fuzz. 

We set a visible folder for AFL++ (aka input) but the binary folder will be managed directly by our custom mutators.

To prepare the data we did this per generated set (You do not have to repeat it):
  - First, we copied the generated set as is to raw.
  - Then we ran these:
```
cd raw
for prog in *.c; do gcc -O3 "$prog" -o "$prog.o"; done
cd ..
mkdir binary input
cp raw/*.type binary/
cp raw/*.o binary/
cp raw/*.txt input/

cd input
rename "s/.c.txt/.txt/" *.txt
sed -i 's:test_input_:/home/ubuntu/experiment-7/TinyLlama/binary/test_input_:g' *.txt
cd ..
ls -l input/*.txt | wc -l
cp -r input split
cd split
for i in `seq 1 10`; do mkdir -p "folder$i"; find . -type f -maxdepth 1 | head -n 25 | xargs -i mv "{}" "folder$i"; done
mv *.txt folder10
ls -l folder1 | wc -l
ls -l folder2 | wc -l
ls -l folder3 | wc -l
ls -l folder4 | wc -l
ls -l folder5 | wc -l
ls -l folder6 | wc -l
ls -l folder7 | wc -l
ls -l folder8 | wc -l
ls -l folder9 | wc -l
ls -l folder10 | wc -l
cd .. ; cd ..
```

After all, We tar them (to save space):
```
tar -czvf  AFL-READY-CodeBooga.tar.gz  CodeBooga 
tar -czvf  AFL-READY-Llama.tar.gz Llama
tar -czvf  AFL-READY-Magicoder.tar.gz Magicoder 
tar -czvf  AFL-READY-Phi.tar.gz Phi 
tar -czvf  AFL-READY-TinyLlama.tar.gz TinyLlama
tar -czvf  AFL-READY-gpt3.5.tar.gz gpt3.5-new
tar -czvf  AFL-READY-gpt3.5-ssbse-2023.tar.gz gpt3.5-old
```

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
For example:
```
./../scripts/filterTests.sh /home/ubuntu/sets/gpt3.5-new/results/ /home/ubuntu/sets/gpt3.5-new/gpt3.5-new/  /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
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
First make sure the system is not due to reboot:
```
sudo shutdown -c
```

To fuzz with AFL++ using any of the input sets (generated via LLM):
TODO

To fuzz with the mutators from SSBSE2023 version:
```
 AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY="/home/ubuntu/ASEGem5/src/custom_mutators/cm-gem5.so" /home/ubuntu/AFLplusplus/afl-fuzz  -m 50000 -t 99000 -i /home/ubuntu/experiment-7/gpt3.5-old/input/ -o output12 /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py  --isa X86 --input @@
```
