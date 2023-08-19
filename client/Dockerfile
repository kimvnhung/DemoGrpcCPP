FROM grpc/cxx:1.12.0

RUN apt-get install -y libjsoncpp-dev

WORKDIR /data

COPY client/client.cc ./client/
COPY protos/example.proto ./proto/
COPY Makefile ./

RUN mkdir json

RUN make greeter-client && make clean

ENTRYPOINT ["./greeter-client"]
