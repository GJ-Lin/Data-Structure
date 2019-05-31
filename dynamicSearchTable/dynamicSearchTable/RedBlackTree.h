#pragma once
#include "dynamicSearchTable.h"
#include <iostream>
using namespace std;

template <class KEY, class OTHER>
class RedBlackTree : public dynamicSearchTable<KEY, OTHER>
{
	struct RedBlackNode;

public:
	RedBlackTree(RedBlackNode* t = NULL) : root(t) {};
	~RedBlackTree() { makeEmpty(root); };
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);

private:
	enum colourT{ RED, BLACK };
	struct RedBlackNode
	{
		SET<KEY, OTHER> data;
		RedBlackNode* left;
		RedBlackNode* right;
		colourT colour;

		RedBlackNode(const SET<KEY, OTHER>& element, RedBlackNode* lt = NULL, RedBlackNode* rt = NULL, colourT h = RED) : data(element), left(lt), right(rt), colour(h) {}
	};
	RedBlackNode* root;

	void makeEmpty(RedBlackNode*& t);
	void insertAdjust(RedBlackNode* gp, RedBlackNode* p, RedBlackNode*& t, KEY del);
	void removeAdjust(RedBlackNode*& p, RedBlackNode*& c, RedBlackNode*& t, KEY del);
	void LL(RedBlackNode* gp);
	void LR(RedBlackNode* gp);
	void RL(RedBlackNode* gp);
	void RR(RedBlackNode* gp);
};

