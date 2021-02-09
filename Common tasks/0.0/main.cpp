#include <iostream>
#include <fstream>
#include "Tree.h"

int main() {
    std::ofstream out("output.txt");
    Tree* tree = new Tree("input.txt");
    out<<tree->count();
    out.close();
    return 0;
}
