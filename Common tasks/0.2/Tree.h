//
// Created by User on 09-Feb-21.
//
#include <string>
#ifndef INC_0_0_TREE_H
#define INC_0_0_TREE_H

class Tree {
public:
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

    Tree(std::string path);

    void addNode(int val);

    Node *getPrev(int val, Node *curr);

    void solution(std::string path);

    void leftTraversal(Node *curr, std::ofstream &out);

    int getNodeToDelete();

    void findNode(Node *&curr, Node *&prev);

    void deleteNode(Node *curr, Node *prev);

private:
    Node *root = nullptr;
    int nodeToDelete;
};


#endif //INC_0_0_TREE_H
