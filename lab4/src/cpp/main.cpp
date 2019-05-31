#include "../header/Database.h"

#include <iostream>
using namespace std;

void createPlacesTable(Database database); // Function for creating the places table

int main() {
    Database database("Ukraine");

    database.init();
    if (!database.hasTable("places")) { createPlacesTable(database); } // Database has no places table
    database.setCurrent("places");

    return 0;
}

void createPlacesTable(Database database) { // Function for creating the places table
    // Широта; Довгота; Тип; Підтип; Назва; Адреса;
    string columns[] = { "id", "latitude", "longitude", "type", "subtype", "name", "address" }; // Table columns
    int amount = 7; // Amount of columns
    database.addTable("places", columns, amount); // Add places table
    /*
     * Читаем файл input/table.csv и на основе его заполняем таблицу places
     */
}