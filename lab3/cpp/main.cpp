#include "../headers/Functions.h"
#include "../headers/Riff.h"
#include <iostream>
#include <fstream>
#include <string>

#define INPUT_FILE "../input/audio.wav"
#define OUTPUT_FILE "../output/audio.wav"

using namespace std;

int main() {
    ifstream fin; // Input file stream
    ofstream fout; // Output file stream
    string number = "";

    unsigned char* bytesOfFile; // Array for bytes in a file
    int size; // Size of a file

    openFileINPUT(fin, INPUT_FILE); // Open input stream
    sizeOfFile(fin, size); // Get size of a file

    bytesOfFile = new unsigned char[size]; // Create new array for bytes

    readFile(fin, bytesOfFile); // Fill the array

    Riff riff(bytesOfFile, size); // New Riff instance

    cout << "Input number: "; cin >> number;
    changeAudioFile(number, riff);

    openFileOUTPUT(fout, OUTPUT_FILE); // Open output stream
    writeFile(fout, riff, OUTPUT_FILE); // Write bytes into output file

    fin.close();
    fout.close();

    return 0;
}