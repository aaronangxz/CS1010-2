#include <iostream>
#include <limits.h>
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

template <typename T>
bool isValidBST(BSTNode<T> &root, BSTNode<T> &minNode, BSTNode<T> &maxNode) {
    if(!root) return true;
    if(minNode && root.item <= minNode.item || maxNode && root.item >= maxNode.item)
        return false;
    return isValidBST(root.left, minNode, root) && isValidBST(root.right, root, maxNode);
}

template <typename T>
bool valid_BST(BSTNode<T> &root) {
    return isValidBST(root, NULL, NULL);
}


template <typename T>
bool isValidBSTAdd(BSTNode<T> &root, long min, long max) 
{
    if(root==NULL)
    {
        return true;
    }
    if(root.item >min && root.item <max)
    {
        return isValidBSTAdd(root.left ,min, root.item) && isValidBSTAdd(root.right ,root.item ,max);
    }
    return false;
}

template <typename T>
bool valid_BST(BSTNode<T> &root) 
{
      
    return isValidBSTAdd(root,LONG_MIN, LONG_MAX);
}