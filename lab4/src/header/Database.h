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
    // Нужно добавить в качестве поля текущий поток для работы с таблицей
    // Потом этот поток будет использоваться для чтения/записи таблицы

    static const string tableDirectory;
    static const string indexDirectory;
    static const string metadataTableFile;
    static const string metadataIndexFile;
public:
    Database(string name);
    void init();
    void save();
    void addTable(string name, string* args, int amount);
    bool hasTable(string name);
    void setCurrent(string name);
    void add(string* args);
    void addIndex(string name);
    string getName();
};


#endif //LAB4_DATABASE_H