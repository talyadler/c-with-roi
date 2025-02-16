#include <iostream>
#include "BTnode.cpp"

class binarytree {
private:
        class BTnode{
    private:
        /* data */
    public:
        BTnode(/* args */);
        ~BTnode();
        BTnode* father;
        BTnode* left;
        BTnode* right;
        int value;
        void insert(int v);
        void remove(int v);
        void contains(int v);
    };
public:
    binarytree(/* args */);
    ~binarytree();
    BTnode* root;
};

binarytree::binarytree(/* args */)
{
}

binarytree::~binarytree()
{
}
