#include "is_bst.hpp"
#include <iostream>

using namespace std;

int main() {
  node *left, *right;
  left = new node(6);
  right = new node(7, left, NULL);
  left = new node(4);
  left = new node(5, left, right);
  right = new node(9);
  right = new node(8, left, right);
  left = new node(1);
  left = new node(2, left, NULL);
  node *root = new node(3, left, right);

  tree_print(root, 0);
  node *prev = NULL;

  if (is_bst(root, prev))
    cout << "Tree is BST";
  else
    cout << "Tree is not BST";
  return 0;
}
