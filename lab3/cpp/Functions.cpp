#include "../headers/Functions.h"
#include "../headers/Riff.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void openFileINPUT(ifstream& fin, string name){
    fin.open(name, ios::binary);
    if (!fin.is_open()){
        cout << "Error: input file wasn't opened." << endl;
        cin.get();
        exit(1);
    }
    cout << "Input file was opened." << endl;
}

void openFileOUTPUT(ofstream& fout, string name){
    fout.open(name, ios::binary);
    if (!fout.is_open()){
        cout << "Error: output file wasn't opened." << endl;
        cin.get();
        exit(1);
    }
    cout << "Ouput file was opened." << endl;
}

void readFile(ifstream& fin, unsigned char* bytesArray){
    fin.seekg(0);
    for (int i = 0; !fin.eof(); i++) {
        bytesArray[i] = fin.get();
    }
}

void writeFile(ofstream& fout, Riff& riff, string path){
    unsigned char* bytesArray = riff.build();
    for (int i = 0; i < riff.getSize(); i++) {
        fout << bytesArray[i];
    }
    delete[] bytesArray;
}

void sizeOfFile(ifstream& fin, int& count){
    if (!fin.is_open()) {
        count = 0;
        return;
    }
    fin.seekg(0, ios::end);
    count = fin.tellg();
}

unsigned char* intToLittleEndian(int data) {
    unsigned char* bytes = new unsigned char[4];
    bytes[0] = (char) data;
    bytes[1] = (char) (((uint)data >> 8) & 0xFF);
    bytes[2] = (char) (((uint)data >> 16) & 0xFF);
    bytes[3] = (char) (((uint)data >> 24) & 0xFF);
    return bytes;
}

int littleEndianToInt(unsigned char* bytes) {
    int data = 0;
    data += (int) bytes[0];
    data += (int) bytes[1] * 256;
    data += (int) bytes[2] * 256 * 256;
    data += (int) bytes[3] * 256 * 256 * 256;
    return data;
}