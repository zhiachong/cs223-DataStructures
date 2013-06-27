//@author Zhia Chong
//@date 24 March 2011
//@file prog8.cpp
//@description this is an initialization program that starts the 234 tree
//@            opens up a document called in8.dat, and writes the 234 tree
//@            to a document called out8.dat. The program will print a welcome message
//@            and a good bye message on screen while processing the information.

#include <fstream>
#include "c234node.h"
#include "citem.h"
#include "c234tree.h"
#include "cexception.h"


const char RED[] = "\033[22;31m"; //sets the output to red
const char RESET[] = "\033[0m"; //resets to white color
char process[7] = {'L', 'O', 'A', 'D', 'I', 'N', 'G'};

//@this function merely prints out dots to visualize the program's processing work
//@pre time is assigned
//@post prints out beautiful dots on screen 
//@param time
//@usage Wait(3);
void Wait(int time);

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

//@this function reads items from a file and Inserts it
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

//@test cases for splitting level 3 node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitLevelThree(infile, outfile, tree);
void TestSplitLevelThree(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for split at root level
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitCase(infile, outfile, tree);
void TestSplitCase(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for root
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRootCase(infile, outfile, tree);
void TestRootCase(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for Level two splitting
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitLevelTwo(infile, outfile, tree);
void TestSplitLevelTwo(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for double split
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleSplit(infile, outfile, tree);
void TestDoubleSplit(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for inserting into level 2 nodes
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestInsertToLevelTwo(infile, outfile, tree);
void TestInsertToLevelTwo(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@test cases for adding to level 3 node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestInsertToLevelThree(infile, outfile, tree);
void TestInsertToLevelThree(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception);

//@prints a header for subcases, gets input and writes to an output file
//@pre: casenum is assigned, tree exists, input and output files are open
//@post: prints a header in the file, and writes output to output file
//@param casenum
//@param infile
//@param outfile
//@param tree
//@usage: WriteFile(19, infile, outfile, tree)
void WriteFile(int casenum, ifstream& infile, ofstream& outfile, c234tree& tree) throw (cexception);


int main()
{
   StartProgram();
   return 0;
}

//@test cases for inserting into level 2 nodes
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestInsertToLevelTwo(infile, outfile, tree);
void TestInsertToLevelTwo(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Insert Into Level 2 cases" << endl;
   outfile << "-------------------------------------" << endl;
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a large item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a small item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a middle item" << endl;
   WriteFile(4, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a large item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a small item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a middle item" << endl;
   WriteFile(4, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a large item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a small item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a small item" << endl;
   WriteFile(4, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a large item" << endl;
   WriteFile(4, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a mid item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a small item" << endl;
   WriteFile(5, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a mid item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to mid-left a small item" << endl;
   WriteFile(5, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a large item" << endl;
   WriteFile(6, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a mid item" << endl;
   WriteFile(6, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent and 2 kids and add to left a small item" << endl;
   WriteFile(6, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent and add to mid-right a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent and add to mid-right a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent and add to mid-right a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent and add to mid-right a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent and add to mid-right a mid item" << endl;
   WriteFile(8, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent and add to mid-left a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent and add to mid-left a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent and add to right a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to right a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to right a mid item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to mid-right a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to mid-right a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent and add to mid-left a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to mid-left a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent and add to left a small item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent and add to left a large item" << endl;
   WriteFile(8, infile, outfile, mytree);
   outfile << "**************************************************************************************************" << endl;
}
      
//@test cases for root node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestRootCase(infile, outfile, tree);
void TestRootCase(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for root case" << endl;
   outfile << "----------------------------------" << endl;
   outfile << "Subcase: Empty tree with no pivot" << endl;
   WriteFile(0, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and insert item that is > root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and insert item that is < root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and insert item that is > root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that is > both" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that is in middle" << endl;
   WriteFile(2, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 1 item and insert item that is > root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that is < both" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and insert item that is < root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that is > both" << endl;
   WriteFile(2, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 1 item and insert item that is < root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that < both" << endl;
   WriteFile(2, infile, outfile, mytree);
   outfile << "Subcase: Tree with 1 item and insert item that is < root" << endl;
   WriteFile(1, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2 item and insert item that is in middle" << endl;
   WriteFile(2, infile, outfile, mytree);   
   outfile << "**************************************************************************************************" << endl;
}

//@test cases for splitting of level 2 nodes
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitLevelTwo(infile, outfile, tree);
void TestSplitLevelTwo(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
	outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Split of Level 2 Nodes without double splitting cases" << endl;
   outfile << "----------------------------------" << endl;
   outfile << "Subcase: Tree with 2-node parent, 4-node left child, add to left a small item " << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent, 4-node left child, add to left a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent, 4-node left child, add to left a small item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent, 4-node left child, add to left a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 2-node parent, 4-node mid-left child, add to mid-left  a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent, 4-node mid-left child, add to mid-left  a small item" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent, 4-node mid-left child, add to mid-left  a small ite" << endl;
   WriteFile(5, infile, outfile, mytree);
   outfile << "Subcase: Tree with 2-node parent, 4-node mid-left child, add to mid-left  a large item" << endl;
   WriteFile(5, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent, 4-node left child, add to left  a large item" << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node left child, add to left  a small item" << endl;
   WriteFile(7, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent, 4-node left child, add to mid-left  a large item " << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node left child, add to mid-left  a small item " << endl;
   WriteFile(7, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-left child, add to left  a large item " << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-left child, add to left  a small item " << endl;
   WriteFile(7, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-left child, add to mid-left  a large item " << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-left child, add to mid-left  a small item" << endl;
   WriteFile(7, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-right child, add to mid-right  a small item" << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-right child, add to mid-right  a large item" << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-right child, add to mid-right  a small item " << endl;
   WriteFile(7, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3-node parent, 4-node mid-right child, add to mid-right  a large item" << endl;
   WriteFile(7, infile, outfile, mytree);
   
   
   outfile << "**************************************************************************************************" << endl;
}

//@test cases for double split
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestDoubleSplit(infile, outfile, tree);
void TestDoubleSplit(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
   outfile << "**************************************************************************************************" << endl;
   outfile << "Tests for Doublt Split cases" << endl;
   outfile << "---------------------------------" << endl;
   outfile << "Subcase: Tree with 4-node parent, 4-node left child, add a middle item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node left child, add a small item " << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node left child, add a large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node left child, add a mid-large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-left child, add a small item " << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-left child, add a mid item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-left child, add a mid-large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-left child, add a large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-right child, add a mid-large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-right child, add a small item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-right child, add a mid item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node mid-right child, add a large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 4-node parent, 4-node right child, add a mid-large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node right child, add a small item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node right child, add a mid item" << endl;
   WriteFile(9, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, 4-node right child, add a large item" << endl;
   WriteFile(9, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a small item to cause double split" << endl;
   WriteFile(14, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to cause double split" << endl;
   WriteFile(14, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to cause double split" << endl;
   WriteFile(14, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid item to cause double split" << endl;
   WriteFile(14, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a mid item to cause double split" << endl;
   WriteFile(15, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a small item to cause double split" << endl;
   WriteFile(15, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to cause double split" << endl;
   WriteFile(15, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to cause double split" << endl;
   WriteFile(15, infile, outfile, mytree);
   outfile << "**************************************************************************************************" << endl;
}



//@test cases for split of root node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitCase(infile, outfile, tree);
void TestSplitCase(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
   outfile << "*********************************************************************************************************" << endl;
   outfile << "Tests for splitting of root node" << endl;
   outfile << "------------------------------------" << endl;
   outfile << "Subcase: Tree with 4-node parent, split node and insert to left " << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, split node and add to left " << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, split node and insert to middle left" << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "Subcase: Tree with 4-node parent, split node and insert to middle left" << endl;
   WriteFile(3, infile, outfile, mytree);
   outfile << "*********************************************************************************************************" << endl;
}


//@test cases for adding to level 3 node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestInsertToLevelThree(infile, outfile, tree);
void TestInsertToLevelThree(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{
   outfile << "*********************************************************************************************************" << endl;
   outfile << "Tests for Inserting Into Level Three Node" << endl;
   outfile << "-----------------------------------------" << endl;
   outfile << "Subcase: Tree with 3 levels and insert a small item to left subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid item to left subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to left subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a small item to mid-left subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to mid-left subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a small item to mid-right subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to mid-right subtree" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels, insert into mid-left subtree and insert a small item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a large item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels, insert into mid-left subtree and insert a small item to mid-left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels, insert into mid-left subtree and insert a mid item to mid-left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a large item to mid-left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a mid item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a small item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a large item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a mid item to left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a small item to left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into left subtree and insert a large item to left leaf" << endl;
   WriteFile(11, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a large item to mid-right leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a small item to mid-right leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a mid item to mid-right leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a large item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a small item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a mid item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a large item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a small item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels insert into mid-left subtree and insert a mid item to left leaf" << endl;
   WriteFile(10, infile, outfile, mytree);
   outfile << "*********************************************************************************************************" << endl;
}

//@test cases for splitting level 3 node
//@pre: input and output file are already opened and tree exists
//@post: writes the cases,along with clearly labeled headers onto output file
//@param infile
//@param outfile
//@param mytree
//@usage TestSplitLevelThree(infile, outfile, tree);
void TestSplitLevelThree(ifstream& infile, ofstream& outfile, c234tree& mytree) throw (cexception)
{

   outfile << "*********************************************************************************************************" << endl;
   outfile << "Tests for Splitting Level Three Node without triple splitting" << endl;
   outfile << "-------------------------------------------------------------" << endl;
   outfile << "Subcase: Tree with 3 levels and insert a small item to left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid item to left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a mid item to mid-left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a small item to mid-left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a large item to mid-left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to mid-left subtree to cause splitting" << endl;
   WriteFile(11, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a large item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a small item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   
   outfile << "Subcase: Tree with 3 levels and insert a large item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a small item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   outfile << "Subcase: Tree with 3 levels and insert a mid-large item to mid-right subtree to cause splitting" << endl;
   WriteFile(13, infile, outfile, mytree);
   
   
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
void WriteFile(int casenum, ifstream& infile, ofstream& outfile, c234tree& tree)
                           throw (cexception)
{
   Citem key;
   try {
      for (int i = 0; i < casenum; i++)
      {
         GetInputFromFile(infile, key);
         tree.Insert(key);
      }
      outfile << "Pre: " << endl << endl;
      tree.prettyDisplay(outfile);
      PrintLines(2, outfile);
      
      GetInputFromFile(infile, key);
      
      outfile << "Inserting " << key << endl << endl;
      outfile << "Post: " << endl << endl;
      tree.Insert(key);
      tree.prettyDisplay(outfile);
      PrintLines(2, outfile);
      tree.~c234tree();
   } catch (cexception de)
   {
      cout << de.what() << endl;
   }   
}

//@initializes the program
//@post starts the program by calling other functions and prints introduction
//@usage StartProgram();
void StartProgram()
{
   ifstream infile;
   ofstream outfile;
   c234tree tree;
   Citem key;
   try {
      OpenInputFile(infile);
      OpenOutputFile(outfile);
      cout << endl << endl;;
      cout << "       ";
      cout << "----------------------------------------------------------" << endl;
      cout << "       ";
      cout << "|            Welcome to Zhia's Spectacular 2-3-4 Tree    |" << endl;
      cout << "       ";
      cout << "----------------------------------------------------------" << endl;
   } catch (cexception de)
   {
      cout << de.what() << endl;
   }
   
   TestRootCase(infile, outfile, tree);
   TestSplitCase(infile, outfile, tree);
   TestInsertToLevelTwo(infile, outfile, tree);
   TestSplitLevelTwo(infile, outfile, tree);
   TestDoubleSplit(infile, outfile, tree);
   TestInsertToLevelThree(infile, outfile, tree);
   TestSplitLevelThree(infile, outfile, tree);
   
   
   cout << endl << endl;
   cout << "                 ";
   cout << "----Processing the data right now----" << endl;
   cout << endl << endl;
   cout << "                ";
   cout << "-------------------------------------" << endl;
   cout << "                ";
   cout << "|    PLEASE WAIT WHILE WE PROCESS   |" << endl;
   cout << "                ";
   cout << "-------------------------------------" << endl;
   cout << endl << endl << endl;
   cout << "                          ";
   
   Wait(7);
   
   cout << endl << endl << endl;
   
   cout << endl;
   cout << "Thank you for waiting! Process has been successfully completed." << endl;
   cout << "The file is saved in a document called " << RED << "out8.dat." << RESET << endl;
   cout << "Have a nice day!" << endl;
   cout << endl << endl;
   
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
   infile.open("in8.dat");
   if (infile.fail())
   {
      throw ("Error! Input file not found!");
   }
}

//@this function reads items from a file and Inserts it
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
   outfile.open("out8.dat");
   if (outfile.fail())
   {
      throw ("Error! Output file not found!");
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

//@this function merely prints out dots to visualize the program's processing work
//@pre time is assigned
//@post prints out beautiful dots on screen 
//@param time
//@usage Wait(3);
void Wait(int time)
{
   for (int i = 0; i < time; i++)
   {
      
      if (i%2 == 1)
         cout << RED;
      else 
         cout << RESET;
      
      cout << process[i] << ".";
      sleep(1);
      cout.flush();
   }
   sleep(1);
}


