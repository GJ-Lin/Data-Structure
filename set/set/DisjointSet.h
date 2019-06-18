#pragma once
#include <iostream>
using namespace std;
class DisjointSet
{
	friend ostream& operator<<(ostream& os, const DisjointSet& rhs)
	{
		for (int i = 0; i < rhs.size; ++i)
			os << rhs.parent[i] << ' ';
		return os;
	}
public:
	DisjointSet(int s);
	~DisjointSet();
	void Union(int root1, int root2);
	void UnionLCA(int root1, int root2);
	int Find(int x);
private:
	int size;
	int* parent;
};

