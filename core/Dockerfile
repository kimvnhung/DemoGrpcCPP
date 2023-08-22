FROM ubuntu:20.04

RUN apt-get update

RUN apt-get install -y libjsoncpp-dev

WORKDIR /data

# COPY client/client.cc ./client/
# COPY protos/example.proto ./proto/
# COPY Makefile ./

RUN mkdir json

# RUN make greeter-client && make clean

ENTRYPOINT ["./runner"]