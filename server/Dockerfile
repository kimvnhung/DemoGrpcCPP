FROM example-core:latest


WORKDIR /data

COPY server ./server
COPY cmake ./server/cmake
COPY protos ./protos


RUN rm -rf build
RUN mkdir build 
RUN cd build && cmake ../server
RUN cd build && make


ENTRYPOINT ["./build/server"]
