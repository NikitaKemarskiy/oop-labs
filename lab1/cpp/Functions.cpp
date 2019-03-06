#include "Team.h"
#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Sort objects
void sortTeams(Team *teams, int numberOfTeams) {
	for (int i = 0; i < numberOfTeams - 1; i++) {
		for (int j = 0; j < numberOfTeams - 1; j++) {
			if (teams[j].equals(teams[j+1])) {
				Team temp;
				temp = teams[j];
				teams[j] = teams[j + 1];
				teams[j + 1] = temp;
			}
		}
	}
}

// Open the file input stream
istream& openFileIN(ifstream &fin, string name) {
	fin.open(name);
	if (!fin.is_open()) {
		cout << "Error: can't open the file." << endl;
		exit(1);
	}
	cout << "Input file was opened." << endl;
	return fin;
}

// Open the file output stream
ostream& openFileOUT(ofstream &fout, string name) {
	fout.open(name);
	if (!fout.is_open()) {
		cout << "Error: can't open the file." << endl;
		exit(1);
	}
	cout << "Output file was opened." << endl;
	return fout;
}

// Reading the file
istream& readFile(ifstream &fin, Team *teams) {
	int index = 0;

	while (!fin.eof()) { // While input file isn't empty
		string temp = "";
		int length = 0;

		getline(fin, temp); // Read next line to the temp string
		if (temp.empty()) { // If temp is empty
			continue; // Go to the next iteration
		}

		while (!temp.empty()) {
			string buff = "";
			size_t ind = temp.find(',');
			if (temp[0] == '"') {
				temp = substrs(temp, 1);
				ind = temp.find('"');
				buff += '"' + substrs(temp, 0, ind + 1);
				temp = ind >= temp.length() - 1 ? substrs(temp, ind + 1) : substrs(temp, ind + 2);
			} else if (ind != string::npos) { // Comma was found
				buff = substrs(temp, 0, ind);
				temp = substrs(temp, ind + 1);
			} else { // Comma wasn't found
				buff = substrs(temp, 0);
				temp = "";
			}

			if (buff.length() > 0 && isdigit(buff[0]) != 0) { // Buff is a goal
				for (int i = index - 1; i >= index - length; i--) {
					teams[i].addGame(buff);
				}
			} else { // Buff is a name
				teams[index++].setName(buff);
				length++;
			}
		}
		//teams[index++] = Team(temp); // Add new team to the teams array
	}
	return fin;
}

//Write to the file
ostream& writeFile(ofstream &fout, Team *teams, int numberOfTeam) {
	string main = "#,Team name,Wins,Draws,Defeats,Difference goals,Score";
	fout << main << endl;
	for (int i = 0; i < numberOfTeam; i++) {
		fout << to_string(i + 1) << ".," << teams[i].getInfo() << endl;
	}
	return fout;
}

// Secure substr
string substrs(string str, size_t from, size_t to) {
	if (from > str.length() - 1) {
		return "";
	}
	if (from < 0) {
		return str.substr(0);
	}
	return str.substr(from, to);
}