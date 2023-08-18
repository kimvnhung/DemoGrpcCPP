FROM grpc/cxx:1.12.0

WORKDIR /data

COPY server/server.cc ./server/
COPY protos/example.proto ./proto/
COPY Makefile ./

RUN make all && make clean

CMD ["./greeter-server"]