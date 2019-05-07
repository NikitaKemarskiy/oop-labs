//
// Created by nikita on 07.05.19.
//

#include "../headers/Riff.h"

Riff::Riff(char* buff, int size) {
    chunkId = new char[4];
    chunkSize = new char[4];
    format = new char[4];
    this->size = size;

    for (int i = 0; i < 4; i++) {
        chunkId[i] = buff[i];
        chunkSize[i] = buff[i + 4];
        format[i] = buff[i + 8];
    }

    wave = new Wav(buff, size);
};

void Riff::build(string path) {
    char* buff = new char[size];

    for (int i = 0; i < 4; i++) {
        buff[i] = chunkId[i];
        buff[i + 4] = chunkSize[i];
        buff[i + 8] = format[i];
    }

    wave->build(buff);

    // buff - массив с готовыми данными
    // запись в файл, переданный аргументом string path
}

void Riff::resize(double factor) {
    size = wave->resize(factor);
}