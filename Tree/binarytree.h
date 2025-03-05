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
    unsigned int depth() const;
    void showinfo(int v) const;
    void OrderShowInfo(int v) const;
    int max() const;
    int min() const;
    void search(int v) const;
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
    return (root->have_childern());
}

bool binarytree::have_parent() const{
    return root->have_parent();
}

void binarytree::insert(int v){
    if (root == nullptr){
        root = new BTnode(v, 1);
        size++;
        deep = 1;
        return;
    }
    root->insert(v);
    size++;
    // unsigned int insert_level = root->search(v)->level;
    // deep = deep < insert_level ? insert_level : deep;
    return;
}

bool binarytree::contains(int v) const {
    if (isEmpty()) return false;
    return root->contains(v);
}

void binarytree::clear(){
    if (isEmpty()) return;
    root->clear();
    delete root;
    size = 0; 
    deep = 0; 
    root = nullptr;
}

void binarytree::remove(int v){
    if (isEmpty()) return;
    if (!root->search(v))return;
    root->remove(v);
    size--;
    
    //validate depth
    //get lowest levels from children
    unsigned int lowest_min_level = root->search(root->min())->level;
    unsigned int lowest_max_level = root->search(root->max())->level;
    unsigned int lowest_level = 0;
    lowest_level = lowest_max_level > lowest_min_level ? lowest_max_level : lowest_min_level;
    
    //update deepth
    if (deep < lowest_level) deep = lowest_level;
}

unsigned int binarytree::length() const{
    return size;
}

unsigned int binarytree::depth() const{
    return deep;
}

void binarytree::showinfo(int v) const{
    if (root->search(v) != nullptr){
        root->search(v)->showinfo();
    }
}

void binarytree::OrderShowInfo(int v) const{
    switch (v){
        case 1:
            root->inOrder();
            break;
        case 2:
            root->preOrder();
            break;
        case 3:
            root->postOrder();
            break;
        default:
            printf("for OrderShowInfo choose 1, 2 or 3\n");
    }
}

int binarytree::max() const{
    return root->max();
}

int binarytree::min() const{
    return root->min();
}

void binarytree::search(int v) const{
    BTnode* to_find = root->search(v);
    if (to_find) to_find->showinfo();
    else printf("bye");
}
