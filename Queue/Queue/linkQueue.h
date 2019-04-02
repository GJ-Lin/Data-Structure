#pragma once
#include "queue.h"
#include <iostream>
using namespace std;
template<class elemType>
class linkQueue : public queue<elemType>
{
public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    elemType getTail() const;

private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL): data(x), next(N){}
        node():next(NULL){}
        ~node(){}
    };

    node *front, *rear;
};

