#ifndef LAB4_NODE_H
#define LAB4_NODE_H


class Nodprivate{
private:
    double key;
    double data;
    unsigned int height;
    Nodprivate* left;
    Nodprivate* right;
public:
    Nodprivate();
    Nodprivate(double key, double data);
    double getKey() { return key; }
    double getData() { return data; }
    unsigned int getHeight() { return height; }
    Nodprivate* getLeft() { return left; }
    Nodprivate* getRight() { return right; }
    void setHeight(unsigned int height) { this->height = height; }
    void setLeft(Nodprivate* left) { this->left = left; }
    void setRight(Nodprivate* right) { this->right = right; }
};


#endif //LAB4_NODE_H
