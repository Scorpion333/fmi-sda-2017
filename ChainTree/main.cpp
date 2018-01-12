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

    tree.print();
    expect("5 100 200 300 6");

    for (string position : { "", "L", "LL", "LR", "R" }) {
        cout << tree[position] << ' ';
    }
    expect("5 100 200 300 6");
}

int main() {
    test_chain_tree();
    return 0;
}