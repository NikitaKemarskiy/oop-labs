#ifndef LAB4_DATABASE_H
#define LAB4_DATABASE_H

#include "Table.h"

#include <string>
#include <map>
using namespace std;

class Database {
private:
    string name;
    map<string, Table> tables;
public:
    Database(string name) {
        this->name = name;
    }

    void addTable(string name) {
        if (hasTable(name)) { return; } // Table already exists
        Table table;
        tables.insert(pair<string, Table>(name, table));
    }

    bool hasTable(string name) {
        return tables.find(name) == tables.end();
    }
};


#endif //LAB4_DATABASE_H
