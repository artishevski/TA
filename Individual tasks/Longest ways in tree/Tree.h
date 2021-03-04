//
// Created by User on 04-Mar-21.
//

#ifndef LONGEST_WAYS_IN_TREE_TREE_H
#define LONGEST_WAYS_IN_TREE_TREE_H

#include <iostream>
#include <fstream>
#include <algorithm>

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

        int getHeight() const;

        void setHeight(int depth);

        int getLeavesAmount() const;

        void setLeavesAmount(int leavesAmount);

        int getLengthOfLongestWays() const;

        void setLengthOfLongestWays(int lengthOfLongestWays);

        int getWayTillFarthestNode() const;

        void setWayTillFarthestNode(int wayTillFarthestNode);

        int getAmountOfWaysTillFarthestNode() const;

        void setAmountOfWaysTillFarthestNode(int amountOfWaysTillFarthestNode);

        int getAmountOfLongestWays() const;

        void setAmountOfLongestWays(int amountOfLongestWays);

    private:
        int val;
        int height = 0;
        int leavesAmount = 0;
        int lengthOfLongestWays = 0;
        int amountOfLongestWays = 0;
        int wayTillFarthestNode = 0;
        int amountOfWaysTillFarthestNode = 1;
        Node *left, *right;
    };

    Tree(std::string path);

    void addNode(int val);

    Node *getPrev(int val, Node *curr);

    void solution(std::string path);

    void leftTraversal(Node *curr, std::ofstream &out);

    void setAllHeights(Node *curr);

    void findLongestWaysLikeRoot(Node *curr, Tree::Node *prev = nullptr);

    void waysIfNotNull(Node *curr, Node *son1, Node *son2);

    void findWayTillFarthestNode(Node *curr);

    void deleteRoot();

    Node *getRoot() const;

    int getMaxWay() const;

    void setMaxWay(int maxWay);

private:
    Node *root = nullptr;
    int maxWay = 0;
};


#endif //LONGEST_WAYS_IN_TREE_TREE_H
