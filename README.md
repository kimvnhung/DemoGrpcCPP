# DemoGrpcCPP


# How to run example   
    - Open terminal (on Ubuntu)
    - rm -rf build
    - mkdir build
    - cd build
    - cmake ../
    - make
    - cd ../
    - docker build -t example-core -f core/Dockerfile .
    - docker-compose up -d
    - docker logs -f client (to check logs response from server)
    - <Change data.json file in json folder to see other result>

