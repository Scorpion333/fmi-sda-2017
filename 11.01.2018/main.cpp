#include<iostream>
#include"GraphTasks.h"
#include"ReplacingWords.h"
#include"BinTree.h"
using namespace std;

void expect(const char* output) {                   // Useful for short tests
    cout << "\nExpected:\n" << output << "\n\n";
}

void test_bfs_and_dfs() {
    cout << "Testing BFS and DFS.\n\n";
    IntGraph g;             

    for (int vertex : {1, 2, 3, 4, 11, 12, 13, 14}) {       // "For each" syntax. (Since C++11. I use it just for short.)
        AddTop(vertex, g);                                  // It must be clear what's happening here.
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

void test_reading_graph() {                       
    cout << "Testing reading graphs.\n\n";        
                                                  
    IntGraph g;                             // The exmaple graph:
    ifstream in("example1.txt");            // 15 -> 17 18      
    read_graph(g, in);                      // 16 -> 16 17 15
    in.close();                             // 17 -> (nothing)
                                            // 18 -> 15
    g.print();
    expect(                             
        "15 17 18"    "\n"              // "abc" "DEF" "xyz" is the same as "abcDEFxyz".
        "16 16 17 15" "\n"              // This way a string can be written in 2 or more lines.
        "17"          "\n"              // - much more readable if it contains '\n' signs.
        "18 15"       "\n"              // The real (ugly) string is: "15 17 18\n16 16 17 15\n17\n18 15\n"
    );
}

void test_start_and_begin() {
    cout << "Testing 'start and begin' problem.\n";
    replace_start_with_begin("example2.txt");
    cout << "Open example2.txt to see if everything is OK.\n\n";
}

void test_reading_tree() {
    cout << "Testing reading tree.\n\n";
    BinTree<int> tree = tree_from_str("(5(100(200()())(300()()))(6()()))");
    tree.print();
    expect("200 100 300 5 6");
}

int main() {
    test_bfs_and_dfs();
    // test_reading_graph();
    // test_start_and_begin();
    // test_reading_tree();
    return 0;
}