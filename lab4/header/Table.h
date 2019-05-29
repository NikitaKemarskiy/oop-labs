#ifndef LAB4_TABLE_H
#define LAB4_TABLE_H

#include "../header/Index.h"

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Table {
private:
    string name; // Name of the table
    map<string, int> columns; // Map with columns names and their indexes in array
    map<string, Index> indexes; // Map with columns names and their binary trees (indexes)
    string** table; // Two-dimensional array for data
    int amount; // Number of columns
    int size; // Number of rows
    int currentSize = initialSize; // Current table size
    static int initialSize; // Initial table size
public:
    Table(string name, string* args, int amount);
    void add(string* args);
    void resize();
    void addIndex(string name);
    bool hasColumn(string name);
    bool hasIndex(string name);
    string getName();

    void printData();
};


#endif //LAB4_TABLE_H
