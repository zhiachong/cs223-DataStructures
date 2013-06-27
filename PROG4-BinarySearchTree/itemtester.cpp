//@author Zhia Chong
//@date 2/15/2011
//@file itemtester.cpp
//@description this is a tester program that fully tests class Citem

#include <iostream>
#include <fstream>
#include <string>
#include "citem.h"
using namespace std;

//@prints out a title for this tester
//@post a header is printed on screen
//@usage PrintHeader();
void PrintHeader();

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@this function read items from a file and inserts it
//@into an item 
//@pre infile, and item are assigned
//@post generates a list of length size
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, Citem& item);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@param num
//@usage PrintLines(3);
void PrintLines (int num);

//@prints a title for the case
//@pre casenum and name are assigned
//@post prints a title on the screen
//@param casenum
//@param name
//@usage PrintTitle(1, "Getting Input From File");
void PrintTitle(int casenum, string name);

int main()
{
   Citem item, item2;
   ifstream infile;
   bool ok;
   char ch;
   
   PrintLines(2);
   PrintHeader();
   
   PrintLines(2);
   
   OpenInputFile(infile, ok);
   
   PrintTitle(1, "Getting Input From File");
   GetInputFromFile(infile, item);
   cout << item << endl;
   ToContinue();
   PrintLines(2);
   
   PrintTitle(2, "Getting Input From User");
   cout << "Enter Key: ";
   cin >> item;
   PrintLines(1);
   cout << "This is the input -> ";
   cout << item << endl;
   ToContinue();
   PrintLines(2);
   
   PrintTitle(3, "Comparing Between 2 Items");
   cout << "---Getting Input From File---" << endl;
   GetInputFromFile(infile, item);
   cout << item << endl << endl;
   GetInputFromFile(infile, item2);
   cout << item2;
   PrintLines(2);
   cout << "Results -> ";
   if (item == item2)
   { 
      cout << "Both keys are equal" << endl;
   } else {
      cout << "Keys are not equal" << endl;
   }
   ToContinue();
   PrintLines(1);
   
   cout << "***User Prompt To Check Operator== Manually***";
   PrintLines(1);
   cout << "Enter key: ";
   cin >> item;
   cout << "Enter second key: ";
   cin >> item2;
   PrintLines(1);
   cout << "Results -> ";
   if (item == item2)
   { 
      cout << "Both keys are equal" << endl;
   } else {
      cout << "Keys are not equal" << endl;
   }
   
   ToContinue();
   PrintLines(2);

   PrintTitle(4, "Checking Less Than");
   cout << "---Getting Input From File---" << endl;
   GetInputFromFile(infile, item);
   cout << "The input is -> " << item;
   PrintLines(2);
   GetInputFromFile(infile, item2);
   cout << "The second input is -> " << item2;
   PrintLines(2);
   cout << "Results -> ";
   if (item < item2)
   {
      cout << "First input is less than second input" << endl;
   } else {
      cout << "First input is not less than second input" << endl;
   }
   ToContinue();
   PrintLines(2);
   
   cout << "***User Prompt To Check Operator< Manually***";
   PrintLines(2);
   cout << "Enter key: ";
   cin >> item;
   cout << "Enter second key: ";
   cin >> item2;
   PrintLines(1);
   cout << "Results -> ";
   if (item < item2)
   {
      cout << "First input is less than second input" << endl;
   } else {
      cout << "First input is not less than second input" << endl;
   }
   ToContinue();
   PrintLines(2);
   
   PrintTitle(5, "Copying Items");
   cout << "Item1 to be copied -> " << item << endl;
   cout << "NewItem before copying Item1 -> " << item2 << endl;
   item = item2;
   PrintLines(1);
   cout << "Original item: " << item << endl;
   cout << "Copied item: " << item2 << endl;
   ToContinue();
   
   PrintLines(2);
   PrintTitle(6, "Testing Copy Constructor");
   cout << "Original Item -> " << item << endl;
   PrintLines(1);
   Citem newItem(item);
   cout << "---Calling Copy Constructor---" << endl;
   cout << "New item -> " << newItem << endl;
   PrintLines(2);
   
   CloseInputFile(infile);
   return 0;   
}

//@prints a title for the case
//@pre casenum and name are assigned
//@post prints a title on the screen
//@param casenum
//@param name
//@usage PrintTitle(1, "Getting Input From File");
void PrintTitle(int casenum, string name)
{
	cout << "****************************************" << endl;
	cout << "Case no: " << casenum << " " << name << endl;
    cout << "****************************************" << endl;
}

//@prints out a title for this tester
//@post a header is printed on screen
//@usage PrintHeader();
void PrintHeader()
{
   cout << "****************************************" << endl;
   cout << "***This is a tester program for Citem***" << endl;
   cout << "****************************************" << endl;
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

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("dictionary.dat");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@this function read items from a file and inserts it
//@into a que 
//@pre infile, and myque are assigned
//@post generates a list of length size
//@param infile
//@param myque
//@usage GetInputFromFile(infile, myque);
void GetInputFromFile(ifstream& infile, Citem& item)
{
   infile >> item;      
}

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile)
{
   infile.close();
}
