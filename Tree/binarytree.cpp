#pragma once
#include <iostream>
#include "BTnode.cpp"

class binarytree {
private:
    BTnode* root = nullptr;
    unsigned int size = 0;
    
    // class iterator{
    // public:
    //     iterator(){}
    //     binarytree operator*(){};
    // private:
    // };
    public:
    binarytree() = default;
    ~binarytree();
    bool isEmpty();
    void insert(int v);
    bool contains(int v) const;
    void remove();
    void remove(int v);
    unsigned int length() const;
    int depth();
};

binarytree::~binarytree(){
    while (!isEmpty()){
        remove();
    }
}

bool binarytree::isEmpty(){
    return size == 0;
}

void binarytree::insert(int v){
    if (isEmpty()){
        root = new BTnode(v);
        return;
    }
    this->insert(v);
    return;
}

bool binarytree::contains(int v) const {

}

void binarytree::remove(){
 return;
}

void binarytree::remove(int v){

}

unsigned int binarytree::length() const{
    return size;
}

int depth(){

}