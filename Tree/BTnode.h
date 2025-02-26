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
    BTnode(int v, unsigned int level) : value(v), level(level){}
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
    BTnode* BTNsearch(BTnode* root, int v); // returns nullptr if not found
    void BTNinsert(int v);
    void BTNinsertRight(int v);
    void BTNinsertLeft(int v);
    void BTNclear();
    void BTNremove(int v);
    void BTNnodeShift(BTnode* node, BTnode* target, int v);
    bool BTNhave_childern() const;
    bool BTNhave_parent() const;
    bool BTNcontains(int v) const;
    bool BTNisLeaf() const;
    int BTNmin() const;
    int BTNmax() const;
    BTnode* successor() const; // returns the next node (inorder) in the tree
    BTnode* predecessor() const; // returns the prev node (inorder) in the tree

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
    if (root->value <= v) return BTNsearch(root->right, v);
    if (root->value > v) return BTNsearch(root->left, v);
    return NULL;
}

void BTnode::BTNinsert(int v){
    if (v <= value){
        BTNinsertLeft(v);
        return;
    }
    if (v > value) {
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
    BTnode* to_remove = BTNsearch(this,v);
    if (to_remove == nullptr) return;
    
    // case 1 - is a leaf
    if (to_remove->BTNisLeaf() && to_remove->BTNhave_parent()){ // root is removed at BT level, so every to_remove will have a parent
        //is left leaf of father
        if(to_remove->father->left == to_remove){
            to_remove->father->left = nullptr;
            delete to_remove;
        }
        //is right leaf of father
        if(to_remove->father->right == to_remove){
            to_remove->father->right = nullptr;
            delete to_remove;
        }
        return;
    }
    // from here on, to_remove is not a leaf, therefore has at least 1 child

    //case 2 - to_remove have one child
    if (to_remove->right == nullptr || to_remove->left == nullptr) 
    {
        // we'll replace to_remove->father pointer with to_remove's only child
	BTnode* only_child = to_remove->right != nullptr ? to_remove->right : to_remove->left;
	if (to_remove->father->right == to_remove) {
       	    to_remove->father->right = only_child;
	} else {
	    to_remove->father->left = only_child;
	}
	only_child->father = to_remove->father;
        delete to_remove;
        return;
    }

    //case 3 - two childs
    // replacing to_remove with its successor 
    BTnode* successor = BTNsearch(to_remove, to_remove->right->BTNmin()); // TODO: replace with `to_remove->successor()`
    // this works only if there are no repeated values, TODO: fix with a remove(BTnode*) method
    int min = successor->value;
    BTNremove(min);
    to_remove->value = min;
    return;
}

void BTnode::BTNnodeShift(BTnode* node, BTnode* target, int v){
    if (target->father == nullptr) node->value = v;
    if (target == target->father->left) target->father->left->value = v;
    if (target == target->father->right) target->father->right->value = v;
    return;
}

bool BTnode::BTNhave_childern() const{
    return (left != nullptr || right != nullptr);
}

bool BTnode::BTNhave_parent() const{
    return (father != nullptr);
}

bool BTnode::BTNcontains(int v) const {
    if (value == v) return true;
    return left->BTNcontains(v) || right->BTNcontains(v);
}

bool BTnode::BTNisLeaf() const{
	return left == nullptr && right == nullptr;
}

int BTnode::BTNmin() const{
    if (left == nullptr) return value;
    return left->BTNmin();
}

int BTnode::BTNmax() const{
    if (right == nullptr) return value;
    return right->BTNmax();
}

//legacy
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

