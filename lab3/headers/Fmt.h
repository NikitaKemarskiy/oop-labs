//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_FMT_H
#define LAB3_FMT_H


class Fmt {
private:
    char* subchunk1Id;
    char* subchunk1Size;
    char* audioFormat;
    char* numChannels;
    char* sampleRate;
    char* byteRate;
    char* blockAlign;
    char* bitsPerSample;
    const static int offset = 12;
public:
    Fmt(char* buff, int size);

    void build(char* buff);
};


#endif //LAB3_FMT_H
