//@author Zhia Chong
//@date 19 Feb 2011
//@file searchtreetester.cpp
//@description this is a tester for cbstree

#include <iostream>
#include <fstream>
#include "cbstree.h"
#include "cexception.h"
#include <string>
using namespace std;

//@opens an external file for reading
//@post if the external file fileName exists, then
//@     it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@this function reads data from a file and inserts it
//@into a tree 
//@pre infile is open, and key is assigned
//@post inputs data from file into key
//@param infile
//@param key
//@usage GetInputFromFile(infile, key);
void GetKeyFromFile(ifstream& infile, Ckey& tkey);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

int main()
{
   ifstream infile;
   bool ok;
   cbstree tree;
   Citem item;
   Ckey key;
	
   OpenInputFile(infile, ok);
   cout << endl << endl;
   cout << "--------------------" << endl;
   cout << "This is current tree" << endl;
   cout << "--------------------" << endl;
   GetInputFromFile(infile, item);
   try 
   {
      tree.insert(item);
      cout << endl;
      GetInputFromFile(infile, item);
      tree.insert(item);
      GetInputFromFile(infile, item);
      tree.insert(item);
      cout << endl << endl;
      tree.inorderTraverse();
   } catch (cexception ce) {
      cout << ce.what() << endl << endl;
   }
   ToContinue();
   try {
      cout << "Retriving a key from tree" << endl;
      GetKeyFromFile(infile, key);
      tree.retrieve(key, item);
      cout << "Retrieving -> " << key << " <- from tree" << endl << endl;
      cout << endl << endl;
      cout << "Results " << item << endl;
   } catch (cexception de) {
      cout << de.what() << endl << endl;
   }
   ToContinue();
   
   try {
      cout << "Retriving a key from tree" << endl;
      GetKeyFromFile(infile, key);
      tree.retrieve(key, item);
      cout << "Retrieving -> " << key << " <- from tree" << endl << endl;
      cout << endl << endl;
      cout << "Results " << item << endl;
   } catch (cexception se) {
      cout << se.what() << endl << endl;
   }
   ToContinue();
	
   CloseInputFile(infile);
   return 0;
}
	
//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@param fileName
//@usage OpenInputFile(infile, fileOk, "ckeydict.txt");
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("searchtree.dat");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile)
{
   infile.close();
}

//@this function reads data from a file and inserts it
//@into a tree 
//@pre infile is open, and key is assigned
//@post inputs data from file into key
//@param infile
//@param key
//@usage GetInputFromFile(infile, key);
void GetKeyFromFile(ifstream& infile, Ckey& tkey)
{
   infile >> tkey;
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                           Hit <Enter> to continue -> ";
   cin.get(ch);
}

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item)
{
   infile >> item;
}
