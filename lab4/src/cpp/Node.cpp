#include "../header/Node.h"

Node::Node() {
    this->key = 0;
    this->data.clear();
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(double key, double data) {
    this->key = key;
    this->data.push_back(data);
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

string Node::toString() {
    string keyStr = to_string(key);
    string dataStr = "";
    keyStr.erase(keyStr.find_last_not_of('0') + 1, string::npos);
    for (int i = 0; i < data.size(); i++) {
        double curr = data[i];
        dataStr += to_string(curr);
        dataStr.erase(dataStr.find_last_not_of('0') + 1, string::npos);
        if (dataStr[dataStr.length() - 1] == '.') {
            dataStr.erase(dataStr.length() - 1, 1);
        }
        if (i < data.size() - 1) { dataStr += ";"; }
    }

    if (keyStr[keyStr.length() - 1] == '.') {
        keyStr.erase(keyStr.length() - 1, 1);
    }
    return "(" + keyStr + ":" + dataStr + ")";
}