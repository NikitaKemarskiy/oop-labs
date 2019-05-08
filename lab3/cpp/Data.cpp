//
// Created by nikita on 07.05.19.
//

#include "../headers/Data.h"

Data::Data(unsigned char* buff, int size) {
    subchunk2Id = new unsigned char[4];
    subchunk2Size = new unsigned char[4];
    data = new unsigned char[size - 44];
    this->size = size;

    for (int i = 0; i < 4; i++) {
        subchunk2Id[i] = buff[i + offset];
        subchunk2Size[i] = buff[i + offset + 4];
    }

    for (int i = 0; i < size - 44; i++) {
        data[i] = buff[i + offset + 8];
    }
}

Data::~Data() {
    delete[] subchunk2Id;
    delete[] subchunk2Size;
    delete[] data;
}

void Data::build(unsigned char* buff) {
    for (int i = 0; i < 4; i++) {
        buff[i + offset] = subchunk2Id[i];
        buff[i + offset + 4] = subchunk2Size[i];
    }

    for (int i = 0; i < size - 44; i++) {
        buff[i + offset + 8] = data[i];
    }
}

int Data::resize(double factor) {
    //...
    return 0;
}