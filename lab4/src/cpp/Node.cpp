#include "../header/Node.h"

Node::Node() {
    this->key = 0;
    this->data = 0;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(double key, double data) {
    this->key = key;
    this->data = data;
    this->height = 1;
    this->left = nullptr;
    this->right = nullptr;
}

string Node::toString() {
    string keyStr = to_string(key);
    string dataStr = to_string(data);
    keyStr.erase(keyStr.find_last_not_of('0') + 1, string::npos);
    dataStr.erase(dataStr.find_last_not_of('0') + 1, string::npos);
    if (keyStr[keyStr.length() - 1] == '.') {
        keyStr.erase(keyStr.length() - 1, 1);
    }
    if (dataStr[dataStr.length() - 1] == '.') {
        dataStr.erase(dataStr.length() - 1, 1);
    }
    return "(" + keyStr + ";" + dataStr + ")";
}