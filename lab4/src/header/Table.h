#ifndef LAB4_TABLE_H
#define LAB4_TABLE_H

#include "Index.h"

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Table {
private:
    string name; // Name of the table
    string systemName; // System name of the table
    map<string, int> columns; // Map with columns names and their indexes in array
    map<string, Index> indexes; // Map with columns names and their binary trees (indexes)
    int columnsAmount; // Number of columns
    int size; // Number of rows
public:
    Table(string name, string systemName, string* args, int columnsAmount);
    void add(string* args);
    void addIndex(string name);
    bool hasColumn(string name);
    bool hasIndex(string name);
    string getName();
};


#endif //LAB4_TABLE_H
