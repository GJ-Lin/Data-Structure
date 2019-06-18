#include <iostream>
#include "Btree.h"
#include "Btree.cpp"
using namespace std;

int main()
{
	Btree<int, 3, 3> bt;
	char order;
	int x;
	while (cin >> order)
	{
		cin >> x;
		if (order == 'i')
			bt.insert(x);
		else if (order == 'q')
			cout << bt.find(x) << endl;
		else if (order == 'e')
			bt.remove(x);
	}
	return 0;
}