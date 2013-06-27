//@author Zhia Chong
//@date 24 March 2011
//@file prog6.cpp
//@description this is an initialization program that starts the avl tree
//@            opens up a document called in6.dat, and writes the avl tree
//@            to a document called avl.dat. The program will print a welcome message
//@            and a good bye message on screen while processing the information.

#include <fstream>
#include "cavltree.h"
using namespace std;
typedef Ckey Citem;

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@param outfile
//@usage PrintLines(2, outfile);
void PrintLines(int num, ofstream& outfile);

//@opens an external file for writing
//@post if the external file fileName exists, then
//@        it is associated with outfile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param outfile
//@usage OpenOutputFile(outfile);
void OpenOutputFile(ofstream& outfile) throw (cexception);

//@opens an external file for reading
//@post if the external file fileName exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param infile
//@usage OpenInputFile(infile);
void OpenInputFile(ifstream& infile) throw (cexception);

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

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item);

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram();

//@test cases for single left rotation
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRotateLeft(infile, outfile, tree);
void TestRotateLeftCase(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@test cases for has no pivot
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestHasNoPivot(infile, outfile, tree);
void TestHasNoPivot(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@test cases for add to short side
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestAddToShortSide(infile, outfile, tree);
void TestAddToShortSide(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@test cases for double right left rotation
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleRightLeft(infile, outfile, tree);
void TestDoubleRightLeft(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@test cases for double left right rotations
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleLeftRight(infile, outfile, tree);
void TestDoubleLeftRight(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@test cases for single right rotations
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRotateRight(infile, outfile, tree);
void TestRotateRightCase(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception);

//@prints a header for subcases, gets input and writes to an output file
//@pre: casenum is assigned, tree exists, input and output files are open
//@post: prints a header in the file, and writes output to output file
//@param casenum
//@param infile
//@param outfile
//@param tree
//@usage: WriteFile(19, infile, outfile, tree)
void WriteFile(int casenum, ifstream& infile, ofstream& outfile, cavltree& tree) throw (cexception);

int main()
{
   StartProgram();
   return 0;
}

//@test cases for single right rotations
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRotateRight(infile, outfile, tree);
void TestRotateRightCase(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Single Right Rotation cases" << endl;
   outfile << "-------------------------------------" << endl;
   outfile << "Subcase: Tree with 2 items and parent pointer is mroot" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 11 items and mroot" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items and parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 12 items and parent pointer is right pointer" << endl;
   WriteFile(12, infile, outfile, mytree);
   outfile << "Subcase: Tree with 15 items and parent pointer is right pointer" << endl;
   WriteFile(15, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items and parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items and parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items and the parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile,mytree);
   outfile << "**************************************************************************************************" << endl;
}
      
//@test cases for has no pivot
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestHasNoPivot(infile, outfile, tree);
void TestHasNoPivot(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Has No Pivot cases" << endl;
   outfile << "----------------------------------" << endl;
   outfile << "Subcase: Empty tree with no pivot" << endl;
   WriteFile(0, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and add to left" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and add to right" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 items and no pivot" << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 items and adding to right" << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 items and adding to left" << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 7 items, balanced and no pivot" << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 12 items and 3 subtrees with -1 balance" << endl;
   WriteFile(12, infile, outfile, mytree); 
   outfile << "**************************************************************************************************" << endl;
}

//@test cases for add to short side
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestAddToShortSide(infile, outfile, tree);
void TestAddToShortSide(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
	outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Add to short side cases" << endl;
   outfile << "----------------------------------" << endl;
   outfile << "Subcase: Tree with 2 items, tall left and added to the right" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item, tall right and add to left" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4 items, left subtree of height 1 and added to right" << endl;
   WriteFile(4, infile, outfile, mytree);   
   outfile << "Subcase: Tree with 4 items, left subtree of height 2 and added to right" << endl;
   WriteFile(4, infile, outfile, mytree);   
   outfile << "Subcase: Tree with 4 items, left subtree of height 2 and added to right" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items, right subtree of height 2 and added to left" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 6 items, tall right and added to left" << endl;
   WriteFile(6, infile, outfile, mytree);
   outfile << "Subcase: Tree with 8 items, left subtree of height 3 and added to right" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 8 items, left subtree of height 2 and added to right" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items, and added to left" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "**************************************************************************************************" << endl;
}

//@test cases for double right left rotation
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleRightLeft(infile, outfile, tree);
void TestDoubleRightLeft(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Double right left cases" << endl;
   outfile << "---------------------------------" << endl;
   outfile << "Subcase: Tree with 11 items, adding to left middle subtree and the parent pointer is mroot" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 11 items, adding to right middle subtree and the parent pointer is mroot" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items, adding to middle left subtree and the parent pointer is mroot" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items, adding to middle right subtree and the parent pointer is mroot" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle left subtree, and the parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle right subtree, and the parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle left subtree and parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle right subtree and parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "**************************************************************************************************" << endl;
}

//@test cases for double left right rotations
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleLeftRight(infile, outfile, tree);
void TestDoubleLeftRight(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
   outfile << "*********************************************************************************************************" << endl;
   outfile << "Tests for Double left right cases" << endl;
   outfile << "---------------------------------" << endl;
   outfile << "Subcase: Tree with 9 items, adding to middle left subtree, the parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 19 items, adding to middle left subtree, and parent pointer is right pointer" << endl;
   WriteFile(19, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items, adding to middle right subtree which was initially empty, parent pointer is mroot" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 23 items, adding to middle left subtree, parent pointer is mroot" << endl;
   WriteFile(23, infile, outfile, mytree);
   outfile << "Subcase: Tree with 23 items, adding to middle right subtree, parent pointer is mroot" << endl;
   WriteFile(23, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle left subtree which was initally empty and the parent pointer is right pointer" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle left subtree which was initially empty and the parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile,mytree);
   outfile << "Subcase: Tree with 9 items, adding to middle right subtree which was initially empty and the parent pointer is left pointer" << endl;
   WriteFile(9, infile, outfile,mytree);
   outfile << "*********************************************************************************************************" << endl;
}

//@test cases for single left rotation
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRotateLeft(infile, outfile, tree);
void TestRotateLeftCase(ifstream& infile, ofstream& outfile, cavltree& mytree) throw (cexception)
{
   outfile << "*********************************************************************************************************" << endl;
   outfile << "Tests for Single Left Rotation cases" << endl;
   outfile << "------------------------------------" << endl;
   outfile << "Subcase: Tree with 2 items and parent pointer is mroot" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4 items and parent pointer is left pointer" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items and parent pointer is right pointer" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 12 items and parent pointer is right pointer" << endl;
   WriteFile(12, infile, outfile, mytree);
   outfile << "Subcase: Tree with 5 items and parent pointer is mroot" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 19 items and parent pointer is left pointer" << endl;
   WriteFile(19, infile, outfile, mytree);
   outfile << "Subcase: Tree with 11 items and parent pointer is mroot" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 14 items and parent pointer is right pointer" << endl;
   WriteFile(14, infile, outfile, mytree);
   outfile << "*********************************************************************************************************" << endl;
}

//@prints a header for subcases, gets input and writes to an output file
//@pre: casenum is assigned, tree exists, input and output files are open
//@post: prints a header in the file, and writes output to output file
//@param casenum
//@param infile
//@param outfile
//@param tree
//@usage: WriteFile(19, infile, outfile, tree)
void WriteFile(int casenum, ifstream& infile, ofstream& outfile, cavltree& tree)
                           throw (cexception)
{
   Citem key;
   try {
      for (int i = 0; i < casenum; i++)
      {
         GetInputFromFile(infile, key);
         tree.insert(key);
      }
      outfile << "Pre: " << endl << endl;
      tree.prettyDisplay(outfile);
      PrintLines(2, outfile);
      
      GetInputFromFile(infile, key);
      
      outfile << "Inserting " << key << endl << endl;
      outfile << "Post: " << endl << endl;
      tree.insert(key);
      tree.prettyDisplay(outfile);
      PrintLines(2, outfile);
      tree.~cavltree();
   } catch (cexception de)
   {
      cout << de.what() << endl;
   }   
}

//@initializes the program
//@post starts the program by calling other functions 
//@usage StartProgram();
void StartProgram()
{
   ifstream infile;
   ofstream outfile;
   cavltree tree;
   Citem key;
   try {
      OpenInputFile(infile);
      OpenOutputFile(outfile);
      cout << endl << endl;;
      cout << "       ";
      cout << "----------------------------------------------------------" << endl;
      cout << "       ";
      cout << "|            Welcome to Zhia's Spectacular AVL Tree      |" << endl;
      cout << "       ";
      cout << "----------------------------------------------------------" << endl;
   } catch (cexception de)
   {
      cout << de.what() << endl;
   }
   cout << endl << endl;
   cout << "----Processing the data right now----" << endl;
   cout << endl;
   cout << "                ";
   cout << "-------------------------------------" << endl;
   cout << "                ";
   cout << "|    PLEASE WAIT WHILE WE PROCESS   |" << endl;
   cout << "                ";
   cout << "-------------------------------------" << endl;
   cout << endl;
   cout << endl;
   cout << "Thank you for waiting! Process has been successfully completed." << endl;
   cout << "The file is saved in a document called avl.dat." << endl;
   cout << "Have a nice day!" << endl;
   cout << endl << endl;
   
   TestHasNoPivot(infile, outfile, tree);
   TestRotateLeftCase(infile, outfile, tree);
   TestRotateRightCase(infile, outfile, tree);
   TestAddToShortSide(infile, outfile, tree);
   TestDoubleRightLeft(infile, outfile, tree);
   TestDoubleLeftRight(infile, outfile, tree);
   
   CloseInputFile(infile);
   CloseOutputFile(outfile);
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
   infile.open("in6.dat");
   if (infile.fail())
   {
      throw ("Error! Dictionary not found!");
   }
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

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@param outfile
//@usage PrintLines(2, outfile);
void PrintLines(int num, ofstream& outfile)
{
   for (int i = 0; i < num; i++)
   {
      outfile << endl;
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

//@opens an external file for writing
//@post if the external file fileName exists, then
//@        it is associated with outfile, its
//@     pointer is at the beginning else an exception
//@     is thrown
//@param outfile
//@usage OpenOutputFile(outfile);
void OpenOutputFile(ofstream& outfile) throw (cexception)
{   
   outfile.open("avl.dat");
   if (outfile.fail())
   {
      throw ("Error! Dictionary not found!");
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

