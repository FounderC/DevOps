FROM gcc:latest

WORKDIR /app
COPY . /app

RUN apt-get update && apt-get install -y make cmake
RUN g++ -o http_server http_server.cpp -Icpp-httplib -std=c++11 -pthread

EXPOSE 8080
CMD ["./http_server"]
