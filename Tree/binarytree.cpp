#include <iostream>
#include "BTnode.cpp"

class binarytree {
private:
    BTnode* root;
    int size;
    class iterator{
    public:
        iterator(){}
        BTnode operator*(){};
        bool operator!=(){};
    private:
    };
public:
    binarytree();
    ~binarytree();
    bool isEmpty();
    void insert(int v);
    bool containsbt(int v);
    void remove(int v);
    int size();
    int depth();
};

binarytree::binarytree(){
}

binarytree::~binarytree(){
}

bool isEmpty(){
}

void insert(int v){

}

bool containsbt(int v){

}

void remove(int v){

}

int size(){
    return size;
}

int depth(){

}