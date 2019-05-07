//
// Created by nikita on 07.05.19.
//

#include "../headers/Fmt.h"

Fmt::Fmt(unsigned char* buff, int size) {
    subchunk1Id = new unsigned char[4];
    subchunk1Size = new unsigned char[4];
    audioFormat = new unsigned char[2];
    numChannels = new unsigned char[2];
    sampleRate = new unsigned char[4];
    byteRate = new unsigned char[4];
    blockAlign = new unsigned char[2];
    bitsPerSample = new unsigned char[2];

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

void Fmt::build(unsigned char* buff) {
    for (int i = 0; i < 4; i++) {
        buff[i + offset] = subchunk1Id[i];
        buff[i + offset + 4] = subchunk1Size[i];
        buff[i + offset + 12] = sampleRate[i];
        buff[i + offset + 16] = byteRate[i];
    }

    for (int i = 0; i < 2; i++) {
        buff[i + offset + 8] = audioFormat[i];
        buff[i + offset + 10] = numChannels[i];
        buff[i + offset + 20] = blockAlign[i];
        buff[i + offset + 22] = bitsPerSample[i];
    }
}