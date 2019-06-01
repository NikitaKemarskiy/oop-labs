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
    map<string, int> sizes; // Map with columns names and their sizes in bytes
    map<string, Index> indexes; // Map with columns names and their binary trees (indexes)
    int columnsAmount; // Number of columns
    int lineSize; // Size of a line in bytes
    bool init; // Flag if the table was ever used before (to prevent from creating new indexes)

    const static int defaultSize;
public:
    Table(string name, string systemName, string* args, int columnsAmount);
    void add(string* args);
    void addIndex(string name);
    void addIndex(string name, string data);
    void setSize(string name, int size);
    void setInit(bool init);
    bool hasColumn(string name);
    bool hasIndex(string name);
    int getLineSize();
    string getName();
};


#endif //LAB4_TABLE_H
