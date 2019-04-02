#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
#include "stack.h"

template <class elemType>
class linkStack : public stack<elemType>
{
public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *n = NULL) : data(x), next(n) {};
        node(): next(NULL){}
        ~node() {}
    };
    node *top_p;
};
#endif // !LINK_LIST

