#include "pch.h"
#include <iostream>
#include "stack.h"
#include "seqStack.h"
#include "seqStack.cpp"
#include "linkStack.h"
#include "linkStack.cpp"
#include "balance.h"

using namespace std;

bool isReverse(char str[])
{
    int len = strlen(str);
    seqStack<char> st(len);

    for (int i = 0; i < len; ++i) st.push(str[i]);
    for (int i = 0; i < len; ++i)
        if (str[i] != st.pop()) return false;
    return true;
}

bool isReverseLS(char *str)
{
    linkStack<char> ls;
    for (int i = 0; str[i] != '\0'; ++i) ls.push(str[i]);
    for (int i = 0; !ls.isEmpty(); ++i)
        if (str[i] != ls.pop()) return false;
    return true;
}

int main(int argc, const char **argv)
{
    char filename[80];
    balance *p;
    int result;

    try
    {
        if (argc == 1)
        {
            cout << "�������ļ�����";
            cin >> filename;
            p = new balance(filename);
            result = p->CheckBalance();
            delete p;
            cout << "��" << result << "������" << endl;
            return 0;
        }
        while (--argc)
        {
            cout << "����ļ�" << *++argv << endl;
            p = new balance(*argv);
            result = p->CheckBalance();
            delete p;
            cout << "��" << result << "������" << endl;
        }
    }
    catch (noFile)
    {
        cout << "δ�ҵ��ļ�" << endl;
    }

    return 0;
}