#ifndef LAB4_TABLE_H
#define LAB4_TABLE_H

#include "Index.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Table {
private:
    string name; // Name of the table
    map<string, int> columns; // Map with columns names and their indexes in array
    map<string, int> sizes; // Map with columns names and their sizes in bytes
    map<string, Index*> indexes; // Map with columns names and their binary trees (indexes)
    map<int, string> columnsIndexes; // Map with indexes and its columns names
    int columnsAmount; // Number of columns
    int lineSize; // Size of a line in bytes
    bool init; // Flag if the table was ever used before (to prevent from creating new indexes)

    string* findById(int id, ifstream& fin);
    vector<int> findIds(string columns, string value);
    vector<int> findIds(string columns, string greater, string less);

    const static int defaultSize;
public:
    Table(string name, string* args, int columnsAmount);
    Table(string name, string* args, int* sizesArg, int columnsAmount);
    void add(string* args, ofstream &fout);
    bool addIndex(string name, string value);
    void addIndex(string name, string value, string data);
    void setInit(bool init);
    bool hasColumn(string name);
    bool hasIndex(string name);
    int getLineSize();
    int getColumnsAmount();
    map<string, Index*> getIndexes();
    vector<string*> find(string column, string value, ifstream& fin);
    vector<string*> find(string column, string greater, string less, ifstream& fin);
    string getName();

    static int getDefaultSize();
};


#endif //LAB4_TABLE_H
