#include "Team.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	Team* teams = nullptr;
	string buff;
	ifstream fin;

	fin.open("test.txt");
	if (!fin.is_open()) {
		cout << "Error: can't open the file" << endl;
		return 1;
	}
	else {
		cout << "File is opened" << endl;
	}

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

	//system("pause");
	return 0;
}