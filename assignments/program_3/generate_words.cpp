///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            (Crazy Words- generate words)
// Files:            (generate_words.cpp, avlTree.cpp,bsTree.h, avlTree.cpp)
// Semester:         (3013-Advanced Structures) Spring 2018
//
// Author:           (Jamal Joseph)
// Email:            (jamal2501@hotmail.com)
// Description:
//       This program creates 10000 random word combinations. It then searches 
//		 through and AVL and BST to see how many comparisons it takes to find all
//       the words.
/////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>;
#include <fstream>;
#include <string>
#include <stdlib.h>     
#include <time.h>       
using namespace std;

int main()
{
	srand((int)time(0));
	fstream infile;
	infile.open("./word_files/adjectives.txt");

	string word;
	string adjective[4000];
	string noun[4000];
	string adverb[3000];
	string verb[4000];
	string animal[235];
	int rand1, rand2, rand3, rand4, count=0;
	

	for (int x = 0; x < 4000; x++) {
		infile >> adjective[x];		
	}
	//cout << adjective[1] << " " << adjective[4] <<" " << adjective[3999] << endl;
	infile.close(); 

	infile.open("./word_files/nouns.txt");	
	for (int x = 0; x < 4000; x++) {
		infile >> noun[x];		
	}
	
	//cout << noun[1] << " " << noun[4] << "" << noun[3999] << endl;
	infile.close();

	infile.open("./word_files/adverbs.txt");
	for (int x = 0; x < 3000; x++) {
		infile >> adverb[x];
	}

	cout << adverb[1] << " " << adverb[4] << "" << adverb[2999] << endl;
	infile.close();

	infile.open("./word_files/verbs.txt");
	for (int x = 0; x < 4000; x++) {
		infile >> verb[x];
	}

	//cout << verb[1] << " " << verb[4] << " " << verb[3999] << endl;
	infile.close();

	infile.open("./word_files/animals.txt");
	for (int x = 0; x < 235; x++) {
		infile >> animal[x];
	}

	//cout << animal[1] << " " << animal[4] << " " << animal[234] << endl;
	infile.close();

	ofstream outfile;
	outfile.open("tenthousandwords.txt");

	
	for (int i = 0; i < 10000; i++) {
		rand1 = rand() % 4000;
		rand2 = rand() % 235;
		rand3 = rand() % 5;
		rand4 = rand() % 3000;
		if(rand3 == 0)
		{
			
			outfile << verb[rand1]<< " " << adjective[rand1] << " " << animal[rand2] << " " << endl;
		}
		else if (rand3 == 1) 
		{
			
			outfile << adverb[rand4] << " " << adjective[rand1] << " " << noun[rand1] << endl;
		}
		else if (rand3 == 2) 
		{
			
			outfile << noun[rand1] << " " << verb[rand1] << " " << adverb[rand4] << " " << animal[rand2] << endl;
		}
		else if (rand3 == 3) 
		{
			
			outfile << adjective[rand1] << " " << noun[rand1] << " " << adverb[rand4] << " " << verb[rand1] << " " << animal[rand2] << endl;
		}
		else if (rand3 == 4) 
		{
			
			outfile << adjective[rand1] << " " << adverb[rand4] << " " << verb[rand1] << " " << animal[rand2] << endl;
		}
		count++;
	}
	
	outfile.close();
    return 0;
}

