#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// Chain representation of binary tree.
// The root, as it must be the first element added to the tree, has index 0 in 'values' 

template<typename T>
class ChainTree {
    vector<T> values;
    vector<int> left;       //  left[i] is the index (in 'values') of the  left child of values[i]. (-1 if there's no  left child)
    vector<int> right;      // right[i] is the index (in 'values') of the right child of values[i]. (-1 if there's no right child)

public:
    bool empty() const {
        return values.empty();
    }
    int size() const {
        return values.size();
    }
    
    int index_for_position(string position) const {
        int index = 0;
        for (int i = 0; i < position.length(); i++) {
            if (position[i] == 'L')
                index = left[index];
            else
                index = right[index];
        }
        return index;
    }

    // position - string of type "LRLRR..."
    void add(T x, string position) {
        values.push_back(x);            // For sure, we add x in the tree
        left.push_back(-1);
        right.push_back(-1);

        int index_of_x = size() - 1;

        if (index_of_x == 0) {
            return;                     // x is the root. We are ready.
        }

        char last_symbol = position.back();                 // .back() returns the last symbol in a string
        position.pop_back();                                // .pop_back() removes the last symbol from a string
        int parent_index = index_for_position(position);    // Now 'position' is the position of x's parent

        if (last_symbol == 'L')
            left[parent_index] = index_of_x;
        else
            right[parent_index] = index_of_x;
    }

    T operator[](string position) const {
        return values[index_for_position(position)];
    }

    void print_bfs() {
        if (values.empty()) {
            return;
        }
        queue<int> q;           // Queue of the indexes of waiting elements
        q.push(0);              // We start from the root - index 0

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            cout << values[i] << ' ';
            if ( left[i] != -1)  q.push( left[i]);
            if (right[i] != -1)  q.push(right[i]);
        }
    }

    // DFS == "root-left-right"
    void print_dfs() const {
        if (!values.empty())
            print_dfs_subtree(0);
    }

private:
    void print_dfs_subtree(int root_index) const {
        if (root_index == -1) {
            return;
        }
        cout << values[root_index] << ' ';          // Change the order of 
        print_dfs_subtree(left[root_index]);            // these 3 lines to change 
        print_dfs_subtree(right[root_index]);           // the order of print.
    }
};