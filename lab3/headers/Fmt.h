//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_FMT_H
#define LAB3_FMT_H


class Fmt {
private:
    unsigned char* subchunk1Id;
    unsigned char* subchunk1Size;
    unsigned char* audioFormat;
    unsigned char* numChannels;
    unsigned char* sampleRate;
    unsigned char* byteRate;
    unsigned char* blockAlign;
    unsigned char* bitsPerSample;
    const static int offset = 12;
public:
    Fmt(unsigned char* buff, int size);
    ~Fmt();
    void build(unsigned char* buff);
    unsigned char* getNumChannels();
    unsigned char* getSampleRate();
    unsigned char* getByteRate();
    unsigned char* getBlockAlign();
    unsigned char* getBitsPerSample();
};


#endif //LAB3_FMT_H
