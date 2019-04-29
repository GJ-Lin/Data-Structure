#include "pch.h"
#include "linkString.h"
#include <iostream>
using namespace std;
linkString::linkString(const char *s)
{
    node *p;

    for (len = 0; s[len] != '\n'; ++len);
    nodeSize = int(sqrt(len));
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

void linkString::clear()
{
    node *p = head->next, *nextp;
    
	while (p)
	{
		nextp = p->next;
		delete p;
		p = nextp;
	}
}

linkString::~linkString()
{
	clear();
	delete head;
}

int linkString::length() const
{
	return len;
}

linkString& linkString::operator=(const linkString& other)
{
	node* p = head, * otherp = other.head->next;
	if (this == &other) return *this;
	clear();
	len = other.len;
	nodeSize = other.nodeSize;
	while (otherp)
	{
		p = p->next = new node(nodeSize);
		for (; p->size < otherp->size; ++p->size)
			p->data[p->size] = otherp->data[p->size];
		otherp = otherp->next;
	}

	return *this;
}

void linkString::findPos(int start, int& pos, node*& p) const
{
	int count = 0;
	p = head->next;
	
	while (count < start)
	{
		if (count + p->size < start)
		{
			count += p->size;
			p = p->next;
		}
		else
		{
			pos = start - count;
			return;
		}
	}
}

linkString linkString::subStr(int start, int num) const
{
	linkString tmp;
	int count = 0, pos;
	node* p, * tp = tmp.head;

	if (start < 0 || start >= len - 1) return tmp;
	
	num = (start + num > len) ? len - start : num;
	tmp.len = num;
	tmp.nodeSize = int(sqrt(num));

	findPos(start, pos, p);

	for (int i = 0; i < tmp.len;)
	{
		tp = tp->next = new node(tmp.nodeSize);
		for (; tp->size < tmp.nodeSize && i < tmp.len; ++tp->size, ++i)
		{
			if (pos == p->size)
			{
				p = p->next;
				pos = 0;
			}
			tp->data[tp->size] = p->data[pos++];
		}
	}

	return tmp;
}

void linkString::split(node* p, int pos)
{
	p->next = new node(nodeSize, p->next);
	int i;
	for (i = pos; i < p->size; ++i)
		p->next->data[i - pos] = p->data[pos];
	p->next->size = i - pos;
	p->size = pos;
}

void linkString::merge(node* p)
{
	node* nextp = p->next;
	if (p->size + nextp->size <= nodeSize)
	{
		for (int pos = 0; pos < nextp->size; ++pos, ++p->size)
			p->data[p->size] = nextp->data[pos];
		p->next = nextp->next;
		delete nextp;
	}
}

void linkString::insert(int start, const linkString& s)
{
	node* p, * nextp, * tmp;
	int pos;

	if (start < 0 || start > len) return;
	findPos(start, pos, p);
	split(p, pos);
	nextp = p->next;
	tmp = s.head->next;
	while (tmp)
	{
		for (pos = 0; pos < tmp->size; ++pos)
		{
			if (p->size == nodeSize)
				p = p->next = new node(nodeSize);
			p->data[p->size] = tmp->data[pos];
			++p->size;
		}
		tmp = tmp->next;
	}
	len += s.len;
	p->next = nextp;
	merge(p);
}

void linkString::remove(int start, int num)
{
	if (start < 0 || start >= len - 1) return;

	node* startp;
	int pos;

	findPos(start, pos, startp);
	split(startp, pos);
	if (start + num >= len)
	{
		num = len - start;
		len = start;
	}
	else len -= num;

	while (true)
	{
		node* nextp = startp->next;
		if (num > nextp->size)
		{
			num -= nextp->size;
			startp->next = nextp->next;
			delete nextp;
		}
		else
		{
			split(nextp, num);
			startp->next = nextp->next;
			delete nextp;
			break;
		}
	}
	merge(startp);
}

linkString operator+(const linkString& s1, const linkString& s2)
{
	char* tmp = new char[s1.len + s2.len + 1];
	linkString::node* p;
	int cnt = 0, i;
	for (p = s1.head->next; p != NULL; p = p->next)
		for (i = 0; i < p->size; ++i)
			tmp[cnt++] = p->data[i];
	for (p = s2.head->next; p != NULL; p = p->next)
		for (i = 0; i < p->size; ++i)
			tmp[cnt++] = p->data[i];
	tmp[cnt] = '\0';
	linkString returnValue(tmp);
	delete [] tmp;
	return returnValue;
}

bool operator==(const linkString& s1, const linkString& s2)
{
	linkString::node* p1 = s1.head->next, * p2 = s2.head->next;
	int pos1 = 0, pos2 = 0;

	if (s1.len != s2.len) return false;
	while (p1 && p2)
	{
		if (p1->data[pos1] != p2->data[pos2]) return false;
		if (++pos1 == p1->size)
		{
			p1 = p1->next;
			pos1 = 0;
		}
		if (++pos2 == p2->size)
		{
			p2 = p2->next;
			pos2 = 0;
		}
	}
	return true;
}

bool operator!=(const linkString& s1, const linkString& s2)
{
	return !(s1 == s2);
}

bool operator>(const linkString& s1, const linkString& s2)
{
	linkString::node* p1 = s1.head->next, * p2 = s2.head->next;
	int pos1 = 0, pos2 = 0;

	while (p1)
	{
		if (p2 == NULL) return true;
		if (p1->data[pos1] > p2->data[pos2]) return true;
		if (p1->data[pos1] < p2->data[pos2]) return false;
		if (++pos1 == p1->size)
		{
			p1 = p1->next;
			pos1 = 0;
		}
		if (++pos2 == p2->size)
		{
			p2 = p2->next;
			pos2 = 0;
		}
	}
	return false;
}

bool operator>=(const linkString& s1, const linkString& s2)
{
	return (s1 == s2 || s1 > s2);
}

bool operator<(const linkString& s1, const linkString& s2)
{
	return !(s1 >= s2);
}

bool operator<=(const linkString& s1, const linkString& s2)
{
	return !(s1 > s2);
}

ostream& operator<<(ostream& os, const linkString& s)
{
	linkString::node* p = s.head->next;
	int pos = 0;

	while (p)
	{
		for (pos = 0; pos < p->size; ++pos)
			os << p->data[pos];
		p = p->next;
	}
	return os;
}