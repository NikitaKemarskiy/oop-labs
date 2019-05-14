#ifndef LAB3_WAV_H
#define LAB3_WAV_H

#include "Fmt.h"
#include "Data.h"

class Wav {
private:
    Fmt* fmt;
    Data* data;
public:
    Wav(unsigned char* buff, int size);

    ~Wav();

    void build(unsigned char* buff);

    int resize(double factor);

    int reduce(double);
};


#endif //LAB3_WAV_H
