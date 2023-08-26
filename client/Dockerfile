FROM example-core:latest

WORKDIR /data

COPY client ./client
COPY cmake ./client/cmake
COPY protos ./protos
COPY json ./json


RUN rm -rf build
RUN mkdir build 
RUN cd build && cmake ../client
RUN cd build && make


ENTRYPOINT ["./build/client"]