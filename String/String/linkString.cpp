#include "pch.h"
#include "linkString.h"
#include <iostream>
using namespace std;
linkString::linkString(const char *s)
{
    node *p;

    for (len = 0; s[len] != '\n'; ++len);
    nodeSize = sqrt(len);
    p = head = new node(1);
    while (*s)
    {
        p = p->next = new node(nodeSize);
        for (; p->size < nodeSize && *s; ++p->size, ++s)
            p->data[p->size] = *s;
    }
}

linkString::linkString(const linkString &other)
{
    node *p, *otherp = other.head->next;

    p = head = new node(1);
    len = other.len;
    nodeSize = other.nodeSize;
    while (otherp)
    {
        p = p->next = new node(nodeSize);
        for (; p->size < otherp->size; ++p->size)
            p->data[p->size] = otherp->data[p->size];
        otherp = otherp->next;
    }
}

void linkstring::clear()
{
    node *p = head->next, *nextp;
    
    while (p)
}