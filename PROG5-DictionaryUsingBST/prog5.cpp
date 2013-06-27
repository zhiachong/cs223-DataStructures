//@author Zhia Chong
//@date 1 March 2011
//@file prog5.cpp
//@description this is a simulation of an electronic dictionary that prompts for 
//@            user input to do:
//@           deletes an abbreviation (and the meaning) from dictionary
//@           find meaning by giving a texting abbreviation
//@           insert a new item(texting abbreviation and meaning) into dictionary
//@           list all the terms in the dictionary (inorder)
//@           print the tree (showing only abbreviations without definition)
//@           rebalance the tree
//@           save the dictionary to a file called dictionary.dat
//@           exit the program

#include <iostream>
#include <fstream>
#include <string>
#include "cbintree.h"
#include "cbstree.h"
#include "cexception.h"
#include "ckey.h"
#include "citem.h"
using namespace std;

const int MAXINT = 2;

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintLines(2);
void PrintLines(int num);

//Prints out a menu that allows users to choose their options
//usage ScreenMenu();
void ScreenMenu();

//Retrives the user's choice and processes it accordingly
//usage DoOption(tree);
void DoOption(cbstree& tree);

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception);

//@opens an external file for writing
//@post if the external file fileName exists, then
//@        it is associated with outfile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param outfile
//@usage OpenOutputFile(outfile);
void OpenOutputFile(ofstream& outfile) throw (cexception);

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram();

//@finds the meaning of a given texting abbreviation
//@pre: tree is already built
//@post: prompts user for key and finds the meaning. if key not found,
//@      throws an exception
//@param: tree
//@usage: SearchForKey(tree);
void SearchForKey(const cbstree& tree);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//@this function closes the textfile
//@post textfile is closed
//@param outfile
//@usage CloseOutputFile(outfile);
void CloseOutputFile(ofstream& outfile);

//@lists all the items in the dictionary on the screen
//@pre: tree is already assigned
//@post: prints all the keys and definitions of the dictionary
//@      on screen
//@param: tree
//@usage: ListItems(tree);
void ListItems(cbstree tree);

//@prints out the tree with the keys only
//@pre: tree exists
//@post: prints out only the keys of the dictionary in pretty fashion
//@param: tree
//@usage: PrettyDisplayTree(tree);
void PrettyDisplayTree(cbstree tree);

//@inserts a new item into the tree
//@pre: tree exists
//@post: prompts user for input and inserts a new item into tree
//@param: tree
//@usage InsertNewItem(tree);
void InsertNewItem(cbstree& tree);

//@rebalances the tree
//@pre: tree exists
//@post: if the tree is unbalanced, it will be made into a balanced tree
//@      with min. height. 
//@param tree
//@usage RebalanceTree(tree);
void RebalanceTree(cbstree& tree);

//@creates the tree
//@pre: infile is open and tree is assigned
//@post: inputs items from a file into the tree
//@param infile
//@param tree
//@usage: InitiateTree(infile, tree);
void InitiateTree(ifstream& infile, cbstree& tree);

//@saves the dictionary to a file
//@pre: outfile is open, and tree exists
//@post: contents of the tree are saved in a file
//@param outfile
//@param tree
//@usage SaveContents(outfile, tree);
void SaveContents(ofstream& outfile, cbstree& tree);

//@removes an item from the tree
//@pre: tree exists
//@post: deletes an itme from tree
//@param tree
//@usage RemoveKey(tree);
void RemoveKey(cbstree& tree);

int main()
{
   StartProgram();
   return 0;
}

//@removes an item from the tree
//@pre: tree exists
//@post: deletes an itme from tree
//@param tree
//@usage RemoveKey(tree);
void RemoveKey(cbstree& tree)
{
   Ckey removeKey;
   PrintLines(2);
   cout << "Please enter item to be removed: ";
   cin >> removeKey;
   PrintLines(2);
   try {
      tree.remove(removeKey);
      cout << "The item '" << removeKey << "' has been removed!" << endl;
   } catch (cexception de) {
      cout << de.what();
      PrintLines(2);
   }
}

//@this function closes the textfile
//@post textfile is closed
//@param outfile
//@usage CloseOutputFile(outfile);
void CloseOutputFile(ofstream& outfile)
{
   outfile.close();
}

