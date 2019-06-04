#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include "../../src/header/Database.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

istream& readFile(ifstream& fin, string& buff);
vector<string> getLimits(string latitude, string longitude, double length);
vector<string*> getSquare(vector<string*> latitude, vector<string*>);
vector<string*> getCircle(vector<string*> square, string latitudeCenter, string longitudeCenter, double radius);
double getLength(string latitudeCenter, string longitudeCenter, string latitudeTemp, string longitudeTemp);
void printObjects(vector<string*> result, int columns);
void createPlacesTable(Database &database);

#endif //LAB4_FUNCTIONS_H