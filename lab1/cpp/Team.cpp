#include "Team.h"
#include "Functions.h"
#include <iostream>
#include <string>

using namespace std;

// Default constructor
Team::Team() {
	name = "";
	wins = 0;
	defeats = 0;
	draws = 0;
	goals = 0;
	misses = 0;
	score = 0;
}

// Function that adds game (change wins / defeats / draws, goals / misses)
void Team::addGame(string game) {
	size_t ind = game.find(':');
	int goals_ = 0;
	int misses_ = 0;
	if (ind != string::npos) { // Colon was found
		goals_ = stoi(substrs(game, 0, ind));
		misses_ = substrs(game, ind + 1).empty() ? 0 : stoi(substrs(game, ind + 1));
	}
	else { // Colon wasn't found
		goals_ = stoi(game);
	}
	if (goals_ > misses_) {
		wins++;
	}
	else if (goals_ < misses_) {
		defeats++;
	}
	else {
		draws++;
	}
	goals += goals_;
	misses += misses_;

	updateScore();
}

// Function that updates team's score
void Team::updateScore() {
	score = wins * 3 + draws;
	differenceGoals = goals - misses;
}

// Function that parses passed info
/*void Team::parseInfo(string info) {
	bool nameInit = false;

	while (!info.empty()) {
		string buff = "";
		size_t ind = info.find(',');
		if (info[0] == '"'){
			info = substrs(info, 1);
			int ind_ = info.find('"');
			buff += '"';
			buff += substrs(info, 0, ind_ + 1);
			info = ind_ >= info.length() - 1 ? substrs(info, ind_ + 1) : substrs(info, ind_ + 2);
		}
		else if (ind != string::npos) { // Comma was found
			buff = substrs(info, 0, ind);
			info = substrs(info, ind + 1);
		}
		else { // Comma wasn't found
			buff = substrs(info, 0);
			info = "";
		}
		if (!nameInit) { // Name wasn't initialized
			name = buff;
			nameInit = true;
			continue;
		}
		// Name was initialized
		addGame(buff);
	}

	
>>>>>>> lab1-task
}*/

// Function that returns team's info
string Team::getInfo() {
	string data = "";
	data += name + ',';
	data += to_string(wins) + ',';
	data += to_string(draws) + ',';
	data += to_string(defeats) + ',';
	data += to_string(goals) + '-' + to_string(misses) + ',';
	data += to_string(score);
	return data;
}

void Team::setName(string name) {
	this->name = name;
}

//Operator =
Team & Team::operator=(const Team newTeam)
{
	this->wins = newTeam.wins;
	this->draws = newTeam.draws;
	this->defeats = newTeam.defeats;
	this->differenceGoals = newTeam.differenceGoals;
	this->goals = newTeam.goals;
	this->misses = newTeam.misses;
	this->name = newTeam.name;
	this->score = newTeam.score;

	return *this;
}

//Comparison of objects
bool Team::equals(const Team &other) {
	if (this->score < other.score) {
		return true;
	}
	if (this->score > other.score) {
		return false;
	}
	if (this->score == other.score && this->differenceGoals < other.differenceGoals) {
		return true;
	}
	else { return false; }
}