#include<iostream>
#include"GraphTasks.h"
using std::cout;

void expect(const char* output) {                   // Useful for short tests
    cout << "\nExpected:\n" << output << "\n\n";
}

void test_graph() {
    cout << "Testing the graph.\n\n";
    IntGraph g;             

    for (int vertex : {1, 2, 3, 4, 11, 12, 13, 14}) {   // "For each" syntax. (Since C++11. I use it just for short.)
        AddTop(vertex, g);                              // It must be clear what's happening here.
    }                                                   
    AddRib(1, 2, g);            // The created graph:
    AddRib(1, 3, g);            // 1 -> 2, 3
                                // 2 -> 2, 3, 4
    AddRib(2, 2, g);            // 3 -> 12, 14
    AddRib(2, 3, g);            // 4 -> 11
    AddRib(2, 4, g);            // 11 -> (nothing)
                                // 12 -> 13
    AddRib(3, 12, g);           // 13 -> (nothing)
    AddRib(3, 14, g);           // 14 -> 12

    AddRib(4, 11, g);  
    AddRib(12, 13, g);
    AddRib(14, 12, g);

    print_bfs(g);
    expect("1 2 3 4 12 14 11 13");
    print_dfs(g);
    expect("1 2 3 12 13 14 4 11");
}

int main() {
    test_graph();

    return 0;
}