#include<iostream>
#include<stack>
#include"LList.h"
#include"Botanic1.h"
#include"Graph.h"
using std::cout;
using std::stack;

typedef LList<int> IntList;

void testLList() {
    LList<int> list;
    list.ToEnd(2);
    list.ToEnd(3);
    list.ToEnd(4);

    cout << list.hasElement(4);
    cout << list.hasElement(5);
    cout << list.hasDuplicate();

    list.ToEnd(3);
    cout << list.hasDuplicate();
}

void testPlant() {
    // TODO
}

void testGraph() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 4);
    g.addVertex(6);
    g.addEdge(7, 8);
    g.addEdge(7, 8);
    g.print();
}

int main() {

    cout << "   Testing LList...\n\n";
    testLList();                    // Expected output: 1001
    cout << "\n\n";

    cout << "   Testing Plant...\n\n";
    testPlant();
    cout << "\n\n";

    cout << "   Testing Graph...\n\n";
    testGraph();

    cout << '\n';
    return 0;
}