#ifndef LAB4_INDEX_H
#define LAB4_INDEX_H

#include "Tree.h"

#include <string>
using namespace std;

class Index {
private:
    string name;
    Tree tree;
public:
    Index(string name);
    Index(string name, string data);

    void init(string data);
    string serialize();

    // дублируем методы дерева для работы с ним
};


#endif //LAB4_INDEX_H
