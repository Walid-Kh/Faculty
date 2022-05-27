#pragma once

#include "Node.h"

class BSTree
{
private:
	Node* root;
	int count = 0;

	// Utility Functions - Recursive Functions --------------------------

	// Given functions
	static void rec_insertBST(Node*& subRoot, int key);
	bool insertToFill(Node*& subRoot, int key);
	static void rec_inorder_traverse(Node* subRoot);
	static void rec_preorder_traverse(Node* subRoot);
	static void rec_postorder_traverse(Node* subRoot);
	static void rec_destroy_tree(Node*& subRoot);
	void inverseTree(Node* subRoot);
	//Functions to be implemented by student
	static Node* rec_find_max(Node* subRoot);
	static Node* rec_find_min(Node* subRoot);
	static int rec_max_depth(Node* subRoot);
	static bool rec_search(Node* subroot, int data);
	int rec_lessthan(Node* subroot, int data);
	static void printParents(Node* subRoot);
	bool isMirror(Node* root, Node* root2);
	// [Note]: in the above utility functions:
	// we made them static --
	// because they don't need an object of BSTree to be executed
	// in otherwords, they don't can't with the non-static data members of BSTree (the "root" data member)
	// this is a way that will prevent you from: 
	// using "root" instead of the passed "subRoot" by mistake  -> syntax error

public:
	BSTree(void);
	~BSTree(void);
	// Public Functions --------------------------

	// Given functions
	void insertBST(int key); // not const
	bool insertToFill(int key);
	void inorder_traverse() const;
	void preorder_traverse() const;
	void postorder_traverse() const;
	void destroy_tree(); // not const
	Node* find_max_rec() const;
	Node* find_min_rec() const;
	bool search_rec(int data)const;
	int lessthan_rec(int data);
	// Functions to be implemented by student
	Node* find_max() const; // return a pointer to the node that hold the maximum value in binary search tree.
	Node* find_min() const; // return a pointer to the node that hold the minimum value in binary search tree.
	int max_depth() const;
	void pluscount();
	int getcount();
	void printParents() const;
	void inverseTree();
	bool isMirror(const BSTree& root2);
	// [Note]: in the above public functions:
	// const functions are const because there is no probibility to change 
	// the root (data member) either directly (root = something) 
	// or by indirectly by passing it (by reference) to another function (utility fn here)
};

