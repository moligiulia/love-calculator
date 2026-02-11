FROM gcc:latest

RUN apt-get update && apt-get install -y \
    cmake git libjsoncpp-dev uuid-dev zlib1g-dev libssl-dev

RUN git clone https://github.com/drogonframework/drogon.git && \
    cd drogon && git submodule update --init && \
    mkdir build && cd build && cmake .. && make install && cd ../..

WORKDIR /app
COPY . .

# Correzione per il tuo CMakeLists: creiamo la cartella che lui si aspetta
RUN mkdir -p compatibilita_project && \
    cp compatibilita_project.cpp compatibilita_project/ && \
    cp compatibilita_project.h compatibilita_project/ && \
    mkdir -p compatibilita_project/models && cp models/CompatibilitaEngine.h compatibilita_project/models/ && \
    mkdir -p compatibilita_project/controllers && cp controllers/CalcolatoreController.h compatibilita_project/controllers/

RUN mkdir build && cd build && cmake .. && make

EXPOSE 8080
CMD ["./build/compatibilita_exe"]
