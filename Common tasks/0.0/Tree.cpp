//
// Created by User on 09-Feb-21.
//

#include "Tree.h"
#include <fstream>

Tree::Tree(std::string path) {
    std::ifstream in(path);
    int temp;
    while (in) {
        in >> temp;
        addNode(temp);
    }
    in.close();
}

void Tree::addNode(int val) {
    if (root == nullptr) {
        root = new Node(val);
    } else {
        Node* prev = getPrev(val, root);
        if (prev!= nullptr){
            if (val > prev->getVal()) {
                prev->setRight(new Node(val));
            } else {
                prev->setLeft(new Node(val));
            }
        }
    }
}

Tree::Node *Tree::getPrev(int val, Node *curr) {
    if(val==curr->getVal()){
        return nullptr;
    } else if (val > curr->getVal()) {
        if (curr->getRight() == nullptr) {
            return curr;
        }
        getPrev(val, curr->getRight());
    } else {
        if (curr->getLeft() == nullptr) {
            return curr;
        }
        getPrev(val, curr->getLeft());
    }
}

int64_t Tree::count() {
    int64_t sum = 0;
    sumLRR(root, sum);
    return sum;
}

void Tree::sumLRR(Tree::Node *curr, int64_t &sum) {
    if (curr->getLeft() != nullptr) {
        sumLRR(curr->getLeft(), sum);
    }
    sum += curr->getVal();
    if (curr->getRight() != nullptr) {
        sumLRR(curr->getRight(), sum);
    }

}

Tree::Node::Node(int val) {
    this->val = val;
    left = right = nullptr;
}

Tree::Node::Node(int val, Tree::Node *left, Tree::Node *right) {
    this->val = val;
    this->left = left;
    this->right = right;
}

int Tree::Node::getVal() {
    return val;
}

Tree::Node *Tree::Node::getLeft() {
    return left;
}

Tree::Node *Tree::Node::getRight() {
    return right;
}

void Tree::Node::setLeft(Tree::Node *left) {
    this->left = left;
}

void Tree::Node::setRight(Tree::Node *right) {
    this->right = right;
}
