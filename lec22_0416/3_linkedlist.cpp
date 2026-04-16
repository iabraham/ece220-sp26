#include <iostream>
using namespace std;

template <typename T> class Node {
  T data;

public:
  Node<T> *next;
  Node(T inval) {
    data = inval;
    next = NULL;
  }
  void print() { cout << data; }
};

template <class H> class LinkedList {
  Node<H> *head;

public:
  LinkedList() { this->head = NULL; }

  void print_list() {
    Node<H> *cursor = head;
    while (cursor) {
      cursor->print();
      cout << "->";
      cursor = cursor->next;
    }
  }

  void add_at_head(H p) {
    Node<H> *newitem = new Node<H>(p);
    newitem->next = head;
    head = newitem;
  }

  ~LinkedList() {
    Node<H> *temp;
    while (head) {
      temp = head;
      head = head->next;
      delete temp;
    }
  }
};

int main() {
  LinkedList<char *> *mylist = new LinkedList<char *>;
  const char *mychars[6] = {"Ivan",  "Petar", "Stojanco",
                            "Danco", "Goran", "Sasho"};
  for (int i = 0; i < 6; i++)
    mylist->add_at_head((char *)mychars[i]);
  mylist->print_list();
  delete mylist;
  return 0;
}
