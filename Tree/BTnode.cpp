#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class BTnode{
private:
    
public:
    BTnode() = default;
    BTnode(int v) : value(v){}
    BTnode(int v, BTnode* father) : value(v), father(father){}
    ~BTnode() = default;
    BTnode* father;
    BTnode* left = nullptr;
    BTnode* right = nullptr;
    int value;
    void insert(int v);
    void remove();
    void remove(int v);
    bool contains(int v) const;
};

void BTnode::insert(int v){
    srand(time(0));
    if ((rand() % 100)<50){
        if (right==nullptr){
            right = new BTnode(v,this);
            return;
        }
        right->insert(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this);
        return;
    }
    left->insert(v);
}

void BTnode::remove(){
    return;
}

void BTnode::remove(int v){
    return;
}

bool BTnode::contains(int v) const {
    if (value == v) return true;
    return left->contains(v) || right->contains(v);

}