#include "../header/Table.h"
#include "../header/Index.h"

Table::Table(string name, string systemName, string* args, int columnsAmount) {
    this->name = name;
    this->systemName = systemName;
    this->columnsAmount = columnsAmount;
    for (int i = 0; i < columnsAmount; i++) { // Fill the columns map with names and their indexes in array
        columns.insert(pair<string, int>(args[i], i));
        sizes.insert(pair<string, int>(args[i], defaultSize));
    }
}

void Table::add(string* args) { // Method for adding a row
    // Добавляем новую строку в файл с таблицей
    // Надо вторым аргументом передавать открытый поток для записи
    // size++; // Increment the size
}

void Table::addIndex(string name) { // Method for adding an index
    if (size > 0 || !hasColumn(name) || hasIndex(name)) { return; }
    Index index(name);
    indexes.insert(pair<string, Index>(name, index));
    /*
     * Создаем новый файл в data/indexes.csv для нового индекса
     * Добавляем инфу про данный индекс в data/metadata/indexes.csv
     */
}

void Table::setSize(string name, int size) {
    if (!hasColumn(name) || size < 1) { return; }
    sizes[name] = size; // Set new size in bytes
}

bool Table::hasColumn(string name) { // Method to check if table has a column
    return !(columns.find(name) == columns.end());
}

bool Table::hasIndex(string name) { // Method to check if table has an index
    return !(indexes.find(name) == indexes.end());
}

string Table::getName() { // Table name getter
    return name;
}