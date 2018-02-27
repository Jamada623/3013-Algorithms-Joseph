#include "stdafx.h"
#include "BSTree.h"

//************************************************************************
//The constructor for the BST
// It generated the BST when it is called.
//************************************************************************
BSTree::BSTree()
{
	root = NULL;
}

//************************************************************************
// The destructor of the BST.
// Deletes the BST when called
//************************************************************************
BSTree::~BSTree()
{
}

//************************************************************************
// Function to return the number of nodes in the tree.
//************************************************************************
int BSTree::count()
{
	return count(root);
}

//************************************************************************
//Function to create and insert a new node into the tree
//************************************************************************
void BSTree::insert(int x)
{
	node *temp = new node(x);
	insert(root, temp);
}

//************************************************************************
// Function to delete a node from the tree.
// It takes the current node and deletes its from the tree
// It ensures the other nodes are still connected to the tree if the node 
// had children.
//************************************************************************
void BSTree::deleteNode(int key)
{
	deleteNode(root, key);
}

//************************************************************************
// Function to find the minimum value of the tree
// It traveserse the required side of the tree and returns the minimum 
// value.
//************************************************************************
void BSTree::minValue()
{
	print_node(minValueNode(root), "minVal");
}

//************************************************************************
// Function to find the height of the tree.
// It updates with the tree every time it is called
//************************************************************************
int BSTree::height(int key = -1)
{
	if (key > 0)
	{
		//find node
	}
	else
	{
		return height(root);
	}
	return 0;
}

//************************************************************************
// Function to return the root value of the tree
// Returns nothing if there is not root
//************************************************************************
int BSTree::top()
{
	if (root)
		return root->data;
	else
		return 0;
}
//************************************************************************
//Function to print out the nodes and values of the tree
// Prints out the parent node as well as the children nodes and list their
// value in memory.
//************************************************************************
/* Function to line by line print level order traversal a tree*/
void BSTree::printLevelOrder()
{
	cout << "Begin Level Order===================\n";
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
		cout << "\n";
	}
	cout << "End Level Order===================\n";
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void BSTree::GraphVizOut(string filename)
{
	ofstream VizOut;
	VizOut.open(filename);
	VizOut << "Digraph G {\n";
	GraphVizGetIds(root, VizOut);
	GraphVizMakeConnections(root, VizOut);
	VizOut << "}\n";
	VizOut.close();
}

//************************************************************************
// Function to count the number of nodes in a tree.
//************************************************************************
int BSTree::count(node *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}

//************************************************************************
// Function to insert a node into the tree.
//Traverses the tree to insert the node in the correct place.
//************************************************************************
void BSTree::insert(node *&root, node *&temp)
{
	if (!root)
	{
		root = temp;
	}
	else
	{
		if (temp->data < root->data)
		{
			insert(root->left, temp);
		}
		else
		{
			insert(root->right, temp);
		}
	}
}

//************************************************************************
// Function to print the node values for the tree.
//Traverses the tree and prints out the nodes including the children nodes
//************************************************************************
/* Print nodes at a given level */
void BSTree::print_node(node *n, string label = "")
{
	if (label != "")
	{
		cout << "[" << label << "]";
	}
	cout << "[[" << n << "][" << n->data << "]]\n";
	if (n->left)
	{
		cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[L][null]\n";
	}
	if (n->right)
	{
		cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
	}
	else
	{
		cout << "\t\\-->[R][null]\n";
	}
}

//************************************************************************
//Function to return the height of the tree.
//Updates the height as nodes are added and removed.
//************************************************************************
int BSTree::height(node *root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		int left = height(root->left);
		int right = height(root->right);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}

//************************************************************************
// Function to print nodes at a given level
// Traverses the tree to print the nodes at the desired level
//************************************************************************

void BSTree::printGivenLevel(node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		print_node(root);
	}
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

//************************************************************************
// Method to help create GraphViz code so the expression tree can
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive
// tree traversal.
//************************************************************************
void BSTree::GraphVizGetIds(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizGetIds(nodePtr->left, VizOut);
		VizOut << "node" << nodePtr->data
			<< "[label=\"" << nodePtr->data << "\\n"
			//<<"Add:"<<nodePtr<<"\\n"
			//<<"Par:"<<nodePtr->parent<<"\\n"
			//<<"Rt:"<<nodePtr->right<<"\\n"
			//<<"Lt:"<<nodePtr->left<<"\\n"
			<< "\"]" << endl;
		if (!nodePtr->left)
		{
			NullCount++;
			VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
		GraphVizGetIds(nodePtr->right, VizOut);
		if (!nodePtr->right)
		{
			NullCount++;
			VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
		}
	}
}

//************************************************************************
// This method is partnered with the above method, but on this pass it
// writes out the actual data from each node.
// Don't worry about what this method and the above method do, just
// use the output as your told:)
//************************************************************************
void BSTree::GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
{
	static int NullCount = 0;
	if (nodePtr)
	{
		GraphVizMakeConnections(nodePtr->left, VizOut);
		if (nodePtr->left)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->left->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		if (nodePtr->right)
			VizOut << "node" << nodePtr->data << "->"
			<< "node" << nodePtr->right->data << endl;
		else
		{
			NullCount++;
			VizOut << "node" << nodePtr->data << "->"
				<< "nnode" << NullCount << endl;
		}

		GraphVizMakeConnections(nodePtr->right, VizOut);
	}
}
