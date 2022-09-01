#include <iostream>
using namespace std;

class List {
private:
  int data;
  List *next;

public:
  List(int info) {
    data = info;
    next = NULL;
  }

  void insertlastnode(List *node);
  void removelastnode();
  void traverse();
  void count();
  friend void insertfirstnode(List **ptr);
  friend void removefirstnode(List **ptr);
};

void List::insertlastnode(List *node) {
  List *last = this;
  while (last->next)
    last = last->next;
  last->next = node;
}

void List::removelastnode() {
  int data;
  List *q, *p = this;
  while (p->next) {
    q = p;
    p = p->next;
  }
  q->next = NULL;
  data = p->data;
  delete p;
  cout << "Removed last node: " << data << endl;
}

void List::traverse() {
  List *ptr = this;
  while (ptr) {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
  cout << endl;
}

void List::count() {
  int counter = 0;
  List *ptr = this;
  while (ptr) {
    counter++;
    ptr = ptr->next;
  }
  cout << "Count:" << counter << endl;
}

void insertfirstnode(List **ptr) {
  int data;
  cout << "Enter Data:";
  cin >> data;
  List *newnode = new List(data);

  if (*ptr == NULL)
    *ptr = newnode;
  else {
    newnode->next = *ptr;
    *ptr = newnode;
  }
  cout << "New node: " << newnode->data << " added successfully" << endl;
}

void removefirstnode(List **ptr) {
  int data;
  if (*ptr != NULL) {
    data = (*ptr)->data;
    *ptr = (*ptr)->next;
  }
  cout << "Removed node: " << data << endl;
}

int main() {
  int choice, data;
  List *first = NULL;
  List *newnode;

  while (1) {
    cout << endl << "--Linked List--" << endl;
    cout << "1-Insert last node" << endl;
    cout << "2-Delete last node" << endl;
    cout << "3-Traverse" << endl;
    cout << "4-Count" << endl;
    cout << "5-Insert first node" << endl;
    cout << "6-Delete first node" << endl;
    cout << "Enter Choice:";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case 1:
      cout << "Enter Data:";
      cin >> data;
      newnode = new List(data);
      if (first == NULL)
        first = newnode;
      else
        first->insertlastnode(newnode);
      break;

    case 2:
      first->removelastnode();
      break;

    case 3:
      first->traverse();
      break;

    case 4:
      first->count();
      break;

    case 5:
      insertfirstnode(&first);
      break;

    case 6:
      removefirstnode(&first);
      break;
    }
  }

  return 0;
}