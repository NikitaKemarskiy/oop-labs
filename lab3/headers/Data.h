//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_DATA_H
#define LAB3_DATA_H


class Data {
private:
    unsigned char* subchunk2Id;
    unsigned char* subchunk2Size;
    unsigned char* data;
    int size;
    const static int offset = 36;
public:
    Data(unsigned char* buff, int size);

    void build(unsigned char* buff);

    int resize(double factor);
};


#endif //LAB3_DATA_H
