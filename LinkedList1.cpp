//  ASSIGNMENT Linked List

#include<iostream>

using namespace std;
class Node {

  int data;
  Node * next;

  public:

    Node(): data(0), next(NULL) {}

  Node(int data, Node * next) {
    this -> data = data;
    this -> next = next;
  }

  int getData() {
    return data;
  }

  Node * getNext() {
    return next;
  }

  void setData(int data) {
    this -> data = data;
  }

  void setNext(Node * next) {
    this -> next = next;
  }
};

class LinkedList {
  Node * head;
  public:

    LinkedList() {
      head = NULL;
    }

  LinkedList(Node * head) {
    this -> head = head;
  }

  Node * getHead() {
    return head;
  }

  void setHead(Node * head) {
    this -> head = head;
  }

  bool isEmpty() {
    if (head == NULL) {
      return true;
    } else {
      return false;
    }
  }

  void TotalElements() {
    int count = 0;
    Node * temp;
    temp = head;
    while (temp != NULL) {
      count++;
      temp = temp -> getNext();
    }
    cout << "       " << count << endl;
  }
  void DisplayAllElements() {
    Node * temp;
    temp = head;
    while (temp != NULL) {
      cout << "       " << temp -> getData();
      temp = temp -> getNext();
    }
  }

  void insertAtBeginning(int v) {
    Node * temp = new Node(v, NULL);
    temp -> setNext(head);
    head = temp;
  }

  void insertAtLast(int v) {
    Node * last = head;
    while (last -> getNext() != NULL) {
      last = last -> getNext();
    }
    Node * temp = new Node(v, NULL);
    last -> setNext(temp);
  }

  int getFirst() {
    return head -> getData();
  }

  int getLast() {
    Node * last = head;
    while (last -> getNext() != NULL) {
      last = last -> getNext();
    }
    return last -> getData();
  }

  void removeFromBeginning() {
    Node * temp = head;
    head = head -> getNext();
    delete temp;
  }

  void removeFromLast() {
    Node * last = head -> getNext();
    Node * secondLast = head;
    while (last -> getNext() != NULL) {
      last = last -> getNext();
      secondLast = secondLast -> getNext();
    }
    delete last;
    secondLast -> setNext(NULL);

  }

};

int main() {
  LinkedList L1;
  L1.insertAtBeginning(1);
  L1.insertAtBeginning(2);
  L1.insertAtBeginning(3);
  L1.insertAtBeginning(4);
  L1.insertAtLast(5);
  L1.DisplayAllElements();
  cout << "\n  Total Length->";
  L1.TotalElements();
  cout << "  List after removing first element" << endl;
  L1.removeFromBeginning();
  L1.DisplayAllElements();
  cout << "\n  List after removed last element" << endl;
  L1.removeFromLast();
  L1.DisplayAllElements();

  return 0;

}
