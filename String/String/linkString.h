#pragma once
#include <iostream>
using namespace std;
class linkString
{
    friend linkString operator+(const linkString &s1, const linkString &s2);
    friend bool operator==(const linkString &s1, const linkString &s2);
    friend bool operator!=(const linkString &s1, const linkString &s2);
    friend bool operator>(const linkString &s1, const linkString &s2);
    friend bool operator>=(const linkString &s1, const linkString &s2);
    friend bool operator<(const linkString &s1, const linkString &s2);
    friend bool operator<=(const linkString &s1, const linkString &s2);
    friend ostream &operator<<(ostream &os, const linkString &s);

    struct node
    {
        int size;
        char *data;
        node *next;

        node(int s = 1, node *n = NULL) :next(n)
        {
            data = new char[s];
            size = 0;
        }
    };

    node *head;
    int len;
    int nodeSize;

    void clear();
    void findPos(int start, int &pos, node *&p) const;
    void split(node *p, int pos);
    void merge(node *p);

public:
    linkString(const char *s = "");
    linkString(const linkString &other);
    ~linkString();
    int length() const;
    linkString &operator=(const linkString &other);
    linkString subStr(int start, int num) const;
    void insert(int start, const linkString &s);
    void remove(int start, int num);
};

