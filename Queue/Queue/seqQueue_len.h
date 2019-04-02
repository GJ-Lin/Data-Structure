#pragma once
#include "queue.h"

template<class elemType>
class seqQueue_len : public queue<elemType>
{
public:
    seqQueue_len(int size = 10)
    {
        elem = new elemType[size];
        maxSize = size;
        front = -1;
        length = 0;
    }

    ~seqQueue_len() { delete[] elem; }

    bool isEmpty() const { return length == 0; }

    void enQueue(const elemType &x)
    {
        if (length == maxSize) doubleSpace();
        int rear = (front + length + 1) % maxSize;
        elem[rear] = x;
        ++length;
    }
    elemType deQueue()
    {
        front = (front + 1) % maxSize;
        --length;
        return elem[front];
    }
    elemType getHead() const { return elem[(front + 1) % maxSize]; }

private:
    elemType *elem;
    int maxSize;
    int front;
    int length;

    void doubleSpace()
    {
        elemType *tmp = elem;
        elem = new elemType[2 * maxSize];
        for (int i = 0; i < maxSize; ++i)
            elem[i] = tmp[(front + i + 1) % maxSize];
        front = -1;
        maxSize *= 2;
        delete tmp;
    }
};

