#include <iostream>
#include <ctime>
#include "DisjointSet.h"
#include "Tree.h"
using namespace std;
const int len = 10;

template<class KEY, class OTHER>
struct set
{
	KEY key;
	OTHER other;
	friend bool operator<=(const set<KEY, OTHER>& lf, const set<KEY, OTHER>& rh) { return lf.key <= rh.key; }
	friend bool operator>=(const set<KEY, OTHER>& lf, const set<KEY, OTHER>& rh) { return lf.key >= rh.key; }
	set<KEY, OTHER>& operator=(const set<KEY, OTHER>& rh)
	{
		if (this == &rh) return *this;
		key = rh.key;
		other = rh.other;
		return *this;
	}
};

int randint(int low, int high) { return low + rand() % (high - low + 1); }

template<class KEY, class OTHER>
void qsort(set<KEY, OTHER>* data, int low, int high)
{
	if (low >= high) return;
	set<KEY, OTHER> k = data[low], tmp;
	int lf = low, rh = high;
	while (lf < rh)
	{
		while (lf < rh && data[rh] >= k) --rh;
		while (lf < rh && data[lf] <= k) ++lf;
		if (lf < rh)
		{
			tmp = data[rh];
			data[rh] = data[lf];
			data[lf] = tmp;
		}
	}
	data[low] = data[lf];
	data[lf] = k;
	qsort(data, low, lf - 1);
	qsort(data, rh + 1, high);
}

template<class KEY, class OTHER>
void printset(const set<KEY, OTHER>* data)
{
	for (int i = 1; i <= len; ++i)
		cout << data[i].key << ' ';
	cout << endl;
}

void testDJSet()
{
	DisjointSet djset(15);
	char order[10];
	int i, j, x;
	while (cin >> order)
	{
		if (order[0] == 'f')
		{
			cin >> x;
			cout << djset.Find(x);
		}
		else if (order[0] == 'u')
		{
			cin >> i >> j;
			djset.Union(i, j);
		}
		else if (order[0] == 'q')
			break;
	}
	cout << djset << endl;
}
int main()
{
	Tree t;
	t.create(-1);
	cout << t.LCA(8, 14);
	return 0;
}