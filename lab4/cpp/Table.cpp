#include "../header/Table.h"

#include <cstdarg>

Table::Table(string name, string* args, int amount) {
    this->name = name;
    this->amount = amount;
    for (int i = 0; i < amount; i++) { // Fill the columns map with names and their indexes in array
        columns.insert(pair<string, int>(args[i], i));
    }
    table = new string*[initialSize]; // Create a table with initialSize number of rows
    for (int i = 0; i < initialSize; i++) {
        table[i] = new string[amount];
    }
}

void Table::add(string* args) {
    if (size == currentSize) { resize(); } // Table is filled -> resize it
    for (int i = 0; i < amount; i++) { // Fill the new row
        table[size][i] = args[i];
    }
    size++; // Increment the size
}

void Table::resize() {
    currentSize *= 2; // Make table currentSize twice greater
    string** buff = new string*[currentSize]; // Create new two-dimensional array for data
    for (int i = 0; i < currentSize; i++) {
        buff[i] = new string[amount];
    }
    for (int i = 0; i < size; i++) { // Fill the existing data
        for (int j = 0; j < amount; j++) {
            buff[i][j] = table[i][j];
        }
    }
    delete[] table; // Delete old table
    table = buff; // Assign new table as a current
}

void Table::addIndex(string name) {
    if (size > 0 || !hasColumn(name) || hasIndex(name)) { return; }
    Tree tree;
    indexes.insert(pair<string, Tree>(name, tree));
}

bool Table::hasColumn(string name) {
    return !(columns.find(name) == columns.end());
}

bool Table::hasIndex(string name) {
    return !(indexes.find(name) == indexes.end());
}

string Table::getName() {
    return name;
}

void Table::printData() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < amount; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int Table::initialSize = 2;