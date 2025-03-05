#pragma once
#include "node.h"

class BinaryTree {
  private:
    Node *root = nullptr;

  public:
    BinaryTree() {}

    void insert(int v) {
        if (root == nullptr)
            root = new Node(v);
        else
            root->insert(v);
    }

    // @returns A srting containing dot code that compiles a graph of the tree
    std::string toDot() {
        std::string graphString = "digraph BinaryTree {\nnode [shape=circle]; \n";
        if (root != nullptr) root->toDot(graphString);
        graphString += "}\n";
        return graphString;
    }
};
