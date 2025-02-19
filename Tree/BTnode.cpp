#pragma once
#include <iostream>
#include <cstdlib>

class BTnode{
private:
    
public:
    BTnode(/* args */);
    ~BTnode();
    BTnode* father;
    BTnode* left;
    BTnode* right;
    int value;
    void insert(int v);
    void remove(int v);
    void contains(int v);
};

BTnode::BTnode(/* args */){
}

BTnode::~BTnode(){
}

void insert(int v){

}

void remove(int v){

}

void contains(int v){

}