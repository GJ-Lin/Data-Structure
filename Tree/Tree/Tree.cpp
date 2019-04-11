#include "pch.h"
#include <iostream>
#include "binaryTree.h"
#include "binaryTree.cpp"
using namespace std;

int main()
{
    binaryTree<char> bt;
    bt.createTree('@');
    bt.preOrder();
    bt.midOrder();
    bt.postOrder();
    bt.levelOrder();
    printTree(bt, '@');
    bt.delLeft('L');
    bt.delLeft('C');
    bt.delRight('C');
    printTree(bt, '@');
    return 0;
}
