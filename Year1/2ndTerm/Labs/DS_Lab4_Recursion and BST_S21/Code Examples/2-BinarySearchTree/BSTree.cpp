#include "BSTree.h"

#include <iostream>
using namespace std;

// Utility Functions - Recursive Functions --------------------------

// Given functions

// Insert an integer key in a binary search tree.
// [Note]: subRoot is passed by ref because 
//         the new node may be inserted in the subRoot (if subRoot is empty nullptr)
void BSTree::rec_insertBST(Node *& subRoot, int key)
{
	if (subRoot == nullptr)
		subRoot = new Node(key); // this line is why we pass subRoot by reference (subRoot = something)
	else if (subRoot->getdata() < key)
	{

		//recursively call insert for the right subtree
		rec_insertBST(subRoot->getright(), key);  

		// ************************   VERY IMPORTANT NOTE  *************************** //

		// Node* & Node::getright();   VS   Node* Node::getright();

		// Notice that function rec_insertBST(Node *& subRoot, int key);
		// takes it 1st parameter (the pointer) by REFERENCE
		// For the above call for the function to be syntactically correct, 
		// we have declared function Node::getright() as:  
		//		Node* & Node::getright(); (see Node class)
		//i.e. it returns a Node pointer but by reference (not by value)

		// Why wouldn't it work if it is return by value ???
		//		if Node::getright() was declared as  
		//		Node* Node::getright();			
		//		i.e. it returns "right" pointer (return by value)
		//		in this case, the returned pointer is called rvale (right-value)
		//		rvalue in C++ cannot be passed by ref to a function and
		//		cannot be used at the left of assignment statement		

		// What should I do if function getright must return by value ???
		//		IF for any reason, getright in your code MUST return by value 
		//		so the previous code line  rec_insertBST(subRoot->getright(), key); is a syntax error
		//		To solve the problem is this case 
		//		we should 
		//			1- store it in temp, 
		//			2- pass the temp to the function, 
		//			3- set the right of subRoot with this temp (after calling the fn because it may be changed inside it - by ref)
		//	Here is the code in this case to perform the same task
				/*
				Node * tmp = subRoot->getright();
				rec_insertBST(tmp, key);
				subRoot->setright(tmp);
				*/
		//	So to avoid all this mess, all what you need is to declare getright as:
		//		Node* & Node::getright();
		//	NOT as:
		//		Node*  Node::getright();

		
		// Remember: rvalue is some expression that is not stored in memory with a specific name
		// hence, you can't reach it by a name beyond the line that contains it 
		// like (x + 9): x is stored in memory, but (x + 9) returns a temp result that is not stored in memory with a name
		// same case for: subRoot->getright() --> if it returns an rvalue (or temp result without a name) of the "right"
	}
	else
	{
		// recursive call on left
		rec_insertBST(subRoot->getleft(), key); 
	}
}

bool BSTree::insertToFill(Node*& subRoot, int key)
{
	if (!root) // empty 
	{
		Node* newNode = new Node(key);
		subRoot = newNode; 
		return 1; 
	}
	else if (!subRoot)
	{
		return 0; 
	}
	else if ((subRoot->getleft() && !subRoot->getright())|| (!subRoot->getleft() && subRoot->getright()))  // found
	{
		Node* newNode = new Node(key); 
		if (!subRoot->getleft())
			subRoot->setleft(newNode); 
		else 
			subRoot->setright(newNode);
		return 1;
	}
	else // keep searching 
	{
		bool x = insertToFill(subRoot->getleft(), key);
		bool y = 0; 
		if (!x)
			y = insertToFill(subRoot->getright(), key);
		return y || x;
	}
}

//* print the tree with inorder traversal.
void BSTree::rec_inorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	rec_inorder_traverse(subRoot->getleft());
	cout << subRoot->getdata() << " ";
	rec_inorder_traverse(subRoot->getright());
}

//* print the tree with preorder traversal.
void BSTree::rec_preorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	cout << subRoot->getdata() << "  ";
	rec_preorder_traverse(subRoot->getleft());
	rec_preorder_traverse(subRoot->getright());
}

//* print the tree with postorder traversal.
void BSTree::rec_postorder_traverse(Node* subRoot)
{
	if (subRoot == nullptr) return;
	rec_postorder_traverse(subRoot->getleft());
	rec_postorder_traverse(subRoot->getright());
	cout << subRoot->getdata() << "  ";
}

//* Deletes all the nodes in the tree.
// [Note]: subRoot is passed by ref because 
//         after deleting subRoot node we will make it point to nullptr (change subRoot)
void BSTree::rec_destroy_tree(Node *& subRoot)
{
	if (subRoot != nullptr)
	{
		// recursive call on left
		rec_destroy_tree(subRoot->getleft());

		// recursive call on right
		rec_destroy_tree(subRoot->getright());

		delete subRoot;
		subRoot = nullptr; // this line is why we pass subRoot by reference (subRoot = something)
	}
}

