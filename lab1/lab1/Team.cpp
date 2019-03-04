#include "Team.h"
#include <iostream>
#include <string>
using namespace std;

Team::Team() {
	name = "";
	wins = 0;
	defeats = 0;
	goals = 0;
	misses = 0;
	score = 0;
}

Team::Team(string info) {
	parseInfo(info);
}

void Team::parseInfo(string info) {
	cout << "parseInfo() was called: " << info << endl;
}

string Team::getInfo() {
	//...
}