//I am running code of Making Nodes

#include using namespace std;

class Node {
  int data;
  Node * next;
  public:
    void setData(int data) {
      this -> data = data;
    }
  void setNext(Node * next) {
    this -> next = next;
  }
  int getData() {
    return data;
  }
  Node * getNext() {
    return next;
  }
  Node(int data, Node * next = NULL) {
    setData(data);
    setNext(next);
  }
  Node() {
    data = NULL;
    next = NULL;
  }
  void print(Node n) //n must be given the starting node of chain { while (n != NULL) { cout << n->getData() << endl; n=n->getNext(); } } int getLenght(Node n)//n must be given the starting node of chain { int c = 0; while (n != NULL) { c++; n= n->getNext(); } return c; } int get_Last_Element(Node* n)//n must be given the starting node of chain { while (n->next != NULL) { n = n->getNext(); } return n->getData(); } int get_nth_Element(Node n,int nth)//n must be given the starting node of chain and nth is the term to be return. { int size = getLenght(n); if (nth <= size) { int node = 0; while (n != NULL) { node++; if(node==nth) { return n->getData(); } n = n-> next; } } else { cout << "\nThe given term is out of range ."; return NULL; } } int get_First_Element(Node n)//n must be given the starting node of chain { return n->getData(); }

  void insert(Node ** start, int data) //To insert an element at last
  {
    Node * newNode = new Node(data); //creating new node

    Node * last = * start; //finding last node
    while (last -> getNext() != NULL)
      last = last -> getNext();

    last -> setNext(newNode); //setting newNode as the last element of chain
  }
