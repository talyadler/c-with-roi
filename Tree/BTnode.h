#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class BTnode{
private:
    
public:
    //construtors
    BTnode() = default;
    BTnode(int v) : value(v){}
    BTnode(int v, BTnode* father, unsigned int level) : value(v), father(father), level(level){}
    
    //destructors
    ~BTnode() = default;
    
    //fields
    BTnode* father = nullptr;
    BTnode* left = nullptr;
    BTnode* right = nullptr;
    int value;
    unsigned int level;
    
    //methods
    static void BTNshowinfo(BTnode*);
    BTnode* BTNsearch(BTnode* root, int v);
    void BTNinsert(int v);
    void BTNinsertRight(int v);
    void BTNinsertLeft(int v);
    void BTNclear();
    void BTNremove(int v);
    bool BTNhave_childern() const;
    bool BTNhave_parent() const;
    bool BTNcontains(int v) const;
	bool BTNisLeaf();

    //legacy
    void BTNinsertChance(int v);
};

// defenistions

void BTnode::BTNshowinfo(BTnode* btn){
    std::cout << "SHOWINFO\tme\t\t" <<btn<<"\n";
    std::cout << "SHOWINFO\tvalue\t\t" <<btn->value<<"\n";
    std::cout << "SHOWINFO\tfather\t\t" <<btn->father<<"\n";
    std::cout << "SHOWINFO\tlevel\t\t" <<btn->level<<"\n";
    std::cout << "SHOWINFO\tleft\t\t" <<btn->left<<"\n";
    std::cout << "SHOWINFO\tright\t\t" <<btn->right<<"\n";
    std::cout << "SHOWINFO\thave parent\t" <<btn->BTNhave_parent()<<"\n";
    std::cout << "SHOWINFO\thave child\t" <<btn->BTNhave_childern()<<"\n";
    std::cout << "SHOWINFO\tis leaf\t\t" <<btn->BTNisLeaf()<<"\n";
    std::cout << "\n";
}

BTnode* BTnode::BTNsearch(BTnode* root, int v){
    if (root->value == v) return root;
    if (root->value <= v) return BTNsearch(root->left, v);
    if (root->value > v) return BTNsearch(root->right, v);
    return NULL;
}

void BTnode::BTNinsert(int v){  
    if (value <= v){
        BTNinsertLeft(v);
        return;
    }
    if (value > v) {
        BTNinsertRight(v);
        return;
    }
}

void BTnode::BTNinsertRight(int v){
    if (right == nullptr){
        right = new BTnode(v,this,this->level+1);
        return;
    }
    right->BTNinsert(v);
}

void BTnode::BTNinsertLeft(int v){
    if (left == nullptr){
        left = new BTnode(v,this,this->level+1);
        return;
    }
    left->BTNinsert(v);
}

void BTnode::BTNclear(){
    if (this == nullptr) return;
    if (left != nullptr) {
		left->BTNclear();
		delete left;
		left = nullptr;
	}
    if (right != nullptr) {
		right->BTNclear();
		delete right;
		right = nullptr;
	}
}

void BTnode::BTNremove(int v){
    if (!BTNcontains(v))return;
    BTnode* to_remove = BTNsearch(this,v);
    //case 1, only 1 item on the. node is root without children.
    if (!to_remove->BTNhave_parent() && !to_remove->BTNhave_childern()){
        delete to_remove;
        return;
    }
    // case 2, this node is a leaf on the tree.
    if (to_remove->BTNisLeaf()){
        //is left child of father
        if(to_remove->father->left == to_remove){
            delete to_remove;
            to_remove->father->left = nullptr;        
        }
        //is right child of father
        if(to_remove->father->right == to_remove){
            delete to_remove;
            to_remove->father->right = nullptr;
        }
        return;
    }
    //case 3, is a child and a parent
    if (to_remove->BTNhave_parent() && to_remove->BTNhave_childern()){
        return;
    }
}

bool BTnode::BTNhave_childern() const{
    return (left != nullptr || right != nullptr);
}

bool BTnode::BTNhave_parent() const{
    return (father != nullptr);
}

bool BTnode::BTNcontains(int v) const {
    if (this == nullptr) return false;
    if (value == v) return true;
    return left->BTNcontains(v) || right->BTNcontains(v);
}

bool BTnode::BTNisLeaf() {
	return left == nullptr && right == nullptr;
}

void BTnode::BTNinsertChance(int v){
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Use Mersenne Twister engine with the seed
    std::uniform_real_distribution<> dis(0.0, 1.0); // Define the distribution range
    double random_number = dis(gen); // Generate a random number
    // double random_number = 0.1;
    if (random_number<0.5){
        if (right==nullptr){
            right = new BTnode(v,this,this->level+1);
            BTNshowinfo(right);
            return;
        }
        right->BTNinsertChance(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this,this->level+1);
        BTNshowinfo(left);
        return;
    }
    left->BTNinsertChance(v);
}
