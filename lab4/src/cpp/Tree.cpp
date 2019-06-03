#include "../header/Tree.h"

#include <iostream>
#include <queue>
using namespace std;

Tree::Tree() {
    root = nullptr;
}

unsigned int Tree::getHeight(Node* node) {
    return node ? node->getHeight() : 0;
}

int Tree::balanceFactor(Node* node) {
    return getHeight(node->getRight()) - getHeight(node->getLeft());
}

void Tree::calculateHeight(Node* node) {
    unsigned int heightLeft = getHeight(node->getLeft());
    unsigned int heightRight = getHeight(node->getRight());
    node->setHeight((heightLeft > heightRight ? heightLeft : heightRight) + 1);
}

Node* Tree::leftRotate(Node* node) {
    Node* newNode = node->getRight();
    node->setRight(newNode->getLeft());
    newNode->setLeft(node);
    calculateHeight(node);
    calculateHeight(newNode);
    return newNode;
}

Node* Tree::rightRotate(Node *node) {
    Node* newNode = node->getLeft();
    node->setLeft(newNode->getRight());
    newNode->setRight(node);
    calculateHeight(node);
    calculateHeight(newNode);
    return newNode;
}

Node* Tree::balancing(Node *node) {
    calculateHeight(node);
    if (balanceFactor(node) == 2) {
        if (balanceFactor(node->getRight()) < 0) {
            node->setRight(rightRotate(node->getRight()));
        }
        node = leftRotate(node);
        return node;
    }
    else if (balanceFactor(node) == -2) {
        if (balanceFactor(node->getLeft()) > 0) {
            node->setLeft(leftRotate(node->getLeft()));
        }
        node = rightRotate(node);
        return node;
    }
    return node;
}

Node* Tree::insert(Node *node, double key, double data) {
    if (!node) {
        return new Node(key, data);
    }
    if (key < node->getKey()) {
        node->setLeft(insert(node->getLeft(), key, data));
    } else if (key > node->getKey()) {
        node->setRight(insert(node->getRight(), key, data));
    } else if (key == node->getKey()){
        node->addData(data);
    }
    return balancing(node);
}

vector<double> Tree::find(Node* node, double greater, double less) {
    vector<double> values;
    if (!node) { return values; }
    if (node->getKey() >= greater && node->getKey() < less) {
        vector<double> data = node->getData();
        for (int i = 0; i < data.size(); i++) {
            values.push_back(data[i]);
        }
        data = find(node->getLeft(), greater, less);
        for (int i = 0; i < data.size(); i++) {
            values.push_back(data[i]);
        }
        data = find(node->getRight(), greater, less);
        for (int i = 0; i < data.size(); i++) {
            values.push_back(data[i]);
        }
    } else if (node->getKey() < greater) {
        vector<double> data = find(node->getRight(), greater, less);
        for (int i = 0; i < data.size(); i++) {
            values.push_back(data[i]);
        }
    } else if (node->getKey() >= less) {
        vector<double> data = find(node->getLeft(), greater, less);
        for (int i = 0; i < data.size(); i++) {
            values.push_back(data[i]);
        }
    }
    return values;
}

void Tree::init(string data) {
    if (root) { return; } // Tree isn't empty
    string buff = "";
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != ',') {
            buff += data[i];
        }
        if (data[i] == ',' || i == data.length() - 1) {
            buff.erase(0, 1);
            buff.erase(buff.length() - 1, 1);
            string keyStr = buff.substr(0, buff.find(':'));
            string dataStr = buff.substr(buff.find(':') + 1);
            string temp = "";
            for (int j = 0; j < dataStr.length(); j++) {
                if (dataStr[j] != ';') {
                    temp += dataStr[j];
                }
                if (dataStr[j] == ';' || j == dataStr.length() - 1) {
                    addNode(stod(keyStr), stod(temp));
                    temp = "";
                }
            }
            buff = "";
        }
    }
}

void Tree::addNode(double key, double data) {
    root = insert(root, key, data);
}

vector<double> Tree::find(double key) {
    Node *newNode = root;
    while (newNode) {
        if (key < newNode->getKey()) {
            newNode = newNode->getLeft();
        } else if (key > newNode->getKey()) {
            newNode = newNode->getRight();
        } else if (key == newNode->getKey()) {
            return newNode->getData();
        }
    }
    vector<double> temp;
    return temp;
}

vector<double> Tree::find(double greater, double less) {
    vector<double> values;
    values = find(root, greater, less);
    return values;
}

string Tree::serialize() {
    string str = "";
    queue<Node*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        Node* curr = nodes.front();
        nodes.pop();
        if (!curr) { continue; }
        str += curr->toString() + ",";
        nodes.push(curr->getLeft());
        nodes.push(curr->getRight());
    }
    if (!str.empty()) {
        str.erase(str.length() - 1, 1);
    }
    return str;
}

void Tree::bypass() {
    bypass(root);
}

void Tree::bypass(Node* node) {
    cout << node->toString() << " ";
    if (node->getLeft()) {
        cout << "-> (left) ->";
        bypass(node->getLeft());
    }
    if (node->getRight()) {
        cout << "-> (right) ->";
        bypass(node->getRight());
    }
}