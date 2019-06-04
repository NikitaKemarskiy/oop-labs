#include "../header/Csv.h"

#include <iostream>

string* csv::parse(string row, int amount) {
    return parse(row, amount, ',');
}

string* csv::parse(string row, int amount, char delimiter) {
    string* items = new string[amount];

    string curr = "";
    bool quoted = false;
    int index = 0;

    for (int i = 0; i < row.length(); i++) {
        if ((row[i] == delimiter && !quoted) || i == row.length() - 1) {
            if (i == row.length() - 1) { curr += row[i]; }
            if (curr[0] == '"' && curr[curr.length() - 1] == '"') {
                curr.erase(0, 1);
                curr.erase(curr.length() - 1, 1);
                int length = curr.length() - 1;
                for (int j = 0; j < length; j++) {
                    if (curr[j] == '"' && curr[j + 1] == '"') {
                        curr.erase(j, 1);
                    }
                }
            }
            items[index++] = curr;
            curr = "";
            continue;
        }
        curr += row[i];
        if (row[i] == '"') { quoted = !quoted; }
    }

    return items;
}