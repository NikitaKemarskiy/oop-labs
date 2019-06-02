#include "../header/Functions.h"

string readFile(ifstream& fin) {
    string temp = "";
    buff = "";
    while(!fin.eof()) {
        getline(fin, temp);
        buff += temp;
        temp = "";
    }
    return buff;
}