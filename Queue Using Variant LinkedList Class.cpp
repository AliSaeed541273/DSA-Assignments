#include <iostream>

using namespace std;
class Node
{
private:
  int data;
  Node *next;
public:
    Node ():data (0), next (NULL)
  {
  }
  Node (int data, Node * next)
  {
    this->data = data;
    this->next = next;
  }

  Node *getNext ()
  {
    return next;
  }
  int getData ()
  {
    return data;
  }

  void setData (int data)
  {
    this->data = data;
  }

  void setNext (Node * next)
  {
    this->next = next;
  }
};

class LinkedList
{
  Node *Last;
  Node *head;
public:
    LinkedList ():head (NULL), Last (NULL)
  {
  }
  LinkedList (Node * head, Node * Last)
  {
    this->head = head;
    this->Last = Last;

  }
  bool isEmpty ()
  {
    if (head == NULL)
      {
	return true;

      }
    else
      {
	return false;
      }
  }

  void insertAtFirst (int val)
  {
    Node *temp = new Node (val, NULL);
    if (!isEmpty ())
      {
	temp->setNext (head);
	head = temp;
      }
    else
      {
	head = temp;
	Last = temp;
      }
  }

  void insertAtLast (int val)
  {
    Node *temp = new Node (val, NULL);
    if (!isEmpty ())
      {
	Last->setNext (temp);
	Last = temp;
      }
    else
      {
	head = temp;
	Last = temp;

      }

  }

  int getFirst ()
  {
    return head->getData ();
  }

  int getLast ()
  {

    return Last->getData ();
  }

  void Display ()
  {
    Node *temp = head;
    while (temp != NULL)
      {
	cout << temp->getData () << "-> ";
	temp = temp->getNext ();
      }
    cout << "NULL\n";
  }

  void Total ()
  {

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
      {
	count++;
	temp = temp->getNext ();
      }
    cout << endl << " Total : " << count;

  }

  int getLength ()
  {
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
      {
	count++;
	temp = temp->getNext ();
      }
    return count;

  }

  void removeFirst ()
  {
    if (!isEmpty ())
      {

	Node *temp = head;
	head = head->getNext ();
	delete temp;
      }

  }

  int getN (int n)
  {
    if (n <= getLength ())
      {
	int count = 1;
	Node *nth = head;
	while (count != n)
	  {
	    nth = nth->getNext ();
	    count++;
	  }
	return nth->getData ();
      }
    return -9999;

  }

  void removeLast ()
  {
    if (!isEmpty ())
      {
	Node *snlast = head;

	while (snlast->getNext () != Last)
	  {
	    snlast = snlast->getNext ();
	  }
	delete Last;
	snlast->setNext (NULL);
	Last = snlast;
      }
    else
      {
	return;
      }
  }
};

class Queue
{
private:
  LinkedList ls;
public:
  Queue ()
  {
  }

  void Enqueue (int val)
  {
    ls.insertAtFirst (val);
  }

  int Dequeue ()
  {
    int x = ls.getLast ();
    ls.removeLast ();

    return x;

  }

};

int
main ()
{
  Queue q;
  q.Enqueue (1);
  q.Enqueue (2);
  q.Enqueue (3);
  q.Enqueue (4);
  cout << q.Dequeue ();

  return 0;
}
