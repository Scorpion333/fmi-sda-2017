#pragma once
#include<iostream>
#include<queue>
#include"LList.h"
using std::cin;
using std::cout;
using std::queue;

typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

elem_link<int>* Point(int a, IntGraph &g)
{
    g.IterStart();
    elem_link<IntList>*p;
    elem_link<int> *q;
    do
    {
        p = g.Iter();
        p->inf.IterStart();
        q = p->inf.Iter();
    } while (q->inf != a);
    return q;
}

void AddTop(int a, IntGraph &g)
{
    IntList l;
    l.ToEnd(a);
    g.ToEnd(l);
}
void AddRib(int a, int b, IntGraph &g)
{
    elem_link<int> * q = Point(a, g), *p;
    while (q->link) q = q->link;
    p = new elem_link<int>;
    p->inf = b;
    p->link = NULL;
    q->link = p;
}

void create_graph(IntGraph &g)
{
    char c;
    do
    {
        cout << "top_of_graph: ";
        int x; cin >> x;
        AddTop(x, g);
        cout << "Top y/n? "; cin >> c;
    } while (c == 'y');
    cout << "Ribs:\n";
    do
    {
        cout << "start top: ";
        int x; cin >> x;
        cout << "end top: ";
        int y; cin >> y;
        AddRib(x, y, g);
        cout << "next: y/n? "; cin >> c;
    } while (c == 'y');
}

void LList<IntList>::print()
{
    elem_link<IntList> *p = this->getStart();
    while (p)
    {
        p->inf.print();
        p = p->link;
    }
    cout << endl;
}

// Returns the list of v's neighbours
IntList& list_of(int v, IntGraph& g) {
    elem_link<IntList>* ptr = g.getStart();
    while (ptr->inf.getStart()->inf != v) {
        ptr = ptr->link;
    }
    return ptr->inf;
}

// Works for connected graph
void print_bfs(IntGraph& g) {
    queue<int> q;
    IntList visited;
    q.push(g.getStart()->inf.getStart()->inf);

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (!visited.hasElement(n)) {
            cout << n << ' ';
            visited.ToEnd(n);
        }
        IntList& list_of_n = list_of(n, g);
        elem_link<int>* ptr = list_of_n.getStart();
        while (ptr) {
            if (!visited.hasElement(ptr->inf)) {
                q.push(ptr->inf);
            }
            ptr = ptr->link;
        }
    }
}

// Works for connected graph
void print_dfs(IntGraph& g, int start, IntList& visited) {
    IntList& list_of_start = list_of(start, g);

    cout << start << ' ';
    visited.ToEnd(start);

    elem_link<int>* ptr = list_of_start.getStart();
    while (ptr) {
        if (!visited.hasElement(ptr->inf)) {
            print_dfs(g, ptr->inf, visited);
        }
        ptr = ptr->link;
    }
}

void print_dfs(IntGraph& g) {
    IntList visited;
    int start = g.getStart()->inf.getStart()->inf;
    print_dfs(g, start, visited);
}
