#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

struct node {
	string value, key;
	node *left;
	node *right;
	node *parent;
	int avlValue;
	node(string word, string wordtype) {
		value = word;
		key = wordtype;
		left = right = parent = NULL;
		avlValue = 0;
	}
};

class avlTree {

private:
	node *root;
	bool rightHeavy(node *);
	bool leftHeavy(node *);
	void insert(node *&, node *&);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	node* remove(node*&, string);
	node* predSuccessor(node*);
	void printNode(node *, string);
	int  height(node *);
	void computeAvlValues(node *&);
	void rotateLeft(node *&);
	void rotateRight(node *&);
	int  avlValue(node *);
	int adjc = 0, adc = 0, verc = 0, nouc = 0, counter =0;

public:
	avlTree();
	~avlTree();
	void doDumpTree(node *);
	void dumpTree() {
		cout << "---------------------------------" << endl;
		cout << "Root:   " << root << "\n";
		doDumpTree(root);
	};
	void insert(string, string);
	void showInorder() { inorder(root); };
	void showPreorder() { preorder(root); };
	void showPostorder() { postorder(root); };
	bool search(string);
	void remove(string word) { root = remove(root, word); };
	int  treeHeight();
	void graphVizGetIds(node *, ofstream &);
	void graphVizMakeConnections(node *, ofstream &);
	void graphVizOut(string);
	int adjectiveCounter();
	int nounCounter();
	int adverbCounter();
	int verbCOunter();
	
	
	int avlCounter();
};


