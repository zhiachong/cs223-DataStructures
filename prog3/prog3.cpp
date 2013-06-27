//@author Zhia Chong
//@date 9 Feb 2011
//@file prog3.cpp
//@description this program prints out pre-order, 
//@            post-order and in-order traversals.

#include <iostream>
#include <fstream>
#include "cnode.h"
#include "cbintree.h"
using namespace std;

//@opens an external file for reading
//@post if the external file "in3.txt" exists, then
//@     it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param tree
//@usage GetInputFromFile(infile, mytree);
void GetInputFromFile(ifstream& infile, Cbintree& tree);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@this function makes Tree 1 as according to textbook 
//@as according to Figure 10.6b on page504
//@pre tree object exists
//@post creates the tree as according to Figure 10.6b
//@param tree
//@param infile
//@usage makeTreeOne(mytree, infile);
void makeTreeOne(Cbintree& tree, ifstream& infile);

//@this function makes Tree2 as according to textbook 
//@as according to Figure 10.6c on page504
//@pre tree object exists
//@post creates the tree as according to Figure 10.6c
//@param tree
//@param infile
//@usage makeTreeOne(mytree, infile);
void makeTreeTwo(Cbintree& tree, ifstream& infile);

//@this function makes Tree3 as according to the requirement
//@pre tree object exists
//@post creates the tree as according to the requirement sheet
//@param tree
//@param infile
//@usage makeTreeThree(mytree, infile);
void makeTreeThree(Cbintree& tree, ifstream& infile);

//@initializes tree and starts the program
//@post fills out the trees and prints out the traversals
//@usage StartTree();
void StartTree();

//@prints out the header for each tree
//@pre num, ch, and page are assigned
//@post prints out the header 
//@usage PrintHeader(1, 'b', 504);
void PrintHeader(int num, char ch, int page);

//@prints out the header for third tree
//@post prints out the header with the original expression
//@usage PrintHeaderForThirdTree();
void PrintHeaderForThirdTree();

//@prints out the intro for pre-order traversal
//@post prints out the header
//@usage PrintIntroForPreOrder();
void PrintIntroForPreOrder();

//@prints out the intro for post-order traversal
//@post prints out the header
//@usage PrintIntroForPostOrder();
void PrintIntroForPostOrder();

//@prints out the intro for in-order traversal
//@post prints out the header
//@usage PrintIntroForInOrder();
void PrintIntroForInOrder();

//@prints out the intro for this program
//@post prints out the header
//@usage PrintIntro();
void PrintIntro();

//@prints out the tree in the figure 10-6b
//@post prints out the tree
//@usage PrintTree();
void PrintTree();

//@prints out the tree in the figure 10-6c
//@post prints out the tree
//@usage PrintTree2();
void PrintTree2();

//@prints out the tree for the infix expression given
//@post prints out the tree
//@usage PrintTree();
void PrintTree3();

int main()
{
   StartTree();
   return 0;
}

//@initializes tree and starts the program
//@post fills out the trees and prints out the traversals
//@usage StartTree();
void StartTree()
{
   Cbintree mytree;
   Cbintree newtree;
   Cbintree newtree2;
   ifstream infile;
   bool ok;
   
   PrintLines(2);
   PrintIntro();
   
   OpenInputFile(infile, ok);
   
   PrintHeader(1, 'b', 504);
   PrintTree();
   makeTreeOne(mytree, infile);
   
   PrintIntroForPreOrder();
   mytree.preOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForPostOrder();
   mytree.postOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForInOrder();
   mytree.inOrderPrint();
   
   PrintLines(2);
   ToContinue();
   
   PrintHeader(2, 'c', 504);
   PrintTree2();
   makeTreeTwo(newtree, infile);
   
   PrintIntroForPreOrder();
   newtree.preOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForPostOrder();
   newtree.postOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForInOrder();
   newtree.inOrderPrint();
   
   PrintLines(2);
   
   ToContinue();
   
   PrintHeaderForThirdTree();
   PrintTree3();
   
   makeTreeThree(newtree2, infile);
   
   PrintIntroForPreOrder();
   newtree2.preOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForPostOrder();
   newtree2.postOrderPrint();
   
   PrintLines(2);
   
   PrintIntroForInOrder();
   newtree2.inOrderPrint();
   
   PrintLines(2);
  
   CloseInputFile(infile); 
}

//@prints out the tree in figure 10-6b
//@post prints out the tree
//@usage PrintTree();
void PrintTree()
{
   cout << "The tree for this expression:" << endl << endl;
   cout << "           A        ";
   PrintLines(1);
   cout << "         /    \\      ";
   PrintLines(1);
   cout << "       B       C     " << endl;
   cout << "      / \\        " << endl;
   cout << "     D   E      " << endl;
   cout << "    /        " << endl;
   cout << "   F            " << endl;
   cout << "  /               " << endl;
   cout << " G                  " << endl;
   PrintLines(1);
}

