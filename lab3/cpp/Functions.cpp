#include "../headers/Functions.h"
#include "../headers/Riff.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

istream& openFileINPUT(ifstream &fin, string name){
    fin.open(name, ios::binary);
    if(!fin.is_open()){
        cout << "Error with opening file!" << endl;
        cin.get();
        exit(1);
    }
    cout << "Input file was opened." << endl;
    return fin;
}

istream& sizeOfFile(ifstream& fin, int &count){
    char temp;
    count = 0;
    while(!fin.eof()) {
        fin.get(temp);
        count++;
    }
    return fin;
}

istream& readFileINPUT(ifstream& fin, unsigned char *BytesArray){
    for(int i = 0; !fin.eof(); i++) {
        BytesArray[i] = fin.get();
    }
    return fin;
}

ostream& openFileOUTPUT(ofstream& fout, string name){
    fout.open(name, ios::binary);
    if(!fout.is_open()){
        cout << "Error with opening file!" << endl;
        cin.get();
        exit(1);
    }
    cout << "Ouput file was opened." << endl;
    return fout;
}

ostream& writeFileOUTPUT(ofstream& fout, Riff& riff, string path){
    unsigned char *newBytesArray = riff.build();
    for(int i = 0; i < riff.getSize(); i++){
        fout << newBytesArray[i];
    }
    delete[] newBytesArray;
    return fout;
}