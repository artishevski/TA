//
// Created by User on 04-Mar-21.
//

#include "Tree.h"
Tree::Tree(std::string path) {
    std::ifstream in(path);
    int temp;
    while (in >> temp) {
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
            if (val >= prev->getVal()) {
                prev->setRight(new Node(val));
            } else {
                prev->setLeft(new Node(val));
            }
        }
    }
}

Tree::Node *Tree::getPrev(int val, Node *curr) {
    if (val == curr->getVal()) {
        while(val == curr->getVal()){
            if(curr->getRight()!= nullptr) {
                curr = curr->getRight();
            }
            else{
                return curr;
            }
        }
        while (curr->getLeft()!= nullptr){
            curr=curr->getLeft();
        }
        return curr;
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
    if (curr == nullptr) {
        return;
    }
    if(root->getLeft()== nullptr&&root->getRight()== nullptr){
        out << curr->getVal() << ' ' << 1 << '\n';
        return;
    }
    if(curr->getLengthOfLongestWays()==maxWay || curr->getHeight()+curr->getWayTillFarthestNode()==maxWay){
        if (curr->getWayTillFarthestNode() + curr->getHeight() == curr->getLengthOfLongestWays()) {
            if (curr->getWayTillFarthestNode()) {
                out << curr->getVal() << ' '
                    << curr->getAmountOfWaysTillFarthestNode() * curr->getLeavesAmount() + curr->getAmountOfLongestWays()
                    << '\n';
            } else {
                out << curr->getVal() << ' ' << curr->getAmountOfLongestWays() << '\n';
            }
        } else if (curr->getWayTillFarthestNode() + curr->getHeight() > curr->getLengthOfLongestWays()) {
            out << curr->getVal() << ' ' << curr->getAmountOfWaysTillFarthestNode() * curr->getLeavesAmount() << '\n';
        } else if (curr->getWayTillFarthestNode() + curr->getHeight() < curr->getLengthOfLongestWays()) {
            out << curr->getVal() << ' ' << curr->getAmountOfLongestWays() << '\n';
        }
    }
    else{
        out << curr->getVal() << ' ' << 0 << '\n';
    }

    if (curr->getLeft() != nullptr) {
        leftTraversal(curr->getLeft(), out);
    }
    if (curr->getRight() != nullptr) {
        leftTraversal(curr->getRight(), out);
    }
}

void Tree::setAllHeights(Tree::Node *curr) {
    if (curr == nullptr) {
        return;
    }
    if (curr->getLeft() != nullptr) {
        setAllHeights(curr->getLeft());
    }
    if (curr->getRight() != nullptr) {
        setAllHeights(curr->getRight());
    }
    if (curr->getLeft() == nullptr && curr->getRight() == nullptr) {
        curr->setHeight(0);
        curr->setLeavesAmount(1);
        return;
    }
    if (curr->getLeft() == nullptr) {
        curr->setHeight(curr->getRight()->getHeight() + 1);
        curr->setLeavesAmount(curr->getRight()->getLeavesAmount());
    } else if (curr->getRight() == nullptr) {
        curr->setHeight(curr->getLeft()->getHeight() + 1);
        curr->setLeavesAmount(curr->getLeft()->getLeavesAmount());
    } else {
        curr->setHeight(std::max(curr->getRight()->getHeight(), curr->getLeft()->getHeight()) + 1);
        if (curr->getRight()->getHeight() == curr->getLeft()->getHeight()) {
            curr->setLeavesAmount(curr->getRight()->getLeavesAmount() + curr->getLeft()->getLeavesAmount());
        } else if (curr->getRight()->getHeight() > curr->getLeft()->getHeight()) {
            curr->setLeavesAmount(curr->getRight()->getLeavesAmount());
        } else if (curr->getRight()->getHeight() < curr->getLeft()->getHeight()) {
            curr->setLeavesAmount(curr->getLeft()->getLeavesAmount());
        }
    }
}

void Tree::deleteRoot() {
    if (root == nullptr) {
        return;
    }
    Node *curr = root;
    if (root->getLeft() == nullptr) {
        root = curr->getRight();
        delete curr;
    } else if (root->getRight() == nullptr) {
        root = curr->getLeft();
        delete curr;
    } else if (root->getRight()->getLeft() == nullptr) {
        root->getRight()->setLeft(root->getLeft());
        root = root->getRight();
        delete curr;
    } else {
        Tree::Node *newCurr = curr->getRight();
        while (newCurr->getLeft()->getLeft() != nullptr) {
            newCurr = newCurr->getLeft();
        }
        curr = newCurr->getLeft();
        newCurr->setLeft(curr->getRight());
        curr->setLeft(root->getLeft());
        curr->setRight(root->getRight());
        delete root;
        root = curr;
    }
}

Tree::Node *Tree::getRoot() const {
    return root;
}

void Tree::findLongestWaysLikeRoot(Node *curr, Tree::Node *prev) {
    if (curr == nullptr) {
        return;
    }
    if (curr->getLeft() != nullptr && curr->getRight() != nullptr) {
        curr->setLengthOfLongestWays(curr->getLeft()->getHeight() + curr->getRight()->getHeight() + 2);
        curr->setAmountOfLongestWays(curr->getLeft()->getLeavesAmount() * curr->getRight()->getLeavesAmount());
    } else if (curr->getLeft() != nullptr) {
        curr->setLengthOfLongestWays(curr->getLeft()->getHeight() + 1);
        curr->setAmountOfLongestWays(curr->getLeft()->getLeavesAmount());
    } else if (curr->getRight() != nullptr) {
        curr->setLengthOfLongestWays(curr->getRight()->getHeight() + 1);
        curr->setAmountOfLongestWays(curr->getRight()->getLeavesAmount());
    }
    if(curr->getLengthOfLongestWays() > maxWay){
        maxWay=curr->getLengthOfLongestWays();
    }
    findLongestWaysLikeRoot(curr->getLeft(), curr);
    findLongestWaysLikeRoot(curr->getRight(), curr);
}

void Tree::findWayTillFarthestNode(Tree::Node *curr) {
    if (curr->getLeft() == nullptr) {
        if (curr->getRight() == nullptr) {
            return;
        }
        curr->getRight()->setWayTillFarthestNode(curr->getWayTillFarthestNode() + 1);
        curr->getRight()->setAmountOfWaysTillFarthestNode(curr->getAmountOfWaysTillFarthestNode());
        findWayTillFarthestNode(curr->getRight());
    } else if (curr->getRight() == nullptr) {
        curr->getLeft()->setWayTillFarthestNode(curr->getWayTillFarthestNode() + 1);
        curr->getLeft()->setAmountOfWaysTillFarthestNode(curr->getAmountOfWaysTillFarthestNode());
        findWayTillFarthestNode(curr->getLeft());
    } else {
        waysIfNotNull(curr, curr->getLeft(), curr->getRight());
        waysIfNotNull(curr, curr->getRight(), curr->getLeft());
        findWayTillFarthestNode(curr->getLeft());
        findWayTillFarthestNode(curr->getRight());
    }
}

void Tree::waysIfNotNull(Tree::Node *curr, Tree::Node *son1, Tree::Node *son2) {
    if (curr->getWayTillFarthestNode() == son2->getHeight() + 1) {
        son1->setWayTillFarthestNode(curr->getWayTillFarthestNode() + 1);
        son1->setAmountOfWaysTillFarthestNode(curr->getAmountOfWaysTillFarthestNode() + son2->getLeavesAmount());
    } else if (curr->getWayTillFarthestNode() < son2->getHeight() + 1) {
        son1->setWayTillFarthestNode(son2->getHeight() + 2);
        son1->setAmountOfWaysTillFarthestNode(son2->getLeavesAmount());
    } else if (curr->getWayTillFarthestNode() > son2->getHeight() + 1) {
        son1->setWayTillFarthestNode(curr->getWayTillFarthestNode() + 1);
        son1->setAmountOfWaysTillFarthestNode(curr->getAmountOfWaysTillFarthestNode());
    }
}

int Tree::getMaxWay() const {
    return maxWay;
}

void Tree::setMaxWay(int maxWay) {
    Tree::maxWay = maxWay;
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

int Tree::Node::getHeight() const {
    return height;
}

void Tree::Node::setHeight(int depth) {
    Node::height = depth;
}

int Tree::Node::getLeavesAmount() const {
    return leavesAmount;
}

void Tree::Node::setLeavesAmount(int leavesAmount) {
    Node::leavesAmount = leavesAmount;
}

int Tree::Node::getLengthOfLongestWays() const {
    return lengthOfLongestWays;
}

void Tree::Node::setLengthOfLongestWays(int lengthOfLongestWays) {
    Node::lengthOfLongestWays = lengthOfLongestWays;
}

int Tree::Node::getWayTillFarthestNode() const {
    return wayTillFarthestNode;
}

void Tree::Node::setWayTillFarthestNode(int wayTillFarthestNode) {
    Node::wayTillFarthestNode = wayTillFarthestNode;
}

int Tree::Node::getAmountOfWaysTillFarthestNode() const {
    return amountOfWaysTillFarthestNode;
}

void Tree::Node::setAmountOfWaysTillFarthestNode(int amountOfWaysTillFarthestNode) {
    Node::amountOfWaysTillFarthestNode = amountOfWaysTillFarthestNode;
}

int Tree::Node::getAmountOfLongestWays() const {
    return amountOfLongestWays;
}

void Tree::Node::setAmountOfLongestWays(int amountOfLongestWays) {
    Node::amountOfLongestWays = amountOfLongestWays;
}