#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Tree
{
    Tree* left;
    Tree* right;
    int num;
};

void add(Tree** t, int n)
{
    if (!(*t))
    {
        (*t) = new Tree;
        (*t)->num = n;
        (*t)->left = (*t)->right = nullptr;
        return;
    }
    if (n < (*t)->num)
        add(&(*t)->left, n);
    else
        add(&(*t)->right, n);
}

void show(Tree** t, int level)
{
    if (!(*t))
        return;
    for (int i(0); i < level; i++)
        cout << "   ";
    cout << (*t)->num << endl;
    show(&(*t)->left, level - 1);
    show(&(*t)->right, level + 1);
}