void BSTree::inverseTree(Node* subRoot)
{
	if (subRoot)
	{
		Node* left = subRoot->getleft();
		Node* right = subRoot->getright();
		subRoot->setright(left);
		subRoot->setleft(right);
		inverseTree(subRoot->getleft());
		inverseTree(subRoot->getright());
	}
}

//Functions to be implemented by student

//* return a pointer to the node that hold the maximum value in binary search tree of the passed subRoot.
Node*  BSTree::rec_find_max(Node* subRoot)
{
	if (subRoot->getright() == nullptr) {
		return subRoot;
	}
	else {
		return rec_find_max(subRoot->getright());
	}
	//TO DO
	//return nullptr; // should be changed
}

//* return a pointer to the node that hold the minimum value in binary search tree of the passed subRoot.
Node*  BSTree::rec_find_min(Node* subRoot)
{
	if (subRoot->getleft() == nullptr) {
		return subRoot;
	}
	else
	{
		return rec_find_min(subRoot->getleft());
	}
	//TO DO
	return nullptr; // should be changed
}
//* return the depth of binary search tree of the passed subRoot.
int BSTree::rec_max_depth(Node* subRoot)
{
	//TO DO
	return 0; // should be changed
}

bool BSTree::rec_search(Node* subroot,int data)
{
	if (subroot == nullptr) {
		return false;
	}
	if (subroot->getdata() == data) 
	{
		return true;
	}else
	{
		if (subroot->getdata() > data) {
			return rec_search(subroot->getleft(),data);
	}
		if (subroot->getdata() < data) {
			return rec_search(subroot->getright(), data);
		}
	
	}

}

int  BSTree::rec_lessthan(Node* subroot, int data)
{
	if (subroot == nullptr) {
		return 0;
	}
	if(data>subroot->getdata())
	{
		return 1;
	}
	return rec_lessthan(subroot->getleft(), data)+ rec_lessthan(subroot->getright(), data);
	 
	//return count;
}

void BSTree::printParents(Node* subRoot)
{
	if (!subRoot)
		return; 
	else if (subRoot->getleft() || subRoot->getright())
	{
		printParents(subRoot->getleft()); 
		cout << subRoot->getdata() << " ";
		printParents(subRoot->getright());
	}
}

bool BSTree::isMirror(Node* root, Node* root2)
{
	if (!root && !root2)
	{
		return 1; 
	}
	else
	{
		if ((root && !root2) || (!root && root2))
			return 0;
		else if (root->getdata() != root2->getdata())
			return 0;
		return isMirror(root->getleft(), root2->getright()) && isMirror(root->getright(), root2->getleft()); 
	}
}



BSTree::BSTree()
{
	root = nullptr;
}


BSTree::~BSTree()
{
	destroy_tree();
}

// Public Functions ---------------------------------

// Given functions
void BSTree::insertBST(int key) // not const
{
	// not const because rec_insertBST takes the root by reference, so may change it
	rec_insertBST(root, key);
}
bool BSTree::insertToFill(int key)
{
	return insertToFill(root, key);
}
void BSTree::inorder_traverse() const
{
	rec_inorder_traverse(root);
}
void BSTree::preorder_traverse() const
{
	rec_preorder_traverse(root);
}
void BSTree::postorder_traverse() const
{
	rec_postorder_traverse(root);
}
void BSTree::destroy_tree() // not const
{
	// not const because rec_destroy_tree takes the root by reference, so may change it
	rec_destroy_tree(root); 
}

Node* BSTree::find_max_rec() const
{
	return rec_find_max(root);
	//return nullptr;
	
}

Node* BSTree::find_min_rec() const
{
	return rec_find_min(root);
}

bool BSTree::search_rec(int data) const
{
	return rec_search(root, data);
}

int BSTree::lessthan_rec(int data)
{
	
	return rec_lessthan(root, data);
}

// Functions to be implemented by student
Node* BSTree::find_max() const // return a pointer to the node that hold the maximum value in binary search tree.
{

	//TO DO
	return nullptr; // should be changed
}
Node* BSTree::find_min() const // return a pointer to the node that hold the minimum value in binary search tree.
{
	//TO DO
	return nullptr; // should be changed
}
int BSTree::max_depth() const
{
	//TO DO
	return 0; // should be changed
}

void BSTree::pluscount()
{
	count++;
}

int BSTree::getcount()
{
	return count;
}

void BSTree::printParents() const
{
	printParents(root);
}

void BSTree::inverseTree()
{
	inverseTree(root); 
}

bool BSTree::isMirror(const BSTree& root2)
{
	return isMirror(root, root2.root); 
}
