#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//http://www.webgraphviz.com/

using namespace std;

struct BSnode
{
	string data;
	string datatype;
	BSnode *left;
	BSnode *right;
	BSnode()
	{
		data = "";
		datatype = "";
		left = NULL;
		right = NULL;
	}
	BSnode(string w, string q)
	{
		data = w;
		datatype = q;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	BSnode *root;
	int adjc = 0, adc = 0, verc = 0, nouc = 0, counter = 0;
	int count(BSnode *root)
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

	void insert(BSnode *&root, BSnode *&temp)
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

	void print_node(BSnode *n, string label = "")
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

	/**
	* type = ['predecessor','successor']
	*/
	BSnode *minValueNode(BSnode *root)
	{
		BSnode *current = root;

		if (root->right)
		{
			current = root->right;
			while (current->left != NULL)
			{
				current = current->left;
			}
		}
		else if (root->left)
		{
			current = root->left;
			while (current->right != NULL)
			{
				current = current->right;
			}
		}

		return current;
	}

	BSnode *deleteNode(BSnode *&root, string key)
	{
		if (!root)
		{
			return NULL;
		}
		if (key < root->data)
		{
			cout << "going left" << endl;
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->data)
		{
			cout << "going right" << endl;
			root->right = deleteNode(root->right, key);
		}
		else
		{
			if (root->left == NULL)
			{
				BSnode *temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == NULL)
			{
				BSnode *temp = root->left;
				delete root;
				return temp;
			}

			// BSnode with two children: Get the inorder successor (smallest
			// in the right subtree)
			BSnode *temp = minValueNode(root);

			print_node(temp, "minvaluenode");

			// Copy the inorder successor's content to this BSnode
			root->data = temp->data;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}

	int height(BSnode *root)
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

	/* Print nodes at a given level */
	void printGivenLevel(BSnode *root, int level)
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
	// be visualized. This method prints out all the unique BSnode id's
	// by traversing the tree.
	// Recivies a BSnode pointer to root and performs a simple recursive
	// tree traversal.
	//************************************************************************
	void GraphVizGetIds(BSnode *nodePtr, ofstream &VizOut)
	{
		static int NullCount = 0;
		if (nodePtr)
		{
			GraphVizGetIds(nodePtr->left, VizOut);
			VizOut << "BSnode" << nodePtr->data
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
	// writes out the actual data from each BSnode.
	// Don't worry about what this method and the above method do, just
	// use the output as your told:)
	//************************************************************************
	void GraphVizMakeConnections(BSnode *nodePtr, ofstream &VizOut)
	{
		static int NullCount = 0;
		if (nodePtr)
		{
			GraphVizMakeConnections(nodePtr->left, VizOut);
			if (nodePtr->left)
				VizOut << "BSnode" << nodePtr->data << "->"
				<< "BSnode" << nodePtr->left->data << endl;
			else
			{
				NullCount++;
				VizOut << "BSnode" << nodePtr->data << "->"
					<< "nnode" << NullCount << endl;
			}

			if (nodePtr->right)
				VizOut << "BSnode" << nodePtr->data << "->"
				<< "BSnode" << nodePtr->right->data << endl;
			else
			{
				NullCount++;
				VizOut << "BSnode" << nodePtr->data << "->"
					<< "nnode" << NullCount << endl;
			}

			GraphVizMakeConnections(nodePtr->right, VizOut);
		}
	}

public:
	BSTree()
	{
		root = NULL;
	}
	~BSTree()
	{
	}

	int count()
	{
		return count(root);
	}

	void insert(string x, string y)
	{
		BSnode *temp = new BSnode(x, y);
		insert(root, temp);
	}

	void deleteNode(string key)
	{
		deleteNode(root, key);
	}

	void minValue()
	{
		print_node(minValueNode(root), "minVal");
	}

	int height(string key = "")
	{
		if (key != "")
		{
			//find BSnode
		}
		else
		{
			return height(root);
		}
		return 0;
	}

	string top()
	{
		if (root)
			return root->data;
		else
			return 0;
	}

	/* Function to line by line print level order traversal a tree*/
	void printLevelOrder()
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
	void GraphVizOut(string filename)
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
	// Method Name: searchNode
	//
	// Public 
	//
	// Purpose: Traverses a binary tree looking for a key value
	//keeps a counter of the number of searchs as well
	//
	// Arguments: string to look for
	//
	// Returns: true if found, false otherwise 
	//*************************************************************************
	bool search(string word) {
		BSnode *nodePtr = root;

		while (nodePtr) {
			if (nodePtr->data == word) {
				counter++;
				if (nodePtr->datatype == "adjective")
					adjc++;
				else if (nodePtr->datatype == "adverb")
					adc++;
				else if (nodePtr->datatype == "verb")
					verc++;
				else if (nodePtr->datatype == "noun")
					nouc++;
				return true;
			}
			else if (word < nodePtr->data) {
				nodePtr = nodePtr->left;
				counter++;
			}
			else {
				nodePtr = nodePtr->right;
				counter++;
			}
		}
		return false;
	}
	int adjectiveCounter()
	{

		return adjc;
	}


	int nounCounter()
	{

		return nouc;
	}


	int adverbCounter()
	{ 
		return adc;
	}


	int verbCounter()
	{
		return verc;
	}

	int avlCounter()
	{
		return counter;
	}

};