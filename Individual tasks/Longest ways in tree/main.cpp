#include "Tree.h"

int main() {
    Tree *tree = new Tree("input.txt");
    tree->deleteRoot();
    tree->setAllHeights(tree->getRoot());
    tree->findLongestWaysLikeRoot(tree->getRoot());
    tree->findWayTillFarthestNode(tree->getRoot());
    tree->solution("output.txt");
    return 0;
}