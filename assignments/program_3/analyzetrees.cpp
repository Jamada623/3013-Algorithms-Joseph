// analyzetrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include "avlTree.h"
#include "bsTree.h"

using namespace std;

int main()
{
	srand(2342);
	string Crazywords[10000];
	avlTree A;
	BSTree B;
	ifstream fin;
	ofstream outfile;
	string word;	

	// used as a counter
	int i = 0;

	// open the "adjectives" file for reading
	fin.open("adjectives.txt");
	// while there are more words.
	for (int m=0;m<15571;m++)
	{
		fin >> word;
		cout << word << endl;
		A.insert(word, "adjective");
		B.insert(word, "adjective");
	}
	fin.close();


	// open the "adjectives" file for reading
	fin.open("adverbs.txt");
	// while there are more words.
	for (int m = 0; m<3237; m++)
	{
		fin >> word;
		cout << word << endl;
		A.insert(word, "adverb");
		B.insert(word, "adverb");
	}
	fin.close();

	// open the "adjectives" file for reading
	fin.open("nouns.txt");
	// while there are more words.
	for (int m = 0; m<53737; m++)
	{
		fin >> word;
		cout << word << endl;
		A.insert(word, "noun");
		B.insert(word, "noun");
		i++;
			}
	fin.close();

	// open the "adjectives" file for reading
	fin.open("animals.txt");
	// while there are more words.
	for (int m = 0; m<235; m++)
	{
		fin >> word;
		cout << word << endl;
		A.insert(word, "animal");
		B.insert(word, "animal");
		i++;
		if (i>235) {
			// We used this if to load a specific amount of words into
			// the tree. Commenting out the break loads all the words
			// from the above file.
			//break;
		}
	}
	fin.close();

	// open the "adjectives" file for reading
	fin.open("verbs.txt");
	// while there are more words.
	for (int m = 0; m<12018; m++)
	{
		fin >> word;
		cout << word << endl;
		A.insert(word, "verb");
		B.insert(word, "verb");
		i++;
		if (i>4000) {
			// We used this if to load a specific amount of words into
			// the tree. Commenting out the break loads all the words
			// from the above file.
			//break;
		}
	}
	fin.close();

	fstream infile;
	infile.open("tenthousandwords.txt");

	cout << endl << endl;
	
	for (int x = 0; x < 10000; x++) {
		infile >> Crazywords[x];		
	}
	 
	for (int i = 0; i < 10000; i++) {
		A.search(Crazywords[i]);
		B.search(Crazywords[i]);
	}
	infile.close();

	outfile.open("analysis.out");
	cout << "Avl comparisons : " << A.avlCounter() << endl;
	cout << "Bst comparisons : " << B.avlCounter() << endl;
	cout << "Adjective count : " << A.adjectiveCounter() << endl;
	cout << "Noun count      : " << A.nounCounter() << endl;
	cout << "Verb count      : " << A.verbCOunter()<< endl;
	cout << "Adverb count    : " << A.adverbCounter() << endl;	

	outfile << "Avl comparisons : " << A.avlCounter() << endl;
	outfile << "Bst comparisons : " << B.avlCounter() << endl;
	outfile << "Adjective count : " << A.adjectiveCounter() << endl;
	outfile << "Noun count      : " << A.nounCounter() << endl;
	outfile << "Verb count      : " << A.verbCOunter() << endl;
	outfile << "Adverb count    : " << A.adverbCounter() << endl;
	

	// Show a graphviz linked version of the tree. 
	A.graphVizOut("avlTree_viz.txt");
	return 0;
}

