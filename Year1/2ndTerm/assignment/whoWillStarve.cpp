#include <iostream>
#include <limits.h>
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
    int size = 0;

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    linkedList(Node *h)
    {
        head = h;
        while (h->getNext())
            h = h->getNext();
        tail = h;
    }
    Node *getHead()
    {
        return head;
    }
    Node *getTail()
    {
        return tail;
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
        size++;
    }
    void pushNode (Node* x)
    {
        if (x)
        {
            tail->setNext(x); 
            tail = x;
            tail->setNext(nullptr); 
        }
    }
    void pushfront(int x)
    {
        Node *NewNode = new Node(x);
        if (!head)
            tail = head = NewNode;
        else
        {
            NewNode->setNext(head); 
            head = NewNode; 
        }
    }
    void rotate(int x)
    {
        for (int i = 0; i < x; i++)
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
    linkedList split()
    {
        Node *x = head;
        int i = 0;
        for (i = 0; i < (size / 2) + (size % 2) - 1; i++)
            x = x->getNext();
        tail = x;
        x = x->getNext();
        tail->setNext(nullptr);
        linkedList l(x);
        return l;
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
    int pop()
    {
        if (head)
        {
            int val;
            val = head->getValue();
            Node *x = head;
            head = head->getNext();
            delete x;
            return val; 
        }
        else 
            return INT_MIN;
    }
    Node* popNode()
    {
        if (head)
        {
            Node* x = head; 
            head = head->getNext(); 
            return x; 
        }
        else return nullptr; 
    }
    ~linkedList()
    {
        destroy(); 
    }
};

class stack
{
public:
    stack()
    {
        l = new linkedList();
        size = 0;
    }
    void push(int x)
    {
        l->pushfront(x);
        size++;
    }
    int pop()
    {    
        int res = l->pop();
        if (res != INT_MIN)
            size--;
        return res;
    }
    int peek()
    {
        return l->getHead()->getValue();
    }
    bool isEmpty()
    {
        return !l->getHead();
    }
    void print()
    {
        l->print();
    }

private:
    linkedList *l;
    int size;
};
class queue
{
public:
    queue()
    {
        l = new linkedList();
        size--; 
    }
    void push(int x)
    {
        l->push(x);
    }
    int peek()
    {
        return l->getHead()->getValue(); 
    }    
    int pop()
    {
        return l->pop();
    }
    bool isEmpty()
    {
        return !l->getHead();
    }
    void print()
    {
        l->print();
    }
    ~queue()
    {
        l->destroy();
    }

private:
    linkedList *l;
    int size; 
};
int main ()
{
    int size;
    cin >> size; 
    stack temp,sandwiches;
    queue people; 
    int x; 
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        people.push(x); 
    }
    for (int i = 0; i < size; i++)
    {
        cin >> x;
        temp.push(x); 
    }
    for (int i = 0; i < size; i++)
    {
        int x = temp.pop(); 
        sandwiches.push(x); 
    }
    /*
    push
    pop
    peek
    */
    bool flag = 1; 
    while (!sandwiches.isEmpty() && flag)
    {
        if (sandwiches.peek() == people.peek())
        {
            people.pop();
            sandwiches.pop();
        }
        else 
        {
            queue temp;
            flag = 0;  
            while (!people.isEmpty())
            {
                int x = people.pop(); 
                if (x == sandwiches.peek())
                    flag = 1; 
                temp.push(x);
            }
            while (!temp.isEmpty())
            {
                people.push(temp.pop());
            }
            people.push(people.pop());
        }
    }
    int res = 0;
    while (!people.isEmpty())
    {
        people.pop(); 
        res++; 
    }
    cout << res; 
    return 0; 
}