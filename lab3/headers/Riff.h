//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_RIFF_H
#define LAB3_RIFF_H

#include "Wav.h"
#include <string>

using namespace std;

class Riff {
private:
    char* chunkId;
    char* chunkSize;
    char* format;
    int size;
    Wav* wave;
public:
    Riff(char* buff, int size); // Constructor

    void build(string path); // Method that builds new file

    void resize(double factor);
};


#endif //LAB3_RIFF_H
