#pragma once
#include<iostream>
#include<fstream>
#include<string> 
#include<vector> 
#include<stack> 
#include<queue> 
#include"LList.h"
using std::cout;
using std::ostream;
using std::string;
using std::vector;
using std::stack;
using std::queue;


typedef string Person;      // It's just easier to work with a string than a gender-age struct

typedef stack<Person> PStack;
typedef queue<Person> PQueue;


class Train {
    LList<PStack> stacks;
    LList<PQueue> qs;

public:
    void distribute() {
        LList<Person> allPeople;
        move_people_from_stacks_to(allPeople);      // Long functions are VERY hard to read and understand
        move_people_from_qs_to(allPeople);          // They'd better be divided into smaller functions
        put_in_stacks_and_qs_again(allPeople);      // It's good when the code looks like English text
    }

    // Helper functions for 'distribute'

    void move_people_from_stacks_to(LList<Person>& allPeople) {
        elem_link<PStack>* p = stacks.getStart();       // Sorry, I find it much more convenient and understandable to work
                                                        // with a pointer, not the 'Iter' methods. The idea is still the same:

        while (p) {                                     // For every stack in 'stacks' we move everything from the stack to 'allPeople'
            while (!p->inf.empty()) {
                allPeople.ToEnd(p->inf.top());
                p->inf.pop();
            }
            p = p->link;
        }
    }

    void move_people_from_qs_to(LList<Person>& allPeople) {
        elem_link<PQueue>* p2 = qs.getStart();          // We do the same with the queues
        while (p2) {
            while (!p2->inf.empty()) {
                allPeople.ToEnd(p2->inf.front());
                p2->inf.pop();
            }
            p2 = p2->link;
        }
    }

    void put_in_stacks_and_qs_again(LList<Person>& allPeople) {
        // TODO: write comments
        elem_link<Person>* person = allPeople.getStart();
        elem_link<PStack>* crrStack = stacks.getStart();
        elem_link<PQueue>* crrQ = NULL;
        bool qs_next = true;

        while (person) {
            if (crrStack) {
                crrStack->inf.push(person->inf);
                crrStack = crrStack->link;
                person = person->link;
            }
            else if (crrQ) {
                crrQ->inf.push(person->inf);
                crrQ = crrQ->link;
                person = person->link;
            }
            else if (qs_next) {
                crrQ = qs.getStart();
                qs_next = false;
            }
            else {
                crrStack = stacks.getStart();
                qs_next = true;
            }
        }
    }


    // For testing
    void print() {
        cout << "\nStacks:\n "; stacks.print();
        cout << "\nQueues:\n "; qs.print();
    }

    Train(const vector<PStack>& _stacks = {}, const vector<PQueue>& _qs = {})
        : stacks(), qs() {
        unsigned i;
        for (i = 0; i < _stacks.size(); i++) stacks.ToEnd(_stacks[i]);
        for (i = 0; i < _qs.size(); i++) qs.ToEnd(_qs[i]);
    }
};


// For testing - std::stack and std::queue have no operator << in the standard library
template<typename T>
ostream& operator << (ostream& out, stack<T> st) {
    while (!st.empty()) {
        out << ' ' << st.top();
        st.pop();
    }
    return out << '\n';
}

template<typename T>
ostream& operator << (ostream& out, queue<T> q) {
    while (!q.empty()) {
        out << ' ' << q.front();
        q.pop();
    }
    return out << '\n';
}
