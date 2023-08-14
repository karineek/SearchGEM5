# Copyright (c) 2023 The Regents of the University of California
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

"""
This gem5 configuation script creates a simple board to a "hello world" binary.

This is a simple alteration of "ssbse-challenge-examples/hello.py" but uses
a local binary instead of obtaining one via gem5 Resources.

The first parameter specifies the ISA and the second parameter specifies a
binary.

For simple usage an X86 binary has been provided at
"ssbse-challenge-examples/refs/binaries/x86-hello64-static".

This was obtained with:

```sh
wget http://dist.gem5.org/dist/develop/test-progs/hello/bin/x86/linux/hello64-static
```

Usage
-----

```sh
scons build/ALL/gem5.opt
./build/ALL/gem5.opt ssbse-challenge-examples/hello-custom-binary.py \
   --isa X86 --binary ssbse-challenge-examples/refs/binaries/x86-hello64-static
```
"""

from gem5.isas import ISA
from gem5.resources.resource import BinaryResource
from gem5.components.memory import SingleChannelDDR3_1600
from gem5.components.processors.cpu_types import CPUTypes
from gem5.components.boards.simple_board import SimpleBoard
from gem5.components.cachehierarchies.classic.no_cache import NoCache
from gem5.components.processors.simple_processor import SimpleProcessor
from gem5.simulate.simulator import Simulator
import argparse

# Here we read in the parameters passed to the configuration script.
parser = argparse.ArgumentParser(description="A hello-world script.")

parser.add_argument(
    "--isa",
    type=str,
    required=True,
    default="X86",
    choices=["ARM", "X86", "RISCV"],
)

parser.add_argument(
    "--binary",
    type=str,
    required=True,
)

parser.add_argument(
    "--options",
    type=str,
    required=True,
)

args = parser.parse_args()

# In this setup we don't have a cache. `NoCache` can be used for such setups.
cache_hierarchy = NoCache()

# We use a single channel DDR3_1600 memory system
memory = SingleChannelDDR3_1600(size="32MB")

isa = None
if args.isa == "ARM":
    isa = ISA.ARM
elif args.isa == "X86":
    isa = ISA.X86
elif args.isa == "RISCV":
    isa = ISA.RISCV

assert isa is not None

# A single core processor. The ISA is dependent on the "isa" parameter.
processor = SimpleProcessor(cpu_type=CPUTypes.TIMING, isa=isa, num_cores=1)

# The gem5 library simble board which can be used to run simple SE-mode
# simulations.
#
# SE is "Syscall Emulation" mode. This is a mode in gem5 which allows for the
# workload binary (in this case, a "hello world" binary) to be run without an
# OS. This is done by emulating the syscalls made by the workload binary.
# When a syscall is encountered in the binary gem5 will attempt to use your
# host system to handle the call. Not having to boot and simulate an OS makes
# SE-mode is much faster than it's alternative (FS, Full-System, mode).
# However, many syscalls are not fully implemented in gem5. This means many
# binaries will not run sucessfully in SE mode.
# In addition, as the syscalls are run on the host, if a workload uses a lot of
# operating system features, the stats received will not be accuate.
board = SimpleBoard(
    clk_freq="3GHz",
    processor=processor,
    memory=memory,
    cache_hierarchy=cache_hierarchy,
)

# Here we set the wokrload binary. In this instance we are using a
# `BinaryResource` which takes an argument, `local_path`, which is the path to
# the binary on your host system.
# **Note**: The `set_se_biary_workload` method only accepts a `BinaryResource`
# obtject as it's parameter, but other types of Resources may be created.
# See "src/python/gem5/resources/resource.py" for more resource types that
# may be created.
print(args.options.split())
board.set_se_binary_workload(BinaryResource(local_path=args.binary),arguments=args.options.split())

# Lastly we run the simulation with the "Simulator" module.
simulator = Simulator(board=board)
simulator.run()

# Once the simulation is complete we print the exit reason and tick count. This
# isn't required but can be useful for debugging.
print(
    "Exiting @ tick {} because {}.".format(
        simulator.get_current_tick(), simulator.get_last_exit_event_cause()
    )
)
