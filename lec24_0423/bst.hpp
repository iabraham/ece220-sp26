#include <iostream>
#include <vector>

using namespace std;

// Tree node structure
template <typename T> struct treenode {
  T data;
  treenode *left;
  treenode *right;

  // Write constructor that initializes data and sets
  // left/right to nullptr
  treenode(T data) : data(data) {
    this->data = T(data);
    left = nullptr;
    right = nullptr;
  }
};

// Binary Search Tree class
template <class N> class bst {
private:
  typedef treenode<N> node;
  node *root;

  /* Private methods
   These methods take an extra argument 'cursor'
   which is a pointer to the current node
   This way we can hide the root pointer from user
   and still be able to traverse the tree recursively
   using 'cursor' as the current node */

  // Inserts data at the correct position
  void insert(N data, node **cursor) {
    if (*cursor == nullptr) {
      // At leaf position, insert new node here
      *cursor = new node(data);
    } else {
      // Recursive cases
      if (data < (*cursor)->data)
        // Insert in left subtree
        insert(data, &((*cursor)->left));
      else
        // Insert in right subtree
        insert(data, &((*cursor)->right));
    }
  }

  // Returns pointer to node if found, else nullptr
  node *search(N key, node *cursor) {
    if (cursor == nullptr) // Item not found
      return nullptr;
    else if (key == cursor->data) // Item found
      return cursor;
    else if (key < cursor->data)
      // Search left subtree
      return search(key, cursor->left);
    else
      // Search right subtree
      return search(key, cursor->right);
  }

  // Inorder traversal
  void inorder(node *cursor) {
    if (cursor == nullptr)
      return;
    // Recursive cases

    // Visit left subtree
    inorder(cursor->left);
    // Visit node
    cout << "(Node: " << cursor << ", Left: " << cursor->left
         << ", Right: " << cursor->right << ", " << cursor->data << ")" << endl;

    // Visit right subtree
    inorder(cursor->right);
  }

  // Counts number of nodes in tree
  int countnodes(node *cursor) {
    if (cursor == nullptr)
      return 0;
    else
      // Count this node + nodes in left subtree + nodes in right subtree
      return 1 + countnodes(cursor->left) + countnodes(cursor->right);
  }

  // Prints tree structure in human readable form
  void print(node *cursor, int depth) {
    if (cursor == nullptr)
      return;
    for (int i = 0; i < depth; i++)
      printf(i == depth - 1 ? "|-" : "  ");
    cout << cursor->data << endl;
    print(cursor->left, depth + 1);
    print(cursor->right, depth + 1);
  }

  // Computes height of tree
  int height(node *cursor) {
    int lh, rh;
    if (cursor == nullptr)
      // Height of empty tree is -1
      return -1;
    else {
      // Height is max height of left/right subtree + 1
      // Calculate left height
      lh = height(cursor->left) + 1;
      // Calculate right height
      rh = height(cursor->right) + 1;
      // Return max of left/right heights
      return (lh > rh) ? lh : rh;
    }
  }

  // Deletes the tree recursively
  void delete_tree(node *cursor) {
    if (cursor == nullptr)
      return;

    // Recursive cases
    // Delete left subtree
    delete_tree(cursor->left);

    // Delete right subtree
    delete_tree(cursor->right);

    // Delete this node
    delete cursor;
  }

  // Vectorizes the tree in inorder fashion
  // Note: vector of type N is passed by reference
  // to avoid copying the entire vector at each recursive call
  void vectorize(node *cursor, vector<N> &v) {
    if (cursor == nullptr)
      return;

    // Recursive cases

    // Vectorize left subtree
    vectorize(cursor->left, v);

    // Visit this node (use pushback to add to vector)
    v.push_back(cursor->data);

    // Vectorize right subtree
    vectorize(cursor->right, v);
  }

public:
  // Constructor
  bst() { root = nullptr; }

  /* Public methods are wrappers over private methods
  / that hide the root pointer from user */

  // Inserts data at the correct position
  void insert(N data) { insert(data, &root); }

  // Returns pointer to node if found, else nullptr
  treenode<N> *search(N data) { return search(data, root); }

  // Inorder traversal
  void inorder() { inorder(root); }

  // Vectorizes the tree in inorder fashion
  vector<N> *vectorize() {
    // Create new vector of type N
    vector<N> *v = new vector<N>;
    vectorize(root, *v);
    return v;
  }

  // Counts number of nodes in tree
  int node_count() { return countnodes(root); }

  // Computes height of tree
  int height() { return height(root); }

  // Prints tree structure in human readable form
  void print() { print(root, 0); }

  // Destructor
  ~bst() { delete_tree(root); }
};
