Command line used to find this crash:

/home/ubuntu/AFLplusplus/afl-fuzz -m 50000 -t 99000 -i input -o output -- /home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/ubuntu/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py --isa X86 --input @@

If you can't reproduce a bug outside of afl-fuzz, be sure to set the same
memory limit. The limit used for this fuzzing session was 48.8 GB.

Need a tool to minimize test cases before investigating the crashes or sending
them to a vendor? Check out the afl-tmin that comes with the fuzzer!

Found any cool bugs in open-source tools using afl-fuzz? If yes, please post
to https://github.com/AFLplusplus/AFLplusplus/issues/286 once the issues
 are fixed :)

