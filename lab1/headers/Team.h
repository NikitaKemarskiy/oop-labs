#ifndef _TEAM_INCLUDED
#define _TEAM_INCLUDED

#include <string>

using namespace std;

// Team class
class Team {
private:
	string name; // Team name
	int wins; // Team wins
	int defeats; // Team defeats
	int draws; // Team draws
	int goals; // Team goals
	int misses; // Team missed goals
	int differenceGoals; // Its means: goals - misses
	int score; // Team total score
public:
	// Constructor
	Team();
	Team(string);
	// Methods
	void addGame(string game); // Add game (change wins / defeats / draws, goals / misses)
	void updateScore(); // Update team's score
	void parseInfo(string info); // Parse passed info
	string getInfo(); // Get team's info
	// Getters
	int getGoals() { return goals; }
	int getMisses() { return misses; }
	int getScore() { return score; }
	string getName() { return name; }
	//Operator =
	Team& operator=(const Team);
	//Comparison of objects
	bool equals(const Team &other);
};

#endif