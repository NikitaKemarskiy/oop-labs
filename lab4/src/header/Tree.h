#ifndef LAB4_TREE_H
#define LAB4_TREE_H

#include "../header/Node.h"

#include <vector>
#include <string>
using namespace std;

class Tree {
private:
    Node* root;
    int balanceFactor(Node* node);
    unsigned int getHeight(Node* node);
    void calculateHeight(Node* node);
    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);
    Node* balancing(Node* node);
    Node* insert(Node* node, double key, double data);
    vector<double> find(Node* node, double greater, double less);
public:
    Tree();
    void init(string data);
    void addNode(double key, double data);
    vector<double> find(double key);
    vector<double> find(double greater, double less);
    string serialize();

    void bypass();
    void bypass(Node* node);
};


#endif //LAB4_TREE_H
