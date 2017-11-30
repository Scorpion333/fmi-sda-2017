#pragma once
#include<iostream>
#include"LList.h"
using std::cout;

typedef LList<int> IntList;

// Oriented graph with ints for vertexes
class Graph {
    IntList vs;                     // List of vertexes
    LList<IntList> lists;           // List of adjacency lists

    IntList* listOf(int v) {        // Returns pointer to the adjacency list of 'v'
        elem_link<int>* crrV = vs.getStart();
        elem_link<IntList>* crrList = lists.getStart();
        while (crrV->inf != v) {
            crrV = crrV->link;
            crrList = crrList->link;
        }
                                    // Now 'crrV' points to 'v' in 'vs', crrList points to the list of 'v' in 'lists'
        return &(crrList->inf);     // But 'crrList' is elem_link<IntList>*, so the real list is crrList->inf
    }

public:
    void addVertex(int v) {
        if (vs.hasElement(v)) {
            return;
        }
        vs.ToEnd(v);
        lists.ToEnd(IntList());     // IntList() == LList<int>() == the empty list of ints
    }
    void addEdge(int a, int b) {
        addVertex(a);
        addVertex(b);

        IntList* listOfA = listOf(a);       // I forgot it today, but
        if (!listOfA->hasElement(b)) {      // 'b' should be added only if it's not already there
            listOf(a)->ToEnd(b);
        }
    }

    // For testing
    void print() {
        elem_link<int>* crrV = vs.getStart();
        elem_link<IntList>* crrList = lists.getStart();

        while (crrV) {
            cout << crrV->inf << ": ";
            crrList->inf.print();
            crrV = crrV->link;
            crrList = crrList->link;
        }
    }
};