#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include "../headers/Riff.h"

using namespace std;

istream &openFileINPUT(ifstream&, string);
istream& sizeOfFile(ifstream&, int &);
istream& readFileINPUT(ifstream&, unsigned char *);
ostream& openFileOUTPUT(ofstream&, string);
ostream& writeFileOUTPUT(ofstream&, Riff&, string);

#endif //LAB3_FUNCTIONS_H
