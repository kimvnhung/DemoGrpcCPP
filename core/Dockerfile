FROM ubuntu:20.04 as build

SHELL ["/bin/bash", "-c"]

# Set timezone:
RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && echo $CONTAINER_TIMEZONE > /etc/timezone

# Install dependencies:
RUN apt-get update && \
    apt-get install -y tzdata && \
    apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    wget \
    autoconf \ 
    git \ 
    pkg-config \
    automake \
    libtool \
    curl \
    make \ 
    g++ \ 
    unzip \ 
    libjsoncpp-dev \
    ca-certificates
RUN mkdir -p /usr/local/share/ca-certificates/cacert.org 
RUN wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt
RUN update-ca-certificates

RUN apt-get clean

# install protobuf first, then grpc
ENV GRPC_RELEASE_TAG v1.57.0
RUN git clone -b ${GRPC_RELEASE_TAG} https://github.com/grpc/grpc /var/local/git/grpc 
RUN cd /var/local/git/grpc && \
    git submodule update --init 
RUN mkdir -p /var/local/git/grpc/cmake/build 
RUN cd /var/local/git/grpc/cmake/build && \
    cmake ../..
RUN cd /var/local/git/grpc/cmake/build && \ 
    make -j$(nproc)
RUN cd /var/local/git/grpc/cmake/build && \ 
    make install && \ 
    make clean && \ 
    ldconfig 
# RUN echo ${PATH} > .env

# FROM ubuntu:20.04 as main

# COPY --from=build /usr/bin /usr/bin
# COPY --from=build /usr/local/lib /usr/local/lib
# COPY --from=build /usr/lib /usr/lib
# COPY --from=build /usr/share /usr/share
# COPY --from=build /.env /.env
# RUN export PATH=$(cat .env)

