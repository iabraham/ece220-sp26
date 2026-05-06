#include <cstdio>

struct node {
  int data;
  struct node *left;
  struct node *right;
  node() : data(0), left(nullptr), right(nullptr) {};
  node(int d) : data(d), left(nullptr), right(nullptr) {};
  node(int d, node *l, node *r) : data(d), left(l), right(r) {};
};

void tree_print(node *cursor, int depth) {
  if (cursor == nullptr)
    return;
  for (int i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");
  printf("%d\n", cursor->data);
  tree_print(cursor->left, depth + 1);
  tree_print(cursor->right, depth + 1);
}
bool is_bst(node *cursor, node *&prev) {
  if (cursor == NULL)
    return true;

  bool left = is_bst(cursor->left, prev);

  if (prev != NULL && cursor->data <= prev->data)
    return false;

  prev = cursor;
  bool right = is_bst(cursor->right, prev);

  return (left && right);
}

bool is_bst(node *cursor) {
  node *prev = nullptr;
  return is_bst(cursor, prev);
}
