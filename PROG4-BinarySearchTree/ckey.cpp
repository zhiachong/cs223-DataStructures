//@author Zhia Chong
//@file ckey.cpp
//@date 2/15/2011
//@data object: a texting abbreviation
//@data structure: a key of strings
//@operations: constructor, copy constructor, destructor, operator=
//@            operator==, operator< 
//@friends:    operator<<, operator>>

#include <iostream>
#include <string>
#include "ckey.h"
using namespace std;

//@creates an empty string object
//@post an empty string object
//@usage Ckey key;
Ckey::Ckey()
{
   mkey = "";
}

//@destroys a string object
//@pre string object exists
//@post string object does not exist
//@usage key.~Ckey(), where key is an instance of Ckey
Ckey::~Ckey()
{
   mkey = "";
}

//@copies an existing string object
//@pre rhsKey is assigned
//@post string object is a copy of rhsKey
//@param rhsKey
//@usage Ckey key(mykey); or passing a Ckey object by value
Ckey::Ckey(const Ckey& rhsKey)
{
   mkey = "";
   operator=(rhsKey);
}

//@copies the string
//@pre rhsKey exists. 
//@post Ckey object is a copy of rhsKey
//@param rhsKey
//@usage key = key2, where key and key2 are instances of Ckey
Ckey& Ckey::operator=(const Ckey& rhsKey)
{
   if (this != &rhsKey)
   {
      mkey = "";
      mkey = rhsKey.mkey;
   }
   return *this;
   
}

//@checks whether two strings are the same
//@pre: rhsKey is assigned
//@post: returns true if two strings are the same, false otherwise
//@param rhsKey
//@usage key == key2, where key and key2 are instances of Ckey
bool Ckey::operator==(const Ckey& rhsKey) const
{
   return (mkey == rhsKey.mkey);
}

//@checks whether a string is less than rhsKey
//@pre rhsKey is assigned
//@post returns true if string is less than rhsKey, false otherwise
//@param rhsKey
//@usage key < key2, where key and key2 are instances of Ckey
bool Ckey::operator<(const Ckey& rhsKey) const
{
   return (mkey < rhsKey.mkey);
}

//@gets input from user or file
//@pre rhsKey exists. input is open.
//@post input is retrieved
//@param input
//@param rhsKey
//@usage cin >> key;  
istream& operator>>(istream& input, Ckey& rhsKey)
{
   input >> rhsKey.mkey;
}

//@outputs a string to a file or the screen
//@pre rhsKey exists. output is open.
//@post contents of rhsKey have been output
//@param output
//@param rhsKey
//@usage cout << rhsKey << endl;   
ostream& operator<< (ostream& output, const Ckey& rhsKey)
{
   if (rhsKey.mkey == "")
   {
      output << "Empty" << endl;
   } else {
      output << rhsKey.mkey;
   }
   return output;
}

