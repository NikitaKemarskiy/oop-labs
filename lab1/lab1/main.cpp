#include "Team.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;
	fin.open("test.txt");
	if (!fin.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	else {
		cout << "File is opened" << endl;
	}
	string temp;
	while (!fin.eof()) {
		getline(fin, temp);
		cout << temp << endl;
	}

	system("pause");
	return 0;
}