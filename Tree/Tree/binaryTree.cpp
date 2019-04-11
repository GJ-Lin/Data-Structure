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
void binaryTree<T>::clear(Node *&t)//wrap
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
void binaryTree<T>::preOrder(Node *t) const
{
    if (t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

template<class T>
void binaryTree<T>::midOrder() const
{
    cout << "\nMidOrder: ";
    midOrder(root);
}

template<class T>
void binaryTree<T>::midOrder(Node *t) const
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
void binaryTree<T>::postOrder(Node *t) const
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

template<class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x, Node *t) const
{
    Node *tmp;
    if (t == NULL) return NULL;
    if (t->data == x) return t;
    if (tmp = find(x, t->left)) return tmp;
    else return find(x, t->right);
}

template<class T>
void binaryTree<T>::delLeft(T x)
{
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->left);
}

template<class T>
void binaryTree<T>::delRight(T x)
{
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->right);
}

template<class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == NULL || tmp->left == NULL) return flag;
    return tmp->left->data;
}

template<class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == NULL || tmp->right == NULL) return flag;
    return tmp->right->data;
}

template<class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;

    cout << "\nInput root: ";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);

    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "\nInput 2 children of " << tmp->data << " (" << flag << " for empty): ";
        cin >> ldata >> rdata;
        if (ldata != flag) que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag) que.enQueue(tmp->right = new Node(rdata));
    }
    cout << "create completed!\n";
}
