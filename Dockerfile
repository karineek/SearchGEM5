FROM debian:12

sudo apt-get update
sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config libssl-dev
sudo apt install libpng-dev libpng++-dev libhdf5-dev
sudo apt install python3-pip

# Getting the project
https://github.com/karineek/SearchGEM5.git
cd SearchGEM5

# Install pre-requirements
sudo apt-get install automake
sudo apt-get install python3-dev
python3 -m venv env/python
source env/python/bin/activate
pip3 install --upgrade pip
pip3 install wheel

sudo apt remove clang-10 clang-11 clang-9 clang-12
sudo rm -rf  /usr/bin/llvm-config
sudo apt autoremove

# Getting AFL++
sudo apt-get -y install gcc-11 g++-11 cpp-11
sudo rm /usr/bin/cpp /usr/bin/gcc /usr/bin/g++  /usr/bin/gcov  /usr/bin/c++
sudo rm /usr/local/bin/cpp /usr/local/bin/gcc /usr/local/bin/g++ /usr/local/bin/gcov  /usr/local/bin/c++ /usr/bin/cc
sudo ln -s /usr/bin/cpp-11 /usr/bin/cpp
sudo ln -s /usr/bin/gcc-11 /usr/bin/gcc
sudo ln -s /usr/bin/gcc-11 /usr/bin/cc
sudo ln -s /usr/bin/g++-11 /usr/bin/g++
sudo ln -s /usr/bin/g++-11 /usr/bin/c++
sudo ln -s /usr/bin/gcov-11 /usr/bin/gcov

wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 13
sudo ln -s /usr/bin/llvm-config-13 /usr/bin/llvm-config
sudo apt-get install -y lld-13 llvm-13-dev clang-13
sudo apt-get install -y lld llvm llvm-dev clang
sudo apt-get install -y build-essential python3-dev automake cmake git flex bison libglib2.0-dev libpixman-1-dev python3-setuptools cargo libgtk-3-dev
sudo apt-get install -y ninja-build cmake
sudo apt-get install -y wget git make cmake llvm gdb coreutils
sudo apt-get install gcc-11-plugin-dev
sudo apt autoremove

# Update default clang to 13
sudo update-alternatives --remove-all clang 
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-13 1300 --slave /usr/bin/clang++ clag++ /usr/bin/clang++-13
sudo update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-13 1300

LLVM_CONFIG=/usr/bin/llvm-config-13
git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
git checkout f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58
cp ../src/gem5-afl/afl-fuzz-init.c src/afl-fuzz-init.c
AFL_USE_ASAN=0 make
sudo make install 
cd ..

# Getting gem5
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
cd gem5-ssbse-challenge-2023

# updating some files
cp ../src/gem5-afl/SConstruct gem5-ssbse-challenge-2023/
cp ../src/gem5-afl/SConscript gem5-ssbse-challenge-2023/src/

# Instrument gem5
pip install -r requirements.txt
# scons build/X86/gem5.opt -j 4 ==> WE NEED THIS WITH AFL++ INST.
CC=afl-cc CXX=afl-c++ scons build/X86/gem5.opt -j 4 --no-cache
./build/X86/gem5.opt -C

# Prepare for fuzzing - we will need ASEGem5 at some point
cd ../src/
cd custom_mutators/
./compile_share.sh
