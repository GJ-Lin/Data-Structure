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
            cout << "请输入文件名：";
            cin >> filename;
            p = new balance(filename);
            result = p->CheckBalance();
            delete p;
            cout << "共" << result << "个错误" << endl;
            return 0;
        }
        while (--argc)
        {
            cout << "检查文件" << *++argv << endl;
            p = new balance(*argv);
            result = p->CheckBalance();
            delete p;
            cout << "共" << result << "个错误" << endl;
        }
    }
    catch (noFile)
    {
        cout << "未找到文件" << endl;
    }

    return 0;
}