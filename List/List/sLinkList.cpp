#include "pch.h"
#include "sLinkList.h"
#include <iostream>

using namespace std;

template <class elemType>
sLinkList<elemType>::sLinkList()
{
	head = new node;
	currentLength = 0;
}

template <class elemType>
void sLinkList<elemType>::clear()
{
	node *p = head->next, *q;
	head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	currentLength = 0;
}

template <class elemType>
int sLinkList<elemType>::length() const
{
	return currentLength;
}

template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x)
{
	node *pos;
	pos = move(i - 1);
	pos->next = new node(x, pos->next);
	++currentLength;
}

template <class elemType>
void sLinkList<elemType>::remove(int i)
{
	node *pos, *delp;
	pos = move(i - 1);
	delp = pos->next;
	pos->next = delp->next;
	delete delp;
	--currentLength;
}

template <class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
	node *p = head->next;
	int i = 0;
	while (p != NULL && p->data != x)
	{
		p = p->next;
		++i;
	}
	if (p == NULL)
		return -1;
	else
		return i;
}

template <class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
	return move(i)->data;
}

template <class elemType>
void sLinkList<elemType>::traverse() const
{
	node *p = head->next;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

template <class elemType>
void sLinkList<elemType>::erase(int i)
{
	node *pre = move(i - 1), *delp = pre->next;
	elemType tmp = delp->data;
	int count = 1;
	pre->next = delp->next;
	delete delp;

	for (pre = head; pre->next != NULL; pre = pre->next)
	{
		if (pre->next->data == tmp)
		{
			delp = pre->next;
			pre->next = delp->next;
			delete delp;
			++count;
		}
	}
	currentLength -= count;
}

template <class elemType>
int sLinkList<elemType>::visit_back(int k) const
{
    node *p = head, *q = head;
    for (int i = 0; i < k && q != NULL; ++i)
        q = q->next;
    if (q == NULL) return 0;
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    cout << p->data << endl;
    return 1;
}

template <class elemType>
void sLinkList<elemType>::test()
{
	sLinkList<int> sll;
	cout << sll.length() << endl;
	for (int i = 0; i < 10; ++i)
		sll.insert(sll.length(), i);
	cout << sll.length() << endl;
	sll.traverse();
}

template <class elemType>
sLinkList<elemType>::~sLinkList()
{
	clear();
	delete head;
}

template <class elemType>
typename sLinkList<elemType>::node *sLinkList<elemType>::move(int i) const
{
	node *p = head;
	while (i-- >= 0) p = p->next;
	return p;
}
