FROM alpine:latest as build

# Set timezone:
RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && echo $CONTAINER_TIMEZONE > /etc/timezone

# Install dependencies:
RUN apk update && \
    apk --no-cache add tzdata 
RUN apk add --update alpine-sdk
RUN mkdir -p /usr/local/share/ca-certificates/cacert.org 
RUN wget -P /usr/local/share/ca-certificates/cacert.org http://www.cacert.org/certs/root.crt http://www.cacert.org/certs/class3.crt
RUN update-ca-certificates
RUN apk --no-cache add cmake


# install protobuf first, then grpc
ENV GRPC_RELEASE_TAG v1.57.0
RUN git clone -b ${GRPC_RELEASE_TAG} https://github.com/grpc/grpc /var/local/git/grpc 
RUN cd /var/local/git/grpc && \
    git submodule update --init 
RUN mkdir -p /var/local/git/grpc/cmake/build 
RUN cd /var/local/git/grpc/cmake/build && \
    cmake ../..
RUN apk --no-cache add linux-headers
RUN cd /var/local/git/grpc/cmake/build && \ 
    make -j$(nproc)
RUN cd /var/local/git/grpc/cmake/build && \ 
    make install && \
    make clean
# RUN echo ${PATH} > .env

