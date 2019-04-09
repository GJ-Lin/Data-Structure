#include "pch.h"
#include "binaryTree.h"
#include "linkQueue.h"
#include "linkQueue.cpp"
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
void binaryTree<T>::clear()
{
    clear(root);
}

template<class T>
void binaryTree<T>::clear(typename binaryTree<T>::Node *&t)//wrap
{
    if (t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template<class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template<class T>
void binaryTree<T>::preOrder() const
{
    cout << "\nPreOrder: ";
    preOrder(root);
}

template<class T>
void binaryTree<T>::preOrder(const typename binaryTree<T>::Node *&t) const
{
    if (t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template<class T>
void binaryTree<T>::midOrder() const
{
    cout << "\nMidOrder";
    midOrder(root);
}

template<class T>
void binaryTree<T>::midOrder(const typename binaryTree<T>::Node *&t) const
{
    if (t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template<class T>
void binaryTree<T>::postOrder() const
{
    cout << "\nPostOrder: ";
    postOrder(root);
}

template<class T>
void binaryTree<T>::postOrder(const typename binaryTree<T>::Node *&t) const
{
    if (t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template<class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<Node *> que;
    Node *tmp;

    cout << "\nLevelOrder: ";
    que.enQueue(root);
    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left) que.enQueue(tmp->left);
        if (tmp->right) que.enQueue(tmp->right);
    }
}