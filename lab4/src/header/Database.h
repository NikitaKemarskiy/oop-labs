#ifndef LAB4_DATABASE_H
#define LAB4_DATABASE_H

#include "Table.h"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

class Database {
private:
    string name;
    map<string, Table*> tables;
    Table* curr;
    ifstream fin;
    ofstream fout;

    static const string tableDirectory;
    static const string indexDirectory;
    static const string metadataTableFile;
    static const string metadataIndexFile;
public:
    Database(string name);
    ~Database();
    void init();
    void save();
    void add(string* args);
    void addTable(string name, string* args, int amount);
    void addTable(string name, string* args, int* sizes, int amount);
    void addIndex(string name, string value);
    void setCurrent(string name);
    bool hasTable(string name);
    int getColumnsAmount();
    vector<string*> find(string column, string value);
    vector<string*> find(string column, string greater, string less);
    string getName();
};


#endif //LAB4_DATABASE_H
