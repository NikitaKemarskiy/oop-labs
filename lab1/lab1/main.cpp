#include "Team.h"
#include <fstream>
#include <iostream>
#include <string>
#define FILE_PATH "premier_league.csv"
using namespace std;


int main() {
	Team* teams = nullptr;
	string buff;
	ifstream fin;

	fin.open(FILE_PATH);
	if (!fin.is_open()) { // File isn't opened
		cout << "Error: can't open the file" << endl;
		return 1;
	}
	else { // File is opened
		cout << "File is opened" << endl;
	}

	int index = 0; // Initial index
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

	//system("pause");
	return 0;
}