#ifndef SEQ_LIST
#define SEQ_LIST

#include "list.h"

template <class elemType>
class seqList : public list<elemType>
{
public:
	seqList(int initSize = 10);
	void clear();
	int length() const;
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;
	void erase(int i);
	static void test();
	~seqList();
private:
	elemType *data;
	int currentLength;
	int maxSize;
	void doubleSpace();
};

#endif // !SEQ_LIST
