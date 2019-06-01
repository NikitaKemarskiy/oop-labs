#include "../header/Database.h"
#include "../../libs/header/md5.h"

Database::Database(string name) {
    this->name = name;
    curr = nullptr;
}

void Database::init() { // Method for initializing the database
    // tableDirectory - папка с таблицами
    // indexDirectory - папка с индексами
    // metadataTableFile - файл с данными про таблицы
    // metadataIndexFile - файл с данными про индексы
    /*
     * Алгоритм действий данного метода:
     *  1. Открываем файл metadataTableFile
     *  2. Читаем с него данные про то, какие есть таблицы и добавляем их в map tables с помощью следующего кода:
     *      Table* table = new Table(name, systemName, args, amount);
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
    string systemName = md5(name + to_string(amount)) + ".csv";
    Table* table = new Table(name, systemName, args, amount);
    tables.insert(pair<string, Table*>(name, table));
    // Создать новый csv файл для таблицы
    // Файл будет расположен в папке с таблицами data/tables
    // Добавляем таблицу в файл metadataTableFile
    // ================================================
    // Добавляем в качестве первой строки имена колонок
    table->add(args);
    table->setInit(false);
}

void Database::add(string *args) { // Method for adding a row to a table
    if (!curr) { return; } // No current table
    // В метод ниже вторым аргументом нужно передавать текущий поток
    curr->add(args);
}

void Database::addIndex(string name) { // Method for adding an index to a current table
    if (!curr) { return; } // No current table
    curr->addIndex(name);
}

void Database::setCurrent(string name) { // Method for setting current table
    if (!hasTable(name)) { return; } // Table doesn't exist
    curr = tables.at(name);
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

const string Database::tableDirectory = "../../data/tables";
const string Database::indexDirectory = "../../data/indexes";
const string Database::metadataTableFile = "../../data/metadata/tables.csv";
const string Database::metadataIndexFile = "../../data/metadata/indexes.csv";