FROM debian:12

# Create User
USER root
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN useradd -ms /bin/bash debian

# Install Env.
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
RUN rm -rf /usr/bin/llvm-config
RUN apt -y autoremove
# Getting AFL++
RUN apt-get -y install gcc-11 g++-11 cpp-11 wget lsb-release gnupg software-properties-common
RUN rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
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
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-13 1300 --slave /usr/bin/clang++ clang++ /usr/bin/clang++-13
RUN update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-13 1300

# Preparing Scripts to test gem5
RUN mkdir /home/debian/ASEGem5
RUN mkdir /home/debian/ASEGem5/src
RUN mkdir /home/debian/ASEGem5/Experiments
COPY ./src /home/debian/ASEGem5/src
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

RUN apt-get -y install zip
#Pre-fuzzing process
WORKDIR /home/debian
COPY ./hello-custom-binary-Ex.py /home/debian/ASEGem5/

WORKDIR /home/debian/experiment
RUN wget "https://zenodo.org/records/10999115/files/LLM_test_inputs-4FuzzExp2.zip" # Get the data
RUN unzip LLM_test_inputs-4FuzzExp2.zip
WORKDIR /home/debian/experiment/
RUN sed -i "s:/home/ubuntu/experiment-7/:/home/debian/experiment/:g" */input/*.txt

# Model Phi
WORKDIR /home/debian/experiment/Phi
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model Phi cmin
WORKDIR /home/debian/experiment/
RUN rm -rf Phi-cmin/binary
RUN cp -r Phi/binary Phi-cmin/binary
WORKDIR /home/debian/experiment/Phi-cmin/input
RUN sed -i 's\/Phi/\/Phi-cmin/\g' *txt

# Model CodeBooga
WORKDIR /home/debian/experiment/CodeBooga  
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done 
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model CodeBooga cmin
WORKDIR /home/debian/experiment/
RUN rm -rf CodeBooga-cmin/binary
RUN cp -r CodeBooga/binary CodeBooga-cmin/binary
WORKDIR /home/debian/experiment/CodeBooga-cmin/input
RUN sed -i 's\/CodeBooga/\/CodeBooga-cmin/\g' *txt

# Model Llama
WORKDIR /home/debian/experiment/Llama  
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model Llama cmin
WORKDIR /home/debian/experiment/
RUN rm -rf Llama-cmin/binary
RUN cp -r Llama/binary Llama-cmin/binary
WORKDIR /home/debian/experiment/Llama-cmin/input
RUN sed -i 's\/Llama/\/Llama-cmin/\g' *txt

# Model Magicoder
WORKDIR /home/debian/experiment/Magicoder
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model Magicoder cmin
WORKDIR /home/debian/experiment/
RUN rm -rf Magicoder-cmin/binary
RUN cp -r Magicoder/binary Magicoder-cmin/binary
WORKDIR /home/debian/experiment/Magicoder-cmin/input
RUN sed -i 's\/Magicoder/\/Magicoder-cmin/\g' *txt

# Model TinyLlama
WORKDIR /home/debian/experiment/TinyLlama
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model TinyLlama cmin
WORKDIR /home/debian/experiment/
RUN rm -rf TinyLlama-cmin/binary
RUN cp -r TinyLlama/binary TinyLlama-cmin/binary
WORKDIR /home/debian/experiment/TinyLlama-cmin/input
RUN sed -i 's\/TinyLlama/\/TinyLlama-cmin/\g' *txt

# Model gpt3.5-new
WORKDIR /home/debian/experiment/gpt3.5-new  
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model gpt3.5-new cmin
WORKDIR /home/debian/experiment/
RUN rm -rf gpt3.5-new-cmin/binary
RUN cp -r gpt3.5-new/binary gpt3.5-new-cmin/binary
WORKDIR /home/debian/experiment/gpt3.5-new-cmin/input
RUN sed -i 's\/gpt3.5-new/\/gpt3.5-new-cmin/\g' *txt

# Model gpt3.5-old
WORKDIR /home/debian/experiment/gpt3.5-old
RUN for prog in raw/*.c; do gcc -O3 "$prog" -o "$prog.o" && mv $prog.o binary/ || true; done
RUN rm  binary/fuzz_* || true
RUN rm  .DS_Store || true
# Model gpt3.5-old cmin
WORKDIR /home/debian/experiment/
RUN rm -rf gpt3.5-old-cmin/binary
RUN cp -r gpt3.5-old/binary gpt3.5-old-cmin/binary
WORKDIR /home/debian/experiment/gpt3.5-old-cmin/input
RUN sed -i 's\/gpt3.5-old/\/gpt3.5-old-cmin/\g' *txt

# Return to main experiment folder
WORKDIR /home/debian/experiment

# Prepare the experiment scripts
COPY ./Experiments /home/debian/ASEGem5/Experiments
COPY ./src /home/debian/ASEGem5/src/custom_mutators

# Prepare for fuzzing - we will need ASEGem5 at some point
WORKDIR /home/debian/ASEGem5/src/custom_mutators
RUN sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" /home/debian/ASEGem5/src/custom_mutators/compile_share_test.sh
RUN sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" /home/debian/ASEGem5/src/custom_mutators/compile_share.sh
RUN head /home/debian/ASEGem5/src/custom_mutators/compile_share.sh
RUN /home/debian/ASEGem5/src/custom_mutators/compile_experiments.sh
RUN /home/debian/ASEGem5/src/custom_mutators/compile_share.sh 1 1 1
RUN sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" /home/debian/ASEGem5/Experiments/Experiment-1-selection.sh
RUN sed -i "s:/home/ubuntu/AFLplusplus:$AFL_HOME:g" /home/debian/ASEGem5/Experiments/Experiment-2-24hruns.sh
RUN sed -i "s:/home/ubuntu/ASEGem5:/home/debian/ASEGem5:g" /home/debian/ASEGem5/Experiments/run_AFL_loop_v*.sh
RUN sed -i "s:/home/ubuntu/gem5-ssbse-challenge-2023/build/X86/gem5.opt:/home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt:g" /home/debian/ASEGem5/Experiments/run_AFL_loop_v*.sh
RUN chmod +x /home/debian/ASEGem5/Experiments/runningScript.sh

RUN echo "Before fuzzing run this :<echo core >/proc/sys/kernel/core_pattern>"

WORKDIR /home/debian/ASEGem5/Experiments
ENTRYPOINT [ "/home/debian/ASEGem5/Experiments/runningScript.sh" ]

CMD [ "echo", "Default argument from CMD instruction" ]

#/home/debian/ASEGem5/scripts/filterTests.sh /home/debian/experiment/input/ /home/debian/experiment/output/  /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py
#Run AFL 
#AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_MAP_SIZE=1200000 AFL_SKIP_BIN_CHECK=1 AFL_CUSTOM_MUTATOR_ONLY=1 AFL_CUSTOM_MUTATOR_LIBRARY="/home/debian/ASEGem5/src/custom_mutators/cm-gem5.so" timeout 24h /home/debian/AFLplusplus/afl-fuzz  -m 50000 -t 99000 -i /home/debian/experiment/output/input/ -o /home/debian/experiment/outputFuzzing /home/debian/ASEGem5/gem5-ssbse-challenge-2023/build/X86/gem5.opt /home/debian/ASEGem5/hello-custom-binary-Ex.py  --isa X86 --input @@
