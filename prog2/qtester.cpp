//@author Zhia Chong
//@date Jan 17, 2011
//@file qtester.cpp
//@description: This program fully tests class Que.

#include <iostream>
#include <fstream>
#include "que.h"
using namespace std;

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

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

int main()
{
   Que myq;
   ItemType it;
   bool ok;
   ifstream infile;
   
   PrintLines(3);
   PrintMessage ("copy constructor", "empty");
   Que bq(myq);

   PrintMessage ("IsEmpty", "empty");
   PrintBool (myq.IsEmpty());

   ToContinue();  

   PrintMessage ("Enqueue", "empty");
   cout << it;
   PrintLines(2);
   OpenInputFile(infile, ok);
   GetInputFromFile(infile, it);
   PrintMessage("Enqueue", "after Enqueue");
   myq.Enqueue(it,ok);
   cout << myq << endl;
   PrintBool (ok);

   PrintMessage ("IsEmpty", "non-empty");
   PrintBool (myq.IsEmpty());

   ToContinue();
   
   PrintMessage ("Enqueue", "size 1"); 
   cout << myq << endl; 
  
   GetInputFromFile(infile, it);
   PrintMessage("Enqueue", "after Enqueue");
   myq.Enqueue(it, ok);
   cout << myq << endl;
   PrintBool (ok);
 
   PrintMessage ("copy constructor", "size 2");
   Que otherq(myq);
   cout << otherq << endl;

   ToContinue();  
   
   PrintMessage ("Dequeue", "size 2");
   cout << myq << endl;
   myq.Dequeue(ok);
   PrintBool (ok);
   cout << myq << endl;
   PrintMessage ("Dequeue", "size 1");
   myq.Dequeue(ok);
   cout << myq << endl;
   PrintBool (ok);
   
   ToContinue();

   PrintMessage ("Dequeue", "empty");
   myq.Dequeue(ok);
   PrintBool (ok);

   ToContinue();

   PrintMessage(" GetFront", "size 2");
   GetInputFromFile(infile, it);
   PrintLines(2);
   cout << otherq << endl;
   GetInputFromFile(infile, it);
   otherq.Enqueue(it, ok);
   PrintLines(2);
   cout << otherq << endl;
   if (!otherq.IsEmpty())
   {
      otherq.GetFront(it);
      PrintLines(1);
      cout << "front = " << it << endl;
      PrintLines(1);
      cout << otherq << endl;
      PrintBool (ok);
   }
      
   ToContinue();
   
   PrintMessage("GetSize", "size 3");
   cout << otherq << endl;
   cout << "size = " << otherq.GetSize() << endl;
   PrintMessage("GetSize", "size 0");
   cout << "size = " << myq.GetSize() << endl; 
   
   CloseInputFile(infile);
   return 0;  
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

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase)
{
   PrintLines(2);
   cout << "Testing *** " << which << " *** in the " 
        << whatCase << " case";
   PrintLines(2);
}

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok)
{
   cout << endl << "          Boolean value is ";
   if (ok)
      cout << "true";
   else
      cout << "false";
   cout << endl;
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
//@pre infile, and myque are assigned
//@post generates a list of length size
//@param infile
//@param myque
//@usage GetInputFromFile(infile, myque);
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
