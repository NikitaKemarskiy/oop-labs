//
// Created by nikita on 07.05.19.
//

#ifndef LAB3_DATA_H
#define LAB3_DATA_H


class Data {
private:
    char* subchunk2Id;
    char* subchunk2Size;
    char* data;
    int size;
    const static int offset = 36;
public:
    Data(char* buff, int size);

    void build(char* buff);

    int resize(double factor);
};


#endif //LAB3_DATA_H
