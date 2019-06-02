#include "../header/Functions.h"

istream& readFile(ifstream& fin, string& buff) {
    string temp = "";
    while(!fin.eof()) {
        getline(fin, temp);
        buff += temp;
        temp = "";
    }
    return fin;
}