//@prints out the tree in figure 10-6c
//@post prints out the tree
//@usage PrintTree2();
void PrintTree2()
{
   cout << "The tree for this expression:" << endl << endl;
   cout << "           A        ";
   PrintLines(1);
   cout << "             \\      ";
   PrintLines(1);
   cout << "              B     " << endl;
   cout << "             /     " << endl;
   cout << "            C   " << endl;
   cout << "             \\" << endl;
   cout << "              D " << endl;
   cout << "             /    " << endl;
   cout << "            E      " << endl;
   cout << "             \\    " << endl;
   cout << "              F    " << endl;
   cout << "             /     " << endl;
   cout << "            G       " << endl;
   PrintLines(1);
}

//@prints out the tree for the infix expression given
//@post prints out the tree
//@usage PrintTree3();
void PrintTree3()
{
   cout << "The tree for this expression:" << endl << endl;
   cout << "         *        ";
   PrintLines(1);
   cout << "       /    \\      ";
   PrintLines(1);
   cout << "     +       +     " << endl;
   cout << "    / \\     /  \\   " << endl;
   cout << "   a   b   /    e   " << endl;
   cout << "          / \\ " << endl;
   cout << "         c   d     " << endl;
   PrintLines(1);
}

//@prints out the intro for this program
//@post prints out the header
//@usage PrintIntro();
void PrintIntro()
{
   cout << "****************************************************";
   PrintLines(1);
   cout << "This is Programming Assignment #3 on ADT Binary Tree";
   PrintLines(1);
   cout << "Makes 3 trees and prints out Pre-Order, Post-Order";
   PrintLines(1);
   cout << "and In-Order traversals of the binary trees";
   PrintLines(1);
   cout << "****************************************************";
   PrintLines(1);
}

//@prints out the intro for pre-order traversal
//@post prints out the header
//@usage PrintIntroForPreOrder();
void PrintIntroForPreOrder()
{
   cout << "This is the pre-order traversal: ";
   PrintLines(1);
}

//@prints out the intro for post-order traversal
//@post prints out the header
//@usage PrintIntroForPostOrder();
void PrintIntroForPostOrder()
{
   cout << "This is the post-order traversal: ";
   PrintLines(1);
}

//@prints out the intro for in-order traversal
//@post prints out the header
//@usage PrintIntroForInOrder();
void PrintIntroForInOrder()
{
   cout << "This is the in-order traversal: ";
   PrintLines(1);
}

//@prints out the header for each tree
//@pre num, ch, and page are assigned
//@post prints out the header 
//@usage PrintHeader(1, 'b', 504);
void PrintHeader(int num, char ch, int page)
{
   PrintLines(1);
   cout << "--------------------------------------------------------------";
   PrintLines(1);
   cout << "Making Tree " << num << " from the textbook";
   cout << " of Figure 10-6"<< ch << " on page " << page << ".";
   PrintLines(1);
   cout << "--------------------------------------------------------------";
   PrintLines(2);
}
   
//@prints out the header for third tree
//@post prints out the header with the original expression
//@usage PrintHeaderForThirdTree();
void PrintHeaderForThirdTree()
{
   PrintLines(1);
   cout << "--------------------------------------------------------------";
   PrintLines(1);
   cout << "Making Tree 3 as according to assignment.";
   PrintLines(1);
   cout << "The original expression is: (a + b) * (c / d + e)";
   PrintLines(1);
   cout << "--------------------------------------------------------------";
   PrintLines(3);
}
//@this function makes TreeOne as according to textbook 
//@as according to Figure 10.6b on page504
//@pre tree object exists
//@post creates the tree as according to Figure 10.6b
//@param tree
//@param infile
//@usage makeTreeOne(mytree, infile);
void makeTreeOne(Cbintree& tree, ifstream& infile)
{
   for (int i = 0; i < 7; i++)
   {
      GetInputFromFile(infile, tree);
   }
}

//@this function makes Tree2 as according to textbook 
//@as according to Figure 10.6c on page504
//@pre tree object exists
//@post creates the tree as according to Figure 10.6c
//@param tree
//@param infile
//@usage makeTreeOne(mytree, infile);
void makeTreeTwo(Cbintree& tree, ifstream& infile)
{
   for (int i = 0; i < 7; i++)
   {
      GetInputFromFile(infile, tree);
   }
}

//@this function makes Tree3 as according to the requirement
//@pre tree object exists
//@post creates the tree as according to the requirement sheet
//@param tree
//@param infile
//@usage makeTreeThree(mytree, infile);
void makeTreeThree(Cbintree& tree, ifstream& infile)
{
   for (int i = 0; i < 9; i++)
   {
      GetInputFromFile(infile, tree);
   }
}

//@opens an external file for reading
//@post if the external file "in3.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("in3.txt");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@this function reads items from a file and inserts it
//@into a tree 
//@pre infile is open, and tree are assigned
//@post inputs data from file into tree
//@param infile
//@param tree
//@usage GetInputFromFile(infile, mytree);
void GetInputFromFile(ifstream& infile, Cbintree& tree)
{
   infile >> tree;      
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
