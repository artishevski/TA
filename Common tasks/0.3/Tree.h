//
// Created by User on 12-Feb-21.
//

#ifndef INC_0_3_TREE_H
#define INC_0_3_TREE_H


#include <string>

class Tree {
public:
    Tree(std::string path);

    void solution(std::string path);

    class Node {
    public:
        int getVal() const;
        void setVal(int val);
        int getLeft() const;
        void setLeft(int left);
        int getRight() const;
        void setRight(int right);

    private:
        int val;
        int left = -1;
        int right = -1;
    };

private:
    Node *arr;
    int size;
};


#endif //INC_0_3_TREE_H
