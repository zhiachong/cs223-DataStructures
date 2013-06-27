//@author Zhia Chong
//@file citem.cpp
//@date 2/15/2011
//@description 
//@data object: meaning of a texting abbreviation
//@data structure: an item of strings
//@operations: constructor, copy constructor, destructor, operator=
//@friends:    operator<<, operator>>
//    Contract: Assumes the this class can access public members of Ckey.
//    those members are: bool operator ==, bool operator < 

#include <iostream>
#include <string>
#include "citem.h"
using namespace std;

//@creates an empty string object
//@post an empty string object
//@usage Citem item;
Citem::Citem() 
{
   mMeaning = "";
}

//@destroys a string object
//@pre string object exists
//@post string object does not exist
//@usage item.~Citem(), where item is an instance of Citem
Citem::~Citem()
{
   mMeaning = "";
}

//@copies an existing string object
//@pre rhsItem is assigned
//@post string object is a copy of rhsItem
//@param rhsItem
//@usage Citem item(myitem); or passing a Citem object by value
Citem::Citem(const Citem& rhsItem)
{
   mMeaning = "";
   mkey = "";
   operator=(rhsItem);
}

//@copies the string
//@pre rhsItem exists. 
//@post Citem object is a copy of rhsItem
//@param rhsItem
//@usage item = item2, where item and item2 are instances of Citem
Citem& Citem::operator=(const Citem& rhsItem)
{
   if (this != &rhsItem)
   {
      mMeaning = "";
      mkey = "";
      mkey = rhsItem.mkey;
      mMeaning = rhsItem.mMeaning;
   }
   return *this;
}

//@gets input from user
//@pre rhsItem exists. input is open.
//@post input is retrieved
//@param input
//@param rhsItem
//@usage cin >> item;  
istream& operator>>(istream& input, Citem& rhsItem)
{   
   if (&input == &cin)
   {
      char ch;
      input >> rhsItem.mkey;
      cout << "Enter definition: ";
      cin.get(ch);
      getline(input, rhsItem.mMeaning);
   } else {
      input >> rhsItem.mkey;
      getline(input, rhsItem.mMeaning);
   }
}

//@outputs a string to a file or the screen
//@pre rhsItem exists. output is open.
//@post contents of rhsItem have been output
//@param output
//@param rhsItem
//@usage cout << rhsItem << endl;   
ostream& operator<< (ostream& output, const Citem& rhsItem)
{
   if (rhsItem.mMeaning == "" && rhsItem.mkey == "") //no key and no definition
   {
      output << "Key: Empty" << endl;
      output << "Definition: N/A" << endl;
   } else if (rhsItem.mMeaning == "" && rhsItem.mkey != "") //user only enters key but not definition
   {
      output << "Key: " << rhsItem.mkey << endl;
      output << "Definition: N/A" << endl;
   } else {      
      output << "Key: " << rhsItem.mkey << endl;
      output << "Definition: " << rhsItem.mMeaning;
   }
   return output;
}

