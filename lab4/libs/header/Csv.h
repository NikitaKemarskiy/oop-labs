#ifndef LAB4_CSV_H
#define LAB4_CSV_H

#include <string>
using namespace std;

namespace csv {
    string* parse(string row, int amount);
    string* parse(string row, int amount, char delimiter);
}

#endif //LAB4_CSV_H
