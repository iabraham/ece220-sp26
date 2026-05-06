#include <iostream>

using namespace std;

/* Properly tempalte this tree data structure */

template <typename T> struct node {
  T data;
  struct node<T> *left;
  struct node<T> *right;
  node(T d) : data(d), left(nullptr), right(nullptr) {};
  node(T d, node<T> *l, node<T> *r) : data(d), left(l), right(r) {};

  friend ostream &operator<<(ostream &ops, const node<T> &n) {
    ops << n.data;
    return ops;
  }
};

/* Properly template this print function */
template <typename T> void tree_print(node<T> *cursor, int depth) {
  if (cursor == nullptr)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  cout << *cursor << endl;
  tree_print(cursor->left, depth + 1);
  tree_print(cursor->right, depth + 1);
}
