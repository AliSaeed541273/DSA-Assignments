
#include <iostream>

using namespace std;
class Node {
    private:
        int data;
    Node * next;
    public:
        Node(): data(0), next(NULL) {}
    Node(int data, Node * next) {
        this -> data = data;
        this -> next = next;
    }

    Node * getNext() {
        return next;
    }
    int getData() {
        return data;
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
        LinkedList(): head(NULL) {}
    LinkedList(Node * head) {
        this -> head = head;
    }
    bool isEmpty() {
        if (head == NULL) {
            return true;

        } else {
            return false;
        }
    }

    void insertAtFirst(int val) {
        Node * temp = new Node(val, NULL);
        if (!isEmpty()) {
            temp -> setNext(head);
            head = temp;
        } else {
            head = temp;
        }
    }

    void insertAtLast(int val) {
        Node * temp = new Node(val, NULL);
        Node * last = head;
        if (!isEmpty()) {
            while (last -> getNext() != NULL) {
                last = last -> getNext();
            }
            last -> setNext(temp);
        } else {
            head = temp;
        }

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

    void Display() {
        Node * temp = head;
        while (temp != NULL) {
            cout << temp -> getData() << "-> ";
            temp = temp -> getNext();
        }
        cout << "NULL\n";
    }

    void Total() {

        int count = 0;
        Node * temp = head;
        while (temp != NULL) {
            count++;
            temp = temp -> getNext();
        }
        cout << endl << " Total : " << count;

    }

    int getLength() {
        int count = 0;
        Node * temp = head;
        while (temp != NULL) {
            count++;
            temp = temp -> getNext();
        }
        return count;

    }

    void removeFirst() {
        Node * temp = head;
        head = head -> getNext();
        delete temp;
    }

    int getN(int n) {
        if (n <= getLength()) {
            int count = 1;
            Node * nth = head;
            while (count != n) {
                nth = nth -> getNext();
                count++;
            }
            return nth -> getData();
        }
        return -9999;

    }

    void removeLast() {
        if (!isEmpty()) {
            Node * snlast = head;
            Node * last = head -> getNext();
            while (last -> getNext() != NULL) {
                snlast = snlast -> getNext();
                last = last -> getNext();
            }
            delete last;
            snlast -> setNext(NULL);

        } else {
            return;
        }
    }
};

class Stack{
    private:
        LinkedList ls;
        int limit;
    public:
    Stack():limit(0){}
    
    Stack(int limit){
        this->limit=limit;
    }
    
    void push(int val){
        ls.insertAtLast(val);
    }
    
    int pop(){
        int x = ls.getLast();
        ls.removeLast();
        return x;
    }
    
     int peek(){
        int x = ls.getLast();
        return x;
    }
    
    void print(){
        ls.Display();
    }
    
    
};
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    return 0;
