FROM ubuntu:bionic 

COPY requirements.system.txt requirements.txt
RUN apt update && xargs apt install -y < requirements.txt

WORKDIR /opt

# RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.0/cmake-3.14.0.tar.gz && \
    # tar -zxvf cmake-3.14.0.tar.gz && \
    # cd cmake-3.14.0 && cmake . && make && make install 

## install bats
RUN git clone --single-branch -b v1.1.0 https://github.com/bats-core/bats-core.git && \
    cd bats-core && ./install.sh /usr/local

WORKDIR /app/

COPY ./ /app

RUN bash scripts/build_all.sh

CMD ["bash","scripts/run_all.sh"]