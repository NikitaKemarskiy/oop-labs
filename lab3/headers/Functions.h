#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Riff.h"

using namespace std;

void openFileINPUT(ifstream&, string);
void openFileOUTPUT(ofstream&, string);
void readFile(ifstream&, unsigned char *);
void writeFile(ofstream&, Riff&, string);
void sizeOfFile(ifstream&, int &);
unsigned char* intToLittleEndian(int data);
unsigned char* numToLittleEndian(int data, int size);
int littleEndianToInt(unsigned char* data, int size);
void changeAudioFile(string number, Riff &riff, int &reduce, int &magnification);

#endif //LAB3_FUNCTIONS_H
