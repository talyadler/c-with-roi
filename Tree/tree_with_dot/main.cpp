#include "tree.h"
#include <iostream>

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    std::string treeGraph = tree.toDot();
    std::cout << treeGraph << std::endl;
}
