#include "Team.h"
#include <fstream>
// Secure substr
string substrs(string str, size_t from = 0, size_t to = string::npos);
// Open the file input stream
istream& openFileIN(ifstream &, string);
// Open the file output stream
ostream& openFileOUT(ofstream &, string);
// Reading the file and create array
istream& readFile(ifstream &, Team *);
// Write to the file good information :)
ostream& writeFile(ofstream &, Team *, int);
// Sort objects
void sortTeams(Team *, int);