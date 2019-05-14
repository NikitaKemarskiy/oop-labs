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
    unsigned int udata = (unsigned int) data;
    bytes[0] = (char) udata;
    bytes[1] = (char) ((udata >> 8) & 0xFF);
    bytes[2] = (char) ((udata >> 16) & 0xFF);
    bytes[3] = (char) ((udata >> 24) & 0xFF);
    return bytes;
}

unsigned char* numToLittleEndian(int data, int size) {
    unsigned char* bytes = new unsigned char[size];
    unsigned int udata = (unsigned int) data;
    for (int i = 0; i < size; i++) {
        bytes[i] = (char) ((udata >> 8 * i) & 0xFF);
    }
    return bytes;
}

int littleEndianToInt(unsigned char* bytes, int size) {
    int data = 0;
    for(int i = 0; i < size; i++) {
        data += (int) bytes[i] * pow(256, i);
    }
    return data;
}

void changeAudioFile(string tempNumber, Riff &riff){
    int numberAfterDot;
    string number;
    if (stod(tempNumber) < 0.0) {
        riff.reverse();
        number = "";
        for (int i = 1; i < tempNumber.length(); i++) {
            number += tempNumber[i];
        }
    } else {
        number = tempNumber;
    }
    for (int i = 0; i < number.length(); i++) {
        if(number[i] == '.') {
            numberAfterDot = number.length() - i - 1;
        }
    }
    int magnification = stod(number) * pow(10, numberAfterDot);
    int reduce = pow(10, numberAfterDot);
    int tempRed = reduce;
    int tempMag = magnification;
    if (stod(number) == 1) { return; }
    if (stod(number) > 1) {
        while (tempRed) {
            int temp = tempRed;
            tempRed = tempMag % tempRed;
            tempMag = temp;
        }
        magnification /= tempMag;
        reduce /= tempMag;
        riff.resize(magnification);
        riff.reduce(reduce);
    }
    if (stod(number) < 1) {
        while (tempMag) {
            int temp = tempMag;
            tempMag = tempRed % tempMag;
            tempRed = temp;
        }
        magnification /= tempRed;
        reduce /= tempRed;
        riff.resize(magnification);
        riff.reduce(reduce);
    }
}