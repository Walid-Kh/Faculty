#include <iostream>
using namespace std;
class Node
{
public:
  void setNext(Node *n)
  {
    next = n;
  }
  void setValue(int v)
  {
    value = v;
  }
  int getValue()
  {
    return value;
  }
  Node *getNext()
  {
    return next;
  }
  Node(int v)
  {
    value = v;
    next = nullptr;
  }

private:
  int value;
  Node *next;
};
class linkedList
{
  Node *head;
  Node *tail;

public:
  linkedList()
  {
    head = nullptr;
    tail = nullptr;
  }
  Node *getHead()
  {
    return head;
  }
  void push(int x)
  {
    Node *NewNode = new Node(x);
    if (!head)
    {
      head = NewNode;
      tail = NewNode;
    }
    else
    {
      tail->setNext(NewNode);
      tail = NewNode;
    }
  }
  void rotate(int rotation)
  {
    for (int i = 0; i < rotation; i++)
    {
      Node *y = head;
      Node *prev = nullptr;
      while (y->getNext())
      {
        prev = y;
        y = y->getNext();
      }
      y->setNext(head);
      head = y;
      prev->setNext(nullptr);
      tail = prev;
    }
  }
  void print()
  {
    Node *x = head;
    while (x)
    {
      cout << x->getValue() << " ";
      x = x->getNext();
    }
  }
  void destroy()
  {
    Node *x = head;
    while (x)
    {
      Node *y = x;
      x->getNext();
      delete y;
    }
  }
};
int main()
{
  linkedList l1; 
  int size, rotation; 
  cin >> size >> rotation; 
  for (int i = 0; i < size; i++)
  {
    int x; 
    cin >> x;
    l1.push(x); 
  }
  l1.rotate(rotation%size); 
  l1.print(); 
  
}