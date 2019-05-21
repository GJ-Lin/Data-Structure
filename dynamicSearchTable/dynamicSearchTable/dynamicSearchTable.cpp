#include <iostream>
#include "SET.h"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
#include "AvlTree.h"
#include "AvlTree.cpp"
using namespace std;

void BinarySearchTreeTest()
{
	SET<int, char>a[] = { {10, 'a'}, {8, 'b'}, {21, 'c'}, {87, 'd'}, {56, 'e'}, {4, 'f'}, {11, 'g'}, {3, 'h'}, {22, 'i'}, {7, 'j'} };
	BinarySearchTree<int, char> tree;
	SET<int, char> x;
	SET<int, char>* p;

	for (int i = 0; i < 10; ++i) tree.insert(a[i]);

	p = tree.find(56);
	if (p) cout << "find 56 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	tree.remove(56);
	p = tree.find(56);
	if (p) cout << "find 56 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	p = tree.find(21);
	if (p) cout << "find 21 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	tree.remove(21);
	p = tree.find(21);
	if (p) cout << "find 21 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	x.key = 30;
	x.other = 'z';
	tree.insert(x);
	p = tree.find(30);
	if (p) cout << "find 30 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;
}

void AvlTreeTest()
{
	SET<int, char>a[] = { {10, 'a'}, {8, 'b'}, {21, 'c'}, {87, 'd'}, {56, 'e'}, {4, 'f'}, {11, 'g'}, {3, 'h'}, {22, 'i'}, {7, 'j'} };
	AvlTree<int, char> tree;
	SET<int, char> x;
	SET<int, char>* p;

	for (int i = 0; i < 10; ++i)
		tree.insert(a[i]);
	
	p = tree.find(56);
	if (p) cout << "find 56 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	tree.remove(56);
	p = tree.find(56);
	if (p) cout << "find 56 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;
	
	p = tree.find(21);
	if (p) cout << "find 21 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	tree.remove(21);
	p = tree.find(21);
	if (p) cout << "find 21 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;

	x.key = 30;
	x.other = 'z';
	tree.insert(x);
	p = tree.find(30);
	if (p) cout << "find 30 is " << p->key << " " << p->other << endl;
	else cout << "not found" << endl;
}
int main()
{
	//BinarySearchTreeTest();
	//AvlTreeTest();
	return 0;
}