//@creates the tree
//@pre: infile is open and tree is assigned
//@post: inputs items from a file into the tree
//@param infile
//@param tree
//@usage: InitiateTree(infile, tree);
void InitiateTree(ifstream& infile, cbstree& tree)
{
   Citem item;
   int times;
   infile >> times;
   try {
      for (int i = 0; i < times; i++) 
      {
          infile >> item;
          tree.insert(item);
      }
   } catch (cexception te) {
      cout << te.what() << endl << endl;
   }
}

//@saves the dictionary to a file
//@pre: outfile is open, and tree exists
//@post: contents of the tree are saved in a file
//@param outfile
//@param tree
//@usage SaveContents(outfile, tree);
void SaveContents(ofstream& outfile, cbstree& tree)
{
   tree.inorderTraverser(outfile);
}   

//@rebalances the tree
//@pre: tree exists
//@post: if the tree is unbalanced, it will be made into a balanced trees
//@      with data from an input file. if input file is not found, an 
//@      exception is thrown
//@param tree
//@usage RebalanceTree(tree);
void RebalanceTree(cbstree& tree)
{
   ifstream infile;
   ofstream outfile;
   cout << "          --------------------------------" << endl;
   cout << "          ------Rebalancing the tree------" << endl;
   cout << "          --------------------------------" << endl;
   
   try {
      OpenOutputFile(outfile);
      SaveContents(outfile, tree);
      CloseOutputFile(outfile);
      OpenInputFile(infile);
      tree.rebalanceTree(infile);
      PrintLines(2);
      cout << "Process completed! Tree has been successfully rebalanced!";
      PrintLines(2);
      CloseInputFile(infile);
   } catch (cexception de) {
      cout << de.what() << endl << endl;
   } 
}

//@inserts a new item into the tree
//@pre: tree exists
//@post: prompts user for input and inserts a new item into tree
//@param: tree
//@usage InsertNewItem(tree);
void InsertNewItem(cbstree& tree)
{
   Citem newItem;
   PrintLines(2);
   cout << "Please enter new texting abbreviation: ";
   cin >> newItem;
   PrintLines(2);
   try {
      tree.insert(newItem);
      cout << "Thank you for adding new things to the dictionary!";
      PrintLines(1);
      cout << "Process has been successfully completed!";
      PrintLines(2);
   } catch (cexception de) {
      cout << de.what();
      PrintLines(2);
   }
}

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram()
{
   ifstream infile;
   cbstree tree;
   try {
      OpenInputFile(infile);
      InitiateTree(infile, tree);
      PrintLines(2);
      cout << "       ";
      cout << "**********************************************************" << endl;
      cout << "       ";
      cout << "***********Welcome to Zhia's Dictionary V1.0**************" << endl;
      cout << "       ";
      cout << "**********************************************************" << endl;
      DoOption(tree);
   } catch (cexception de) {
      cout << de.what() << endl << endl;
   } 
}

//@prints out the tree with the keys only
//@pre: tree exists
//@post: prints out only the keys of the dictionary in pretty fashion
//@param: tree
//@usage: PrettyDisplayTree(tree);
void PrettyDisplayTree(cbstree tree)
{
   cout << "---------------------------------" << endl;
   cout << "Printing out contents of the tree" << endl;
   cout << "---------------------------------" << endl;
   PrintLines(2);
   tree.prettyDisplay();
}   

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintLines(2);
void PrintLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}

//Prints out a menu that allows users to choose their options
//usage ScreenMenu();
void ScreenMenu()
{
   PrintLines(2);
   cout << "********************************|Menu|************************************" << endl;
   cout << "Your options: " << endl;
   cout << "   d) deletes an abbreviation (and the meaning) from dictionary" << endl;
   cout << "   f) find meaning by giving a texting abbreviation" << endl;
   cout << "   i) insert a new item(texting abbreviation and meaning) into dictionary" << endl;
   cout << "   l) list all the terms in the dictionary (inorder)" << endl;
   cout << "   p) print the tree (showing only abbreviations without definition)" << endl;
   cout << "   r) rebalance the tree" << endl;
   cout << "   s) save the dictionary to a file called dictionary.dat" << endl;
   cout << "   x) exit the program" << endl;
   cout << "*************************************************************************" << endl;
}

