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

	char* data;
	int len;
public:
    seqString(const char *s = "");
	seqString(const seqString& other);
    ~seqString();
	int length() const;
	seqString& operator=(const seqString& other);
	seqString subStr(int start, int num) const;
	void insert(int start, const seqString& s);
	void remove(int start, int num);
};

