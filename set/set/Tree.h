#pragma once
#include "DisjointSet.h"
#include <iostream>
using namespace std;
class Tree
{
	struct Node;
public:
	Tree()
	{
		treesize = 0;
		root = NULL;
	}
	void create(int flag)
	{
		int rt;
		cout << "input root: " << endl;
		cin >> rt;
		root = new Node(rt);
		treesize = 1;
		int parent, child;
		cout << "input parent and child: ";
		while (cin >> parent)
		{
			if (parent == flag) return;
			cin >> child;
			insert(root, parent, child);
			++treesize;
			cout << "input parent and child: ";
		}
	}
	bool insert(Node* now, int parent, int child)
	{
		if (now->data == parent)
		{
			now->insert(child);
			return true;
		}
		bool flag = false;
		for (int i = 0; i < now->sonsize; ++i)
		{
			if (insert(now->sons[i], parent, child))
				flag = true;
		}
		return flag;
	}
	void print() const
	{
		print(root);
	}
	void print(Node* now) const
	{
		cout << now->data << ' ';
		for (int i = 0; i < now->sonsize; ++i)
			print(now->sons[i]);
	}
	int LCA(int x, int y) const
	{
		DisjointSet djset(treesize);
		LCA(x, y, root, djset);
		int u = djset.Find(x), v = djset.Find(y);
		if (u == v) return u;
		else return -1;
	}
	void LCA(int x, int y, Node* now, DisjointSet& djset) const
	{
		if (now->sonsize == 0) return;
		for (int i = 0; i < now->sonsize; ++i)
		{
			Node* t = now->sons[i];
			LCA(x, y, t, djset);
			if (djset.Find(x) == djset.Find(y)) return;
			djset.UnionLCA(now->data, t->data);
		}
	}
	//~Tree();
private:
	struct Node
	{
		int data;
		int sonsize;
		int maxsize;
		Node** sons;
		Node(int _data_ = -1) : data(_data_), maxsize(10)
		{
			sonsize = 0;
			sons = new Node*[maxsize];
		}
		void insert(int child)
		{
			if (sonsize == maxsize) doublespace();
			sons[sonsize] = new Node(child);
			++sonsize;
		}
		void doublespace()
		{
			Node** tmp = sons;
			maxsize *= 2;
			sons = new Node*[maxsize];
			for (int i = 0; i < sonsize; ++i)
				sons[i] = tmp[i];
			delete[] tmp;
		}
	};
	Node* root;
	int treesize;
};

