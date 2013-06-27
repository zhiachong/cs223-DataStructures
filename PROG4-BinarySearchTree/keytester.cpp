//@author Zhia Chong
//@date 2/15/2011
//@file keytester.cpp
//@description this is a tester program that fully tests class Ckey

#include <iostream>
#include <fstream>
#include <string>
#include "ckey.h"
using namespace std;

//@prints out a title for this tester
//@post a header is printed on screen
//@usage PrintHeader();
void PrintHeader();

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok);

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
//@into a que 
//@pre infile, and myque are assigned
//@post generates a list of length size
//@param infile
//@param myque
//@usage GetInputFromFile(infile, myque);
void GetInputFromFile(ifstream& infile, Ckey& item);

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
   Ckey mkey;
   Ckey key;
   ifstream infile;
   bool ok;
   char ch; 
   
   PrintLines(3);
   PrintHeader();
   PrintLines(2);
   
   PrintTitle(1, "Getting Input From File");
   OpenInputFile(infile, ok);
   GetInputFromFile(infile, mkey);
   cout << mkey;
   ToContinue();
   
   PrintTitle(1, "Getting Input From User");
   cout << "Please enter a key: ";
   cin >> mkey;
   cout << mkey << endl;
   ToContinue();
   cin.get(ch);
   
   PrintLines(2);
   PrintTitle(2, "Assigning Keys");
   cout << "The original key: " << mkey << endl;
   cout << "New key: " << key << endl << endl;
   cout << "----Assigning original key to new key----" << endl;
   key = mkey;
   cout << "New key -> " << key << endl;
   ToContinue();
   
   PrintLines(2);
   PrintTitle(3, "Checking Less Than");
   cout << "The original key -> " << mkey << endl;
   cout << "Getting input from file and inserting into new key" << endl;
   GetInputFromFile(infile, key);
   cout << "The new key -> " << key;
   PrintLines(2);
   cout << "---Checking whether new key is less than original key---" << endl;
   if (key < mkey)
   {
      cout << "New key is less than original key" << endl;
   } else {
      cout << "New key is not less than original key" << endl;
   }
   ToContinue();
   
   PrintLines(2);
   PrintTitle(4, "Checking Less Than With User Input");
   cout << "The original key -> " << mkey << endl;
   cout << "Please enter a key to new key: ";
   cin >> key;
   cout << "---Checking whether new key is less than original key---" << endl;
   if (key < mkey)
   {
      cout << "New key is less than original key" << endl;
   } else {
      cout << "New key is not less than original key" << endl;
   }
   ToContinue();
   cin.get(ch);
   
   PrintLines(2);
   PrintTitle(5, "Checking Equals To");
   cout << "The original key -> " << mkey << endl;
   cout << "Getting input from file and inserting into new key" << endl;
   GetInputFromFile(infile, key);
   cout << "The new key -> " << key;
   PrintLines(2);
   cout << "---Checking whether new key is equals to original key---" << endl;
   if (key == mkey)
   {
      cout << "New key is equals to original key" << endl;
   } else {
      cout << "New key is not equals to original key" << endl;
   }
   ToContinue();
   
   PrintLines(2);
   PrintTitle(6, "Checking Equals To With User Input");
   cout << "The original key -> " << mkey << endl;
   cout << "Please enter a key: ";
   cin >> key;
   cout << "---Checking whether new key is equals to original key---" << endl;
   if (key == mkey)
   {
      cout << "New key is equals to original key" << endl;
   } else {
      cout << "New key is not equals to original key" << endl;
   }
   ToContinue();
   cin.get(ch);
   
   PrintLines(2);
   PrintTitle(7, "Checking Copy Constructor");
   cout << "The original key -> " << mkey << endl;
   Ckey newkey(mkey);
   cout << "---Copying The Original Key---" << endl;
   cout << newkey << endl;
   ToContinue();
   
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
	cout << "*************************************" << endl;
	cout << "Case no: " << casenum << " " << name << endl;
    cout << "*************************************" << endl;
}

//@prints out a title for this tester
//@post a header is printed on screen
//@usage PrintHeader();
void PrintHeader()
{
   cout << "**************************************" << endl;
   cout << "***This is a tester program for Ckey***" << endl;
   cout << "**************************************" << endl;
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
   infile.open("ckeydict.dat");
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
void GetInputFromFile(ifstream& infile, Ckey& item)
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

