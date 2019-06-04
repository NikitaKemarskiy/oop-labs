#include "../header/Table.h"
#include "../header/Index.h"
#include "../../libs/header/Csv.h"

Table::Table(string name, string* args, int columnsAmount) {
    int* sizesArg = new int[columnsAmount];
    for (int i = 0; i < columnsAmount; i++) {
        sizesArg[i] = defaultSize;
    }
    Table(name, args, sizesArg, columnsAmount);
}

Table::Table(string name, string* args, int* sizesArg, int columnsAmount) {
    this->name = name;
    this->columnsAmount = columnsAmount;
    init = false;
    for (int i = 0; i < columnsAmount; i++) { // Fill the columns map with names and their indexes in array
        columns.insert(pair<string, int>(args[i], i));
        sizes.insert(pair<string, int>(args[i], sizesArg[i]));
        columnsIndexes.insert(pair<int, string>(i, args[i]));
    }
    lineSize = 0;
    for (map<string, int>::iterator iter = sizes.begin(); iter != sizes.end(); ++iter) {
        lineSize += iter->second + 1;
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

    for (map<string, Index*>::iterator iter = indexes.begin(); iter != indexes.end(); ++iter) {
        int name = columns[iter->first];
        int value = columns[iter->second->getValue()];
        Index* indexCurr = iter->second;
        indexCurr->add(stod(args[name]), stod(args[value]));
    }
}

bool Table::addIndex(string name, string value) { // Method for adding an index
    if (init || !hasColumn(name) || !hasColumn(value) || hasIndex(name)) { return 1; }
    Index* index = new Index(name, value);
    indexes.insert(pair<string, Index*>(name, index));
    return 0;
}

void Table::addIndex(string name, string value, string data) { // Method for adding an index
    if (!hasColumn(name) || hasIndex(name)) { return; }
    Index* index = new Index(name, value, data);
    indexes.insert(pair<string, Index*>(name, index));
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

int Table::getColumnsAmount() {
    return columnsAmount;
}

map<string, Index*> Table::getIndexes() {
    return indexes;
}

string* Table::findById(int id, ifstream &fin) {
    fin.seekg(0);
    fin.ignore(lineSize * (id - 1));
    /*for (int i = 0; i < id - 1; i++) {
        fin.ignore(lineSize);
    }*/
    string row;
    getline(fin, row);
    //cout << "Row: " << row << endl;
    string* arr = csv::parse(row, columnsAmount);
    for (int i = 0; i < columnsAmount; i++) {
        arr[i].erase(arr[i].find_last_not_of(" \n\r\t")+1);
    }
    return arr;
}

vector<int> Table::findIds(string column, string value) {
    vector<int> ids;
    if (column.compare("id") == 0) { // Passed column is id
        ids.push_back(stoi(value));
        return ids;
    }
    Index* curr = indexes[column];
    vector<double> values = curr->find(stod(value));
    for (int i = 0; i < values.size(); i++) {
        vector<int> result = (findIds(curr->getValue(), to_string(values[i])));
        for (int i = 0; i < result.size(); i++) {
            ids.push_back(result[i]);
        }
    }
    return ids;
}

vector<int> Table::findIds(string column, string greater, string less) {
    vector<int> ids;
    if (column.compare("id") == 0) { // Passed column is id
        for (int i = stoi(greater); i < stoi(less); i++) {
            ids.push_back(i);
        }
        return ids;
    }
    Index* curr = indexes[column];
    vector<double> values = curr->find(stod(greater), stod(less));
    for (int i = 0; i < values.size(); i++) {
        vector<int> result = (findIds(curr->getValue(), to_string(values[i])));
        for (int i = 0; i < result.size(); i++) {
            ids.push_back(result[i]);
        }
    }
    return ids;
}

vector<string*> Table::find(string column, string value, ifstream &fin) {
    vector<string *> rows;
    if (column.compare("id") == 0) { // Passed column is id
        rows.push_back(findById(stoi(value), fin));
        return rows;
    }
    bool hasIndex = true; // Flag
    Index *curr = indexes[column]; // Current index
    while (curr && curr->getValue() != "id") { // Loop to check if indexes chain lead to id
        curr = indexes[curr->getValue()];
    }
    if (!curr) { hasIndex = false; } // Passed column indexes chain doesn't lead to id
    if (hasIndex) { // There's an index for search
        vector<int> ids = findIds(column, value);
        for (int i = 0; i < ids.size(); i++) {
            rows.push_back(findById(ids[i], fin));
        }
    }
    // Нету индекса для поиска
    // Перебираем весь файл таблицы в поисках
    return rows;
}

vector<string*> Table::find(string column, string greater, string less, ifstream &fin) {
    vector<string*> rows;
    if (column.compare("id") == 0) { // Passed column is id
        for (int i = stoi(greater); i < stoi(less); i++) {
            rows.push_back(findById(i, fin));
        }
        return rows;
    }
    bool hasIndex = true; // Flag
    Index *curr = indexes[column]; // Current index
    while (curr && curr->getValue() != "id") { // Loop to check if indexes chain lead to id
        curr = indexes[curr->getValue()];
    }
    if (!curr) { hasIndex = false; } // Passed column indexes chain doesn't lead to id
    if (hasIndex) { // There's an index for search
        vector<int> ids = findIds(column, greater, less);
        for (int i = 0; i < ids.size(); i++) {
            rows.push_back(findById(ids[i], fin));
        }
    }
    // Нету индекса для поиска
    // Перебираем весь файл таблицы в поисках
    return rows;
}

string Table::getName() { // Table name getter
    return name;
}

int Table::getDefaultSize() {
    return defaultSize;
}

const int Table::defaultSize = 32;