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
    int size = 0;

public:
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    linkedList(Node *h)
    {
        if (h)
        {
        head = h;
        while (h->getNext())
            h = h->getNext();
        tail = h;
        }
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
        size++;
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
        if (!head)
            return;
        Node *x = head;
        while (x) 
        {
            cout << x->getValue() << " ";
            x = x->getNext();
        }
    }
    linkedList split()
    {
        linkedList y;
        if (!head)
            return y;
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
            x = x->getNext();
            delete y;
            y = nullptr;
        }
    }
};

int main()
{
    linkedList l1;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        l1.push(x);
    }
    linkedList l2 = l1.split();
    l1.print();
    if (l2.getHead())
        cout << "\n";
    l2.print();
    l1.destroy(); 
    l2.destroy();
}