#pragma once
#include <iostream>
using namespace std;
class seqString
{
    friend seqString operator+(const seqString &s1, const seqString &s2);
    friend bool operator==(const seqString &s1, const seqString &s2);
    friend bool operator!=(const seqString &s1, const seqString &s2);
    friend bool operator>(const seqString &s1, const seqString &s2);
    friend bool operator>=(const seqString &s1, const seqString &s2);
    friend bool operator<(const seqString &s1, const seqString &s2);
    friend bool operator<=(const seqString &s1, const seqString &s2);
    friend ostream &operator<<(ostream &os, const seqString &s);
public:
    seqString();
    ~seqString();
};

