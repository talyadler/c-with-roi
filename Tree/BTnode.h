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
    BTnode(int v, BTnode* father) : value(v), father(father){}
    // BTnode(int v, unsigned int height) : value(v), height(height){}
    // BTnode(int v, BTnode* father, unsigned int height) : value(v), father(father), height(height){}
    
    //destructors
    ~BTnode() = default;
    
    //fields
    BTnode* father = nullptr;
    BTnode* left = nullptr;
    BTnode* right = nullptr;
    int value;
    unsigned int height = 0;
    
    //methods
    void showinfo();
    BTnode* search(int v, unsigned int place = 1) const; // if not given 2 parameter place gets `1` as its value
    unsigned int duplicates() const;
    void insert(int v);
    void clear();
    void remove(int v, unsigned int place = 1);
    void remove (BTnode* to_remove, unsigned int place = 1);
    int AVLbalance();
    void nodeShift();
    void shiftRight();
    void shiftLeft();
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
    int getHeight(BTnode* node);

    //legacy
    void insertChance(int v);
};

// defenistions

void BTnode::showinfo(){
    if (this == nullptr) return;
    std::cout << "SHOWINFO\tnode\t\t" << this << "\n";
    std::cout << "SHOWINFO\tvalue\t\t" << value << "\n";
    std::cout << "SHOWINFO\tfather\t\t" << father << "\n";
    std::cout << "SHOWINFO\theight\t\t" << height << "\n";
    std::cout << "SHOWINFO\tleft\t\t" << left << "\n";
    std::cout << "SHOWINFO\tright\t\t" << right <<"\n";
    std::cout << "SHOWINFO\thave parent\t" << have_parent() << "\n";
    std::cout << "SHOWINFO\thave child\t" << have_childern() << "\n";
    std::cout << "SHOWINFO\tis leaf\t\t" << isLeaf() << "\n";
    std::cout << "\n";
}

BTnode* BTnode::search(int v, unsigned int place) const{
    if (v == value){
        BTnode* toReturn = nullptr;
        //found maching value
        if (!left) return const_cast<BTnode*>(this);
        // no more left nodes ie no more of this value
        // lets try to find if there are more nodes with this value
        unsigned int counter = 0;
        // printf("test\n");
        for (BTnode* temp = const_cast<BTnode*>(this) ; temp != nullptr && temp->value == v; temp = temp->left) {
            counter++;
            if (counter == place) {
                toReturn = temp;
            }
        }
        if (counter > 1) printf("there are %d matches for this value. \t showing accurence %d\n",counter, place);
        return toReturn;
    }
    if (v < value && left) return left->search(v,place);
    if (v > value && right) return right->search(v,place);
    return nullptr;
}

unsigned int BTnode::duplicates() const{
    unsigned int counter = 0;
    for (BTnode* temp = const_cast<BTnode*>(this) ; temp != nullptr && temp->value == value; temp = temp->left) {
        counter++;
    }
    return counter;
}

void BTnode::insert(int v){
    // add new node
    if (v <= value){
        if (left == nullptr) left = new BTnode(v,this);
        else left->insert(v);
    }
    if (v > value) {
        if (right == nullptr)right = new BTnode(v,this);
        else right->insert(v);
    }

    // validate creating node height
    int h_left = getHeight(left);
    int h_right = getHeight(right);
    this->height = 1 + std::max(h_left,h_right);

    // balance tree
    if (std::abs(h_left - h_right) > 1){
        nodeShift();
    }
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

void BTnode::remove(int v, unsigned int place){
    if (value == v){
        remove(this,place);
        return;
    }
    if (left) left->remove(v,place);
    if (right) right->remove(v,place);
}

void BTnode::remove (BTnode* to_remove, unsigned int place){
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

int BTnode::AVLbalance(){
    if (this == nullptr) return 0;
    return getHeight(left) - getHeight(right);
}

void BTnode::nodeShift(){
    printf("nodeshift\n");
    printf("AVLbalance %d\n", AVLbalance());
    // LL
    if (AVLbalance() > 1 && left->AVLbalance() >= 0){
        printf("nodeshift LL\n");
        return shiftRight();
    }
    
    // LR
    if (AVLbalance() > 1 && left->AVLbalance() < 0){
        printf("nodeshift LR\n");
        left->left->shiftLeft();
        return left->shiftRight();
    }
    
    // RR
    if (AVLbalance() < -1 && right->AVLbalance() <= 0){
        printf("nodeshift RR\n");
        return shiftLeft();
    }

    // RL
    if (AVLbalance() < -1 && right->AVLbalance() < 0){
        printf("nodeshift RL\n");
        right->right->shiftRight();
        return shiftLeft();
    }
}

void BTnode::shiftRight(){
    BTnode* y = this;
    if (y == nullptr) return;
    // y is the node to be shifted
    // x will be the left node of this shifting node
    BTnode* x = y->left;
    //keep y->left->right in temp for later use
    BTnode* temp = x->right;
    // y->left->right point to y
    x->right = y;
    // y->left will point to y->right;
    y->left = temp;
    // set new hights
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    printf("shiftRight Done\n");
    // return x;
}

void BTnode::shiftLeft(){
    BTnode* x = this;
    if (x == nullptr) return;
    BTnode* y = x->right;
    BTnode* temp = y->left;
    y->left = x;
    x->right = temp;
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    printf("shiftLeft Done\n");
    // return y;
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
    return right == nullptr ? value : right->max();
}

BTnode* BTnode::successor() const {
    if (!right) return nullptr;
    BTnode* successor;
    for (successor = right; successor->left != nullptr; successor = successor->left) continue;
    return successor;
}

BTnode* BTnode::predecessor() const{
    if (!left) return nullptr;
    BTnode* predecessor;
    for (predecessor = left; predecessor->right != nullptr; predecessor = predecessor->right) continue;
    return predecessor;
}

void BTnode::inOrder(){
    if (left) left->inOrder();
    printf("%d, ",value);
    if (right) right->inOrder();
}

void BTnode::preOrder(){
    printf("%d, ",value);
    if (left) left->preOrder();
    if (right) right->preOrder();
}

void BTnode::postOrder(){
    if (left) left->postOrder();
    if (right) right->postOrder();
    printf("%d, ",value);
}

int BTnode::getHeight(BTnode* node){
    return node == nullptr ? -1 : node->height;
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
            right = new BTnode(v,this);
            right->showinfo();
            return;
        }
        right->insertChance(v);
        return;
    }
    if (left == nullptr){
        left = new BTnode(v,this);
        left->showinfo();
        return;
    }
    left->insertChance(v);

    // validate creating node height
    this->height = 1 + std::max(getHeight(left),getHeight(right));
}

