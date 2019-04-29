#pragma once
#include "dynamicSearchTable.h"

template <class KEY, class OTHER>
class AvlTree : public dynamicSearchTable<KEY, OTHER>
{
public:
	AvlTree();
	~AvlTree();
private:
	struct AvlNode
	{
		SET<KEY, OTHER> data;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode(const SET<KEY, OTHER>& element, AvlNode* lt, AvlNode* rt, int h = 1) : data(element), left(lt), right(rt), height(h) {}
	};

	AvlNode* root;

	void insert(const SET<KEY, OTHER>& x, AvlNode*& t);
	bool remove(const KEY& x, AvlNode*& t);
	void makeEmpty(AvlNode* t);
	int height(AvlNode* t) const { return t == NULL ? 0 : t->height; }

};

