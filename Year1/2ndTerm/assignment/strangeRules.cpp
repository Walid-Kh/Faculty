#include <iostream>
#include <cmath>
#include <string>
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
    bool pop(int &val)
    {
        if (head)
        {
            val = head->getValue();
            Node *x = head;
            head = head->getNext();
            delete x;
            return 1;
        }
        else
            return 0;
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
        int x;
        if (l->pop(x))
        {
            size--;
            return x;
        }
        else
            return -999999999;
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

int main()
{
    int res = 0;
    stack s;
    int num;
    cin >> num;
    string x;
    for (int i = 0; i < num; i++)
    {
        cin >> x;
        if (x == "D")
            s.pop();
        else if (x == "+")
        {
            int x0, x1;
            x0 = s.pop();
            x1 = s.pop();
            s.push(x1);
            s.push(x0);
            s.push(x0 + x1);
        }
        else
            s.push(stoi(x));
    }
    while (!s.isEmpty())
        res += s.pop();
    cout << res;
    return 0;
}
