//@author Zhia Chong
//@file ckey.cpp
//@date 2/15/2011
//@data : a texting abbreviation
//@data structure: a integer 
//@operations: constructor, copy constructor, destructor, operator=
//@            operator==, operator< 
//@friends:    operator<<, operator>>

#include <iostream>
#include "ckey.h"
using namespace std;

//@creates an empty integer 
//@post an empty integer 
//@usage Ckey key;
Ckey::Ckey()
{
   mkey = 0;
}

//@destroys a integer 
//@pre integer  exists
//@post integer  does not exist
//@usage key.~Ckey(), where key is an instance of Ckey
Ckey::~Ckey()
{
   mkey = 0;
}

//@copies an existing integer 
//@pre rhsKey is assigned
//@post integer  is a copy of rhsKey
//@param rhsKey
//@usage Ckey key(mykey); or passing a Ckey  by value
Ckey::Ckey(const Ckey& rhsKey)
{
   mkey = 0;
   operator=(rhsKey);
}

//@copies the integer
//@pre rhsKey exists. 
//@post Ckey  is a copy of rhsKey
//@param rhsKey
//@usage key = key2, where key and key2 are instances of Ckey
Ckey& Ckey::operator=(const Ckey& rhsKey)
{
   if (this != &rhsKey)
   {
      mkey = 0;
      mkey = rhsKey.mkey;
   }
   return *this;
   
}

//@checks whether two integers are the same
//@pre: rhsKey is assigned
//@post: returns true if two integers are the same, false otherwise
//@param rhsKey
//@usage key == key2, where key and key2 are instances of Ckey
bool Ckey::operator==(const Ckey& rhsKey) const
{
   return (mkey == rhsKey.mkey);
}

//@checks whether an integer is less than rhsKey
//@pre rhsKey is assigned
//@post returns true if integer is less than rhsKey, false otherwise
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

//@outputs rhsKey content to a file or the screen
//@pre rhsKey exists. output is open.
//@post contents of rhsKey have been output
//@param output
//@param rhsKey
//@usage cout << rhsKey << endl;   
ostream& operator<< (ostream& output, const Ckey& rhsKey)
{
   output << rhsKey.mkey;
   return output;
}

