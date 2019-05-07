#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Functions.h"
#include "../headers/Riff.h"

#define INPUT_FILE "../input/audio.wav"
#define OUTPUT_FILE "../output/audio.wav"

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    int size;
    unsigned char *bytesOfFile;
    openFileINPUT(fin, INPUT_FILE);
    sizeOfFile(fin, size);
    bytesOfFile = new unsigned char[size];
    readFileINPUT(fin, bytesOfFile);
    Riff riff(bytesOfFile, size);
    //resize
    openFileOUTPUT(fout, OUTPUT_FILE);
    writeFileOUTPUT(fout, riff, OUTPUT_FILE);

    delete[] bytesOfFile;
    return 0;
}