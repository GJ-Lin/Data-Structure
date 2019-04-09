#include "pch.h"
#include "binaryTree.h"
//#include <iostream>
//using namespace std;

template<class T>
bool binaryTree<T>::isEmpty() const
{
    return root == NULL;
}


template<class T>
T binaryTree<T>::Root(T flag) const
{
    if (root == NULL) return flag;
    else return root->data;
}

template<class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)//wrap
{
    if (t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template<class T>
void binaryTree<T>::clear()
{
    clear(root);
}

template<class T>
binaryTree<T>::~binaryTree()
{
    delete root;
}
