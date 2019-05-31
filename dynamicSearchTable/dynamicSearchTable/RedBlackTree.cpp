#pragma once
#include "RedBlackTree.h"
#include <iostream>

template <class KEY, class OTHER>
SET<KEY, OTHER>* RedBlackTree<KEY, OTHER>::find(const KEY& x) const
{
	RedBlackNode* t = root;
	while (t != NULL && t->data.key != x)
	{
		if (x < t->data.key) t = t->left;
		else t = t->right;
	}
	
	if (t == NULL) return NULL;
	else return (SET<KEY, OTHER>*)t;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::makeEmpty(RedBlackNode*& t)
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x)
{
	RedBlackNode* t, * parent, * grandP;

	if (root == nULL)
	{
		root = new RedBlackNode(x, NULL, NULL, BLACK);
		return;
	}

	parent = grandP = t = root;
	while (true)
	{
		if (t)
		{
			if (t->left && t->left->colour == RED && t->right && t->right->colour == RED)
			{
				t->left->colour = t->right->colour = BLACK;
				t->colour = TED;
				insertAdjust(grandP, parent, t);
			}
			grandP = parent;
			parent = t;
			t = (x.key < t->data.key ? t->left : t->right);
		}
		else
		{
			t = new RedBlackNode(x);
			if (x.key < parent->data.key)
				parent->left = t;
			else
				parent->right = t;
			insertAdjust(grandP, parent, t);
			root->colour = BLACK;
			return;
		}
	}
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::insertAdjust(RedBlackNode* gp, RedBlackNode* p, RedBlackNode* t)
{
	if (p->colour == BLACK) return;
	if (p == root)
	{
		p->colour = BLACK;
		return;
	}
	if (gp->left == p)
		if (p->left == t)
			LL(gp);
		else
			LR(gp);
	else
		if (p->right == t)
			RR(gp);
		else
			RL(gp);
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::LL(RedBlackNode* gp)
{
	RedBlackNode* p = gp->left, * t = p->left;
	RedBlackNode tmp = *gp;
	gp->data = p->data;
	gp->left = t;
	gp->right = p;
	p->data = tmp.data;
	p->left = p->right;
	p->right = tmp.right;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::LR(RedBlackNode* gp)
{
	RedBlackNode* p = gp->left, * t = p->right;
	RedBlackNode tmp = *gp;
	gp->data = t->data;
	gp->right = t;
	p->right = t->left;
	t->data = tmp.data;
	t->left = t->right;
	t->right = tmp.right;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::RR(RedBlackNode* gp)
{
	RedBlackNode* p = gp->right, * t = p->right;
	RedBlackNode tmp = *gp;
	gp->data = p->data;
	gp->right = t;
	gp->left = p;
	p->data = tmp.data;
	p->right = p->left;
	p->left = tmp.left;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::RL(RedBlackNode* gp)
{
	RedBlackNode* p = gp->right, * t = p->right;
	RedBlackNode tmp = *gp;
	gp->data = t->data;
	gp->left = t;
	p->left = t->right;
	t->data = tmp.data;
	t->right = t->left;
	t->left = tmp.left; 
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::remove(RedBlackNode* )