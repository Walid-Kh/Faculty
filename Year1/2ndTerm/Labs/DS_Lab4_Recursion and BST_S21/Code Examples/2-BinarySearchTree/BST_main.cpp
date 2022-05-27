
#include "BSTree.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	BSTree bst;
	BSTree bst1;
	BSTree bst2; 
	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9

	//==============================================================
	//							InsertBST function
	//==============================================================
	cout << "building the tree with sequence 8 13 3 9 1 4" << endl << endl;
	bst.insertBST(8);
	bst.insertBST(13);
	bst.insertBST(3);
	cout << "printParent Test 1 : "; 
	bst.printParents();
	cout << endl;
	bst.insertBST(9);
	cout << "printParent Test 2 : ";
	bst.printParents(); 
	cout << endl;
	bst.insertBST(1);
	cout << "printParent Test 3 : ";
	bst.printParents();
	cout << endl;

	// test deleting 9 and addding 1 
	bst.insertToFill(15); 
	bst.inorder_traverse(); 
	cout << endl; 

	for (int i = 0; i < 5; i++)
	{
		bst1.insertBST(i); 
		bst2.insertBST(i);
	}

	bst2.inverseTree(); 
	string isMirror = bst1.isMirror(bst2) ? "YEs" : "NO";
	cout << isMirror << endl;

	bst2.inverseTree();
	isMirror = bst1.isMirror(bst2)? "YEs" : "NO";
	cout << isMirror << endl; 


	//==============================================================
	//							Traversal
	//==============================================================
	// traverse the tree with different orders
	/*cout << "The tree pre-order traversal" << endl;
	bst.preorder_traverse();
	cout << endl;

	cout << "The tree in-order traversal" << endl;
	bst.inorder_traverse();
	cout << endl;

	cout << "The tree post-order traversal" << endl;
	bst.postorder_traverse();
	cout << endl;*/
	//--------------------------------------------------------------------------
	//========================== to be implemented ==============================
	cout << "The max number is (by rec) :" << bst.find_max_rec()->getdata()<<endl;
	cout << "The min number is (by rec ): " << bst.find_min_rec()->getdata() << endl;
	cout << "number 10 exist (by rec) ? " << bst.search_rec(10)<<endl;
	cout << "number of nodes that are less than 80 is (by rec) :" << bst.lessthan_rec(80) << endl;
	//==============================================================
	//							Destroy
	//==============================================================
	cout << "Destroying tree " << endl;
	bst.destroy_tree();
	bst1.destroy_tree();
	bst2.destroy_tree();
	string s;
	//cin >> s;
	getline(cin, s); //just to pause console (output) screen
	return 0;
}
