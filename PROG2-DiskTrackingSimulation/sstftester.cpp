//@author Zhia Chong
//@date Jan 22, 2011
//@file sstftester.cpp
//@description: This program fully tests class SSTF.

#include <iostream>
#include <fstream>
#include "sstf.h"
using namespace std;

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
//@into a que 
//@pre infile, and item are assigned
//@post generates a list of length size
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, ItemType& item);

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

//@prints a testing message on the screen
//@pre which is strings
//@post which is output on the screen
//@usage PrintMessage("Enqueue");
void PrintMessage (const char* which);

int main()
{
   SSTF myseek;
   ifstream infile;
   bool ok;
   ItemType item;
   
   cout << "***This program fully tests the class SSTF***";
   PrintLines(2);
   
   PrintMessage("Enqueue");
   PrintLines(1);
   OpenInputFile(infile, ok);
   GetInputFromFile(infile, item);
   cout << "Before: " << myseek;
   PrintLines(2);
   cout << "After Enqueue: ";
   myseek.Enqueue(item, ok);
   cout << myseek;
   
   ToContinue();

   PrintMessage("Enqueue");
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   cout << "Current que: " << myseek;
   PrintLines(2);
   
   ToContinue();
             
   PrintMessage("GetNextRecord");
   cout << "Current que: " << myseek;
   PrintLines(2);
   cout << "***Getting next record***" << endl;
   myseek.GetNextRecord(item);
   cout << "Next record to be serviced: " << item;
   
   ToContinue();
   
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   
   PrintMessage("Dequeue");
   cout << "Current que: " << myseek;
   cout << "***Dequeue***" << endl;
   myseek.Dequeue(ok);
   cout << "After dequeue: " << myseek;
   
   ToContinue();
   
   myseek.GetNextRecord(item);
   myseek.Dequeue(ok);
   cout << "Current Que after dequeue: " << myseek;
   PrintLines(2);
   cout << "***Getting next record and servicing***" << endl;
   myseek.GetNextRecord(item);
   myseek.Dequeue(ok);
   cout << "Que after dequeue: " << myseek;
   
   ToContinue();
   
   myseek.GetNextRecord(item);
   myseek.Dequeue(ok);
   cout << "Current Que after dequeue: " << myseek;
   PrintLines(2);
   cout << "***Getting next record and servicing***" << endl;
   myseek.GetNextRecord(item);
   myseek.Dequeue(ok);
   cout << "Que after dequeue: " << myseek;
   
   ToContinue();
   
   GetInputFromFile(infile, item);
   myseek.Enqueue(item, ok);
   
   PrintMessage("CopyConstructor");
   cout << "Que -> " << myseek;
   PrintLines(2);
   cout << "Copied que -> ";
   SSTF seek(myseek);
   cout << seek;
   
   PrintLines(2);
   
   ToContinue();
   
   PrintMessage("Operator=");
   SSTF newseek;
   cout << "Que to be copied: " << myseek;
   PrintLines(1);
   cout << "Newly initialized variable: " << newseek;
   PrintLines(1);
   newseek = myseek;
   cout << "After operator= : " << newseek;
   PrintLines(2);
   
   ToContinue();
   
   PrintMessage("Destructor");
   cout << "Current que: " << myseek;
   myseek.~SSTF();
   cout << "After: " << myseek;
   PrintLines(3);
   
   CloseInputFile(infile);
   
   return 0;
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which)
{
   PrintLines(2);
   cout << "Testing *** " << which << "***";
   PrintLines(2);
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
   infile.open("in2.txt");
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
//@pre infile, and item are assigned
//@post generates a list of length size
//@param infile
//@param item
//@usage GetInputFromFile(infile, item);
void GetInputFromFile(ifstream& infile, ItemType& item)
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
