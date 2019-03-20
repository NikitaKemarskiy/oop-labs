#include "HashMap.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <string>

#define INPUT_FILE "./input/dictionary.txt"

using namespace std;

int main() {
	ifstream fin;
	string buff;
	string key = "";
	HashMap Map;
	int count = 0;
	openFileINPUT(fin, INPUT_FILE);
	while (!fin.eof()) {
		string buff = "";
		getline(fin, buff);
		key = ParseWord(buff);
		//Map.add(key, buff);
		cout << key << endl;
	}

	cin.get();
	return 0;
}