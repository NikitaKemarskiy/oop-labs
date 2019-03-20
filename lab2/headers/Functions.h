#include "HashMap.h"
#include <fstream>

using namespace std;

string ParseWord(string);
istream& openFileINPUT(ifstream &, string);
istream& FillingHashMap(ifstream &, HashMap &);