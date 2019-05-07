//
// Created by nikita on 07.05.19.
//

#include "../headers/Fmt.h"

Fmt::Fmt(char* buff, int size) {
    subchunk1Id = new char[4];
    subchunk1Size = new char[4];
    audioFormat = new char[2];
    numChannels = new char[2];
    sampleRate = new char[4];
    byteRate = new char[4];
    blockAlign = new char[2];
    bitsPerSample = new char[2];

    for (int i = 0; i < 4; i++) {
        subchunk1Id[i] = buff[i + offset];
        subchunk1Size[i] = buff[i + offset + 4];
        sampleRate[i] = buff[i + offset + 12];
        byteRate[i] = buff[i + offset + 16];
    }

    for (int i = 0; i < 2; i++) {
        audioFormat[i] = buff[i + offset + 8];
        numChannels[i] = buff[i + offset + 10];
        blockAlign[i] = buff[i + offset + 20];
        bitsPerSample[i] = buff[i + offset + 22];
    }
}