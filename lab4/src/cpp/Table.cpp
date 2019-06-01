#include "../header/Table.h"
#include "../header/Index.h"

Table::Table(string name, string* args, int columnsAmount) {
    this->name = name;
    this->columnsAmount = columnsAmount;
    init = false;
    for (int i = 0; i < columnsAmount; i++) { // Fill the columns map with names and their indexes in array
        columns.insert(pair<string, int>(args[i], i));
        sizes.insert(pair<string, int>(args[i], defaultSize));
        columnsIndexes.insert(pair<int, string>(i, args[i]));
    }
    lineSize = 0;
    for (map<string, int>::iterator iter = sizes.begin(); iter != sizes.end(); ++iter) {
        lineSize += iter->second;
    }
}

void Table::add(string* args, ofstream& fout) { // Method for adding a row
    if (!init) { init = true; }
    string str = "";
    for (int i = 0; i < columnsAmount; i++) {
        int size = sizes[columnsIndexes[i]];
        string curr = args[i];
        if (curr.length() > size) {
            curr = curr.substr(0, size);
        }
        while (curr.length() < size) {
            curr += " ";
        }
        str += curr;
        if (i < columnsAmount - 1) {
            str += ",";
        }
    }
    fout << str + "\n";
    // Добавляем новую строку в файл с таблицей
    // Надо вторым аргументом передавать открытый поток для записи
}

void Table::addIndex(string name) { // Method for adding an index
    if (init || !hasColumn(name) || hasIndex(name)) { return; }
    Index index(name);
    indexes.insert(pair<string, Index>(name, index));
    /*
     * Создаем новый файл в data/indexes.csv для нового индекса
     * Добавляем инфу про данный индекс в data/metadata/indexes.csv
     */
}

void Table::addIndex(string name, string data) { // Method for adding an index
    if (!hasColumn(name) || hasIndex(name)) { return; }
    Index index(name, data);
}

void Table::setSize(string name, int size) {
    if (init || !hasColumn(name) || size < 1) { return; }
    lineSize -= sizes[name];
    sizes[name] = size; // Set new size in bytes
    lineSize += sizes[name];
}

void Table::setInit(bool init) {
    this->init = init;
}

bool Table::hasColumn(string name) { // Method to check if table has a column
    return !(columns.find(name) == columns.end());
}

bool Table::hasIndex(string name) { // Method to check if table has an index
    return !(indexes.find(name) == indexes.end());
}

int Table::getLineSize() {
    return lineSize;
}

string Table::getName() { // Table name getter
    return name;
}

const int Table::defaultSize = 32;