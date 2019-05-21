#pragma once
#include <iostream>
#include "dynamicSearchTable.h"
#include "SET.h"
template <class KEY, class OTHER>
class BinarySearchTree : public dynamicSearchTable<KEY, OTHER>
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);
private:
	struct BinaryNode
	{
		SET<KEY, OTHER> data;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const SET<KEY, OTHER>& thedata, BinaryNode* lt = NULL, BinaryNode* rt = NULL) : data(thedata), left(lt), right(rt) {}
	};
	BinaryNode* root;
	
	void insert(const SET<KEY, OTHER>& x, BinaryNode*& t);
	void remove(const KEY& x, BinaryNode*& t);
	SET<KEY, OTHER>* find(const KEY& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode* t);
};

