#include "Team.h"
#include <iostream>
#include <string>
using namespace std;

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

// Constructor with info as a parameter
Team::Team(string info) {
	name = "";
	wins = 0;
	defeats = 0;
	draws = 0;
	goals = 0;
	misses = 0;
	score = 0;
	parseInfo(info);
}

// Function that adds game (change wins / defeats / draws, goals / misses)
void Team::addGame(string game) {
	size_t ind = game.find(':');
	int goals_ = 0;
	int misses_ = 0;
	if (ind != string::npos) { // Colon was found
		goals_ = stoi(substrs(game, 0, ind));
		misses_ = substrs(game, ind + 1).empty() ? 0 : stoi(substrs(game, ind + 1));
	} else { // Colon wasn't found
		goals_ = stoi(game);
	}
	if (goals_ > misses_) {
		wins++;
	} else if (goals_ < misses_) {
		defeats++;
	} else {
		draws++;
	}
	goals += goals_;
	misses += misses_;
}

// Function that updates team's score
void Team::updateScore() {
	score = wins * 3 + draws;
}

// Function that parses passed info
void Team::parseInfo(string info) {
	bool nameInit = false;

	while (!info.empty()) {
		string buff = "";
		size_t ind = info.find(',');
		if (ind != string::npos) { // Comma was found
			buff = substrs(info, 0, ind);
			info = substrs(info, ind + 1);
		} else { // Comma wasn't found
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

	updateScore();
}

// Function that returns team's info
string Team::getInfo() {
	string data = "";
	data += name + ',';
	data += to_string(wins) + ',';
	data += to_string(defeats) + ',';
	data += to_string(draws) + ',';
	data += to_string(goals) + ',';
	data += to_string(misses) + ',';
	data += to_string(score);
	return data;
}