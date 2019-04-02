#include "pch.h"
#include <iostream>
#include "seqQueue.h"
#include "seqQueue.cpp"
#include "seqQueue_len.h"
#include "seqQueue_len.cpp"
#include "linkQueue.h"
#include "linkQueue.cpp"
#include "linkQueue_cir.h"
#include "linkQueue_cir.cpp"
using namespace std;

void arrange(int *in, int n, int k);
bool putBuffer(linkQueue<int> *buffer, int size, int in);
void checkBuffer(linkQueue<int> *buffer, int size, int &last);
void arrange(int *in, int n, int k)
{
    linkQueue<int> *buffer = new linkQueue<int>[k];
    int last = 0;

    for (int i = 0; i < n; ++i)
    {
        if (!putBuffer(buffer, k, in[i])) return;
        checkBuffer(buffer, k, last);
    }
}

bool putBuffer(linkQueue<int> *buffer, int size, int in)
{
    int avail = -1, max = 0;
    for (int j = 0; j < size; ++j)
    {
        if (buffer[j].isEmpty())
        {
            if (avail == -1) avail = j;
        }
        else if (buffer[j].getTail() < in && buffer[j].getTail() > max)
        {
            avail = j;
            max = buffer[j].getTail();
        }
    }

    if (avail != -1)
    {
        buffer[avail].enQueue(in);
        cout << in << "移入缓冲区" << avail << endl;
        return true;
    }
    else
    {
        cout << "无可行的方案" << endl;
        return false;
    }
}

void checkBuffer(linkQueue<int> *buffer, int size, int &last)
{
    int j;
    int flag = true;

    while (flag)
    {
        flag = false;
        for (j = 0; j < size; ++j)
        {
            if (!buffer[j].isEmpty() && buffer[j].getHead() == last + 1)
            {
                cout << "将" << buffer[j].deQueue() << "从缓冲区" << j << "移到出轨" << endl;
                ++last;
                flag = true;
                break;
            }
        }
    }
}

void testQueue()
{
    linkQueue_cir<int> sq;
    cout << sq.isEmpty() << endl;
    for (int i = 1; i <= 25; ++i)
        sq.enQueue(i);
    cout << sq.isEmpty() << endl;
    while (!sq.isEmpty())
    {
        cout << sq.getHead() << ' ';
        sq.deQueue();
    }
    cout << endl << sq.isEmpty();
}
int main()
{
    int in[9] = { 9, 8, 7, 6, 4, 2, 1, 3, 5 };
    arrange(in, 9, 3);
    return 0;
}


