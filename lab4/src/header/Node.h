#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include <string>
#include <vector>
using namespace std;

class Node{
private:
    double key;
    vector<double> data;
    unsigned int height;
    Node* left;
    Node* right;
public:
    Node();
    Node(double key, double data);
    double getKey() { return key; }
    vector<double> getData() { return data; }
    unsigned int getHeight() { return height; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    void setHeight(unsigned int height) { this->height = height; }
    void setLeft(Node* left) { this->left = left; }
    void setRight(Node* right) { this->right = right; }
    string toString();
};


#endif //LAB4_NODE_H
