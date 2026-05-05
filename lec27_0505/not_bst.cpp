#include "is_bst.hpp"
#include <iostream>

using namespace std;

int main() {

  node *left, *right;
  left = new node(5);
  right = new node(6);
  right = new node(4, left, right);
  left = new node(3, NULL, right);
  left = new node(2, left, NULL);

  right = new node(11);
  right = new node(8, new node(9, new node(10), right), NULL);
  right = new node(7, NULL, right);
  node *root = new node(1, left, right);

  tree_print(root, 0);
  node *prev = NULL;

  if (is_bst(root, prev))
    cout << "Tree is BST";
  else
    cout << "Tree is not BST";
  return 0;
}
