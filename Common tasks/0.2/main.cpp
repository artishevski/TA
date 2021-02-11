#include <iostream>
#include "Tree.h"

int main() {
    Tree *tree = new Tree("input.txt");
    Tree::Node *curr, *prev;
    tree->findNode(curr, prev);
    tree->deleteNode(curr, prev);
    tree->solution("output.txt");

    return 0;
}
