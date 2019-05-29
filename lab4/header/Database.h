#ifndef LAB4_DATABASE_H
#define LAB4_DATABASE_H

#include "Table.h"

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Database {
private:
    string name;
    map<string, Table*> tables;
    Table* curr;
public:
    Database(string name);
    void addTable(string name, string* args, int amount);
    bool hasTable(string name);
    void setCurrent(string name);
    void add(string* args);
    void addIndex(string name);
    string getName();

    void printData();
};


#endif //LAB4_DATABASE_H
