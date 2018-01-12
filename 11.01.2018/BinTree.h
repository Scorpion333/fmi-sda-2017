#pragma once

template <class T>
struct node
{
    T inf;
    node<T> *left, *right;
};

template <class T>
class BinTree
{
private:
    node<T> *root;
    void DeleteBinTree(node<T>* &) const;
    void Copy(node<T> * &, node<T>* const&) const;
    void CopyBinTree(BinTree<T> const&);
    void pr(const node<T> *) const;
public:
    BinTree();
    ~BinTree();
    BinTree(BinTree<T> const&);
    BinTree& operator=(BinTree<T> const&);
    void print() const;
    void Create3(T, BinTree<T>, BinTree<T>);
};

template <class T>
BinTree<T>::BinTree()
{
    root = NULL;
}

template <class T>
BinTree<T>::~BinTree()
{
    DeleteBinTree(root);
}

template <class T>
BinTree<T>::BinTree(BinTree<T> const& r)
{
    CopyBinTree(r);
}

template <class T>
BinTree<T>& BinTree<T>::operator=(BinTree<T> const& r)
{
    if (this != &r) {
        DeleteBinTree(root);
        CopyBinTree(r);
    }
    return *this;
}

template <class T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const
{
    if (p)
    {
        DeleteBinTree(p->left);
        DeleteBinTree(p->right);
        delete p;
        p = NULL;
    }
}

template <class T>
void BinTree<T>::CopyBinTree(BinTree<T> const& r)
{
    Copy(root, r.root);
}

template <class T>
void BinTree<T>::Copy(node<T> * & pos, node<T>* const & r) const
{
    pos = NULL;
    if (r)
    {
        pos = new node<T>;
        pos->inf = r->inf;
        Copy(pos->left, r->left);
        Copy(pos->right, r->right);
    }
}

template <class T>
void BinTree<T>::pr(const node<T>*p) const
{
    if (p)
    {
        pr(p->left);
        cout << p->inf << " ";
        pr(p->right);
    }
}

template <class T>
void BinTree<T>::print() const
{
    pr(root);
}

template <class T>
void BinTree<T>::Create3(T x, BinTree<T> l, BinTree<T> r)
{
    root = new node<T>;
    root->inf = x;
    Copy(root->left, l.root);
    Copy(root->right, r.root);
}

// Written by Pepi

BinTree<int> tree_from_str(const string& str) {     // The string is something like:  (5(100(200()())(300()()))(6()()))
    if (str == "()") {                              
        return BinTree<int>();                      // More readable equivalent:   (5 (100 (200 () ())
    }                                               //                                     (300 () ()) )
    string root, left, right;                       //                                (6 () ()) )

    int i = 1;
    while (str[i] != '(') {
        root += str[i];
        i++;
    }

    left = "(";
    int left_br = 1, right_br = 0;          // left and right brackets counters
    i++;
    while (left_br > right_br) {
        if (str[i] == '(') {
            left_br++;
        }
        else if (str[i] == ')') {
            right_br++;
        }
        left += str[i];
        i++;
    }

    for (; i < str.length() - 1; i++) {
        right += str[i];
    }
    int r = stoi(root);                     // stoi("135") returns 135
    BinTree<int> bt;
    bt.Create3(r, tree_from_str(left), tree_from_str(right));
    return bt;
}