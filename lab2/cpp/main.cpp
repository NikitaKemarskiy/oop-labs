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
	string word;
	string key = "";
	HashMap Map;
	openFileINPUT(fin, INPUT_FILE);
	cout << "Wait, our hash-table is filling..." << endl;
	FillingHashMap(fin, Map);
	cout << "Its done." << endl;
	fin.close();
	cout << "Input your word: "; getline(cin, word);
	cout << Map.find(word) << endl;

	cin.get();
	return 0;
}