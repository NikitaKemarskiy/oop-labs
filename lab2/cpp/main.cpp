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
	openFileINPUT(fin, INPUT_FILE);
	FillingHashMap(fin, Map);
	fin.close();

	cin.get();
	return 0;
}