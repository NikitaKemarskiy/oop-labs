#include "../header/Database.h"
#include "../../libs/header/Csv.h"

#include <string>
#include <iostream>
using namespace std;

void createPlacesTable(Database &database); // Function for creating the places table

int main() {
    Database database("Ukraine");

    database.init();
    if (!database.hasTable("places")) { createPlacesTable(database); } // Database has no places table
    database.setCurrent("places");

    vector<string*> data1 = database.find("latitude", "124");
    vector<string*> data2 = database.find("longitude", "45");

    for (int i = 0; i < data1.size(); i++) {
        for (int j = 0; j < database.getColumnsAmount(); j++) {
            cout << data1[i][j] << " ";
        }
        cout << " | ";
    }
    cout << endl;
    for (int i = 0; i < data1.size(); i++) {
        for (int j = 0; j < database.getColumnsAmount(); j++) {
            cout << data2[i][j] << " ";
        }
        cout << " | ";
    }

    database.save();

    return 0;
}

void createPlacesTable(Database &database) { // Function for creating the places table
    // Широта; Долгота; Тип; Подтип; Название; Адрес;
    string columns[] = { "id", "latitude", "longitude", "type", "subtype", "name", "address" }; // Table columns
    int amount = 7; // Amount of columns
    database.addTable("places", columns, amount); // Add places table
    database.setCurrent("places");
    database.addIndex("longitude", "latitude");
    database.addIndex("latitude", "id");

    string arr[] = { "1", "123", "45", "1", "subtype3", "some name", "123 karla marska" };
    string arr_[] = { "2", "124", "45", "1", "subtype3", "some name", "123 karla marska" };
    database.add(arr);
    database.add(arr_);
    database.add(arr);
    database.add(arr_);
    database.add(arr);
    database.add(arr_);
    database.add(arr);
    database.add(arr_);
}