#include "../header/Functions.h"
#include <math.h>
#include <cmath>

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