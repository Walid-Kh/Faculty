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
    void loadQueue(queue q)
    {
        int x;
        stack s;
        while (!q.isEmpty())
        {
            x = q.pop();
            s.push(x);
        }
        while (!s.isEmpty())
        {
            x = s.pop();
            push(x);
        }
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
    int x;
    int n, m;
    stack initS, auxS, resS;
    queue initQ, resQ;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        auxS.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        x = auxS.pop();
        initS.push(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x; 
        initQ.push(x); 
    }
    for (int i = 0; i < n; i++)
    {
        x = initS.pop();
        resQ.push(x);
    }
    
    resS.loadQueue(initQ);

    resS.print();
    cout << "\n"; 
    resQ.print(); 
    
}