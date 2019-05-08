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

    unsigned char* bytesOfFile; // Array for bytes in a file
    int size; // Size of a file

    openFileINPUT(fin, INPUT_FILE); // Open input stream
    sizeOfFile(fin, size); // Get size of a file

    cout << "Size: " << size << endl;

    bytesOfFile = new unsigned char[size]; // Create new array for bytes

    readFile(fin, bytesOfFile); // Fill the array

    for (int i = 0; i < 100; i++) {
        cout << (int) bytesOfFile[i] << " ";
    }
    cout << endl;

    Riff riff(bytesOfFile, size); // New Riff instance

    /*
     * RESIZE
     */

    openFileOUTPUT(fout, OUTPUT_FILE); // Open output stream
    writeFile(fout, riff, OUTPUT_FILE); // Write bytes into output file

    delete[] bytesOfFile;

    return 0;
}