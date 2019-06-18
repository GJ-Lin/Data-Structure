#pragma once
#include <iostream>
using namespace std;
template <class T, int idxSize, int dataBlkSize>
class Btree
{
	struct idxNode
	{
		int type;
		T key[idxSize - 1];
		void* idx[idxSize];
		int len;
		idxNode() : len(1) {}
	};

	struct dataNode
	{
		int len;
		T record[dataBlkSize];
		dataNode() : len(1) {}
	};
	idxNode* root;
public:
	Btree() : root(NULL) {};
	//~Btree() { makeEmpty(root); }
	bool find(const T& x);
	void insert(const T& x);
	void remove(const T& x);
private:
	void makeEmpty(idxNode* t);
	bool find(const T& x, idxNode* t);
	bool findData(const T& x, dataNode* t);
	void remove(const T& x, idxNode* t);
	void removeData(const T& x, dataNode* t);
	idxNode* insert(const T& x, idxNode* t);
	dataNode* insertData(const T& x, dataNode* t);
	idxNode* addIdxBlk(idxNode* n, idxNode* t);
	idxNode* addDataBlk(dataNode* n, idxNode* t);
};