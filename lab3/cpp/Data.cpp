//
// Created by nikita on 07.05.19.
//

#include "../headers/Data.h"

Data::Data(char* buff, int size) {
    subchunk2Id = new char[4];
    subchunk2Size = new char[4];
    data = new char[size - 44];
    this->size = size;

    for (int i = 0; i < 4; i++) {
        subchunk2Id[i] = buff[i + offset];
        subchunk2Size[i] = buff[i + offset + 4];
    }

    for (int i = 0; i < size; i++) {
        data[i] = buff[i + offset + 8];
    }
}

void Data::build(char* buff) {
    for (int i = 0; i < 4; i++) {
        buff[i + offset] = subchunk2Id[i];
        buff[i + offset + 4] = subchunk2Size[i];
    }

    for (int i = 0; i < size; i++) {
        buff[i + offset + 8] = data[i];
    }
}

int Data::resize(double factor) {
    //...
}