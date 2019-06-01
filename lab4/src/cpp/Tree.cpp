#include "../header/Tree.h"

Tree::Tree(){
    root = nullptr;
}

unsigned int Tree::getHeight(Nodprivate* node){
    return node ? node->getHeight() : 0;
}

int Tree::balanceFactor(Nodprivate* node){
    return getHeight(node->getRight()) - getHeight(node->getLeft());
}

void Tree::calculateHeight(Nodprivate* node){
    unsigned int heightLeft = getHeight(node->getLeft());
    unsigned int heightRight = getHeight(node->getRight());
    node->setHeight((heightLeft > heightRight ? heightLeft : heightRight) + 1);
}

Nodprivate* Tree::leftRotate(Nodprivate* node){
    Nodprivate* newNode = node->getRight();
    node->setRight(newNode->getLeft());
    newNode->setLeft(node);
    calculateHeight(node);
    calculateHeight(newNode);
    return newNode;
}

Nodprivate* Tree::rightRotate(Nodprivate *node) {
    Nodprivate* newNode = node->getLeft();
    node->setLeft(newNode->getRight());
    newNode->setRight(node);
    calculateHeight(node);
    calculateHeight(newNode);
    return newNode;
}

Nodprivate* Tree::balancing(Nodprivate *node) {
    calculateHeight(node);
    if(balanceFactor(node) == 2){
        if(balanceFactor(node->getRight()) < 0){
            node->setRight(rightRotate(node->getRight()));
        }
        node = leftRotate(node);
        return node;
    }
    else if(balanceFactor(node) == -2){
        if(balanceFactor(node->getLeft()) > 0){
            node->setLeft(leftRotate(node->getLeft()));
        }
        node = rightRotate(node);
        return node;
    }
    return node;
}

Nodprivate* Tree::insert(Nodprivate *node, double key, double data) {
    if(!node){
        return new Nodprivate(key, data);
    }
    if(data < node->getData()){
        node->setLeft(insert(node->getLeft(), key, data));
    }else{
        node->setRight(insert(node->getRight(), key, data));
    }
    return balancing(node);
}

void Tree::addNode(double key, double data) {
    root = insert(root, key, data);
}

double Tree::search(double key) {
    Nodprivate *newNode = root;
    while (newNode) {
        if (key < newNode->getKey()){
            newNode = newNode->getLeft();
        }else if (key > newNode->getKey()) {
            newNode = newNode->getRight();
        }else if (key == newNode->getKey()) {
            return newNode->getData();
        }
    }
    return -1;
}

