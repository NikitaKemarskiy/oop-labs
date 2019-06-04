#include "../header/Functions.h"
#include "../../src/header/Database.h"
#include "../header/Csv.h"
#include <math.h>
#include <cmath>


#define INPUT_FILE "../input/table.csv"
const int radiusOfEarth = 6371;

istream& readFile(ifstream& fin, string& buff) {
    string temp = "";
    while(!fin.eof()) {
        getline(fin, temp);
        buff += temp;
        temp = "";
    }
    return fin;
}


vector<string> getLimits(string latitude, string longitude, double length){
    vector<string> limits;
    double d = length/radiusOfEarth;
    double latitudeInRadians = (stod(latitude) * M_PI) / 180;
    double longitudeInRadians = (stod(longitude) * M_PI) / 180;
    double firstPointLatitudeRad = 2*asin(sin(d/2)) + latitudeInRadians; //Верхня
    double secondPointLongitudeRad = 2*asin(sin(d/2) / cos(stod(latitude))) + longitudeInRadians; //Права
    double firstPointLatitude = (firstPointLatitudeRad * 180) / M_PI;
    double secondPointLongitude = (secondPointLongitudeRad * 180) / M_PI;
    double thirdPointLatitude = stod(latitude) - firstPointLatitude + stod(latitude); //Нижня
    double forthPointLongitude = stod(longitude) - secondPointLongitude + stod(longitude); //Лєва
    limits.push_back(to_string(firstPointLatitude));
    limits.push_back(to_string(thirdPointLatitude));
    limits.push_back(to_string(secondPointLongitude));
    limits.push_back(to_string(forthPointLongitude));
    return limits;
}

vector<string*> getSquare(vector<string*> latitude, vector<string*> longitude){
    vector<string*> result;
    for(int i = 0; i < latitude.size(); i++){
        for(int j = 0; j < longitude.size(); j++){
            if(latitude[i][0] == longitude[j][0]){
               result.push_back(latitude[i]);
            }
        }
    }
    return result;
}

vector<string*> getCircle(vector<string*> squareResult, string latitudeCenter, string longitudeCenter, double radius){
    vector<string*> result;
    for(int i = 0; i < squareResult.size(); i++){
        if(radius >= getLength(latitudeCenter, longitudeCenter, squareResult[i][1], squareResult[i][2])){
            result.push_back(squareResult[i]);
        }
    }
    return result;
}

double getLength(string latitudeCenter, string longitudeCenter, string latitudeTemp, string longitudeTemp){
    double length;
    double latitudeCenterRad = (stod(latitudeCenter) * M_PI) / 180;
    double longitudeCenterRad = (stod(longitudeCenter) * M_PI) / 180;
    double latitudeTempRad = (stod(latitudeCenter) * M_PI) / 180;
    double longitudeTempRad = (stod(longitudeTemp) * M_PI) / 180;
    double deltaLatitude = latitudeCenterRad - latitudeTempRad;
    double deltaLongitude = longitudeCenterRad - longitudeTempRad;
    double squareRoot = sqrt(pow(sin(deltaLatitude / 2), 2) + cos(longitudeCenterRad) * cos(longitudeTempRad) * pow(sin(deltaLongitude / 2), 2));
    length = 2 * radiusOfEarth * asin(squareRoot);
    return length;
}

void printObjects(vector<string*> result, int columns){
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < columns; j++){
            cout << result[i][j] << "; ";
        }
        cout << endl;
    }
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