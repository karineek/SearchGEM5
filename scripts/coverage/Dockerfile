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
ENV LLVM_CONFIG=/usr/bin/llvm-config-13

# Preparing Scripts to test gem5
USER debian
RUN mkdir /home/debian/ASEGem5
RUN mkdir /home/debian/ASEGem5/scripts
RUN mkdir /home/debian/ASEGem5/scripts/coverage
COPY ./* /home/debian/ASEGem5/scripts/coverage/
WORKDIR /home/debian

# Getting & Building gem5
RUN git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
WORKDIR /home/debian/gem5-ssbse-challenge-2023
RUN pip3 install --upgrade pip --break-system-packages
RUN pip3 install wheel --break-system-packages
RUN mkdir build

# updating some files
RUN cp /home/debian/ASEGem5/scripts/coverage/SConstruct .
RUN cp /home/debian/ASEGem5/scripts/coverage/SConscript src/

# Build with Coverage
RUN mkdir /home/debian/gem5-ssbse-challenge-2023/TMP_GCOV_FOLDER
# Send gcda of build to temp.
ENV GCOV_PREFIX=TMP_GCOV_FOLDER/coverage_gcda_files/application_run-init 
ENV GCOV_PREFIX_STRIP=0
ENV CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs'
ENV CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs'
ENV LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs'

RUN CC=gcc-11 CXX=g++-11 CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs' scons -Q -c build/X86/gem5.opt -j 4 --no-cache

# Cleaning after build
rm -rf TMP_GCOV_FOLDER
