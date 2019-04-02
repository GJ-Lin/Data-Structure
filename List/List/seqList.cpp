#include "pch.h"
#include "seqList.h"
#include <iostream>

using namespace std;

template <class elemType>
seqList<elemType>::seqList(int initSize)
{
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}

template <class elemType>
void seqList<elemType>::clear()
{
	currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const
{
	return currentLength;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
	if (currentLength == maxSize) doubleSpace();
	for (int j = currentLength; j > i; --j)
		data[j] = data[j - 1];
	data[i] = x;
	++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
	for (int j = i; j < currentLength - 1; ++j)
		data[j] = data[j + 1];
	--currentLength;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const
{
	int i;
	for (i = 0; i < currentLength && data[i] != x; ++i);
	if (i == currentLength) return -1;
	else return i;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const
{
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const
{
	for (int i = 0; i < currentLength; ++i)
		cout << data[i] << ' ';
	cout << endl;
}

template <class elemType>
void seqList<elemType>::erase(int i)
{
	elemType tmp = data[i];
	int count = 0;
	for (int j = 0; j < currentLength; ++j)
	{
		if (data[i] == tmp) ++count;
		else data[j - count] = data[j];
	}
	currentLength -= count;
}

template <class elemType>
void seqList<elemType>::test()
{
	seqList<int> sl;
	for (int i = 0; i < 20; ++i)
		sl.insert(i, i * 2);
	cout << sl.length() << endl;
	sl.traverse();
	sl.remove(5);
	cout << sl.length() << endl;
	sl.traverse();
	sl.insert(8, 66);
	cout << sl.length() << endl;
	sl.traverse();
	cout << sl.search(4) << endl;
	cout << sl.search(3) << endl;
	cout << sl.visit(12) << endl;
	sl.clear();
	cout << sl.length() << endl;
	sl.traverse();
}

template <class elemType>
seqList<elemType>::~seqList()
{
	delete[] data;
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType *tmp = data;
	maxSize *= 2;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; ++i)
		data[i] = tmp[i];
	delete[] tmp;
}
