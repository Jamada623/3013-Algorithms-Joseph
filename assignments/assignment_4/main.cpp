///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            (Fix deletion)
// Files:            (main.cpp, BSTree.cpp,BStree.h)
// Semester:         (3013-Advanced Structures) Spring 2018
//
// Author:           (Jamal Joseph)
// Email:            (jamal2501@hotmail.com)
// Description:
//       This program creates a tree. It then recursively deletes the root of the
//		 tree until the tree is empty.
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "stdafx.h"
#include "BSTree.h"


int main()
{
	srand(2342);

	BSTree B;

	B.insert(38);
	B.insert(10);
	B.insert(29);
	B.insert(27);
	B.insert(5);
	B.insert(43);
	B.insert(36);
	B.insert(3);
	B.printLevelOrder();
	B.GraphVizOut("before.txt");

	// loop to delete the tree
	 while(B.top()){
	    cout<<"removing: "<<B.top()<<endl;
	     B.deleteNode(B.top());
	 }
	 
	/*B.deleteNode(38);
	
	B.printLevelOrder();

	B.deleteNode(43);

	B.printLevelOrder();
	B.deleteNode(10);
	B.printLevelOrder();*/
	
	/*B.deleteNode(29);
	B.deleteNode(27);
	B.deleteNode(10);
	B.printLevelOrder();*/

	B.GraphVizOut("after.txt");
	return 0;
}

