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
#USER debian
RUN mkdir /home/debian/ASEGem5
RUN mkdir /home/debian/ASEGem5/scripts
RUN mkdir /home/debian/ASEGem5/scripts/coverage
COPY ./* /home/debian/ASEGem5/scripts/coverage/
RUN ls -l /home/debian/ASEGem5/scripts/coverage/
RUN sed -i "s:ubuntu:debian:g" /home/debian/ASEGem5/scripts/coverage/3-compute-coverage_DIR_gfauto.sh
WORKDIR /home/debian

# Install gfauto for Python3.11
RUN git clone https://github.com/google/graphicsfuzz.git \
    && cd graphicsfuzz \
    && git checkout aa32d4c
WORKDIR graphicsfuzz/gfauto/
# EDIT TO YOUR LOCAL VERSION of Python3: PYTHON=${PYTHON-python3.6}
RUN sed -i "s:PYTHON-python3.6:PYTHON-python3.11:g" dev_shell.sh.template
RUN rm Pipfile.lock

# RUN ./dev_shell.sh.template
# Set shell options
# Set shell options
RUN set -x \
    && set -e \
    && set -u

# Check for known files
RUN test -f ./Pipfile
RUN test -f ./dev_shell.sh.template

# Upgrade/install pip and pipenv
ENV PATH="/home/debian/.local/bin:${PATH}"
# Print the value of PATH during the build process
RUN echo "PATH: $PATH"
RUN python3 -m pip install --upgrade 'pip>=19.2.3' 'pipenv==2022.8.5' --break-system-packages

# Place virtual environment at gfauto/.venv
ENV PIPENV_VENV_IN_PROJECT=1

# Use hard-coded versions of packages in Pipfile.lock
ENV PIPENV_IGNORE_PIPFILE=1

# Install project dependencies using pipenv
RUN pipenv lock --clear
RUN python3 -m pipenv install --dev
# END of script


# Getting & Building gem5
WORKDIR /home/debian
RUN git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git \
    && cd gem5-ssbse-challenge-2023 \
    && git checkout 65edbe0
WORKDIR /home/debian/gem5-ssbse-challenge-2023
RUN ls -l
RUN pip install -r requirements.txt --break-system-packages
RUN mkdir build

## Adding the inputs for the init experiment

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

RUN CC=gcc-11 CXX=g++-11 CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs' scons -Q build/X86/gem5.opt -j 4 --no-cache

# Cleaning after build
RUN rm -rf TMP_GCOV_FOLDER

# Start setting up the env for experiments - connect the input
#USER debian
WORKDIR /home/debian/ASEGem5/scripts/coverage
COPY hello-custom-binary-Ex.py /home/debian/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
RUN mkdir /home/debian/experiment/

USER root
RUN chown -R debian:debian /home/debian/

# How to copy data?
# TODO

USER root
RUN chmod +x /home/debian/ASEGem5/scripts/coverage/runningScript.sh

WORKDIR /home/debian/ASEGem5/scripts/coverage
ENTRYPOINT [ "/home/debian/ASEGem5/scripts/coverage/runningScript.sh" ]

# NOTES:
# Building a base-line coverage
# docker cp d75081e47091:/home/debian/experiment/Phi .
# docker cp Phi db155f87d931:/home/debian/experiment/
# debian@db155f87d931:~/ASEGem5/scripts/coverage$ ./1-wrapper-get-coverage.sh /home/debian/ /home/debian/experiment/Phi/input/ 0 5 /home/debian/graphicsfuzz/gfauto/ func-gem5-llm-phi.csv lines-gem5-llm-phi.csv report-gem5-llm-phi.csv
# rm input to input-afl. cp queue to input;  cp binary/*.txt to input
# call the script - start point
# TODO - edit the script to have the right constants
# CMD [./get-cov-afl.sh i j k]
