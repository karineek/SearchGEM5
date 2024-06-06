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
RUN mkdir -p /home/debian/ASEGem5/scripts/coverage
COPY ./* /home/debian/ASEGem5/scripts/coverage/
RUN sed -i "s:ubuntu:debian:g" /home/debian/ASEGem5/scripts/coverage/3-compute-coverage_DIR_gfauto.sh
WORKDIR /home/debian
# Set the scripts for coverage - for later

# Install Python packages within a virtual environment
RUN python3 -m venv venv
ENV PATH="/home/debian/venv/bin:$PATH"
RUN pip install --upgrade pip==24.0 --no-warn-script-location
RUN pip install pipenv

# Clone and configure graphicsfuzz
RUN git clone https://github.com/google/graphicsfuzz.git \
    && cd graphicsfuzz \
    && git checkout aa32d4c
WORKDIR /home/debian/graphicsfuzz/gfauto/
RUN cp /home/debian/ASEGem5/scripts/coverage/requirements.txt /home/debian/graphicsfuzz/gfauto/
RUN sed -i "s:PYTHON-python3.6:PYTHON-python3.11:g" dev_shell.sh.template \
    && sed -i "s:--user:--break-system-packages:g" dev_shell.sh.template \
    && rm Pipfile.lock \
    && cp /home/debian/ASEGem5/scripts/coverage/Pipfile /home/debian/graphicsfuzz/gfauto/ \
    && sed -i "s:--dev:--verbose --skip-lock --dev:g" dev_shell.sh.template

#====================================================================================================== 
# Set shell options --break-system-packages
# Set shell options
RUN set -x \
    && set -e \
    && set -u

# Check for known files
# RUN ./dev_shell.sh.template
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
# RUN pip install --use-deprecated=legacy-resolver -r requirements.txt
RUN python3 -m pipenv install --requirements requirements.txt
RUN rm Pipfile.lock
# RUN pipenv lock --clear
RUN python3 -m pipenv install --dev
# END of script    
#====================================================================================================== 

# Getting & Building gem5
WORKDIR /home/debian
RUN git clone https://github.com/BobbyRBruce/gem5-ssbse-challenge-2023.git \
    && cd gem5-ssbse-challenge-2023 \
    && git checkout 65edbe0
WORKDIR /home/debian/gem5-ssbse-challenge-2023
RUN pip install -r requirements.txt --break-system-packages
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
# Build with coverage - the command of the build itself.
RUN CC=gcc-11 CXX=g++-11 CFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' CXXFLAGS='-g --coverage -ftest-coverage -fprofile-arcs' LDFLAGS='-lgcov --coverage -ftest-coverage -fprofile-arcs' scons -Q build/X86/gem5.opt -j 4 --no-cache
# Cleaning after build
RUN rm -rf TMP_GCOV_FOLDER
# END of Coverage Build    
#====================================================================================================== 

# Start setting up the env for experiments - connect the input
USER debian
WORKDIR /home/debian/ASEGem5/scripts/coverage
COPY hello-custom-binary-Ex.py /home/debian/gem5-ssbse-challenge-2023/ssbse-challenge-examples/hello-custom-binary-Ex.py
RUN mkdir /home/debian/experiment/

USER root
RUN chown -R debian:debian /home/debian/
RUN chmod +x /home/debian/ASEGem5/scripts/coverage/runningScript.sh
WORKDIR /home/debian/ASEGem5/scripts/coverage
ENTRYPOINT [ "/home/debian/ASEGem5/scripts/coverage/runningScript.sh" ]

CMD [ "echo", "Default argument from CMD instruction" ]
