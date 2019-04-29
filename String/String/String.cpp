#include "pch.h"
#include <iostream>
#include "linkString.h"
using namespace std;


int main()
{
	linkString str1 = "Hello, SJTU! ", str2 = "Hello, THU! ", str3;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << (str1 == str2) << endl;
	cout << (str1 > str2) << endl;
	cout << (str1 < str2) << endl;
	cout << (str1 >= str2) << endl;
	cout << (str1 <= str2) << endl;
	cout << (str1 != str2) << endl;
	str3 = str1 + str2;
	cout << str3 << endl;
	return 0;
}
