#include <iostream>
#include "graph.h"
#include "adjMatrixGraph.h"
#include "adjMatrixGraph.cpp"
#include "adjListGraph.h"
#include "adjListGraph.cpp"
const int MAXINT = 2147483647;
using namespace std;

void testAMG()
{
	adjMatrixGraph<char, int> g(10, "abcdefghuj", -1);
	g.print(); cout << endl;
	g.insert('a', 'f', 9);
	g.print(); cout << endl;
	g.remove('a', 'f');
	g.print(); cout << endl;
}

void testALG()
{
	adjListGraph<char, int> g(10, "abcdefghuj");
	g.print(); cout << endl;
	g.insert('a', 'f', 9);
	g.print(); cout << endl;
	g.remove('a', 'f');
	g.print(); cout << endl;
}

void testSearch()
{
	int vers[7] = { 1, 2, 3, 4, 5, 6, 7 };
	const int weight = 1;
	adjListGraph<int, int> g(7, vers);
	g.insert(1, 2, weight);
	g.insert(2, 3, weight);
	g.insert(2, 4, weight);
	g.insert(3, 1, weight);
	g.insert(4, 1, weight);
	g.insert(4, 3, weight);
	g.insert(5, 6, weight);
	g.insert(5, 7, weight);
	g.insert(6, 2, weight);
	g.insert(7, 4, weight);
	g.insert(7, 6, weight);
	g.print(); cout << endl;
	g.dfs();
	g.bfs();
}

void testTopSort()
{
	int vers[7] = { 1, 2, 3, 4, 5, 6, 7 };
	const int weight = 1;
	adjListGraph<int, int> g(7, vers);
	g.insert(1, 2, weight);
	g.insert(1, 3, weight);
	g.insert(2, 4, weight);
	g.insert(2, 5, weight);
	g.insert(2, 6, weight);
	g.insert(3, 5, weight);
	g.insert(3, 7, weight);
	g.insert(5, 6, weight);
	g.insert(5, 7, weight);
	g.insert(6, 4, weight);
	g.print(); cout << endl;
	g.topSort();
}

void testUSD()
{
	int vers[7] = { 0, 1, 2, 3, 4, 5, 6 };
	const int weight = 1;
	adjListGraph<int, int> g(7, vers);
	g.insert(0, 1, weight);
	g.insert(0, 3, weight);
	g.insert(1, 3, weight);
	g.insert(1, 4, weight);
	g.insert(2, 0, weight);
	g.insert(2, 5, weight);
	g.insert(3, 2, weight);
	g.insert(3, 4, weight);
	g.insert(3, 5, weight);
	g.insert(3, 6, weight);
	g.insert(4, 6, weight);
	g.insert(6, 5, weight);
	g.print(); cout << endl;
	g.unweightedShortDistance(2, MAXINT);
}

void testDijkstra()
{
	int vers[7] = { 0, 1, 2, 3, 4, 5, 6 };
	//const int weight = 1;
	adjListGraph<int, int> g(7, vers);
	g.insert(0, 1, 2);
	g.insert(0, 3, 1);
	g.insert(1, 3, 3);
	g.insert(1, 4, 10);
	g.insert(2, 0, 4);
	g.insert(2, 5, 5);
	g.insert(3, 2, 2);
	g.insert(3, 4, 2);
	g.insert(3, 5, 8);
	g.insert(3, 6, 4);
	g.insert(4, 6, 6);
	g.insert(6, 5, 1);
	g.print(); cout << endl;
	g.dijkstra(1, MAXINT);
}
int main()
{
	//testAMG();
	//testALG();
	//testSearch();
	//testTopSort();
	//testUSD();
	testDijkstra();
	return 0;
}
