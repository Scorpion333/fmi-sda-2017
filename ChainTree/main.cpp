#include"ChainTree.h"

void expect(const char* output) {
    cout << "\nExpected:\n" << output << "\n\n";
}

void test_chain_tree() {
    ChainTree<int> tree;
    tree.add(5, "");
    tree.add(100, "L");
    tree.add(200, "LL");
    tree.add(300, "LR");
    tree.add(6, "R");

    cout << "BFS:\n";
    tree.print_bfs();
    expect("5 100 6 200 300");

    cout << "DFS:\n";
    tree.print_dfs();
    expect("5 100 200 300 6");

    cout << "Operator[]:\n";
    for (string position : { "", "L", "LL", "LR", "R" }) {
        cout << tree[position] << ' ';
    }
    expect("5 100 200 300 6");
}

int main() {
    test_chain_tree();
    return 0;
}