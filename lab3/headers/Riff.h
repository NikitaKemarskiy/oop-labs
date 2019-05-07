//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_RIFF_H
#define LAB3_RIFF_H

#include "Wav.h"

class Riff {
private:
    char* chunkId;
    char* chunkSize;
    char* format;
    Wav* wave;
public:
    Riff(char* buff, int size);
};


#endif //LAB3_RIFF_H
