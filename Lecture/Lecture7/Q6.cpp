#include <iostream>

using namespace std;

template <typename T>
struct BSTNode {
    T item;
    BSTNode<T> *left, *right;
};

template <typename T>
bool valid_BST(BSTNode<T> &root) 
{
    if (root == NULL) return true;
    if(root.left != NULL && root.left->item <= root.item) return 0;
    if(root.right != NULL && root.right->item >= root.item) return 0;
    
    return valid_BST(root.left) and valid_BST(root.right);
    // your code here
    
}

template <typename T>
bool valid_BST(BSTNode<T> &root) 
{
    static BSTNode<T> &prev = NULL;
     
    // traverse the tree in inorder fashion
    // and keep track of prev node
    if (root)
    {
        if (!valid_BST(root.left)))
        return false;
 
        // Allows only distinct valued nodes
        if (prev != NULL &&
            root.item <= prev.item)
        return false;
 
        prev = root;
 
        return valid_BST(root.right);
    }
 
    return true;
}

template <typename T>
bool valid_BST_util(BSTNode<T> &root, BSTNode<T> &prev) 
{
    // traverse the tree in inorder fashion and 
    // keep track of prev node
    if (root)
    {
        if (!valid_BST_util(root.left, prev))
          return false;
    
        // Allows only distinct valued nodes 
        if (prev != NULL && root.item <= prev.item)
          return false;
    
        prev = root;
    
        return valid_BST_util(root.right, prev);
    }
    return true;
}

template <typename T>
bool valid_BST(BSTNode<T> &root) 
{
    BSTNode<T> *prev = NULL;
    return valid_BST_util(root, prev);
}