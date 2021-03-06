#ifndef LAB3_DATA_H
#define LAB3_DATA_H

#include "Fmt.h"

class Data {
private:
    unsigned char* subchunk2Id;
    unsigned char* subchunk2Size;
    unsigned char* data;
    int size;
    Fmt* fmt;

    int subchunk2SizeInt;

    const static int offset = 36;
public:
    Data(unsigned char* buff, int size, Fmt* fmt);

    ~Data();

    void build(unsigned char* buff);

    int resize(double factor);

    int reduce(double factor);

    void reverse();
};


#endif //LAB3_DATA_H
