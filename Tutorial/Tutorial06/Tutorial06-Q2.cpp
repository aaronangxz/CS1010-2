#include <iostream>

using namespace std;

struct BSTNode {
    int item;
    BSTNode *left, *right, *parent;
};

struct Set {
    BSTNode *root = NULL;
};

void remove_node(BSTNode &node)
{
    //case 1
    if(node.left == NULL && node.right == NULL && node.parent) 
    {
        if(node == node.parent->left) node.parent->left = NULL;
        else node.parent->right = NULL;
        delete &node;
    }
    //cse 2
    else if(node.right == NULL)
    {
        node.left->parent = node.parent;
        if(node.parent)
            if(node == node.parent->left)
                node.parent->left = node.left;
            else node.parent->right = node.left;
        delete &node;
    }    
    //case 3
    else{
        //find left most descendent
        BSTNode *replace = node.right;
        while(replace->right)
        replace = replace->left;

        //found left most descendent
        node.item = replace->item;
        replace->parent->left = replace->right;
        if (replace->right)
            replace->right->parent = replace->parent;
        delete replace;

    }
}

