//@author Zhia Chong
//@date Jan 17, 2011
//@file itemtester.cpp
//@description: This program fully tests class Que. It is a tester program.

#include <iostream>
#include "itemtype.h"
using namespace std;

ItemType item;

//@starts the program
//@post program initializes
//@usage StartProgram();
void StartProgram();

//@prints a number of new lines
//@pre: num is assigned
//@post: outputs num new lines
//@param: num is the number of new lines to output
//@usage: PrintNewLines(2);
void PrintNewLines(int num);

//@tests ItemType's GetSector
//@post retrieves the sector no.
//@usage TestGetSector()
void TestGetSector();

//@prompts user for input
//@pre item object exists
//@post inserts user input into item
//@param item
//@usage PromptUser(item);
void PromptUser(ItemType& item);

//@tests ItemType's friend ostream and friend istream
//@post prints out the ItemType and receives input into ItemType
//@post TestInputOutput
void TestInputOutput();

//@tests ItemType's copy constructor
//@post item is copied into another item
//@usage TestCopy()
void TestCopy();

//@tests ItemType's destructor
//@pre item exists
//@post item destroyed
//@usage TestDestructor
void TestDestructor();

//@prints out user's input
//@pre useritem is assigned
//@post prints out useritem
//@param useritem
//@usage UserInput(item)
void UserInput(ItemType& useritem);

//@tests ItemType's GetReadWrite
//@pre item exists
//@post retrieves read/write of the item
//@usage TestGetReadWrite()
void TestGetReadWrite();

//@tests ItemType's GetTrack
//@pre item exists
//@post retrieves item's track no.
//@usage TestGetTrack();
void TestGetTrack();

//@tests ItemType's GetID
//@pre item exists
//@post retrieves item's ID no.
//@usage TestGetID()
void TestGetID();

//@tests ItemType's operator= 
//@post executes a1 = a2 
//@usage TestOperator();
void TestOperator();

int main()
{
   StartProgram();
   return 0;
}

//@starts the program
//@post program initializes
//@usage StartProgram();
void StartProgram()
{
   PrintNewLines(2);
   cout << "***This program fully tests the class ItemType***";
   PrintNewLines(2);
   TestInputOutput();
   PrintNewLines(2);
   TestCopy();
   PrintNewLines(2);
   TestDestructor();
   PrintNewLines(2);
   TestGetReadWrite();
   PrintNewLines(2);
   TestGetSector();
   PrintNewLines(2);
   TestGetTrack();
   PrintNewLines(2);
   TestGetID();
   PrintNewLines(2);
   TestOperator();
   PrintNewLines(2);
}

//@prompts user for input
//@pre item object exists
//@post inserts user input into item
//@param item
//@usage PromptUser(item);
void PromptUser(ItemType& item)
{
   cout << "Enter sector no.(0-200 inclusive) -> ";
   cin >> item;
}

//@prints out user's input
//@pre useritem is assigned
//@post prints out useritem
//@param useritem
//@usage UserInput(item)
void UserInput(ItemType& useritem)
{
   cout << "-----Input has been assigned-----";
   PrintNewLines(1);
   cout << "Your input is:" << endl;
   cout << useritem;
}
   
//@tests ItemType's friend ostream and friend istream
//@post prints out the ItemType and receives input into ItemType
//@post TestInputOutput
void TestInputOutput()
{
   cout << "**********Testing Itemtype Input And Output**********";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(1);
   UserInput(item);
   cout << "**********************************************************";
}
  
//@tests ItemType's copy constructor
//@post item is copied into another item
//@usage TestCopy()
void TestCopy()
{
   cout << "**********Testing ItemType Copy**********";
   PrintNewLines(1);
   PromptUser(item);
   ItemType item2(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "Here's the copy:" << endl;
   cout << item2;
   cout << "**********************************************************";
} 

//@tests ItemType's destructor
//@pre item exists
//@post item destroyed
//@usage TestDestructor
void TestDestructor()
{
   cout << "***********Testing ItemType Destructor***********" << endl;
   cout << "Default value for sector, track and ID is -1." << endl;
   cout << "Default for read/write is Write.";
   PrintNewLines(2);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Destroying input-------" << endl;
   item.~ItemType();
   cout << item;
   cout << "*************************************************";
}

//@tests ItemType's GetReadWrite
//@pre item exists
//@post retrieves read/write of the item
//@usage TestGetReadWrite()
void TestGetReadWrite()
{
   bool input;
   cout << "***********Testing GetReadWrite************";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Getting Read/Write-------" << endl;
   input = item.GetReadWrite();   
   
   if (input)
   {
      cout <<"Retrieved data -> Read" << endl;
   } else {
      cout << "Retrieved data -> Write" << endl;
   }
   PrintNewLines(2);
   cout << "************************************************";
}

//@tests ItemType's GetSector
//@post retrieves the sector no.
//@usage TestGetSector()
void TestGetSector()
{
   int input;
   cout << "***********Testing GetSector************";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Getting Sector no.-------" << endl;
   input = item.GetSector();   
   cout << "Retrieved data -> " << input << endl;
   PrintNewLines(1);
   cout << "************************************************";
}

//@tests ItemType's GetTrack
//@pre item exists
//@post retrieves item's track no.
//@usage TestGetTrack();
void TestGetTrack()
{
   int input;
   cout << "***********Testing GetTrack************";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Getting Track no-------" << endl;
   input = item.GetTrack();
   cout << "Retrieved data -> " << input << endl;
   PrintNewLines(1);
   cout << "************************************************";
}   

//@tests ItemType's GetID
//@pre item exists
//@post retrieves item's ID no.
//@usage TestGetID()
void TestGetID()
{
   int input;
   cout << "***********Testing GetID************";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Getting ID no-------" << endl;
   input = item.GetId();
   cout << "Retrieved data -> " << input << endl;
   PrintNewLines(1);
   cout << "************************************************";
}

//@tests ItemType's operator= 
//@post executes item = item2 
//@usage TestOperator();
void TestOperator()
{
   int input;
   ItemType item2;
   cout << "***********Testing Operator =************";
   PrintNewLines(1);
   PromptUser(item);
   PrintNewLines(2);
   UserInput(item);
   PrintNewLines(2);
   cout << "-------Copying from input to another item-------";
   PrintNewLines(1);
   item2 = item;
   cout << "The copied item is: " << endl;
   cout << item2;
   PrintNewLines(2);
   cout << "************************************************";
}
   
//@prints a number of new lines
//@pre: num is assigned
//@post: outputs num new lines
//@param: num is the number of new lines to output
//@usage: PrintNewLines(2);
void PrintNewLines(int num)
{
   if (num > 0)
   {
      cout << endl;
      PrintNewLines(num - 1);
   }
} 
  
