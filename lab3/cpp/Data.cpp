//
// Created by nikita on 07.05.19.
//

#include "../headers/Data.h"
#include "../headers/Functions.h"

Data::Data(unsigned char* buff, int size, Fmt* fmt) {
    subchunk2Id = new unsigned char[4];
    subchunk2Size = new unsigned char[4];
    this->size = size;
    this->fmt = fmt;

    for (int i = 0; i < 4; i++) {
        subchunk2Id[i] = buff[i + offset];
        subchunk2Size[i] = buff[i + offset + 4];
    }

    subchunk2SizeInt = (unsigned) littleEndianToInt(subchunk2Size);
    data = new unsigned char[subchunk2SizeInt];

    for (int i = 0; i < subchunk2SizeInt; i++) {
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

    for (int i = 0; i < subchunk2SizeInt; i++) {
        buff[i + offset + 8] = data[i];
    }
}

int Data::resize(double factor_) {
    int factor = (int) factor_; // Целочисленный коэффициент

    //unsigned char* buff = new unsigned char[(int)(subchunk2SizeInt * factor)]; // New data array
    unsigned char* buff = new unsigned char[subchunk2SizeInt * factor]; // New data array

    unsigned int numChannels = littleEndianToInt(fmt->getNumChannels()); // Number of channels
    unsigned int sampleRate = littleEndianToInt(fmt->getSampleRate()); // Sample rate
    unsigned int byteRate = littleEndianToInt(fmt->getByteRate()); // Byte rate
    unsigned int blockAlign = littleEndianToInt(fmt->getBlockAlign()); // Block align
    unsigned int bitsPerSample = littleEndianToInt(fmt->getBitsPerSample()); // Bits per sample

    int delim = subchunk2SizeInt / numChannels;

    int n = 0;
    int coef = 0;
    for (int i = 0; i < numChannels; i++) { // For every channel
        for (int j = 0; j < delim; j++) {
            // data[j + delim * i] - текущий байт в текущем канале
            // buff[j + delim * i + delim * n]
            coef = n;
            for (int k = 0; k < factor; k++) {
                buff[j + delim * i + delim * coef++] = data[j + delim * i];
            }
        }
        n = coef - 1;
    }

    data = buff;

    size -= subchunk2SizeInt;
    subchunk2SizeInt *= factor;
    subchunk2Size = intToLittleEndian(subchunk2SizeInt);
    size += subchunk2SizeInt; // New data array size

    /*int delim = (size - 44) / numChannels;

    cout << "size: " << size - 44 << " size: " << littleEndianToInt(subchunk2Size) << endl;
    cout << "delim: " << delim << endl;

    int n = 0;
    int coef = 0;
    for (int i = 0; i < numChannels; i++) { // For every channel
        for (int j = 0; j < delim; j++) {
            // data[j + delim * i] - текущий байт в текущем канале
            // buff[j + delim * i + delim * n]
            coef = n;
            for (int k = 0; k < factor; k++) {
                buff[j + delim * i + delim * coef] = data[j + delim * i];
                coef++;
            }
        }
        n = coef;
    }

    size = (size - 44) * factor + 44; // New Riff size
    subchunk2Size = intToLittleEndian(size - 44); // New data array size
     */

    return size;
}