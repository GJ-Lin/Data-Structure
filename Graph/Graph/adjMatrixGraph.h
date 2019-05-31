#pragma once
#include <iostream>
#include "graph.h"
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	adjMatrixGraph(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
	void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
	void remove(TypeOfVer x, TypeOfVer y);
	bool exist(TypeOfVer x, TypeOfVer y) const;
	void print() const
	{
		cout << '\t';
		for (int i = 0; i < Vers; ++i) cout << ver[i] << '\t';
		cout << endl;
		for (int i = 0; i < Vers; ++i)
		{
			cout << ver[i] << '\t';
			for (int j = 0; j < Vers; ++j)
				cout << edge[i][j] << '\t';
			cout << endl;
		}
	}
	~adjMatrixGraph();
private:
	int Vers, Edges;
	TypeOfEdge** edge;
	TypeOfVer* ver;
	TypeOfEdge noEdge;
	int find(TypeOfVer v) const
	{
		for (int i = 0; i < Vers; ++i)
			if (ver[i] == v) return i;
	}
};

