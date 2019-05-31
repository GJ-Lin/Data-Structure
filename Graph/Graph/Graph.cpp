#include <iostream>
#include "graph.h"
#include "adjMatrixGraph.h"
#include "adjMatrixGraph.cpp"
#include "adjListGraph.h"
#include "adjListGraph.cpp"
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
int main()
{
	//testAMG();
	//testALG();
	testSearch();
	return 0;
}
