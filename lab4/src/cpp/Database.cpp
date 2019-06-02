#include "../header/Database.h"
#include "../../libs/header/csv.h"
#include <fstream>

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
    string buff = "";
    while (!fin.eof()) {
        string* arr;
        getline(fin, buff);
        if (fin.eof()) { return; }
        arr = csv::parse(buff, 3);
        string* columns = new string[stoi(arr[1])];
        string temp = "";
        int index = 0;
        for (int j = 0; j < arr[2].length(); j++) {
            if (arr[2][j] == ':') {
                columns[index] = temp;
                temp = "";
                index++;
                continue;
            }
            temp += arr[2][j];
        }
        Table* table = new Table(arr[0], columns, stoi(arr[1]));
        tables.insert(pair<string, Table*>(arr[0], table));
        table->setInit(true);

        delete[] arr;
        delete[] columns;
    }
    fin.close();
    /*
     * Алгоритм действий данного метода:
     *  1. Открываем файл metadataTableFile
     *  2. Читаем с него данные про то, какие есть таблицы и добавляем их в map tables с помощью следующего кода:
     *      Table* table = new Table(name, args, amount);
     *      tables.insert(pair<string, Table*>(name, table));
     *  3. После добавления всех таблиц читаем файл metadataIndexFile про то, какие индексы у каких есть таблиц. Теперь
     *     каждый индекс нужно подобавлять в таблицы, для каждого индекса беря информацию в string из data/indexes и передавая
     *     эту информацию в конструктор индекса (то есть все индексы построятся в оперативной памяти)
     *  4. Нужно сделать все прочитанные таблицы проинициализированными table.setInit(true);
     */
}

void Database::save() { // Method for saving updated data on disk
    // tableDirectory - папка с таблицами
    // indexDirectory - папка с индексами
    // metadataTableFile - файл с данными про таблицы
    // metadataIndexFile - файл с данными про индексы
    /*
     * В данном методе все индексы сохраняются на диск
     * Сериализация индекса в string выполняется посредством метода serialize() (возвращает дерево в формате string)
     */
    /*
     * ?????????????? А что если программа аварийно завершится - индексы не сохранятся
     * ?????????????? Может можно сделать как-то понадежнее? Но сериализовать индекс и перезацисывать файл после каждой вставки НЕЭФФЕКТИВНО
     */
}

void Database::addTable(string name, string* args, int amount) { // Method for adding a table
    if (hasTable(name)) { return; } // Table already exists
    Table* table = new Table(name, args, amount);
    tables.insert(pair<string, Table*>(name, table));

    cout << tableDirectory + "/" + name + ".csv" << endl;
    ofstream foutTable(tableDirectory + "/" + name + ".csv");

    table->setInit(false);

    foutTable.close();

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

void Database::add(string *args) { // Method for adding a row to a table
    if (!curr) { return; } // No current table
    // В метод ниже вторым аргументом нужно передавать текущий поток
    curr->add(args, fout);
}

void Database::addIndex(string name) { // Method for adding an index to a current table
    if (!curr) { return; } // No current table
    curr->addIndex(name);
}

void Database::setCurrent(string name) { // Method for setting current table
    if (!hasTable(name)) { return; } // Table doesn't exist
    curr = tables.at(name);
    if (fin.is_open()) {
        fin.close();
    }
    if (fout.is_open()) {
        fout.close();
    }
    fin.open(tableDirectory + "/" + curr->getName() + ".csv");
    if (!fin.is_open()) {
        cout << "Error: No data directory" << endl;
        exit(1);
    }
    fout.open(tableDirectory + "/" + curr->getName() + ".csv", ios::app);
    // Нужно открыть текущий поток
    // Текущий поток - поле данного класса (Database)
}

void Database::setSize(string name, int size) { // Method for setting table column size in bytes
    if (!curr) { return; } // No current table
    curr->setSize(name, size);
}

bool Database::hasTable(string name) { // Method for checking if database has a table
    return !(tables.find(name) == tables.end());
}

string Database::getName() { // Database name getter
    return name;
}

const string Database::tableDirectory = "../data/tables";
const string Database::indexDirectory = "../data/indexes";
const string Database::metadataTableFile = "../data/metadata/tables.csv";
const string Database::metadataIndexFile = "../data/metadata/indexes.csv";