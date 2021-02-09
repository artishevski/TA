//
// Created by User on 09-Feb-21.
//
#include <string>
#ifndef INC_0_0_TREE_H
#define INC_0_0_TREE_H


class Tree {
    class Node {
    public:
        Node(int val);
        Node(int val, Node *left, Node *right);
        int getVal();
        Node *getLeft();
        Node *getRight();
        void setLeft(Node *left);
        void setRight(Node *right);

    private:
        int val;
        Node *left, *right;
    };

public:
    Tree(std::string path);
    void addNode(int val);
    Node* getPrev(int val, Node* curr);
    int64_t count();
    void sumLRR(Node* curr, int64_t& sum);

private:
    Node *root = nullptr;
};


#endif //INC_0_0_TREE_H
