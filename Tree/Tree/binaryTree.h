#pragma once
#include "bTree.h"
#include <iostream>
#include "linkQueue.h"
#include "linkQueue.cpp"
using namespace std;

template <class T>
class binaryTree : public bTree<T>
{
    friend void printTree(const binaryTree &t, T flag)
    {
        linkQueue<T> q;
        q.enQueue(t.root->data);
        cout << endl;
        while (!q.isEmpty())
        {
            char p, l, r;
            p = q.deQueue();
            l = t.lchild(p, flag);
            r = t.rchild(p, flag);
            cout << p << ' ' << l << ' ' << r << endl;
            if (l != flag) q.enQueue(l);
            if (r != flag) q.enQueue(r);
        }
    }
public:
    binaryTree(): root(NULL){}
    binaryTree(T x) { root = new Node(x); }
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const { return flag; }
private:
    struct Node
    {
        Node *left, *right;
        T data;

        Node(): left(NULL), right(NULL){}
        Node(T item, Node *L = NULL, Node *R = NULL): data(item), left(L), right(R){}
        ~Node(){}
    };

    Node *root;
    typename binaryTree<T>::Node * find(T x, typename binaryTree<T>::Node * t) const;
    void preOrder(typename binaryTree<T>::Node *t) const;
    void midOrder(typename binaryTree<T>::Node *t) const;
    void postOrder(typename binaryTree<T>::Node *t) const;
    void clear(typename binaryTree<T>::Node *&t);
};

