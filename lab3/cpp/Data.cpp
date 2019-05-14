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

    subchunk2SizeInt = (unsigned) littleEndianToInt(subchunk2Size, 4);
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

    unsigned int bitsPerSample = littleEndianToInt(fmt->getBitsPerSample(), 2); // Bits per sample
    unsigned int bytePerSample = bitsPerSample / 8;
    unsigned char* buff = new unsigned char[subchunk2SizeInt * factor]; // New data array

    int index = 0;
    for (int i = 0; i < subchunk2SizeInt; i += bytePerSample) {
        for (int k = 0; k < factor; k++) {
            for (int j = 0; j < bytePerSample; j++) {
                buff[index++] = data[i + j];
            }
        }
    }

    delete[] data;
    delete[] subchunk2Size;

    data = buff;

    size -= subchunk2SizeInt; // Extract old data array size from the whole wav size
    subchunk2SizeInt *= factor; // Change data array size value
    subchunk2Size = intToLittleEndian(subchunk2SizeInt);
    size += subchunk2SizeInt; // New wav file size

    return size;
}

int Data::reduce(double _factor) {
    int factor = _factor;
    unsigned int bitsPerSample = littleEndianToInt(fmt->getBitsPerSample(), 2); // Bits per sample
    unsigned int bytePerSample = bitsPerSample / 8;
    unsigned int newSubchunk2SizeInt = subchunk2SizeInt / factor - (subchunk2SizeInt / factor) % bytePerSample;
    unsigned char* buff = new unsigned char[newSubchunk2SizeInt]; // New data array

    int index = 0;
    int sample = 0;

    for (int i = 0; i < newSubchunk2SizeInt; i += bytePerSample) {
        if (sample++ % factor) {
            index += bytePerSample;
            i -= bytePerSample;
            continue;
        }
        for (int j = 0; j < bytePerSample; j++) {
            buff[i + j] = data[index++];
        }
    }

    delete[] data;
    delete[] subchunk2Size;

    data = buff;

    size -= subchunk2SizeInt; // Extract old data array size from the whole wav size
    subchunk2SizeInt = newSubchunk2SizeInt; // Change data array size value
    subchunk2Size = intToLittleEndian(subchunk2SizeInt);
    size += subchunk2SizeInt; // New wav file size

    return size;
}