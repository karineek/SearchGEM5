echo "--> TOTAL: "
ls -l Experiment-*/BUG-*/gem5.log | wc -l

echo "--> Not a bug:"
grep "gem5 has encountered a segmentation fault!" Experiment-*/BUG-*/gem* | cut -d':' -f1 | sort | uniq
grep "gem5 has encountered a segmentation fault!" Experiment-*/BUG-*/gem* | wc -l
echo "===== END Not a bug ====="

echo "--> Assertion violation in gem5"
grep -e"Assertion" Experiment-*/BUG-*/gem5.log | wc -l

echo "--> src/base/loader/elf_object.cc:80: virtual gem5::loader::ObjectFile* gem5::loader::ElfObjectFormat::load(gem5::loader::Im"
grep -e"Assertion" Experiment-*/BUG-*/gem5.log | grep "src/base/loader/elf_object.cc:80: virtual gem5::loader::ObjectFile" | wc -l

echo "--> src/base/loader/elf_object.cc:311: void gem5::loader::ElfObject::determineOpSys(): Assertion"
grep -e"Assertion" Experiment-*/BUG-*/gem5.log | grep "src/base/loader/elf_object.cc:311: void gem5::loader::ElfObject::determineOpSys(): Assertion" | wc -l

#ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-1-18-Aug-2023-X86$ grep -e"Assertion" BUG-*/gem5.log 
#BUG-45/gem5.log:gem5.opt: src/base/loader/elf_object.cc:80: virtual gem5::loader::ObjectFile* gem5::loader::ElfObjectFormat::load(gem5::loader::ImageFileDataPtr): Assertion `elf' failed.
#BUG-46/gem5.log:gem5.opt: src/base/loader/elf_object.cc:80: virtual gem5::loader::ObjectFile* gem5::loader::ElfObjectFormat::load(gem5::loader::ImageFileDataPtr): Assertion `elf' failed.
#ubuntu@fuzzer-03:~/Gem5Testing/Evaluation/Experiment-1-18-Aug-2023-X86$ 

echo "Number of bugs:"
grep "panic" Experiment-*/BUG-*/gem* | wc -l

echo "--> src/arch/x86/faults.cc:166: panic: Tried to write unmapped address"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/arch/x86/faults.cc:166: panic: Tried to write unmapped address" | wc -l

echo "--> src/arch/x86/faults.cc:166: panic: Tried to read unmapped address"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/arch/x86/faults.cc:166: panic: Tried to read unmapped address" | wc -l

echo "--> src/arch/x86/faults.cc:166: panic: Tried to execute unmapped address"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/arch/x86/faults.cc:166: panic: Tried to execute unmapped address" | wc -l

echo "--> src/arch/x86/faults.cc:164: panic: Tried to execute unmapped address" 
grep "panic" Experiment-*/BUG-*/gem* | grep "src/arch/x86/faults.cc:164: panic: Tried to execute unmapped address" | wc -l

echo "--> src/arch/x86/faults.cc:131: panic: Unrecognized/invalid instruction executed"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/arch/x86/faults.cc:131: panic: Unrecognized/invalid instruction executed" | wc -l

echo "--> src/cpu/simple/timing.cc:953: panic: panic condition pkt->isError() occurred: Data access"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/cpu/simple/timing.cc:953: panic: panic condition pkt->isError() occurred: Data access" | wc -l

echo "--> src/base/loader/memory_image.hh:70: panic: panic condition offset + size > ifd->len() occurred: Segment"
grep "panic" Experiment-*/BUG-*/gem* | grep "src/base/loader/memory_image.hh:70: panic: panic condition offset + size > ifd->len() occurred: Segment outside the bounds of the image data" | wc -l

echo "--> src/base/loader/elf_object.cc:129: panic: gelf_getphdr failed for segment 0."
grep "panic" Experiment-*/BUG-*/gem* | grep "src/base/loader/elf_object.cc:129: panic: gelf_getphdr failed for segment 0." | wc -l

echo "--> FullSystem occurred: fault (General-Protection) detected"
grep "panic" Experiment-*/BUG-*/gem* | grep "FullSystem occurred: fault (General-Protection) detected" | wc -l

echo "--> build/X86/arch/x86/generated/exec-ns.cc.inc:17: panic: attempt to execute unimplemented instruction 'femm'"
grep "panic" Experiment-*/BUG-*/gem* | grep "build/X86/arch/x86/generated/exec-ns.cc.inc:17: panic: attempt to execute unimplemented instruction" | wc -l
