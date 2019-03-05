#include "Team.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <string>

#define INPUT_FILE "./input/premier_league.csv"
#define OUTPUT_FILE "./output/results.csv"

using namespace std;

int main() {
	Team* teams = nullptr;
	string buff;
	ifstream fin;
	ofstream fout;
	
	openFileIN(fin, INPUT_FILE); // Open the file
	getline(fin, buff); // Read the first line that contains the number of teams
	int n = stoi(buff); // Number of teams
	teams = new Team[n]; // Create new Team array

	readFile(fin, teams); // Reading the file and create array of class Team
	fin.close(); // Close an input stream
	
	// Sorting and writing to the file
	sortTeams(teams, n);
	// Open file output stream
	openFileOUT(fout, OUTPUT_FILE);
	// Write to file
	writeFile(fout, teams, n);

	fout.close();

	delete[] teams;
	
	return 0;
}