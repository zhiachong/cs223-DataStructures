//@author Zhia Chong
//@date 19 Feb 2011
//@file prog4.cpp
//@description this is the main program that runs cbstree and 
//@            and cbintree

#include <iostream>
#include <fstream>
#include <string>
#include "cbintree.h"
#include "cbstree.h"
#include "cexception.h"
#include "ckey.h"
#include "citem.h"
using namespace std;

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
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

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param key
//@usage GetInputFromFile(infile, key);
void GetKeyFromFile(ifstream& infile, Ckey& tkey);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//@prints out the header 
//@pre description is assigned
//@post prints out the header 
//@usage PrintHeader("This is a program");
void PrintHeader(string description);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram();

//@prints out the intro for order traversal
//@post prints out the header
//@usage PrintIntroForOrder("in-order");
void PrintIntroForOrder(string order);

int main()
{
   StartProgram();
   return 0;
}

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram()
{
   cbintree tree;
   cbstree searchTree;
   Citem treeItem;
   Ckey treeKey;
   ifstream infile;
   bool ok;
   
   PrintLines(2);
   PrintHeader("This is Programming Assignment #4");
   OpenInputFile(infile, ok);
   PrintLines(2);
   cout << "----Making A Tree with Cbintree makeTree----" << endl;
   tree.makeTree(infile);
   
   PrintLines(2);
   PrintIntroForOrder("in-order");
   PrintLines(1);
   tree.inorderTraverse();
   ToContinue();
   
   PrintLines(2);
   PrintHeader("This is Cbintree prettyDisplay");
   PrintLines(3);
   tree.prettyDisplay();
   ToContinue();
   PrintLines(2);
   
   try {
      for (int i = 0; i < 4; i++)
      {
         GetInputFromFile(infile, treeItem);
         searchTree.insert(treeItem);
         cout << "---Building tree Step " << (i + 1) << "---";
         PrintLines(2);
         searchTree.prettyDisplay();
         PrintLines(2);
         ToContinue();
         PrintLines(2);
      }
   }
   catch (cexception de)
   {
      cout << de.what();
      PrintLines(2);
   }
   
   PrintHeader("This is the Binary Search Tree");
   PrintLines(3);
   searchTree.prettyDisplay();
   ToContinue();
   
   try {
      PrintLines(2);
      PrintHeader("Search for a key in the Binary Search Tree");
      PrintLines(2);
      GetKeyFromFile(infile, treeKey);
      cout << "Searching for -> " << treeKey << " <- in the tree" << endl;
      searchTree.retrieve(treeKey, treeItem);
      PrintLines(2);
      cout << "Results -> " << treeItem << endl;
   } catch (cexception err) {
      cout << err.what();
      PrintLines(2);
   }
   
   ToContinue();
   
   try {
      PrintLines(2);
      PrintHeader("Search for a key NOT in the Binary Search tree");
      PrintLines(2);
      GetKeyFromFile(infile, treeKey);
      cout << "Searching for -> " << treeKey << " <- in the tree " << endl;
      PrintLines(2);
      searchTree.retrieve(treeKey, treeItem);
   }
   catch (cexception ex) {
      cout << ex.what();
      PrintLines(3);
   }
   
   CloseInputFile(infile);
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

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param key
//@usage GetInputFromFile(infile, key);
void GetKeyFromFile(ifstream& infile, Ckey& tkey)
{
   infile >> tkey;
}
                    
//@prints out the intro for order traversal
//@post prints out the header
//@usage PrintIntroForOrder("in-order");
void PrintIntroForOrder(string order)
{
   cout << "This is the " << order << " traversal: ";
   PrintLines(1);
}

//@prints out the header 
//@pre description is assigned
//@post prints out the header 
//@usage PrintHeader("This is a program");
void PrintHeader(string description)
{
   cout << "***********************************************" << endl;
   cout << description << endl;
   cout << "***********************************************" << endl;
}

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@param fileName
//@usage OpenInputFile(infile, fileOk, "in4.dat");
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("in4.dat");
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

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
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

