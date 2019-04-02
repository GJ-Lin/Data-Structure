#ifndef D_LINK_LIST
#define D_LINK_LIST

#include "list.h"
#include <iostream>

template <class elemType>
class dLinkList : public list<elemType>
{
public:
	dLinkList();
	void clear();
	int length() const;
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;
	void reverse() const;
	static void test();
	~dLinkList();
private:
	struct node
	{
		elemType data;
		node *prev, *next;

		node(const elemType &x, node *p = NULL, node *n = NULL) : data(x), prev(p), next(n) {}
		node() : prev(NULL), next(NULL) {}
		~node() {}
	};

	node *head, *tail;
	int currentLength;
	node *move(int i) const;
};

#endif // !D_LINK_LIST
