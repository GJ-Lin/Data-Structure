#pragma once
#include <iostream>
#include "graph.h"
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
	adjListGraph(int vSize, const TypeOfVer d[]);
	void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
	void remove(TypeOfVer x, TypeOfVer y);
	bool exist(TypeOfVer x, TypeOfVer y) const;
	void dfs() const;
	void dfs(int start, bool visited[]) const;
	void bfs() const;
	void topSort() const;
	void unweightedShortDistance(TypeOfVer start, TypeOfEdge noEdge) const;
	void dijkstra(TypeOfVer start, TypeOfEdge noEdge) const;
	void printPath(int start, int end, int prev[]) const;

	void print() const
	{
		for (int i = 0; i < Vers; ++i)
		{
			edgeNode* p = verList[i].head;
			cout << verList[i].ver << ":\t";
			while (p != NULL)
			{
				cout << verList[p->end].ver << '(' << p->weight << ')' << '\t';
				p = p->next;
			}
			cout << endl;
		}
	}
 	~adjListGraph();
private:
	int Vers, Edges;
	struct edgeNode
	{
		int end;
		TypeOfEdge weight;
		edgeNode* next;
		edgeNode(int e, TypeOfEdge w, edgeNode* n = NULL) : end(e), weight(w), next(n) {}
	};
	struct verNode
	{
		TypeOfVer ver;
		edgeNode* head;
		verNode(edgeNode *h = NULL) : head(h) {}
	};
	verNode* verList;
	int find(TypeOfVer v) const
	{
		for (int i = 0; i < Vers; ++i)
			if (verList[i].ver == v) return i;
	}
};

