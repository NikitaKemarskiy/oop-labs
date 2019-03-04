#include "Team.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#define FILE_PATH "premier_league.csv"

void openingFile(ifstream &, string);

int main() {
	Team* teams = nullptr;
	string buff;
	ifstream fin;

	int index = 0; // Initial index
	openingFile(fin, fileName); // Open the file
	getline(fin, buff); // Read the first line that contains the number of teams
	int n = stoi(buff); // Number of teams
	teams = new Team[n]; // Create new Team array

	while (!fin.eof()) {
		string temp = "";
		getline(fin, temp);
		if (temp.empty()) {
			continue;
		}
		teams[index++] = Team(temp);
	}

	for (int i = 0; i < n; i++) {
		cout << teams[i].getInfo() << endl;
	}

	fin.close();
	
	system("pause");
	return 0;
}

void openingFile(ifstream &fin, string name) {
	fin.open(name);
	if (!fin.is_open()) {
		cout << "Error: can't open the file." << endl;
		exit(1);
	}
	cout << "File was opened." << endl;
}