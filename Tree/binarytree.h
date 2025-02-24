#pragma once
#include <iostream>
#include "BTnode.h"

class binarytree {
private:
    BTnode* root = nullptr;
    unsigned int size = 0;
    /*
    class iterator {
        public:
            iterator(BTnode* curr) : curr(curr) {}
            iterator(const iterator& o) : curr(o.curr) {}
    
            BTnode operator*() {
                return curr->value;
            };
    
            bool operator!=(const iterator& o) const {
                return curr != o.curr;
            }
    
            iterator& operator++() {
                curr = curr->left;
                return *this;
            }
    
            iterator operator++(int) {
                iterator prevState(*this);
                curr = curr->left;
                return prevState;
            }

        private:
            BTnode* curr;
        };
    
    friend iterator begin() { return iterator(root); }
    friend iterator end() { return iterator(nullptr); }
    */
    public:
    binarytree() = default;
    ~binarytree();
    bool isEmpty() const;
    bool have_childern() const;
    void insert(int v);
    bool contains(int v) const;
    void clear();
    void remove(int v);
    unsigned int length() const;
    int depth();
    void showinfoo();
};

binarytree::~binarytree(){
    while (!isEmpty()){
        clear();
    }
}

bool binarytree::isEmpty() const {
    return size == 0;
}

bool binarytree::have_childern() const{
    return (root->BTNhave_childern());
}

void binarytree::insert(int v){
    if (root == nullptr){
        root = new BTnode(v);
        size++;
        return;
    }
    root->BTNinsert(v);
    size++;
    return;
}

bool binarytree::contains(int v) const {
    if (isEmpty()) return false;
    return root->BTNcontains(v);
}

void binarytree::clear(){
    // if (isEmpty()) return;
    root->BTNremove();
    delete root;
    size = 0;  
    root = nullptr;
}

void binarytree::remove(int v){
    return;
}

unsigned int binarytree::length() const{
    return size;
}

int depth(){
    return 100;
}

void binarytree::showinfoo(){
    BTnode* toshow = root;
    if (toshow != nullptr){
        BTnode::showinfo(toshow);
    }
    if (toshow->right != nullptr){
        BTnode::showinfo(toshow->right);
    }
    if (toshow->left != nullptr){
        BTnode::showinfo(toshow->left);
    }
    // toshow = toshow->left;
}

