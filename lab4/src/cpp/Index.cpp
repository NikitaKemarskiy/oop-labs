#include "../header/Index.h"

Index::Index(string name) {
    this->name = name;
}

Index::Index(string name, string data) {
    this->name = name;
    init(data);
}

void Index::init(string data) { // Method for initializing the tree from a string
    tree.init(data);
}

string Index::serialize() { // Method for serializing the tree into a string
    return tree.serialize();
}