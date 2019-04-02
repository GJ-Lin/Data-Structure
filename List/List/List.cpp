#include "pch.h"
#include <iostream>
#include "seqList.h"
#include "seqList.cpp"
#include "sLinkList.h"
#include "sLinkList.cpp"
#include "dLinkList.h"
#include "dLinkList.cpp"

using namespace std;

int main()
{
	//seqList<int>::test();
	//sLinkList<int>::test();
	//dLinkList<int>::test();
    sLinkList<int> sll;
    for (int i = 0; i < 10; ++i)
        sll.insert(i, i);
    sll.traverse();
    sll.visit_back(1);
    sll.visit_back(5);
    sll.visit_back(10);
    sll.visit_back(11);
    sll.visit_back(15);
	return 0;
}
