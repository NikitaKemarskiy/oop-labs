#include "../header/Database.h"

Database::Database(string name) {
    this->name = name;
    curr = nullptr;
}

void Database::addTable(string name, string* args, int amount) {
    if (hasTable(name)) { return; } // Table already exists
    Table* table = new Table(name, args, amount);
    tables.insert(pair<string, Table*>(name, table));
}

bool Database::hasTable(string name) {
    return !(tables.find(name) == tables.end());
}

void Database::setCurrent(string name) {
    if (!hasTable(name)) { return; } // Table doesn't exist
    curr = tables.at(name);
}

void Database::add(string *args) {
    if (!curr) { return; } // No current table
    curr->add(args);
}

void Database::addIndex(string name) {
    if (!curr) { return; } // No current table
    curr->addIndex(name);
}

string Database::getName() {
    return name;
}

void Database::printData() {
    if (!curr) { return; }
    curr->printData();
}