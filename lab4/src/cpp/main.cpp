#include "../header/Database.h"
#include "../../libs/header/csv.h"

#include <iostream>
using namespace std;

void createPlacesTable(Database &database); // Function for creating the places table

int main() {
    Database database("Ukraine");

    database.init();
    if (!database.hasTable("places")) { createPlacesTable(database); } // Database has no places table
    database.setCurrent("places");

    //string arr[] = {"1","123","45","type1","subtype3","some name","123 karla marska"};
    //database.add(arr);

    /*string* items = csv::parse("1997,Ford,E350,\"ac, abs, moon\",3000.00", 5);
    for (int i = 0; i < 5; i++) {
        cout << items[i] << endl;
    }*/

    return 0;
}

void createPlacesTable(Database &database) { // Function for creating the places table
    // Широта; Довгота; Тип; Підтип; Назва; Адреса;
    string columns[] = { "id", "latitude", "longitude", "type", "subtype", "name", "address" }; // Table columns
    int amount = 7; // Amount of columns
    database.addTable("places", columns, amount); // Add places table
    /*
     * Читаем файл input/table.csv и на основе его заполняем таблицу places
     */
}