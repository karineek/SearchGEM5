FROM debian:12

sudo apt-get update
sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config
sudo apt install libpng-dev libpng++-dev libhdf5-dev
sudo apt install python3-pip

# Getting the project
https://github.com/karineek/SearchGEM5.git
cd SearchGEM5

# Getting AFL++
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

git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
git checkout f596a297c4de6a5e1a6fb9fbb3b4e18124a24f58

make all
sudo make install 

# Getting gem5
git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git
cd gem5-ssbse-challenge-2023
pip install -r requirements.txt
scons build/X86/gem5.opt -j 4
./build/X86/gem5.opt -C

# updating some files
cp ../src/gem5-afl/SConstruct gem5-ssbse-challenge-2023/
cp ../src/gem5-afl/SConscript gem5-ssbse-challenge-2023/src/





