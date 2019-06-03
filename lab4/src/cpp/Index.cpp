#include "../header/Index.h"

Index::Index(string name, string value) {
    this->name = name;
    this->value = value;
}

Index::Index(string name, string value, string data) {
    this->name = name;
    this->value = value;
    init(data);
}

void Index::init(string data) { // Method for initializing the tree from a string
    tree.init(data);
}

void Index::add(double key, double data) {
    tree.addNode(key, data);
}

double Index::find(double key) {
    return tree.find(key);
}

string Index::getName() {
    return name;
}

string Index::getValue() {
    return value;
}

string Index::serialize() { // Method for serializing the tree into a string
    return tree.serialize();
}