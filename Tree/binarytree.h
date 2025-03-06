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
    void remove(int v, unsigned int place = 1);
    unsigned int length() const;
    unsigned int depth() const;
    void showinfo(int v, unsigned int place = 1) const;
    void OrderShowInfo(int v) const;
    int max() const;
    int min() const;
    void search(int v, unsigned int place = 1) const;
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
        root = new BTnode(v);
        size++;
        deep = 1;
        return;
    }
    root->insert(v);
    size++;
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

void binarytree::remove(int v, unsigned int place){
    if (isEmpty()) return;
    if (!root->search(v,place))return;
    root->remove(v);
    size--;
    
    //validate depth
    //get lowest hights from children
    unsigned int lowest_min_hight = root->search(root->min(),place)->height;
    unsigned int lowest_max_hight = root->search(root->max(),place)->height;
    unsigned int lowest_hight = 0;
    lowest_hight = lowest_max_hight > lowest_min_hight ? lowest_max_hight : lowest_min_hight;
    
    //update deepth
    if (deep < lowest_hight) deep = lowest_hight;
}

unsigned int binarytree::length() const{
    return size;
}

unsigned int binarytree::depth() const{
    return deep;
}

void binarytree::showinfo(int v, unsigned int place) const{
    if (root->search(v,place) != nullptr){
        root->search(v,place)->showinfo();
    }
}

void binarytree::OrderShowInfo(int v) const{
    switch (v){
        case 1:
            root->inOrder();
            printf("\n");
            break;
        case 2:
            root->preOrder();
            printf("\n");
            break;
        case 3:
            root->postOrder();
            printf("\n");
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

void binarytree::search(int v, unsigned int place) const{
    BTnode* to_find = root->search(v,place);
    if (to_find) to_find->showinfo();
    else printf("search found no match for this duplicate: %d\n", place);
}
