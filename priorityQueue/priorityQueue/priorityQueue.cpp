#include <iostream>
#include <ctime>
#include "priorityQueue.h"
#include "pQueue.cpp"
using namespace std;

int randint(int min, int max)
{
	return min + rand() % (max - min + 1);
}

int main()
{
	srand(time(NULL));
	int arr[100];
	for (int i = 0; i < 10; ++i)
		arr[i] = randint(1, 99);
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << ' ';
	cout << endl;

	priorityQueue<int> pq(arr, 10);
	for (int i = 0; i < 10; ++i)
		cout << pq.deQueue() << ' ';
	cout << endl;
	
	return 0;
}