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
    void showinfo(BTnode*);
    void BTNinsert(int v);
    void BTNremove();
    void BTNremove(int v);
    bool BTNhave_childern() const;
    bool BTNcontains(int v) const;
};

void BTnode::showinfo(BTnode*){
    std::cout << "info\tme=" <<this<<"\n";
    std::cout << "info\tvalue=" <<value<<"\n";
    std::cout << "info\tfather=" <<father<<"\n";
    std::cout << "info\tleft=" <<left<<"\n";
    std::cout << "info\tright=" <<right<<"\n\n";
}

void BTnode::BTNinsert(int v){
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
        right->BTNinsert(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this);
        showinfo(left);
        return;
    }
    left->BTNinsert(v);
}

void BTnode::BTNremove(){
    if (left == nullptr) delete this;
    else left->BTNremove();
    if (right == nullptr) delete this;
    right->BTNremove();
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

bool BTnode::BTNcontains(int v) const {
    printf("value to check %d", v);
    if (value == v) return true;
    return left->BTNcontains(v) || right->BTNcontains(v);
}