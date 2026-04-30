#include "person.hpp"
#include "tree_template.hpp"
#include <iostream>

typedef node<Person> inode;

int main() {
  inode *left, *right;
  left = new inode(Person("Alice", 65));
  right = new inode(Person("Bob", 67), left, (inode *)nullptr);
  left = new inode(Person("Rick", 68));
  left = new inode(Person("Susan", 65), left, right);

  right = new inode(Person("Mike", 69));
  right = new inode(Person("Matt", 68), left, right);

  left = new inode(Person("Damon", 71));
  left = new inode(Person("Mark", 72), left, (inode *)nullptr);
  inode *root = new inode(Person("Johnny", 73), left, right);

  tree_print(root, 0);
}
