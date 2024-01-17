# Reporting Bugs

During the evaluation, we found bugs such as mis-simulation, hang of the simulation and crashes.

To report these you have to take the following steps.

## 1. Download gem5.

When reporting bugs, it is essential to respect the developers' time and report bugs that exist only in the tool's most recent version.

To do so, you will need to download the recent version of gem5, build it, and use it to try to reproduce the error again.

To clone and build:
```
git clone https://github.com/gem5/gem5.git
cd gem5/
pip install -r requirements.txt
scons build/X86/gem5.opt -j 4
```
This will give you output similar to:
```
 [     CXX] X86/mem/ruby/slicc_interface/Controller.py.cc -> .o
 [SO Param] m5.objects.Controller, RubyController -> X86/python/_m5/param_RubyController.cc
 [     CXX] src/mem/ruby/slicc_interface/AbstractController.cc -> X86/mem/ruby/slicc_interface/AbstractController.o
 [     CXX] X86/python/_m5/param_RubyController.cc -> .o
 [     CXX] src/mem/ruby/slicc_interface/AbstractCacheEntry.cc -> X86/mem/ruby/slicc_interface/AbstractCacheEntry.o
 [     CXX] src/mem/ruby/slicc_interface/RubyRequest.cc -> X86/mem/ruby/slicc_interface/RubyRequest.o
 [     CXX] X86/python/m5/defines.py.cc -> .o
 [     CXX] X86/python/m5/info.py.cc -> .o
 [     CXX] src/base/date.cc -> X86/base/date.o
 [    LINK]  -> X86/gem5.opt
scons: done building targets.
*** Summary of Warnings ***
Warning: Deprecated namespaces are not supported by this compiler.
         Please make sure to check the mailing list for deprecation announcements.
Warning: Header file <capstone/capstone.h> not found.
         This host has no capstone library installed.
Warning: Can not enable KVM, host seems to lack KVM support
```
And you should double check you got the message: "scons: done building targets.".

## 2. Try to reproduce the bug with the latest version.
I took the set of 17 bugs we reported via email in the SSBSE paper and tried to check if any still have not yet been fixed.

Let's look at bug 17. It is a mis-simulation with byval-alignment.c (LLVM test suite program). I did the following steps:

   - Run gem5 from August 2023:
```
/home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input byval-alignment_test1.txt
```
With the input in byval-alignment_test1.txt:
```
/home/ubuntu/experiment-6/binary/byval-alignment.c.o
2.0 2.0
```
and got 
```
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
g0.x: 3.0000, g0.y: 3.0000
Exiting @ tick 11785715487 because exiting with last active thread context.
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-3-20-Aug-2023-X86-6h/Q/BUG-1179$ /home/ubuntu/gem5-17012024/gem5/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input byval-alignment_test1.txt Experiment-3-20-Aug-2023-X86-6h/Q/BUG-1179^C
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-3-20-Aug-2023-X86-6h/Q/BUG-1179$ /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input byval-alignment_test1.txt 
gem5 Simulator System.  https://www.gem5.org
gem5 is copyrighted software; use the --copyright option for details.

gem5 version 23.0.0.1--SSBSE Challeng Track
gem5 compiled Aug 13 2023 00:24:12
gem5 started Jan 17 2024 12:48:50
gem5 executing on fuzzer-03, pid 973584
command line: /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input byval-alignment_test1.txt

Global frequency set at 1000000000000 ticks per second
warn: No dot file generated. Please install pydot to generate the dot file and pdf.
src/mem/dram_interface.cc:690: warn: DRAM device capacity (8192 Mbytes) does not match the address range assigned (32 Mbytes)
src/base/statistics.hh:279: warn: One of the stats is a legacy stat. Legacy stat is a stat that does not belong to any statistics::Group. Legacy stat is deprecated.
board.remote_gdb: Listening for connections on port 7000
src/sim/simulate.cc:194: info: Entering event queue @ 0.  Starting simulation...
src/sim/mem_state.cc:443: info: Increasing stack size by one page.
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
src/sim/syscall_emul.cc:74: warn: ignoring syscall mprotect(...)
g0.x: 3.0000, g0.y: 5.0000
Exiting @ tick 11791866663 because exiting with last active thread context.
```
That is the output is: "g0.x: 3.0000, g0.y: 5.0000", while with X86 machine:
```
ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-3-20-Aug-2023-X86-6h/Q/BUG-1179$ /home/ubuntu/experiment-6/binary/byval-alignment.c.o 2.0 2.0
g0.x: 3.0000, g0.y: 3.0000
```
The output is: "g0.x: 3.0000, g0.y: 3.0000". So, this is the original bug: wrong result during simulation.


   - Next, I will try to reproduce the bug with the new version of gem5.
     
   - If the bug still exists in the most recent version, consider reporting it.

## 3. Add the bug to SSBSE-gem5-bugs.xlsx with any detail you can extract:
   - Date, inputs, object, mutations carried, logs, etc.
