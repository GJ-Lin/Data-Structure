#pragma once
#include "queue.h"

template <class elemType>
class seqQueue : public queue<elemType>
{
public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();
};

