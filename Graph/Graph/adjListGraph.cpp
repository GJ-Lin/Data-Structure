#include "adjListGraph.h"
#include "linkQueue.h"
#include "linkQueue.cpp"
#include <iostream>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[])
{
	Vers = vSize;
	Edges = 0;
	verList = new verNode[vSize];
	for (int i = 0; i < Vers; ++i) verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph()
{
	edgeNode* p;
	for (int i = 0; i < Vers; ++i)
	{
		while ((p = verList[i].head) != NULL)
		{
			verList[i].head = p->next;
			delete p;
		}
	}
	delete[] verList;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w)
{
	int u = find(x), v = find(y);
	verList[u].head = new edgeNode(v, w, verList[u].head);
	++Edges;
}

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y)
{
	int u = find(x), v = find(y);
	edgeNode* p = verList[u].head, * q;
	if (p == NULL) return;

	if (p->end = v)
	{
		verList[u].head = p->next;
		delete p;
		--Edges;
		return;
	}
	while (p->next != NULL && p->next->end != v) p = p->next;
	if (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		delete q;
		--Edges;
	}
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y) const
{
	int u = find(x), v = find(y);
	edgeNode* p = verList[u].head;
	while (p != NULL && p->end != v) p = p->next;
	if (p == NULL) return false;
	else return true;
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const
{
	bool* visited = new bool[Vers];
	for (int i = 0; i < Vers; ++i) visited[i] = false;
	cout << "DFS order: " << endl;
	for (int i = 0; i < Vers; ++i)
	{
		if (visited[i] == true) continue;
		dfs(i, visited);
		cout << endl;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const
{
	edgeNode* p = verList[start].head;
	cout << verList[start].ver << '\t';
	visited[start] = true;
	while (p != NULL)
	{
		if (visited[p->end] == false) dfs(p->end, visited);
		p = p->next;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::bfs() const
{
	bool* visited = new bool[Vers];
	int currentNode;
	linkQueue<int> q;
	edgeNode* p;
	for (int i = 0; i < Vers; ++i) visited[i] = false;

	cout << "BFS order: " << endl;
	for (int i = 0; i < Vers; ++i)
	{
		if (visited[i] == true) continue;
		q.enQueue(i);
		while (!q.isEmpty())
		{
			currentNode = q.deQueue();
			if (visited[currentNode] == true) continue;
			cout << verList[currentNode].ver << '\t';
			visited[currentNode] = true;
			p = verList[currentNode].head;
			while (p != NULL)
			{
				if (visited[p->end] == false) q.enQueue(p->end);
				p = p->next;
			}
		}
		cout << endl;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const
{
	linkQueue<int> q;
	edgeNode* p;
	int current;
	int* inDegree = new int[Vers];
	for (int i = 0; i < Vers; ++i) inDegree[i] = 0;
	for (int i = 0; i < Vers; ++i)
	{
		for (p = verList[i].head; p != NULL; p = p->next)
			++inDegree[p->end];
	}
	for (int i = 0; i < Vers; ++i)
		if (inDegree[i] == 0) q.enQueue(i);

	cout << "topSort: " << endl;
	while (!q.isEmpty())
	{
		current = q.deQueue();
		cout << verList[current].ver << '\t';
		for (p = verList[current].head; p != NULL; p = p->next)
			if (--inDegree[p->end] == 0)
				q.enQueue(p->end);
	}
	cout << endl;
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::unweightedShortDistance(TypeOfVer start, TypeOfEdge noEdge) const
{
	linkQueue<int> q;
	TypeOfEdge* distance = new TypeOfEdge[Vers];
	int* prev = new int[Vers];
	int u, sNo;
	edgeNode* p;

	for (int i = 0; i < Vers; ++i) distance[i] = noEdge;
	sNo = find(start);

	distance[sNo] = 0;
	prev[sNo] = sNo;
	q.enQueue(sNo);

	while (!q.isEmpty())
	{
		u = q.deQueue();
		for (p = verList[u].head; p != NULL; p = p->next)
		{
			if (distance[p->end] == noEdge)
			{
				distance[p->end] = distance[u] + 1;
				prev[p->end] = u;
				q.enQueue(p->end);
			}
		}
	}

	for (int i = 0; i < Vers; ++i)
	{
		cout << "Shorted path from " << start << " to " << verList[i].ver << " is: " << endl;
		printPath(sNo, i, prev);
		cout << endl;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dijkstra(TypeOfVer start, TypeOfEdge noEdge) const
{
	TypeOfEdge* distance = new TypeOfEdge[Vers];
	int* prev = new int[Vers];
	bool* known = new bool[Vers];

	int u, sNo;
	edgeNode* p;
	TypeOfEdge min;
	for (int i = 0; i < Vers; ++i)
	{
		known[i] = false;
		distance[i] = noEdge;
	}
	
	sNo = find(start);
	distance[sNo] = 0;
	prev[sNo] = sNo;

	for (int i = 1; i < Vers; ++i)
	{
		min = noEdge;
		for (int j = 0; j < Vers; ++j)
		{
			if (!known[j] && distance[j] < min)
			{
				min = distance[j];
				u = j;
			}
		}
		known[u] = true;
		for (p = verList[u].head; p != NULL; p = p->next)
		{
			if (!known[p->end] && distance[p->end] > min + p->weight)
			{
				distance[p->end] = min + p->weight;
				prev[p->end] = u;
			}
		}
	}

	for (int i = 0; i < Vers; ++i)
	{
		cout << "Shorted path from " << start << " to " << verList[i].ver << " is: " << endl;
		printPath(sNo, i, prev);
		cout << "\tdistance: " << distance[i] << endl;
	}
}

template<class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::printPath(int start, int end, int prev[]) const
{
	if (start == end)
	{
		cout << verList[start].ver;
		return;
	}
	printPath(start, prev[end], prev);
	cout << "-" << verList[end].ver;
}
