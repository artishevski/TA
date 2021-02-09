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
        Node *prev = getPrev(val, root);
        if (prev != nullptr) {
            if (val > prev->getVal()) {
                prev->setRight(new Node(val));
            } else {
                prev->setLeft(new Node(val));
            }
        }
    }
}

Tree::Node *Tree::getPrev(int val, Node *curr) {
    if (val == curr->getVal()) {
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

void Tree::solution(std::string path) {
    std::ofstream out(path);
    leftTraversal(root, out);
    out.close();
}

void Tree::leftTraversal(Tree::Node *curr, std::ofstream &out) {
    out << curr->getVal() << '\n';
    if (curr->getLeft() != nullptr) {
        leftTraversal(curr->getLeft(), out);
    }
    if (curr->getRight() != nullptr) {
        leftTraversal(curr->getRight(), out);
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