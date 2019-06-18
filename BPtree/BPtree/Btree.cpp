#include "Btree.h"


template<class T, int idxSize, int dataBlkSize>
bool Btree<T, idxSize, dataBlkSize>::find(const T& x)
{
	if (root == NULL) return false;
	return find(x, root);
}

template<class T, int idxSize, int dataBlkSize>
inline void Btree<T, idxSize, dataBlkSize>::insert(const T& x)
{
	if (root == NULL)
	{
		root = new idxNode;
		root->type = 1;
		root->idx[0] = new dataNode;
		dataNode* p = (dataNode*)root->idx[0];
		p->record[0] = x;
		return;
	}

	idxNode* p = insert(x, root);
	if (p != NULL)
	{
		idxNode* t = root;
		root = new idxNode;
		root->type = 0;
		root->len = 2;
		root->idx[0] = t;
		root->idx[1] = p;
		while (p->type == 0) p = (idxNode*)p->idx[0];
		dataNode* d = (dataNode*)p->idx[0];
		root->key[0] = d->record[0];
	}
}

template<class T, int idxSize, int dataBlkSize>
void Btree<T, idxSize, dataBlkSize>::remove(const T& x)
{
	if (root == NULL) return;
	remove(x, root);
}

template<class T, int idxSize, int dataBlkSize>
bool Btree<T, idxSize, dataBlkSize>::find(const T& x, idxNode* t)
{
	int i;
	for (i = 0; i < t->len - 1; ++i)
		if (x < t->key[i]) break;

	if (t->type == 0) return find(x, (idxNode*)t->idx[i]);
	else return findData(x, (dataNode*)t->idx[i]);
}

template<class T, int idxSize, int dataBlkSize>
bool Btree<T, idxSize, dataBlkSize>::findData(const T& x, dataNode* t)
{
	for (int i = 0; i < t->len; ++i)
		if (x == t->record[i])
			return true;
	return false;
}

template<class T, int idxSize, int dataBlkSize>
void Btree<T, idxSize, dataBlkSize>::remove(const T& x, idxNode* t)
{
	int i;
	for (i = 0; i < t->len - 1; ++i)
		if (x < t->key[i]) break;

	if (t->type == 0) remove(x, (idxNode*)t->idx[i]);
	else removeData(x, (dataNode*)t->idx[i]);
}

template<class T, int idxSize, int dataBlkSize>
void Btree<T, idxSize, dataBlkSize>::removeData(const T& x, dataNode* t)
{
	for (int i = 0; i < t->len; ++i)
		if (x == t->record[i])
		{
			for (int j = i; j < t->len; ++j)
				t->record[j] = t->record[j + 1];
			--(t->len);
			return;
		}
}

template<class T, int idxSize, int dataBlkSize>
typename Btree<T, idxSize, dataBlkSize>::idxNode* Btree<T, idxSize, dataBlkSize>::insert(const T& x, idxNode* t)
{
	void* newNode;

	int i;
	for (i = 0; i < t->len - 1; ++i)
		if (x < t->key[i]) break;

	if (t->type == 0) newNode = insert(x, (idxNode*)t->idx[i]);
	else newNode = insertData(x, (dataNode*)t->idx[i]);

	if (newNode == NULL) return NULL;
	else
	{
		if (t->type == 0) return addIdxBlk((idxNode*)newNode, t);
		else return addDataBlk((dataNode*)newNode, t);
	}
}

template<class T, int idxSize, int dataBlkSize>
typename Btree<T, idxSize, dataBlkSize>::dataNode* Btree<T, idxSize, dataBlkSize>::insertData(const T& x, dataNode* t)
{
	for (int i = 0; i < t->len; ++i)
		if (t->record[i] == x) return NULL;

	if (t->len < dataBlkSize)
	{
		int i;
		for (i = t->len; i > 0 && x < t->record[i - 1]; --i)
			t->record[i] = t->record[i - 1];
		t->record[i] = x;
		++(t->len);
		return NULL;
	}

	dataNode* newNode = new dataNode;
	int i, j;
	int max = dataBlkSize / 2;
	newNode->len = max + 1;
	for (i = max, j = dataBlkSize - 1; i >= 0 && t->record[j] > x; --i)
		newNode->record[i] = t->record[j--];
	if (i >= 0) newNode->record[i--] = x;
	for (; i >= 0; --i) newNode->record[i] = t->record[j--];

	t->len = dataBlkSize - max;
	if (j < t->len - 1)
	{
		for (; j >= 0 && x < t->record[j]; --j)
			t->record[j + 1] = t->record[j];
		t->record[j + 1] = x;
	}
	return newNode;
}

