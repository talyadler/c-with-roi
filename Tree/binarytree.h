#pragma once
#include <iostream>
#include "BTnode.h"

class binarytree {
private:
    //fields
    BTnode* root = nullptr;
    unsigned int size = 0;
    unsigned int deep = 0;
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
    //constructors
    binarytree() = default;
    
    //destructors
    ~binarytree();
    
    //methods
    bool isEmpty() const;
    bool have_childern() const;
    bool have_parent() const;
    void insert(int v);
    bool contains(int v) const;
    void clear();
    void remove(int v);
    unsigned int length() const;
    unsigned int depth();
    void showinfo(int v) const;
    int max() const;
    int min() const;
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

bool binarytree::have_parent() const{
    return root->BTNhave_parent();
}

void binarytree::insert(int v){
    if (root == nullptr){
        root = new BTnode(v, 1);
        size++;
        deep = 1;
        return;
    }
    root->BTNinsert(v);
    size++;
    if (deep < root->BTNsearch(root,v)->level) deep = root->BTNsearch(root,v)->level;
    return;
}

bool binarytree::contains(int v) const {
    if (isEmpty()) return false;
    return root->BTNcontains(v);
}

void binarytree::clear(){
    if (isEmpty()) return;
    root->BTNclear();
    delete root;
    size = 0; 
    deep = 0; 
    root = nullptr;
}

void binarytree::remove(int v){
    if (isEmpty()) return;
    
    if (size == 1){
        delete root;
        root = nullptr;
        size = 0;
        deep = 0;
        return;
    }
    
    root->BTNremove(v);
    size--;

    //validate depth
    //PROBABLY WRONG
    /*
    //get lowest levels from children
    unsigned int lowest_min_level = root->BTNsearch(root,root->BTNmin())->level;
    unsigned int lowest_max_level = root->BTNsearch(root,root->BTNmax())->level;
    unsigned int lowest_level = 0;
    if (lowest_max_level > lowest_min_level)lowest_level = lowest_max_level;
    else lowest_level = lowest_min_level;
    //update deepth
    if (deep < lowest_level)deep = lowest_level;
    */
}

unsigned int binarytree::length() const{
    return size;
}

unsigned int binarytree::depth(){
    return deep;
}

void binarytree::showinfo(int v) const{
    BTnode* toshow = root;
    if (toshow != nullptr){
        BTnode::BTNshowinfo(toshow->BTNsearch(toshow,v));
    }
}

int binarytree:: max() const{
    return root->BTNmax();
}

int binarytree:: min() const{
    return root->BTNmin();
}