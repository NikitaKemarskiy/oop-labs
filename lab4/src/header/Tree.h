#ifndef LAB4_TREE_H
#define LAB4_TREE_H

#include "../header/Node.h"

class Tree {
private:
    Nodprivate* root;
    unsigned int getHeight(Nodprivate* node);
    int balanceFactor(Nodprivate* node);
    void calculateHeight(Nodprivate* node);
    Nodprivate* leftRotate(Nodprivate* node);
    Nodprivate* rightRotate(Nodprivate* node);
    Nodprivate* balancing(Nodprivate* node);
    Nodprivate* insert(Nodprivate* node, double key, double data);
public:
    Tree();
    void addNode(double key, double data);
    double search(double key);
};


#endif //LAB4_TREE_H