//Retrives the user's choice and processes it accordingly
//usage DoOption();
void DoOption(cbstree& tree)
{
   char choice = 'a';
   bool ok = true;
   
   while (ok)
   {
      ScreenMenu();
      cout << "Enter option -> ";
      cin.get(choice);
      PrintLines(2);
      if (choice == 'f')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option f - Find Meaning Of A Term." << endl;
         SearchForKey(tree);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cin.get(choice);
      } else if (choice == 'd')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option d - Deletes An Abbreviation And Its Meaning.";
         PrintLines(2);
         RemoveKey(tree);
         cin.get(choice);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      } else if (choice == 'i')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option i - Insert A New Term And Definition.";
         PrintLines(2);
         InsertNewItem(tree);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      } else if (choice == 'l')
      { 
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option l - List All Terms In The Dictionary (InOrder style)";
         PrintLines(2);
         ListItems(tree);
         cin.get(choice);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      } else if (choice == 'p')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option p - Print Tree (showing only the keys)";
         PrintLines(2);
         PrettyDisplayTree(tree);
         cin.get(choice);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      }  else if (choice == 'r')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option r - Rebalance The Tree";
         PrintLines(2);
         RebalanceTree(tree);
         cin.get(choice);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      }  else if (choice == 's')
      {
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
         cout << "Option s - Save Dictionary To A File";
         PrintLines(2);
         cout << "-----------------------------------------------------  " << endl;
         cout << "Saving contents of the dictionary to dictionary.dat" << endl;
         cout << "-----------------------------------------------------  " << endl;
         PrintLines(2);
         ofstream outfile;
         try {
            OpenOutputFile(outfile);
            SaveContents(outfile, tree);
            cout << "Thank you for your patience." << endl;
            cout << "Contents have been successfully saved!";
            PrintLines(2);
         } catch (cexception de) {
            cout << de.what() << endl << endl;
         }
         cin.get(choice);
         cout << "------------------------------------------";
         cout << "-------------------------------" << endl;
      }  else if (choice == 'x')
      {
         try {
            ofstream outfile;
            OpenOutputFile(outfile);
            SaveContents(outfile, tree);
            CloseOutputFile(outfile);
            ok = false;
         } catch (cexception xe) {
            cout << xe.what() << endl << endl;
         }
         PrintLines(2);
      } 
   }
   
}
//@finds the meaning of a given texting abbreviation
//@pre: tree is already built
//@post: prompts user for key and finds the meaning. if key not found,
//@      throws an exception
//@param: tree
//@usage: SearchForKey(tree);
void SearchForKey(const cbstree& tree)
{
   Ckey searchKey;
   Citem definition;
   PrintLines(1);
   cout << "Please enter the texting abbreviation: ";
   cin >> searchKey;
   PrintLines(1);
   try {
      tree.retrieve(searchKey, definition);
      cout << "Thanks for your patience." << endl;
      cout << "The definition for '"  << searchKey << "' is found!";
      PrintLines(2);
      cout << "The abbreviation is listed along with definition" << endl;
      cout << "Eg: lol (followed by definition) laugh out loud";
      PrintLines(2);
      cout << definition;
      PrintLines(2);
   } catch (cexception de) {
      cout << de.what();
      PrintLines(2);
   }
}

//@lists all the items in the dictionary on the screen
//@pre: tree is already assigned
//@post: prints all the keys and definitions of the dictionary
//@      on screen
//@param: tree
//@usage: ListItems(tree);
void ListItems(cbstree tree) 
{
   cout << "----------------------------------------------" << endl;
   cout << "The contents of the dictionary are shown below" << endl;
   cout << "----------------------------------------------";
   PrintLines(2);    
   cout << "The abbreviation is printed first, followed by the definition" << endl;
   cout << "Eg: lol laugh out loud" << endl;
   cout << "(lol is the abbreviation,";
   cout << " laugh out loud is the definition)" << endl;
   PrintLines(2);
   tree.inorderTraverse();
}

//@opens an external file for writing
//@post if the external file fileName exists, then
//@        it is associated with outfile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param outfile
//@usage OpenOutputFile(outfile);
void OpenOutputFile(ofstream& outfile) throw (cexception)
{   
   outfile.open("dictionary.dat");
   if (outfile.fail())
   {
      throw ("Error! Dictionary not found!");
   }
}
 
//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception)
{
   infile.open("dictionary.dat");
   if (infile.fail())
   {
      throw ("Error! Dictionary not found!");
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
