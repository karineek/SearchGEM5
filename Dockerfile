FROM debian:12

USER root
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN useradd -ms /bin/bash debian

RUN apt-get -y update
RUN apt install -y build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config libssl-dev
RUN apt install -y libpng-dev libpng++-dev libhdf5-dev
RUN apt install -y python3-pip python3-venv

# Install pre-requirements
RUN apt-get install -y automake
RUN apt-get install -y python3-dev
WORKDIR /home/debian
USER debian
RUN mkdir env
RUN python3 -m venv /home/debian/env/python
RUN source /home/debian/env/python/bin/activate
RUN pip3 install --upgrade pip --break-system-packages
RUN pip3 install wheel --break-system-packages

USER root
#RUN apt-get remove clang-10 clang-11 clang-9 clang-12
RUN rm -rf /usr/bin/llvm-config
RUN apt -y autoremove

# Getting AFL++
RUN apt-get -y install gcc-11 g++-11 cpp-11 wget lsb-release gnupg software-properties-common
RUN rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
#RUN rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++
RUN rm /usr/bin/cc
RUN ln -s /usr/bin/cpp-11 /usr/bin/cpp
RUN ln -s /usr/bin/gcc-11 /usr/bin/gcc
RUN ln -s /usr/bin/gcc-11 /usr/bin/cc
RUN ln -s /usr/bin/g++-11 /usr/bin/g++
RUN ln -s /usr/bin/g++-11 /usr/bin/c++
RUN ln -s /usr/bin/gcov-11 /usr/bin/gcov

RUN wget https://apt.llvm.org/llvm.sh
RUN chmod +x llvm.sh
RUN ./llvm.sh 13
RUN ln -s /usr/bin/llvm-config-13 /usr/bin/llvm-config
RUN apt-get install -y lld-13 llvm-13-dev clang-13
RUN apt-get install -y lld llvm llvm-dev clang
RUN apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
RUN apt-get install -y ninja-build cmake
RUN apt-get install -y wget git make cmake llvm gdb coreutils
RUN apt-get install -y gcc-11-plugin-dev
RUN apt -y autoremove

# Update default clang to 13
#RUN update-alternatives --remove-all clang 
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-13 1300 --slave /usr/bin/clang++ clag++ /usr/bin/clang++-13
RUN update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-13 1300

RUN mkdir /home/debian/ASEGem5
RUN mkdir /home/debian/ASEGem5/src
RUN mkdir /home/debian/ASEGem5/Experiments
COPY ./src /home/debian/ASEGem5/src
COPY ./Experiments /home/debian/ASEGem5/Experiments
WORKDIR /home/debian/ASEGem5
ENV LLVM_CONFIG=/usr/bin/llvm-config-13
WORKDIR /home/debian

USER debian
RUN git clone https://github.com/AFLplusplus/AFLplusplus.git
WORKDIR /home/debian/AFLplusplus
#RUN git config --global --add safe.directory /home/debian/ASEGem5/AFLplusplus
RUN git checkout f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58
RUN cp ../ASEGem5/src/gem5-afl/afl-fuzz-init.c src/afl-fuzz-init.c
RUN AFL_USE_ASAN=0 make

USER root
RUN make install 
WORKDIR /home/debian/ASEGem5
ENV AFL_HOME=/home/debian/AFLplusplus
# Getting gem5
RUN git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
WORKDIR /home/debian/ASEGem5/gem5-ssbse-challenge-2023

# updating some files
RUN cp ../src/gem5-afl/SConstruct .
RUN cp ../src/gem5-afl/SConscript src/

# Instrument gem5
RUN pip install -r requirements.txt --break-system-packages
# scons build/X86/gem5.opt -j 4 ==> WE NEED THIS WITH AFL++ INST.
RUN CC=afl-cc CXX=afl-c++ scons build/X86/gem5.opt -j 4 --no-cache
RUN ./build/X86/gem5.opt -C

# Prepare for fuzzing - we will need ASEGem5 at some point
WORKDIR /home/debian/ASEGem5/src/custom_mutators
RUN sed -i "s\/home/ubuntu/AFLplusplus\/$AFL_HOME\g" ./compile_share.sh
RUN ./compile_experiments.sh
RUN ./compile_share.sh 1 1 1

RUN chmod +x /home/debian/ASEGem5/Experiments/runningScript.sh

ENTRYPOINT [ "/home/debian/ASEGem5/Experiments/runningScript.sh" ]

CMD [ "echo", "Default argument from CMD instruction" ]

#Run the filtering process
WORKDIR /home/debian/experiment
#/home/debian/ASEGem5/scripts/filterTests.sh /home/debian/experiment/input/ /home/debian/experiment/output/  /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py

#Run AFL 
#AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_MAP_SIZE=1200000 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY="/home/debian/ASEGem5/src/custom_mutators/cm-gem5.so" timeout 24h /home/debian/AFLplusplus/afl-fuzz  -m 50000 -t 99000 -i /home/debian/experiment/output/input/ -o /home/debian/experiment/outputFuzzing /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py  --isa X86 --input @@
