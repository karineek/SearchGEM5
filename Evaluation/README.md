# Reporting Bugs

During the evaluation, we found bugs such as mis-simulation, hang of the simulation and crashes.

To report these you have to take the following steps.

1. Download the recent version of gem5 and build it.
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

2. Try to reproduce the bug with the latest version.
   - If the bug still exists in the most recent version, consider reporting it.

3. Add the bug to SSBSE-gem5-bugs.xlsx with any detail you can extract:
   - Date, inputs, object, mutations carried, logs, etc.
