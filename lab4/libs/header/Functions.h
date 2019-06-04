#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include <string>
#include <fstream>
#include <vector>
using namespace std;

istream& readFile(ifstream& fin, string& buff);
vector<string> getLimits(string latitude, string longitude, double length);
vector<string*> getSquare(vector<string*> latitude, vector<string*> longitude);

#endif //LAB4_FUNCTIONS_H