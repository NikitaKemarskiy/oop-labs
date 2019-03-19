#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

istream& openFileINPUT(ifstream &fin, string name) {
	fin.open(name);
	if (!fin.is_open()) {
		cout << "Error with opening file." << endl;
		cin.get();
		exit(1);
	}
	cout << "Input file was opened." << endl;
	return fin;
}

ostream& openFileOUTPUT(ofstream &fout, string name) {
	fout.open(name);
	if (!fout.is_open()) {
		cout << "Error with opening file." << endl;
		cin.get();
		exit(1);
	}
	cout << "Output file was opened." << endl;
	return fout;
}