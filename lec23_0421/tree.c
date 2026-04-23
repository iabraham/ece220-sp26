#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Implementation in C
   Functions:
   1. Add left child
   2. Add right child
   3. Preorder Traversal
   4. Inorder Traversal
   5. Postorder Traversal
   6. Delete Tree
   7. Human Readable Print

*/

/* Define the structure for a tree node */
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

/*  Function to add a left child to a given node */
void add_left(node *cursor, int data) {
  /*If left child doesn't exist */
  if (cursor->left == NULL) {
    /* Allocate memory for the new node */
    node *new_node = (node *)malloc(sizeof(node));

    /* Set the data for the new node */
    new_node->data = data;

    /* Initialize left and right children to NULL */
    new_node->left = new_node->right = NULL;

    /* Link the new node as the left child of the cursor */
    cursor->left = new_node;
  } else {
    /* If left child already exists, do nothing */
    return;
  }
}

/*  Function to add a right child to a given node */
void add_right(node *cursor, int data) {
  /*If right child doesn't exist */
  if (cursor->right == NULL) {
    /* Allocate memory for the new node */
    node *new_node = (node *)malloc(sizeof(node));

    /* Set the data for the new node */
    new_node->data = data;

    /* Initialize left and right children to NULL */
    new_node->left = new_node->right = NULL;

    /* Link the new node as the right child of the cursor */
    cursor->right = new_node;
  } else {
    /* If right child already exists, do nothing */
    return;
  }
}

/* Function for Preorder Traversal */
void print_preorder(node *cursor) {
  /* Base case: if the current node is NULL, return */
  if (cursor == NULL) {
    return;
  }

  /* Visit the root node first -- cast to (void *) to
   * prevent warnings from gcc (sometimes) */
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data,
         (void *)cursor, (void *)cursor->left, (void *)cursor->right);

  /* Traverse the left subtree */
  print_preorder(cursor->left);

  /* Traverse the right subtree */
  print_preorder(cursor->right);
}

/* Function for Inorder Traversal */
void print_inorder(node *cursor) {
  /* Base case: if the current node is NULL, return */
  if (cursor == NULL) {
    return;
  }

  /* Traverse the left subtree */
  print_inorder(cursor->left);

  /* Visit the root node first -- cast to (void *) to
   * prevent warnings from gcc (sometimes) */
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data,
         (void *)cursor, (void *)cursor->left, (void *)cursor->right);

  /* Traverse the right subtree */
  print_inorder(cursor->right);
}

/* Function for Postorder Traversal */
void print_postorder(node *cursor) {
  /* Base case: if the current node is NULL, return */
  if (cursor == NULL) {
    return;
  }

  /* Traverse the left subtree */
  print_postorder(cursor->left);

  /* Traverse the right subtree */
  print_postorder(cursor->right);

  /* Visit the root node */
  printf("Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n", cursor->data,
         (void *)cursor, (void *)cursor->left, (void *)cursor->right);
}

/* Function to delete the entire tree */
void delete_tree(node *cursor) {
  /* Base case: if the current node is NULL, return */
  if (cursor == NULL) {
    return;
  }

  /* Recursively delete left and right subtrees */
  delete_tree(cursor->left);
  delete_tree(cursor->right);

  printf("Deleting Node %d: (Address: %p,\t Left:%p, \t Right:%p)\n",
         cursor->data, (void *)cursor, (void *)cursor->left,
         (void *)cursor->right);

  /* Free the emory allocated for the current node */
  free(cursor);
}

/* Function to print the tree in a human-readable format */
void treeprint(node *cursor, int depth) {
  int i;
  /* Base case: if the current node is NULL, return */
  if (cursor == NULL)
    return;

  /* Add indentation based on the depth of the node */
  for (i = 0; i < depth; i++)
    printf(i == depth - 1 ? "|-" : "  ");

  /* Print the data of the current node */
  printf("%d\n", cursor->data);

  /* Recursively print the left and right subtrees */
  treeprint(cursor->left, depth + 1);
  treeprint(cursor->right, depth + 1);
}

int main(void) {
  int i, j, arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  node *cursor;
  node *root = (node *)malloc(sizeof(node));
  root->data = arr[0];
  root->left = NULL;
  root->right = NULL;
  cursor = root;

  for (j = 0, i = 1; i < 11; i = i + 2, j++) {
    add_left(cursor, arr[i]);
    add_right(cursor, arr[i + 1]);
    cursor = (j % 2 == 0) ? cursor->right : cursor->left;
  }
  // printf("==================PREORDER=====================\n");
  // print_preorder(root);
  // printf("===================INORDER===================\n");
  // print_inorder(root);
  printf("=================POSTORDER======================\n");
  print_postorder(root);
  printf("==================HUMAN READABLE===============\n");
  treeprint(root, 0);
  delete_tree(root);
}
