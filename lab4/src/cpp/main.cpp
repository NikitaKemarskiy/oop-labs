#include "../header/Database.h"
#include "../../libs/header/Csv.h"

#include <string>
#include <fstream>
#include <iostream>

#define INPUT_FILE "../input/table.csv"
using namespace std;

void createPlacesTable(Database &database); // Function for creating the places table

int main() {
    Database database("Ukraine");

    database.init();
    if (!database.hasTable("places")) { createPlacesTable(database); } // Database has no places table
    database.setCurrent("places");

    vector<string*> result = database.find("latitude", "49.02827");
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < database.getColumnsAmount(); j++) {
            cout << result[i][j] << "; ";
        }
        cout << endl;
    }

    database.save();

    return 0;
}

void createPlacesTable(Database &database) { // Function for creating the places table
    // Широта; Долгота; Тип; Подтип; Название; Адрес;
    string columns[] = { "id", "latitude", "longitude", "type", "subtype", "name", "address" }; // Table columns
    int sizes[] = { 9, 12, 12, 32, 32, 80, 48 }; // Table columns sizes in bytes
    const int amount = 7; // Amount of columns
    database.addTable("places", columns, sizes, amount); // Add places table
    database.setCurrent("places");
    database.addIndex("latitude", "longitude");
    database.addIndex("longitude", "id");

    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cout << "Error: No input table" << endl;
        exit(1);
    }

    int index = 1;
    while (!fin.eof()) {
        string buff = "";
        getline(fin, buff);
        if (fin.eof()) { break; }
        string* temp = csv::parse(buff, amount - 1, ';');
        string* arr = new string[amount];
        arr[0] = to_string(index++);
        for (int i = 0; i < amount - 1; i++) {
            arr[i + 1] = temp[i];
        }
        if (arr[amount - 1].length() > 0) { // Last column is empty
            arr[amount - 1].erase(arr[amount - 1].length() - 1, 1); // Erase excess ';'
        }
        arr[1].replace(arr[1].find(','), 1, "."); // Replace ',' with '.' in double values
        arr[2].replace(arr[2].find(','), 1, "."); // Replace ',' with '.' in double values

        database.add(arr);

        delete[] arr;
        delete[] temp;
    }
}