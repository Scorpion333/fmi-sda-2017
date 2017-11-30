#include<iostream>
#include<stack>
#include"LList.h"
#include"Botanic1.h"
#include"Graph.h"
#include"Train.h"
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

void testTrain() {
    PStack stack1({ "Ivan", "Petar", "Georgi" });           // Yeah, this is OK - almost all built-in structures (stack, queue, vector, ...)
    PStack stack2({ "Maria", "Elena" });                    // can be initialized with their elements between {}
    
    PStack stack3;                                          // This stack is empty
    
    PQueue q1({ "Gabriela", "Aleks" });
    PQueue q2({ "Dimitar", "Teadora", "Nikolai", "Ani" });  // The names are random

    Train train({ stack1, stack2, stack3 }, { q1, q2 });    // I hope it's obvious what's happening here  
    train.distribute();
    train.print();
}

int main() {

    cout << "   Testing LList...\n\n";
    testLList();                    // Expected output: 1001
    cout << "\n\n";

    cout << "   Testing Graph...\n\n";
    testGraph();
    cout << '\n';

    cout << "   Testing Train...\n\n";
    testTrain();
    cout << '\n';

    return 0;
}