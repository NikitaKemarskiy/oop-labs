#include "Team.h"
#include <fstream>
#include <iostream>
#include <string>

#define INPUT_FILE "./input/premier_league.csv"
#define OUTPUT_FILE "./output/results.csv"

using namespace std;

void openingFile(ifstream &, string);

int main() {
	Team* teams = nullptr;
	string buff;
	ifstream fin;
	ofstream fout;

	int index = 0; // Initial index
	openingFile(fin, INPUT_FILE); // Open the file
	getline(fin, buff); // Read the first line that contains the number of teams
	int n = stoi(buff); // Number of teams
	teams = new Team[n]; // Create new Team array

	while (!fin.eof()) { // While input file isn't empty
		string temp = "";
		getline(fin, temp); // Read next line to the temp string
		if (temp.empty()) { // If temp is empty
			continue; // Go to the next iteration
		}
		teams[index++] = Team(temp); // Add new team to the teams array
	}
	fin.close(); // Close an input stream

	for (int i = 0; i < n; i++) {
		cout << teams[i].getInfo() << endl;
	}

	// Sorting and writing to the file
	
	//system("pause");
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