template<class T, int idxSize, int dataBlkSize>
typename Btree<T, idxSize, dataBlkSize>::idxNode* Btree<T, idxSize, dataBlkSize>::addIdxBlk(idxNode* newNode, idxNode* t)
{
	idxNode* p = newNode;

	while (p->type == 0) p = (idxNode*)p->idx[0];
	dataNode* d = (dataNode*)p->idx[0];
	T min = d->record[0];

	if (t->len < idxSize)
	{
		int i;
		for (i = t->len - 1; i > 0 && min < t->key[i - 1]; --i)
		{
			t->key[i] = t->key[i - 1];
			t->idx[i + 1] = t->idx[i];
		}
		t->idx[i + 1] = newNode;
		t->key[i] = min;
		++(t->len);
		return NULL;
	}

	idxNode* newIdx = new idxNode;
	newIdx->type = 0;
	int max = idxSize / 2;
	newIdx->len = max + 1;
	int i, j;
	
	if (min > t->key[idxSize - 2])
	{
		newIdx->key[max - 1] = min;
		newIdx->idx[max] = newNode;
	}
	else
	{
		newIdx->key[max - 1] = t->key[idxSize - 2];
		newIdx->idx[max] = t->idx[idxSize - 1];
		int i;
		for (i = t->len - 2; i > 0 && min < t->key[i - 1]; --i)
		{
			t->key[i] = t->key[i - 1];
			t->idx[i + 1] = t->idx[i];
		}
		t->key[i] = min;
		t->idx[i + 1] = newNode;
	}

	for (i = max - 1, j = idxSize - 1; i > 0; --i, --j)
	{
		newIdx->idx[i] = t->idx[j];
		newIdx->key[i - 1] = t->key[j - 1];
	}
	newIdx->idx[0] = t->idx[j];

	t->len = idxSize - max;
	return newIdx;
}

template<class T, int idxSize, int dataBlkSize>
typename Btree<T, idxSize, dataBlkSize>::idxNode* Btree<T, idxSize, dataBlkSize>::addDataBlk(dataNode* newNode, idxNode* t)
{
	if (t->len < idxSize)
	{
		int i;
		for (i = t->len - 1; i > 0 && newNode->record[0] < t->key[i - 1]; --i)
		{
			t->key[i] = t->key[i - 1];
			t->idx[i + 1] = t->idx[i];
		}
		t->key[i] = newNode->record[0];
		t->idx[i + 1] = newNode;
		++(t->len);
		return NULL;
	}

	idxNode* newIdx = new idxNode;
	newIdx->type = 1;
	int max = idxSize / 2;
	newIdx->len = max + 1;
	int i, j;

	if (newNode->record[0] > t->key[idxSize - 2])
	{
		newIdx->key[max - 1] = newNode->record[0];
		newIdx->idx[max] = newNode;
	}
	else
	{
		newIdx->key[max - 1] = t->key[idxSize - 2];
		newIdx->idx[max] = t->idx[idxSize - 1];
		int i;
		for (i = t->len - 2; i > 0 && newNode->record[0] < t->key[i - 1]; --i)
		{
			t->key[i] = t->key[i - 1];
			t->idx[i + 1] = t->idx[i];
		}
		t->key[i] = newNode->record[0];
		t->idx[i + 1] = newNode;
	}

	for (i = max - 1, j = idxSize - 1; i > 0; --i, --j)
	{
		newIdx->idx[i] = t->idx[j];
		newIdx->key[i - 1] = t->key[j - 1];
	}
	newIdx->idx[0] = t->idx[j];

	t->len = idxSize - max;
	return newIdx;
}


