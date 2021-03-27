#include <iostream>
#include <vector>
// #include <bits/stdc++.h> 

using namespace std;
//----------------------------------Vector----------------------------------//
template <typename T>
struct Set 
{
    vector<T> myset;
};
//O(N)
template <typename T>
bool element_of(Set<T> s, T element) 
{
    return count(s.myset.begin(), s.myset.end(), element);
}
//O(N)
template <typename T>
void insert(Set<T> &s, T element)
{
    if(!element_of(s,element))
    s.myset.push_back(element);
}
//O(N^2)
template <typename T>
Set<T> intersect(Set<T> &s, Set<T> &t) 
{
    Set<T> newset;
    for (int i = 0; i < s.myset.size(); i++ )
    {
        for (int j = 0; j < t.myset.size() ; j++)
        {
            if(s.myset[i] == t.myset[j]) 
            {
                newset.myset.push_back(s.myset[i]);
                s.myset.erase(s.myset.begin() + i);
                t.myset.erase(t.myset.begin() + j);
            }
        }
    }
    return newset;
}
//----------------------------Sorted Vector----------------------------------//
template <typename T>
struct Set 
{
    vector<T> myset;
};
//O(N)
template <typename T>
bool element_of(Set<T> s, T element) 
{

}
//O(N)
template <typename T>
void insert(Set<T> &s, T element)
{
    if(!element_of(s,element))
    {
        s.myset.push_back(element);
        for(int i = s.myset.size() - 1; i > 0 && s.myset[i] < s.myset[i] ; i++)
        {
            swap(s.myset[i],s.myset[i-1]);
        }
    }
}
//O(N+M)
template <typename T>
Set<T> intersect(Set<T> &s, Set<T> &t) 
{
    Set<T> newset;
    int i = 0; j = 0;
    while(i < s.myset.size() && t.myset.size()
    {
        if()
    }

    return newset;
}
//----------------------------BST----------------------------------//
template <typename T>
struct BSTNode {
    T item;
    BSTNode<T> *left, *right;
};
template <typename T>
struct Set
{
    BSTNode<T> *root = NULL;
};

//O(logN) if balanced, O(N) if skewed
template <typename T>
bool element_of(BSTNode<T> *node, T element) 
{
    if(node == NULL) return false;
    if(node->item == element) return true;
    if(element < node->item) return find(node->left,element);
    if(element > node->item) return find(node->right,element);
    return false;
}
template <typename T>
bool element_of(Set<T> s, T element) 
{
    return find(s.root,element);
}
//O(logN) if balanced, O(N) if skewed
template <typename T>
BSTNode<T> *RECinsert(BSTNode<T> *node, T element)
{
    if(node == NULL) return new BSTNode<T> {item,NULL,NULL};
    if(item < node->item) node->left = insert(node->left,item);
    if(node->item < item) node->right = insert(node->right,item);
    return node;
}
template <typename T>
void insert(Set<T> &s, T element)
{
    if(element_of(s,element)) return;
    s.root = RECinsert(s.root,element);



}
//In-order traversal
template <typename T>
void flatten(vector<T> &v, BSTNode<T> *node)
{
    
    if (node->left != NULL) flatten(v,node->left);
    v.push_back(node->item);
    if(node->right != NULL) flatten(v,node->right);
}

template <typename T>
Set<T> intersect(Set<T> &s, Set<T> &t) 
{
    vector<T> v1,v2;
    flatten(v1,s.root);
    flatten(v2,t.root);
    
    Set<T> newset;
    int i = 0; j = 0;
    while(i < s.myset.size() && t.myset.size()
    {
        if()
    }

    return newset;
}

int main(void)
{
    Set<int> set1;
    Set<int> set2;    
    Set<int> out;


    insert(set1,6);
    insert(set2,6);

    cout << set1.myset[0] << endl;
    out = intersect(set1,set2);
    cout << out.myset[0] << endl;
}