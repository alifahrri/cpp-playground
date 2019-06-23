FROM ubuntu:bionic 

RUN apt update && apt install -y cmake wget tar build-essential

WORKDIR /opt

# RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.0/cmake-3.14.0.tar.gz && \
    # tar -zxvf cmake-3.14.0.tar.gz && \
    # cd cmake-3.14.0 && cmake . && make && make install 

WORKDIR /app/

COPY ./ /app

RUN bash scripts/build_all.sh

CMD ["bash","scripts/run_all.sh"]