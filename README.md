# DemoGrpcCPP


# How to run example   
    - Open terminal (on Ubuntu)
    - docker load -i core/example-core.tar (or rebuild use command 'docker build -t example-core -f core/Dockerfile .')
    - docker build -t example-server -f server/Dockerfile .
    - docker build -t example-client -f client/Dockerfile .
    - docker-compose up -d
    - docker logs -f client (to check logs response from server)
    - <Change data.json file in json folder to see other result>

