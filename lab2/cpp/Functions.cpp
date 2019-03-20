#include "Functions.h"
#include "HashMap.h"
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

istream& FillingHashMap(ifstream &fin, HashMap &Map) {
	string key = "";
	while (!fin.eof()) {
		string buff = "";
		getline(fin, buff);
		key = ParseWord(buff);
		Map.add(key, buff);
	}
	return fin;
}