#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

class BTnode{
private:
    
public:
    BTnode() = default;
    BTnode(int v) : value(v){}
    BTnode(int v, BTnode* father) : value(v), father(father){}
    ~BTnode() = default;
    BTnode* father = nullptr;
    BTnode* left = nullptr;
    BTnode* right = nullptr;
    int value;
    static void showinfo(BTnode*);
    void BTNinsertChance(int v);
    void BTNinsert(int v);
    void BTNinsertRight(int v);
    void BTNinsertLeft(int v);
    void BTNremove();
    void BTNremove(int v);
    bool BTNhave_childern() const;
    bool BTNhave_parent() const;
    bool BTNcontains(int v) const;
    BTnode* search(BTnode* root, int v);
	bool isLeaf();
};

bool BTnode::isLeaf() {
	return left == nullptr && right == nullptr;
}

void BTnode::showinfo(BTnode* btn){
    std::cout << "SHOWINFO\t\t\tinfo\tme=" <<btn<<"\n";
    std::cout << "SHOWINFO\t\t\tinfo\tvalue=" <<btn->value<<"\n";
    std::cout << "SHOWINFO\t\t\tinfo\tfather=" <<btn->father<<"\n";
    std::cout << "SHOWINFO\t\t\tinfo\tleft=" <<btn->left<<"\n";
    std::cout << "SHOWINFO\t\t\tinfo\tright=" <<btn->right<<"\n\n";
}

void BTnode::BTNinsertChance(int v){
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Use Mersenne Twister engine with the seed
    std::uniform_real_distribution<> dis(0.0, 1.0); // Define the distribution range
    double random_number = dis(gen); // Generate a random number
    // double random_number = 0.1;
    if (random_number<0.5){
        if (right==nullptr){
            right = new BTnode(v,this);
            showinfo(right);
            return;
        }
        right->BTNinsertChance(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this);
        showinfo(left);
        return;
    }
    left->BTNinsertChance(v);
}

BTnode* BTnode::search(BTnode* root, int v){
    // if (BTNhave_parent()) return root;
    if (value == v) return root;
    if (value <= v) return search(left, v);
    if (value > v) return search(right, v);
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
        right = new BTnode(v,this);
        right->father = this;
        // showinfo(search(right,v));
        return;
    }
    right->BTNinsert(v);
}

void BTnode::BTNinsertLeft(int v){
    if (left == nullptr){
        left = new BTnode(v,this);
        // showinfo(search(left,v));
        return;
    }
    left->BTNinsert(v);
}

void BTnode::BTNremove(){
    if (left != nullptr) {
		left->BTNremove();
		delete left;
		left = nullptr;
	}
    if (right != nullptr) {
		right->BTNremove();
		delete right;
		right = nullptr;
	}
}

void BTnode::BTNremove(int v){
    if (BTNcontains(v)){
        BTnode* to_remove;
        delete to_remove;
    }
}

bool BTnode::BTNhave_childern() const{
    return (this->left != nullptr || this->right != nullptr);
}

bool BTnode::BTNhave_parent() const{
    return father;
}

bool BTnode::BTNcontains(int v) const {
    if (value == v) return true;
    return left->BTNcontains(v) || right->BTNcontains(v);
}

