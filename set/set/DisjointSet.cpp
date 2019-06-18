#pragma once
#include "DisjointSet.h"

DisjointSet::DisjointSet(int s) : size(s)
{
	parent = new int[size];
	for (int i = 0; i < size; ++i)
		parent[i] = -1;
}

int DisjointSet::Find(int x)
{
	if (parent[x] < 0) return x;
	return parent[x] = Find(parent[x]);
}

void DisjointSet::Union(int i, int j)
{
	int root1 = Find(i), root2 = Find(j);
	if (root1 == root2) return;
	if (parent[root1] > parent[root2])
	{
		parent[root2] += parent[root1];
		parent[root1] = root2;
	}
	else
	{
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}

void DisjointSet::UnionLCA(int i, int j)
{
	int root1 = Find(i), root2 = Find(j);
	if (root1 == root2) return;
	parent[root1] += parent[root2];
	parent[root2] = root1;
}

DisjointSet::~DisjointSet()
{
	delete[] parent;
}
