#pragma once
#include <string>

class Node {
private:
    int value;
    Node* father = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    Node(int v) : value(v) {}
    Node(int v, Node* father) : value(v), father(father) {}

    void insert(int v) {
        if (v <= value) { //insert left
            if (left == nullptr) left = new Node(v, this);
            else left->insert(v);
        } else { // insert right
            if (right == nullptr) right = new Node(v, this);
            else right->insert(v);
        }
    }

    /** 
     * @brief Adds to `graphString` the relationship of subtree starting at `this`.
     * @returns node-string of `this`.
     */
    std::string toDot(std::string& graphString) {
        static unsigned int nodeID = 0;
        std::string nameOfThis = std::string("node") + std::to_string(nodeID++);
        graphString += nameOfThis + " [label=\"" + std::to_string(value) + "\"];\n";

        // add relationship with left
        std::string nameOfLeft;
        if (left == nullptr) {
            nameOfLeft = std::string("node") + std::to_string(nodeID++);
            graphString += nameOfLeft + " [label=\"N\"];\n";
        } else {
            nameOfLeft = left->toDot(graphString);
        }
        graphString += nameOfThis + " -> " + nameOfLeft + "\n";

        // add relationship with right
        std::string nameOfRight;
        if (right == nullptr) {
            nameOfRight = std::string("node") + std::to_string(nodeID++);
            graphString += nameOfRight + " [label=\"N\"];\n";
        } else {
            nameOfRight = right->toDot(graphString);
        }
        graphString += nameOfThis + " -> " + nameOfRight + "\n";


        return nameOfThis;
    }
};
