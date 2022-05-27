#include "ArrayStack.h"

#include "../3-Queues/LinkedQueue.h"

#include <iostream>
using namespace std;


template <class T>
void RemoveConNegative(LinkedQueue<T>& q)
{
	LinkedQueue<T> Aux;
	T Item1,Item2; 
	q.dequeue(Item1); 
	while (!q.isEmpty())
	{
		q.dequeue(Item2);
		if (q.isEmpty())
			Aux.enqueue(Item2);
		if (!(Item2 < 0 && Item1 < 0))
			Aux.enqueue(Item1);
		Item1 = Item2; 
	}
	while (!Aux.isEmpty())
	{
		T Item;
		Aux.dequeue(Item);
		q.enqueue(Item);
	}
}
template <class T> 
bool sameOrder(LinkedQueue<T> q, ArrayStack<T> s)
{
	LinkedQueue<T> queue = q;
	ArrayStack<T> stack = s; 
	int qsize = 0; 
	int ssize = 0; 
	while (!queue.isEmpty())
	{
		T Item;
		qsize++;
		queue.dequeue(Item);
	}
	while (!stack.isEmpty())
	{
		T Item;
		ssize++;
		stack.pop(Item);
	}
	if (qsize != ssize)
		return 0; 
	ArrayStack<T> aux(s.getCapacity());
	while (!s.isEmpty())
	{
		T Item; 
		s.pop(Item); 
		aux.push(Item);
	}
	while (!aux.isEmpty())
	{
		T Item1,Item2;
		aux.pop(Item1); 
		q.dequeue(Item2);
			if (Item1 != Item2)
				return 0;
	}
	return 1; 
	
}

template<class T>
void removeDuplicates (LinkedQueue<T>& q)
{
	T Item1, Item2; 
	LinkedQueue<T> aux;
	q.dequeue(Item1); 
	aux.enqueue(Item1);
	Item2 = Item1;
	while (!q.isEmpty())
	{
		q.dequeue(Item1);
		if (Item1 != Item2)
		{
			aux.enqueue(Item1); 
		}
		Item2 = Item1;
	}
	while (!aux.isEmpty())
	{
		aux.dequeue(Item1); 
		q.enqueue(Item1); 
	}

}
template<class T>
void collapse(ArrayStack<T>& S)
{
	T Item;
	ArrayStack<T> Aux(S.getCapacity());
	while (!S.isEmpty())
	{
		T num1, num2;
		S.pop(num1); 
		if (!S.isEmpty())
			S.pop(num2);
		else
			num2 = 0;
		Aux.push(num1 + num2); 
	}
	while (!Aux.isEmpty())
	{
		Aux.pop(Item); 
		S.push(Item); 
	}
}
template<class T>
void printQueue(LinkedQueue<T> q)
{
	cout << "printing queue contents : "; 
	while (!q.isEmpty())
	{
		T Item; 
		q.dequeue(Item); 
		cout << Item << " "; 
	}
}



// A function to print stack contents
//as the function shoud operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(ArrayStack<T> S)
{
	
	cout << endl<<"Printing stack contents: ";

	T x;
	while(S.pop(x))		
		cout << x << " ";
	
	cout<<endl;
}

//A function that takes a ArrayStack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
void Reverse(ArrayStack<T>& S)
{
	LinkedQueue<T> Rev; 
	T Item;
	while(S.pop(Item))	//pop from S
		Rev.enqueue(Item);//push into Rev
	while (!Rev.isEmpty())
	{
		Rev.dequeue(Item);
		S.push(Item); 
	}
}

//A function that takes a ArrayStack<T> S and replaces all occurrances of "value" with "newValue" (if found)
//if v is not found, it returns false
template <typename T>
bool ReplaceAll(ArrayStack<T> & Source, T value, T newValue)	//Source is passe by ref
{
	ArrayStack<T> tempS(Source.getCapacity());	//a temp stack is needed
	T x;
	bool found = false;
	while(Source.pop(x))
	{ 
		if (x == value)		//repalce the value if found
		{
			tempS.push(newValue);
			found = true;
		}
		else
			tempS.push(x);
	}

	//After the above loop, stack "Source" is empty
	//Restore Source stack again
	while (tempS.pop(x))
		Source.push(x);

	return found;
}






int main()

{
	ArrayStack<int> stack1(20);

	int i,x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout << "---replace---" << endl;
	cout<<"Please Enter the 5 values to push in stack1 :";
	for(i = 0; i < 5; i++)
	{	 
		cin>>x;
		stack1.push(x); //pushing x to stack1
	}

	cout<<"\nstack1 contents\n";
	PrintStack(stack1);

	int a, b;
	cout << "\nEnter a value to replace:";
	cin >> a;
	cout << "\nEnter the new value:";
	cin >> b;

	bool isFound = ReplaceAll(stack1, a, b);
	if (isFound)
		cout << "\nValue replaced";
	else
		cout << "\nValue not found";
	PrintStack(stack1);


	cout << "---reverse---" << endl;
	/*ArrayStack<int> stack2 = */
	Reverse(stack1);

	cout<<"\nAfter Reverse...\nstack1 contents\n";
	PrintStack(stack1);



	cout << "---collapse---" << endl;
	collapse(stack1); 
	cout << "\nAfter After collapse...\nstack1 contents\n";
	PrintStack(stack1); 
	
	cout << "---RemoveDuplicates---" << endl;
	cout << "\n enter a 5 element to be put in the queue : ";
	LinkedQueue<int> queue1;
	for (int i = 0; i < 5; i++)
	{
		int x; 
		cin >> x; 
		queue1.enqueue(x); 
	}
	removeDuplicates(queue1); 
	cout << "\nAfter After remove duplicates...\n ";
	printQueue(queue1); 

	cout << "\n---sameOrder---" << endl;
	cout << "\n enter a 5 element to be put in the queue : ";
	LinkedQueue<int> queue2;
	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		queue2.enqueue(x);
	}

	cout << "Please Enter the 5 values to push in stack1 :";
	ArrayStack<int> stack3(5);
	for (i = 0; i < 5; i++)
	{
		cin >> x;
		stack3.push(x); //pushing x to stack1
	}
	if (sameOrder(queue2, stack3))
		cout << "Same !" << endl; 
	else 
		cout << "Different !" << endl;


	cout << "\n---removeConNegative---" << endl;
	cout << "\n enter a 5 element to be put in the queue : ";
	LinkedQueue<int> queue4;
	for (int i = 0; i < 5; i++)
	{
		int x;
		cin >> x;
		queue4.enqueue(x);
	}
	RemoveConNegative(queue4);
	printQueue(queue4);
	cout << endl;

	return 0;


}
