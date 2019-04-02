#include "pch.h"
#include "balance.h"
#include "seqStack.h"
#include "seqStack.cpp"
#include <iostream>
using namespace std;

balance::balance(const char *s)
{
    fin.open(s);
    if (!fin) throw noFile();

    currentLine = 1;
    Errors = 0;
}

int balance::CheckBalance()
{
    struct Symbol node;
    seqStack<balance::Symbol> st;
    char LastChar, Match;
    while (LastChar = GetNextSymbol())
    {
        switch (LastChar)
        {
        case '(': case '[': case '{':
            node.Token = LastChar;
            node.TheLine = currentLine;
            st.push(node);
            break;
        case ')': case ']': case '}':
            if (st.isEmpty())
            {
                ++Errors;
                cout << "在第" << currentLine << "行有一个多余的" << LastChar << endl;
            }
            else
            {
                node = st.pop();
                Match = node.Token;
                if (!CheckMatch(Match, LastChar, node.TheLine, currentLine))
                    ++Errors;
            }
            break;
        }
    }
    while (!st.isEmpty())
    {
        ++Errors;
        node = st.pop();
        cout << "第" << node.TheLine << "行的符号" << node.Token << "不匹配\n" << endl;
    }
    return Errors;
}

bool balance::CheckMatch(char Symb1, char Symb2, int Line1, int Line2)
{
    if (Symb1 == '(' && Symb2 != ')' || Symb1 == '[' && Symb2 != ']' || Symb1 == '{' && Symb2 != '}')
    {
        cout << "发现第" << Line2 << "行的符号" << Symb2 << "与第" << Line1 << "行的符号" << Symb1 << "不匹配" << endl;
        return false;
    }
    else
        return true;
}

char balance::GetNextSymbol()
{
    char ch;
    while (ch = NextChar())
    {
        if (ch == '/')
        {
            ch = NextChar();
            if (ch == '*') SkipComment(SlashStar);
            else if (ch == '/') SkipComment(SlashSlash);
            else PutBackChar(ch);
        }
        else if (ch == '\\' || ch == '""') SkipQuote(ch);
        else if (ch == '{' || ch == '[' || ch == '(' || ch == ')' || ch == ']' || ch == '}') return ch;
    }
    return NULL;
}

char balance::NextChar()
{
    char ch;
    if ((ch = fin.get()) == EOF) return NULL;
    if (ch == '\n') ++currentLine;
    return ch;
}

void balance::PutBackChar(char ch)
{
    fin.putback(ch);
    if (ch == '\n') --currentLine;
}

void balance::SkipQuote(char type)
{
    char ch;
    while ((ch = NextChar()))
    {
        if (ch == type) return;
        else if (ch == '\n')
        {
            ++Errors;
            cout << "在第" << currentLine << "行缺少闭括号" << endl;
            return;
        }
        else if (ch == '\\') ch = NextChar();
    }
}

void balance::SkipComment(enum CommentType type)
{
    char ch, flag;

    if (type == SlashSlash)
    {
        while ((ch = NextChar()) && (ch != '\n'));
        return;
    }

    flag = ' ';
    while ((ch = NextChar()) != NULL)
    {
        if (flag == '*' && ch == '/') return;
        flag = ch;
    }
    ++Errors;
    cout << "未结束的注释！" << endl;
}