# DemoGrpcCPP


# How to run example   
    - Open terminal (on Ubuntu)
    - docker load -i docker_images/*
    - docker-compose up -d
    - docker logs -f client (to check logs response from server)
    - <Change data.json file in json folder to see other result>

# Build Dockerfile
    - docker build -t example-server -f server/Dockerfile .
    