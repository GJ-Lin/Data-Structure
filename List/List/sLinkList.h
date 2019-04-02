#ifndef S_LINK_LIST
#define S_LINK_LIST

#include "list.h"
#include <iostream>

template <class elemType>
class sLinkList : public list<elemType>
{
public:
	sLinkList();
	void clear();
	int length() const;
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;
	void erase(int i);
    int visit_back(int k) const;
	static void test();
	~sLinkList();
private:
	struct node
	{
		elemType data;
		node *next;

		node(const elemType &x, node *n = NULL) : data(x), next(n) {}
		node() : next(NULL) {}
		~node() {}
	};

	node *head;
	int currentLength;
	node *move(int i) const;
};

#endif // !S_LINK_LIST
