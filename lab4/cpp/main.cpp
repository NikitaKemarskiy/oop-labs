#include "../header/Database.h"

#include <iostream>
using namespace std;

int main() {
    Database database("Ukraine");

    string columns[] = { "id", "width", "height", "name" }; // Table columns
    int amount = 4; // Amount of columns
    database.addTable("places", columns, amount); // Add new table
    database.setCurrent("places");

    /*string data[] = {"0", "100", "100", "name1"};

    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);
    database.add(data);*/

    database.printData();

    return 0;
}