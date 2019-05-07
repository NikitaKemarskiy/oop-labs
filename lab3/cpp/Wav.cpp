//
// Created by nikita on 07.05.19.
//

#include "../headers/Wav.h"

Wav::Wav(char* buff, int size) {
    fmt = new Fmt(buff, size);
    data = new Data(buff, size);
}

void Wav::build(char* buff) {
    fmt->build(buff);
    data->build(buff);
}

int Wav::resize(double factor) {
    return data->resize(factor);
}
