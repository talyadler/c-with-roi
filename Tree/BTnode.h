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
    static void showinfo(BTnode*);
    BTnode* search(BTnode* root, int v); // returns nullptr if not found
    void insert(int v);
    void insertRight(int v);
    void insertLeft(int v);
    void clear();
    void remove(int v);
    void remove (BTnode* to_remove);
    void nodeShift(BTnode* node, BTnode* target, int v);
    bool have_childern() const;
    bool have_parent() const;
    bool contains(int v) const;
    bool isLeaf() const;
    int min() const;
    int max() const;
    BTnode* successor() const; // returns the next node (inorder) in the tree
    BTnode* predecessor() const; // returns the prev node (inorder) in the tree
    void inOrder();
    void preOrder();
    void postOrder();

    //legacy
    void insertChance(int v);
};

// defenistions

void BTnode::showinfo(BTnode* btn){
    std::cout << "SHOWINFO\tme\t\t" <<btn<<"\n";
    std::cout << "SHOWINFO\tvalue\t\t" <<btn->value<<"\n";
    std::cout << "SHOWINFO\tfather\t\t" <<btn->father<<"\n";
    std::cout << "SHOWINFO\tlevel\t\t" <<btn->level<<"\n";
    std::cout << "SHOWINFO\tleft\t\t" <<btn->left<<"\n";
    std::cout << "SHOWINFO\tright\t\t" <<btn->right<<"\n";
    std::cout << "SHOWINFO\thave parent\t" <<btn->have_parent()<<"\n";
    std::cout << "SHOWINFO\thave child\t" <<btn->have_childern()<<"\n";
    std::cout << "SHOWINFO\tis leaf\t\t" <<btn->isLeaf()<<"\n";
    std::cout << "\n";
}

BTnode* BTnode::search(BTnode* root, int v){
    // printf("start search %d\n",v);
    
    if (root->value == v) return root;
    if (root->value <= v && root->right) return search(root->right, v);
    if (root->value > v && root->left) return search(root->left, v);
    // showinfo(this);
    return nullptr;
}

void BTnode::insert(int v){
    if (v <= value){
        insertLeft(v);
        return;
    }
    if (v > value) {
        insertRight(v);
        return;
    }
}

void BTnode::insertRight(int v){
    if (right == nullptr){
        right = new BTnode(v,this,this->level+1);
        return;
    }
    right->insert(v);
}

void BTnode::insertLeft(int v){
    if (left == nullptr){
        left = new BTnode(v,this,this->level+1);
        return;
    }
    left->insert(v);
}

void BTnode::clear(){
    if (this == nullptr) return;
    if (left != nullptr) {
		left->clear();
		delete left;
		left = nullptr;
	}
    if (right != nullptr) {
		right->clear();
		delete right;
		right = nullptr;
	}
}

void BTnode::remove(int v){
    if (value == v){
        remove(this);
        return;
    }
    if (left) left->remove(v);
    if (right) right->remove(v);
}

void BTnode::remove (BTnode* to_remove){
    if (to_remove == nullptr) return;
    // case 1 - is a leaf
    if (to_remove->isLeaf()){
        // check for root
        if (!to_remove->have_parent()){
            delete to_remove;
            return;
        }
        //is left leaf of father
        if(to_remove->father->left == to_remove){
            to_remove->father->left = nullptr;
            delete to_remove;
            return;
        }
        //is right leaf of father
        if(to_remove->father->right == to_remove){
            to_remove->father->right = nullptr;
            delete to_remove;
            return;
        }
    } // from here on, to_remove is not a leaf, therefore has at least 1 child

    // case 2 - to_remove have one child
    if (to_remove->right == nullptr || to_remove->left == nullptr){
        // we'll replace to_remove->father pointer with to_remove's only child
        // variable = (condition) ? expressionTrue : expressionFalse;
        BTnode* only_child = to_remove->right != nullptr ? to_remove->right : to_remove->left;
        if (to_remove->father->right == to_remove) {
                to_remove->father->right = only_child;
        }
        else {
            to_remove->father->left = only_child;
        }
        only_child->father = to_remove->father;
        delete to_remove;
        return;
    }

    // case 3 - two childs
    BTnode* successor = to_remove->successor();
    to_remove->value = successor->value;
    remove(successor);
}

void BTnode::nodeShift(BTnode* node, BTnode* target, int v){
    if (target->father == nullptr) node->value = v;
    if (target == target->father->left) target->father->left->value = v;
    if (target == target->father->right) target->father->right->value = v;
    return;
}

bool BTnode::have_childern() const{
    return (left != nullptr || right != nullptr);
}

bool BTnode::have_parent() const{
    return (father != nullptr);
}

bool BTnode::contains(int v) const {
    if (value == v) return true;
    return left->contains(v) || right->contains(v);
}

bool BTnode::isLeaf() const{
	return left == nullptr && right == nullptr;
}

int BTnode::min() const{
    if (left == nullptr) return value;
    return left->min();
}

int BTnode::max() const{
    if (right == nullptr) return value;
    return right->max();
}

BTnode* BTnode::successor() const{
    if (left == nullptr) return const_cast<BTnode*>(this);
    return left->successor();
}

BTnode* BTnode::predecessor() const{
    if (right == nullptr) return const_cast<BTnode*>(this);
    return right->predecessor();
}

void BTnode::inOrder(){
    if (left) left->inOrder();
    printf("%d\n",value);
    if (right) right->inOrder();
}

void BTnode::preOrder(){
    printf("%d\n",value);
    if (left) left->preOrder();
    if (right) right->preOrder();
}

void BTnode::postOrder(){
    if (left) left->postOrder();
    if (right) right->postOrder();
    printf("%d\n",value);
}


//legacy
void BTnode::insertChance(int v){
    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd()); // Use Mersenne Twister engine with the seed
    std::uniform_real_distribution<> dis(0.0, 1.0); // Define the distribution range
    double random_number = dis(gen); // Generate a random number
    // double random_number = 0.1;
    if (random_number<0.5){
        if (right==nullptr){
            right = new BTnode(v,this,this->level+1);
            showinfo(right);
            return;
        }
        right->insertChance(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this,this->level+1);
        showinfo(left);
        return;
    }
    left->insertChance(v);
}

