#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// Name : Waleed Ousama Khamees
// Dep  : Computer - first Year
// Sec  : 2
// BN   : 33

//First let's declare a single node in the list
template<typename T>
class Node
{
private :
	T item;	// A data item (can be any complex sturcture)
	Node<T>* next;	// Pointer to next node
public :

	Node( ) //default constructor
	{
		next= nullptr;
	} 

	Node( T newItem) //non-default constructor
	{
		item = newItem;
		next= nullptr;

	}

	void setItem( T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node


template <typename T>
class LinkedList
{
private:
	Node<T> *Head;
public:

	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll(); 
	}

	void PrintList()	const
	{		
		Node<T> *p = Head;

		while(p)
		{
			cout << p->getItem() << " ";
			p = p->getNext();
		}
		cout << endl;
	}

	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	void InsertEnd(const T &data)
	{
		if (Head == nullptr)
		{
			Head = new Node<T>(data);
		}
		else
		{
			Node<T>* ptr = Head;
			while (ptr->getNext())
				ptr = ptr->getNext();
			ptr->setNext(new Node<T>(data));
		}
	}

	// =========================== The Required Function ==================================


	// TODO
	void ConsecutiveGroup()
	{
		// TODO: implement this function and don't change its prototype
		if (!Head)
			return; 
		Node<T>* prev = nullptr; 
		Node<T>* tra = Head; 
		while (tra)
		{
			bool flag = true; 
			if (tra && tra->getNext() && tra->getItem() < 0 && tra->getNext()->getItem() < 0)
				while (tra && tra->getItem() < 0)
				{
					Node<T>* x; 
					x = tra;
					tra = tra->getNext(); 
					if (x == Head)
						Head = tra; 
					delete x;
					x = nullptr; 
					flag = false;
					
				}
			else if (tra && tra->getItem() < 0)
			{
				Node<T>* newNode = new Node<T>(99); 
				newNode->setNext(tra->getNext()); 
				tra->setNext(newNode); 
			}
			if (Head && flag)
			{
				prev = tra; 
				tra = tra->getNext(); 
			}
			else if (Head && tra != Head)
			{
				prev->setNext(tra); 
			}

		}






	}

};


// =========================== The Main Function ==================================

int main()
{
	// Note: Don't change the main function.
	LinkedList<int> L;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		L.InsertEnd(x);
	}
	L.ConsecutiveGroup();
	L.PrintList();
	return 0;
}