//
// Created by nikita on 07.05.19.
//

#include "../headers/Riff.h"

Riff::Riff(char* buff, int size) {
    chunkSize = new char[4];
    chunkId = new char[4];
    format = new char[4];

    for (int i = 0; i < 4; i++) {
        chunkSize[i] = buff[i];
        chunkId[i] = buff[i + 4];
        format[i] = buff[i + 8];
    }

    wave = new Wav(buff, size);
};