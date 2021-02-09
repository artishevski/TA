#include <iostream>
#include "Tree.h"

int main() {
    Tree* tree = new Tree("input.txt");
    tree -> solution("output.txt");
    return 0;
}
