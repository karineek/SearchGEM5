FROM debian:12

# Create User
USER root
RUN rm /bin/sh && ln -s /bin/bash /bin/sh
RUN useradd -ms /bin/bash debian

# Install Env.
RUN apt-get -y update
RUN apt-get install -y build-essential software-properties-common apt-utils \
    zlib1g zlib1g-dev libprotobuf-dev protobuf-compiler libprotoc-dev \
    libgoogle-perftools-dev libboost-all-dev pkg-config libssl-dev lsb-release 
RUN apt install -y libpng-dev libpng++-dev libhdf5-dev

RUN apt-get install -y gnupg dirmngr git m4 scons wget make cmake ninja-build
RUN apt-get install -y automake
RUN apt-get install -y python3-dev python3-pip python3-venv 
RUN apt-get install -y fdupes

# Getting GCC
RUN apt -y autoremove
RUN apt-get -y install gcc-11 g++-11 cpp-11
RUN apt-get install -y gcc-11-plugin-dev
RUN rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
RUN rm /usr/bin/cc
RUN ln -s /usr/bin/cpp-11 /usr/bin/cpp
RUN ln -s /usr/bin/gcc-11 /usr/bin/gcc
RUN ln -s /usr/bin/gcc-11 /usr/bin/cc
RUN ln -s /usr/bin/g++-11 /usr/bin/g++
RUN ln -s /usr/bin/g++-11 /usr/bin/c++
RUN ln -s /usr/bin/gcov-11 /usr/bin/gcov
RUN apt-get install -y flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev llvm gdb coreutils   

# After all:
RUN apt -y autoremove

# Back to user level permissions
USER debian
WORKDIR /home/debian/

# Set the LANG environment variable
ENV LANG C.UTF-8

# Preparing Scripts to test gem5
RUN mkdir -p /home/debian/ASEGem5/scripts/bugs
COPY ./* /home/debian/ASEGem5/scripts/bugs/
WORKDIR /home/debian
# Set the scripts for coverage - for later

# Getting two versions of gem5 for testing
WORKDIR /home/debian
RUN git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git \
    && cd gem5-ssbse-challenge-2023 \
    && git checkout 65edbe0
WORKDIR /home/debian/gem5-ssbse-challenge-2023
RUN pip install -r requirements.txt --break-system-packages
RUN scons build/X86/gem5.opt -j 4

WORKDIR /home/debian
RUN git clone https://github.com/gem5/gem5.git
WORKDIR /home/debian/gem5
RUN pip install -r requirements.txt --break-system-packages
RUN scons build/X86/gem5.opt -j 4

# END of Build    
#====================================================================================================== 

# Start setting up the env for experiments - connect the input
USER debian
WORKDIR /home/debian/ASEGem5/scripts/bugs
COPY hello-custom-binary-Ex.py /home/debian/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
COPY hello-custom-binary-Ex.py /home/debian/gem5/hello-custom-binary-Ex.py
RUN mkdir /home/debian/experiment/

USER root
WORKDIR /home/debian/ASEGem5/scripts/bugs
CMD [ "/bin/bash" ]
