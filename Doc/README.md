# Reported Bugs

Reported bugs for gem5 via the reporting bug system. Other bugs discussed via private/public communication (e.g. [gem5 Dev Meeting](https://www.youtube.com/watch?v=hEyhXJg-rbU&t=1s))

## X86

- Panic error when executing avx2 on X86 due to Unrecognized/invalid instruction executed [#1508](https://github.com/gem5/gem5/issues/1508)
- gem5 crashes with panic: 'Tried to read unmapped address' on x86 when reading from argv [#1507](https://github.com/gem5/gem5/issues/1507)
- Hang when simulated program's input is near INT_MIN [#790](https://github.com/gem5/gem5/issues/790) (Won't Fix)
- subtraction of two long numbers simulated wrongly [#1227](https://github.com/gem5/gem5/issues/1227)
- Crash with panic with "Tried to write unmapped address" on x86 when sprintf with argv used. [#1483](https://github.com/gem5/gem5/issues/1483)
- gem5 crash with panic: panic condition !FullSystem occurred when simulating program that div by 0 on x86 [#1506](https://github.com/gem5/gem5/issues/1506)

## ARM

- SIGABRT does not trigger its signal handler and skips outputs on ARM [#1544](https://github.com/gem5/gem5/issues/1544) (Won't Fix)
- Missing Locale support within gem5 simulator on ARM [#1547](https://github.com/gem5/gem5/issues/1547)
- Panic Page table fault error in ARM when accessing invalid address in the simulated program [#1527](https://github.com/gem5/gem5/issues/1527) 
