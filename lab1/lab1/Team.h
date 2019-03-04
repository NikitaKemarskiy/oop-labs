#ifndef _TEAM_INCLUDED
#define _TEAM_INCLUDED

#include <string>
using namespace std;

class Team {
private:
	string name;
	int wins;
	int defeats;
	int goals;
	int misses;
	int score;
public:
	// Constructor
	Team();
	Team(string);
	// Methods
	void parseInfo(string);
	string getInfo();
	// Getters
	int getGoals() { return goals; }
	int getScore() { return score; }
};

#endif