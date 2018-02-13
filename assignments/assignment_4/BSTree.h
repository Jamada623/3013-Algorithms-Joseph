#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//http://www.webgraphviz.com/

using namespace std;



struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	node *root;

	int count(node *root);	
	void insert(node *&root, node *&temp);	
	void print_node(node *n, string label);

	/**
	* type = ['predecessor','successor']
	*/
	node *minValueNode(node *root)
	{
		node *current = root;

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

	node *deleteNode(node *&root, int key)
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
		{//condition to delete if the left side has no child.
			if (root->left == NULL)
			{
				node *temp = root;
				root = temp ->right;
				delete temp;
				return root;
			}//condition to delete if the right side has no child.
			else if (root->right == NULL)
			{
				node *temp = root;
				root = temp->left;
				delete temp;
				return root;
			}
						
			
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			node *temp = minValueNode(root);

			print_node(temp, "minvaluenode");

			// Copy the inorder successor's content to this node
			root->data = temp->data;		

			// Delete the inorder successor	
			
			if (root->right != NULL) {
				root->right = deleteNode(root->right, temp->data);
			}else if (root ->left != NULL)
			{
				root->left = deleteNode(root->left, temp->data);
			}
			//root->right = deleteNode(root->right, temp->data);
			
			key = temp->data;

			
			
		
		}
		return root;
	}

	int height(node *root);
	void printGivenLevel(node *root, int level);	
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);
	

public:
	BSTree();	
	~BSTree();
	int count();
	void insert(int x);
	void deleteNode(int key);
	void minValue();
	int height(int key);
	int top();
	void printLevelOrder();
	void GraphVizOut(string filename);
	
};

