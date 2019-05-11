#include "../headers/Functions.h"
#include "../headers/Riff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

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
    unsigned int udata = data < 0 ? (-1) * data : data;
    bytes[0] = (char) udata;
    bytes[1] = (char) ((udata >> 8) & 0xFF);
    bytes[2] = (char) ((udata >> 16) & 0xFF);
    bytes[3] = (char) ((udata >> 24) & 0xFF);
    // FOR UNSIGNED
    if (data < 0) {
        bytes[3] += 128;
    }
    return bytes;
}

unsigned char* numToLittleEndian(int data, int size) {
    unsigned char* bytes = new unsigned char[size];
    unsigned int udata = data < 0 ? (-1) * data : data;
    for (int i = 0; i < size; i++) {
        bytes[i] = (char) ((udata >> 8 * i) & 0xFF);
    }
    // FOR UNSIGNED
    if (data < 0) {
        bytes[size - 1] += 128;
    }
    return bytes;
}

int littleEndianToInt(unsigned char* bytes, int size) {
    int data = 0;

    // ONLY FOR SIGNED
    /*for(int i = 0; i < size; i++) {
        data += (int) bytes[i] * pow(256, i);
    }*/

    // FOR UNSIGNED ALSO
    for(int i = 0; i < size - 1; i++) {
        data += (int) bytes[i] * pow(256, i);
    }
    if ((int) bytes[size - 1] >= 128) {
        data += ((int) bytes[size - 1] - 128) * pow(256, size - 1);
        data *= -1;
    } else {
        data += (int) bytes[size - 1] * pow(256, size - 1);
    }
    return data;
}