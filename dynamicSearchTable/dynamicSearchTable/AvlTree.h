#pragma once
#include "dynamicSearchTable.h"
#include "SET.h"
#include <iostream>
using namespace std;

template <class KEY, class OTHER>
class AvlTree : public dynamicSearchTable<KEY, OTHER>
{
public:
	AvlTree() { root = NULL; }
	~AvlTree() { makeEmpty(root); }
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);

private:
	struct AvlNode
	{
		SET<KEY, OTHER> data;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode(const SET<KEY, OTHER>& element, AvlNode* lt = NULL, AvlNode* rt = NULL, int h = 1) : data(element), left(lt), right(rt), height(h) {}
	};

	AvlNode* root;

	void insert(const SET<KEY, OTHER>& x, AvlNode*& t);
	bool remove(const KEY& x, AvlNode*& t);
	void makeEmpty(AvlNode* t);
	int height(AvlNode* t) const { return t == NULL ? 0 : t->height; }
	void LL(AvlNode*& t);
	void LR(AvlNode*& t);
	void RL(AvlNode*& t);
	void RR(AvlNode*& t);
	int max(int a, int b) { return a > b ? a : b; }
	bool adjust(AvlNode*& t, int subTree);
};

