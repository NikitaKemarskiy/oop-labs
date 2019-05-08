//
// Created by nikita on 07.05.19.
//

#include "../headers/Riff.h"
#include "../headers/Functions.h"

Riff::Riff(unsigned char* buff, int size) {
    chunkId = new unsigned char[4];
    chunkSize = new unsigned char[4];
    format = new unsigned char[4];
    this->size = size;

    for (int i = 0; i < 4; i++) {
        chunkId[i] = buff[i];
        chunkSize[i] = buff[i + 4];
        format[i] = buff[i + 8];
    }

    wave = new Wav(buff, size);
};

Riff::~Riff(){
    delete[] chunkId;
    delete[] chunkSize;
    delete[] format;
    delete wave;
}

unsigned char* Riff::build() {
    unsigned char* buff = new unsigned char[size];

    for (int i = 0; i < 4; i++) {
        buff[i] = chunkId[i];
        buff[i + 4] = chunkSize[i];
        buff[i + 8] = format[i];
    }

    cout << "Size: " << size << ", chunkSize: " << (unsigned) littleEndianToInt(chunkSize);

    wave->build(buff);

    return buff;
}

void Riff::resize(double factor) {
    size = wave->resize(factor);
    chunkSize = intToLittleEndian(size);
}