#ifndef LAB4_INDEX_H
#define LAB4_INDEX_H

#include "Tree.h"

#include <string>
using namespace std;

class Index {
private:
    string name;
    string value;
    Tree tree;
public:
    Index(string name, string value);
    Index(string name, string value, string data);

    void init(string data);
    void add(double key, double data);
    double find(double key);
    string getName();
    string getValue();
    string serialize();

    // дублируем методы дерева для работы с ним
};


#endif //LAB4_INDEX_H
