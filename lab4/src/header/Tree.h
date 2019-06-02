#ifndef LAB4_TREE_H
#define LAB4_TREE_H

#include "../header/Node.h"

#include <string>
using namespace std;

class Tree {
private:
    Node* root;
    unsigned int getHeight(Node* node);
    int balanceFactor(Node* node);
    void calculateHeight(Node* node);
    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);
    Node* balancing(Node* node);
    Node* insert(Node* node, double key, double data);
public:
    Tree();
    void init(string data);
    void addNode(double key, double data);
    double search(double key);
    string serialize();

    void bypass();
    void bypass(Node* node);
};


#endif //LAB4_TREE_H
