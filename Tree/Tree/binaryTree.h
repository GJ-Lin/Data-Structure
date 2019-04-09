#pragma once
#include "bTree.h"
#include <iostream>
using namespace std;

template <class T>
class binaryTree : public bTree<T>
{
    friend void printTree(const binaryTree &t, T flag);
public:
    binaryTree(): root(NULL){}
    binaryTree(T x) { root = new Node(x); }
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    void clear(binaryTree<T>::Node);
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
};
