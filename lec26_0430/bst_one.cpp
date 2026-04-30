#include "is_bst.hpp"
#include <iostream>

using namespace std;

int main() {
  node *left, *right;
  left = new node(7);
  right = new node(8, left, NULL);
  left = new node(3);
  left = new node(5, left, right);
  right = new node(25);
  right = new node(20, new node(18), right);
  node *root = new node(10, left, right);

  tree_print(root, 0);

  if (is_bst(root))
    cout << "Tree is BST";
  else
    cout << "Tree is not BST";
  return 0;
}
