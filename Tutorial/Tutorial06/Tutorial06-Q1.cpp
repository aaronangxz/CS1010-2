#include <iostream>
#include <vector>
// #include <bits/stdc++.h> 

using namespace std;

template <typename T>
struct Set 
{
    vector<T> myset;// your code here
};

template <typename T>
bool element_of(Set<T> s, T element) 
{
    return count(s.myset.begin(), s.myset.end(), element);
    // your code here
}

template <typename T>
void insert(Set<T> &s, T element)
{
    s.myset.push_back(element);
    // your code here
}

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
    // your code here
}

int main(void)
{
    Set<int> set1;
    Set<int> set2;    
    Set<int> out;


    insert(set1,6);
    insert(set2,6);

    cout << set1.myset[0] << endl;
    // cout << element_of(set1,5) << endl;
    out = intersect(set1,set2);
    cout << out.myset[0] << endl;
}