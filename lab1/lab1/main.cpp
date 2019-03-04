#include "Team.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void openingFile(ifstream &, string);

int main() {
	Team* teams = nullptr;
	string buff;
	string fileName;
	ifstream fin;

	cout << "Input name of file: "; getline(cin, fileName);

	openingFile(fin, fileName);

	int index = 0;
	getline(fin, buff); // Read the first line that contains the number of teams
	teams = new Team[stoi(buff)]; // Create new Team array

	while (!fin.eof()) {
		string temp;
		getline(fin, temp);
		if (fin.eof()) {
			break;
		}
		teams[index++] = Team(temp);
	}

	fin.close();
	system("pause");
	return 0;
}

void openingFile(ifstream &fin, string name) {
	fin.open(name);
	if (!fin.is_open()) {
		cout << "Error!!!" << endl;
		exit(1);
	}
	cout << "File is opened!" << endl;
}