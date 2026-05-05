#include <iostream>

using namespace std;

typedef struct node {
  int data;
  struct node *next;
  node() : data(-1), next(NULL) {};
  node(int d) : data(d), next(NULL) {};
  node(int d, node *n) : data(d), next(n) {};
} node;

void print_circlist(node *head) {
  /*If null do nothing */
  if (head == nullptr) {
    return;
  }

  /* Set temp to head */
  node *temp = head;

  /* Print the list until we reach head again */
  do {
    cout << temp->data << "->";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

node *sortedInsert(node *head, int data) {
  // Create the new node with the given data
  node *newNode = new node(data);

  // If linked list is empty
  if (head == nullptr) {
    /* Node points to itself */
    newNode->next = newNode;
    head = newNode;
    return head;
  }

  node *curr = head;
  node *nextToCurr = head->next;

  // Insert at the beginning if data is less
  // than or equal to head's data
  if (data <= head->data) {
    node *lastNode = head;
    // Find the last node
    while (lastNode->next != head) {
      lastNode = lastNode->next;
    }

    // Set new node's next to head
    newNode->next = head;

    // Update last node's next to new node
    lastNode->next = newNode;

    // Update head to new node
    head = newNode;

    return head;
  }

  // Insert in the middle of the list
  while (curr->next != head) {
    if (curr->data < data && nextToCurr->data >= data) {
      // Set new node's next to current's next
      newNode->next = curr->next;

      // Set current's next to inserted node & return
      curr->next = newNode;

      return head;

    } else {
      // Move to the next node
      curr = curr->next;
      nextToCurr = nextToCurr->next;
    }
  }

  // Fell through -- so must insert at the end of the list
  newNode->next = head;
  curr->next = newNode;
  return head;
}

int main() {
  node *head = nullptr;
  head = sortedInsert(head, 5);
  head = sortedInsert(head, 6);
  head = sortedInsert(head, 8);
  head = sortedInsert(head, 3);
  head = sortedInsert(head, 7);
  head = sortedInsert(head, 4);

  print_circlist(head);
}
