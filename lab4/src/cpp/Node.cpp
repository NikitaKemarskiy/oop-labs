#include "../header/Node.h"

Nodprivate::Nodprivate() {
    this->key = 0;
    this->data = 0;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Nodprivate::Nodprivate(double key, double data) {
    this->key = key;
    this->data = data;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
}