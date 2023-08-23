FROM example-core:latest

WORKDIR /data

COPY client ./client
COPY cmake ./cmake
COPY server ./server
COPY protos ./protos
COPY json ./json
# COPY build.sh ./build.sh
COPY CMakeLists.txt ./CMakeLists.txt


RUN rm -rf build
RUN mkdir build 
RUN cd build && cmake ../
RUN cd build && make


ENTRYPOINT ["./build/client"]