//
// Created by User on 12-Feb-21.
//
#include <iostream>
#include <fstream>
#include "Tree.h"

Tree::Tree(std::string path) {
    std::ifstream in(path);
    in >> size;
    arr = new Tree::Node[size];
    int curr, prev;
    char pos;
    in >> curr;
    arr[0].setVal(curr);
    for (int i = 1; i < size; i++) {
        in >> curr >> prev >> pos;
        arr[i].setVal(curr);
        if (pos == 'L') {
            arr[prev - 1].setLeft(i);
        } else if (pos == 'R') {
            arr[prev - 1].setRight(i);
        }
    }
    in.close();
}

void Tree::solution(std::string path) {
    bool isTree = true;
    for (int i = 0; i < size; i++) {
        int index;
        if (arr[i].getLeft() != -1) {
            index = arr[i].getLeft();
            while(arr[index].getRight() != -1){
                index= arr[index].getRight();
            }
            if(arr[i].getVal() <= arr[index].getVal()){
                isTree = false;
                break;

            }
        }
        if (arr[i].getRight() != -1){
            index = arr[i].getRight();
            while(arr[index].getLeft() != -1){
                index= arr[index].getLeft();
            }
            if(arr[i].getVal() > arr[index].getVal()){
                isTree = false;
                break;
            }
        }
    }
    std::ofstream out(path);
    if (isTree) {
        out << "YES";
    } else {
        out << "NO";
    }
    out.close();
}

int Tree::Node::getVal() const {
    return val;
}

void Tree::Node::setVal(int val) {
    Node::val = val;
}

int Tree::Node::getLeft() const {
    return left;
}

void Tree::Node::setLeft(int left) {
    Node::left = left;
}

int Tree::Node::getRight() const {
    return right;
}

void Tree::Node::setRight(int right) {
    Node::right = right;
}