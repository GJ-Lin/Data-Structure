#pragma once

#include <fstream>
using namespace std;

class noFile {};

class balance
{
public:
    balance(const char *s);
    int CheckBalance();
private:
    ifstream fin;
    int currentLine;
    int Errors;

    struct Symbol
    {
        char Token;
        int TheLine;
    };

    enum CommentType { SlashSlash, SlashStar };

    bool CheckMatch(char Symb1, char Symb2, int Line1, int Line2);
    char GetNextSymbol();
    void PutBackChar(char ch);
    void SkipComment(enum CommentType type);
    void SkipQuote(char type);
    char NextChar();
};
