#include "../header/Database.h"
#include "../../libs/header/Csv.h"
#include "../../libs/header/Functions.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    Database database("Ukraine");
    string latitude, longitude;
    double radius;

    database.init();
    if (!database.hasTable("places")) { createPlacesTable(database); } // Database has no places table
    database.setCurrent("places");

    cout << "Write latitude: "; cin >> latitude;
    cout << "Write longitude: "; cin >> longitude;
    cout << "Write radius: "; cin >> radius;

    vector<string> limits;
    limits = getLimits(latitude, longitude, radius);
    cout << limits[0] << " " << limits[1] << endl;
    cout << limits[2] << " " << limits[3] << endl;
    vector<string*> resultLatitude = database.find("latitude", limits[1], limits[0]);
    vector<string*> resultLongitude = database.find("longitude", limits[3], limits[2]);
    vector<string*> resultSquare = getSquare(resultLatitude, resultLongitude);
    vector<string*> resultCircle = getCircle(resultSquare, latitude, longitude, radius);
    printObjects(resultCircle, database.getColumnsAmount());

    database.save();

    return 0;
}