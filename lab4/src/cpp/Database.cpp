#include "../header/Database.h"
#include "../../libs/header/Functions.h"
#include "../../libs/header/Csv.h"

Database::Database(string name) {
    this->name = name;
    curr = nullptr;
}

Database::~Database() {
    fin.close();
    fout.close();
}

void Database::init() { // Method for initializing the database
    ifstream fin(metadataTableFile);

    while (!fin.eof()) {
        string* arr;
        string buff = "";
        getline(fin, buff);
        if (fin.eof()) { break; }
        arr = csv::parse(buff, 3);
        string* columns = new string[stoi(arr[1])];
        string temp = "";
        int index = 0;
        for (int j = 0; j < arr[2].length(); j++) {
            if (arr[2][j] == ':') {
                columns[index++] = temp;
                temp = "";
                continue;
            }
            temp += arr[2][j];
            if (j == arr[2].length() - 1) {
                columns[index++] = temp;
            }
        }
        Table* table = new Table(arr[0], columns, stoi(arr[1]));
        tables.insert(pair<string, Table*>(arr[0], table));

        delete[] arr;
        delete[] columns;
    }
    fin.close();

    fin.open(metadataIndexFile);

    while (!fin.eof()) {
        string* arr;
        string buff = "";
        getline(fin, buff);
        if (fin.eof()) { break; }
        arr = csv::parse(buff, 3);
        Table* table = tables[arr[0]];
        string name = arr[1];
        string value = arr[2];

        cout << "Index detected; table: " << table->getName() << "; " << name << " " << value << endl;

        ifstream finIndex(indexDirectory + "/" + name + ".csv");
        if (!finIndex.is_open()) {
            table->addIndex(name, value, "");
            continue;
        }
        string data = "";
        readFile(finIndex, data);
        finIndex.close();

        table->addIndex(name, value, data);

        delete[] arr;
    }

    fin.close();

    for (map<string, Table*>::iterator iter = tables.begin(); iter != tables.end(); ++iter) {
        iter->second->setInit(true);
    }
}

void Database::save() { // Method for saving updated data on disk
    for (map<string, Table*>::iterator iter = tables.begin(); iter != tables.end(); ++iter) {
        Table* curr = iter->second;
        map<string, Index*> indexes = curr->getIndexes();
        for (map<string, Index*>::iterator iterInd = indexes.begin(); iterInd != indexes.end(); ++iterInd) {
            string name = iterInd->first;
            string data = iterInd->second->serialize();
            ofstream foutIndex(indexDirectory + "/" + name + ".csv");
            foutIndex << data;
            foutIndex.close();
        }
    }
}

void Database::add(string* args) { // Method for adding a row to a table
    if (!curr) { return; } // No current table
    curr->add(args, fout);
}

void Database::addTable(string name, string* args, int amount) { // Method for adding a table
    if (hasTable(name)) { return; } // Table already exists
    Table* table = new Table(name, args, amount);
    tables.insert(pair<string, Table*>(name, table));

    ofstream foutMetadata(metadataTableFile, ios::app);
    string str = name + ",";
    str += to_string(amount) + ",";
    for (int i = 0; i < amount; i++) {
        str += args[i];
        if (i < amount - 1) { str += ":"; }
    }
    foutMetadata << str + "\n";
    foutMetadata.close();
}

void Database::addIndex(string name, string value) { // Method for adding an index to a current table
    if (!curr) { return; } // No current table
    int status = curr->addIndex(name, value);
    if (!status) { // Success
        ofstream foutMetadata(metadataIndexFile, ios::app);
        foutMetadata << curr->getName() << "," << name << "," << value << "\n";
        foutMetadata.close();
    }
}

void Database::setCurrent(string name) { // Method for setting current table
    if (!hasTable(name)) { return; } // Table doesn't exist
    if (curr && name.compare(curr->getName()) == 0) { return; } // Current table and the new table are the same
    curr = tables[name];
    if (fin.is_open()) {
        fin.close();
    }
    if (fout.is_open()) {
        fout.close();
    }
    fout.open(tableDirectory + "/" + curr->getName() + ".csv", ios::app);
    fin.open(tableDirectory + "/" + curr->getName() + ".csv");
    if (!fin.is_open()) {
        cout << "Error: No data directory" << endl;
        exit(1);
    }
}

void Database::setSize(string name, int size) { // Method for setting table column size in bytes
    if (!curr) { return; } // No current table
    curr->setSize(name, size);
}

bool Database::hasTable(string name) { // Method for checking if database has a table
    return !(tables.find(name) == tables.end());
}

int Database::getColumnsAmount() {
    if (!curr) { return -1; } // No current table
    return curr->getColumnsAmount();
}

vector<string*> Database::find(string column, string value) {
    if (!curr) { // No current table
        vector<string*> vector;
        return vector;
    }
    return curr->find(column, value, fin);
}

vector<string*> Database::find(string column, string greater, string less) {
    if (!curr) { // No current table
        vector<string*> vector;
        return vector;
    }
    return curr->find(column, greater, less, fin);
}

string Database::getName() { // Database name getter
    return name;
}

const string Database::tableDirectory = "../data/tables";
const string Database::indexDirectory = "../data/indexes";
const string Database::metadataTableFile = "../data/metadata/tables.csv";
const string Database::metadataIndexFile = "../data/metadata/indexes.csv";