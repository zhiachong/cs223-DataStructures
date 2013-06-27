//@author Zhia Chong
//@file citem.h
//@date 2/15/2011
//@description 
//@data object: meaning of a texting abbreviation
//@operations: constructor, copy constructor, destructor, operator=
//@friends:    operator<<, operator>>
//    Contract: Assumes the this class can access public members of Ckey.
//    those members are: bool operator ==, bool operator < 

#ifndef CITEM_H
#define CITEM_H
#include <iostream>
#include <string>
#include "ckey.h"
using namespace std;

class Citem : public Ckey
{
   //@gets input from user
   //@pre rhsItem exists. input is open.
   //@post input is retrieved
   //@param input
   //@param rhsItem
   //@usage cin >> item;  
   friend istream& operator>>(istream& input, Citem& rhsItem);

   //@outputs a string to a file or the screen
   //@pre rhsItem exists. output is open.
   //@post contents of rhsItem have been output
   //@param output
   //@param rhsItem
   //@usage cout << rhsItem << endl;   
   friend ostream& operator<< (ostream& output, const Citem& rhsItem);

public:
   
   //@creates an empty string object
   //@post an empty string object
   //@usage Citem item;
   Citem();
   
   //@destroys a string object
   //@pre string object exists
   //@post string object does not exist
   //@usage item.~Citem(), where item is an instance of Citem
   ~Citem();
   
   //@copies an existing string object
   //@pre rhsitem is assigned
   //@post string object is a copy of rhsitem
   //@param rhsitem
   //@usage Citem item(myitem); or passing a Citem object by value
   Citem(const Citem& rhsItem);
   
   //@copies the string
   //@pre rhsitem exists. 
   //@post Citem object is a copy of rhsitem
   //@param rhsitem
   //@usage item = item2, where item and item2 are instances of Citem
   Citem& operator=(const Citem& rhsItem);

private:
   string mMeaning;
};
#endif
