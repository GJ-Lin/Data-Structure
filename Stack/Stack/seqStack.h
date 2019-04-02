#pragma once

#include "stack.h"

template <class elemType>
class seqStack : public stack<elemType>
{
public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();
};
