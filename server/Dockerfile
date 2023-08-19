FROM grpc/cxx:1.12.0

RUN apt-get install -y libjsoncpp-dev

WORKDIR /data

COPY server/server.cc ./server/
COPY protos/example.proto ./proto/
COPY Makefile ./

RUN make greeter-server && make clean

CMD ["./greeter-server"]
