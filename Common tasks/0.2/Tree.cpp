//
// Created by User on 09-Feb-21.
//

#include "Tree.h"
#include <fstream>

Tree::Tree(std::string path) {
    std::ifstream in(path);
    in >> nodeToDelete;
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
    if(curr== nullptr){
        return;
    }
    out << curr->getVal() << '\n';
    if (curr->getLeft() != nullptr) {
        leftTraversal(curr->getLeft(), out);
    }
    if (curr->getRight() != nullptr) {
        leftTraversal(curr->getRight(), out);
    }
}

int Tree::getNodeToDelete() {
    return nodeToDelete;
}

void Tree::findNode(Node *&curr, Node *&prev) {
    curr = prev = root;
    if (nodeToDelete > curr->getVal()) {
        curr = curr->getRight();
    } else if (nodeToDelete < curr->getVal()) {
        curr = curr->getLeft();
    }
    while (curr != nullptr && curr->getVal() != nodeToDelete) {
        prev = curr;
        if (nodeToDelete > curr->getVal()) {
            curr = curr->getRight();
        } else {
            curr = curr->getLeft();
        }
    }
}

void Tree::deleteNode(Tree::Node *curr, Tree::Node *prev) {
    if(curr == nullptr){
        return;
    }
    if(curr==root){
        if(root->getLeft()== nullptr){
            root = curr->getRight();
            delete curr;
        } else if(root->getRight()== nullptr){
            root = curr->getLeft();
            delete curr;
        } else if(root->getRight()->getLeft()== nullptr){
            root->getRight()->setLeft(root->getLeft());
            root = root->getRight();
            delete curr;
        }
        else{
            Tree::Node *newCurr = curr->getRight();
            while (newCurr->getLeft()->getLeft() != nullptr) {
                newCurr = newCurr->getLeft();
            }
            curr=newCurr->getLeft();
            newCurr->setLeft(curr->getRight());
            curr->setLeft(root->getLeft());
            curr->setRight(root->getRight());
            root = curr;
            delete prev;
        }
    }
    else {
        if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
            if (curr->getVal() > prev->getVal()) {
                prev->setRight(nullptr);
            } else {
                prev->setLeft(nullptr);
            }
        } else if (curr->getLeft() == nullptr) {
            if (curr->getVal() > prev->getVal()) {
                prev->setRight(curr->getRight());
            } else {
                prev->setLeft(curr->getRight());
            }
        } else if (curr->getRight() == nullptr) {
            if (curr->getVal() > prev->getVal()) {
                prev->setRight(curr->getLeft());
            } else {
                prev->setLeft(curr->getLeft());
            }
        } else if (curr->getRight()->getLeft() == nullptr) {
            curr->getRight()->setLeft(curr->getLeft());
            if (curr->getVal() > prev->getVal()) {
                prev->setRight(curr->getRight());
            } else {
                prev->setLeft(curr->getRight());
            }
        } else {

            Tree::Node *newCurr = curr->getRight();
            while (newCurr->getLeft()->getLeft() != nullptr) {
                newCurr = newCurr->getLeft();
            }

            if (curr->getVal() > prev->getVal()) {
                prev->setRight(newCurr->getLeft());
                newCurr->setLeft(newCurr->getLeft()->getRight());
                prev->getRight()->setLeft(curr->getLeft());
                prev->getRight()->setRight(curr->getRight());
            } else {
                prev->setLeft(newCurr->getLeft());
                newCurr->setLeft(newCurr->getLeft()->getRight());
                prev->getLeft()->setLeft(curr->getLeft());
                prev->getLeft()->setRight(curr->getRight());
            }
        }
        delete curr;

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