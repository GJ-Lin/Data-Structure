#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

template<class elemType>
class linkQueue_cir : public queue<elemType>
{
public:
    linkQueue_cir() { rear = NULL; }
    ~linkQueue_cir()
    {
        node *tmp, *delp;

        if (rear == NULL) return;
        delp = rear->next;
        rear->next = NULL;
        while (delp != NULL)
        {
            tmp = delp;
            delp = delp->next;
            delete tmp;
        }
    }
    bool isEmpty() const { return rear == NULL; }
    void enQueue(const elemType &x)
    {
        if (rear == NULL)
        {
            rear = new node(x);
            rear->next = rear;
        }
        else
            rear = rear->next = new node(x, rear->next);
    }
    elemType deQueue()
    {
        node *tmp = rear->next;
        elemType value = tmp->data;
        if (rear == tmp) rear = NULL;
        else rear->next = tmp->next;
        delete tmp;
        return value;
    }
    elemType getHead() const { return rear->next->data; }
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL): data(x), next(N){}
        node(): next(NULL){}
        ~node(){}
    };

    node *rear;
};

