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

    database.addIndex("longitude", "latitude");

    string arr[] = {"1","123","45","type1","subtype3","some name","123 karla marska"};
    database.add(arr);

    database.save();

    return 0;
}

void createPlacesTable(Database &database) { // Function for creating the places table
    // Широта; Довгота; Тип; Підтип; Назва; Адреса;
    string columns[] = { "id", "latitude", "longitude", "type", "subtype", "name", "address" }; // Table columns
    int amount = 7; // Amount of columns
    database.addTable("places", columns, amount); // Add places table
}