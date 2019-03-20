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

string ParseWord(string value) {
	string key = "";
	for (int i = 0; i < value.length(); i++) {
		if (value[i] == ';') {
			break;
		}
		key += value[i];
	}
	return key;
}

