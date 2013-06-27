//@author Zhia Chong
//@file ckey.h
//@date 2/15/2011
//@data : a texting abbreviation
//@operations: constructor, copy constructor, destructor, operator=
//@            operator==, operator< 
//@friends:    operator<<, operator>>

#ifndef CKEY_H
#define CKEY_H
#include <iostream>
using namespace std;

class Ckey
{
   //@gets input from user or a file
   //@pre rhsKey exists. input is open.
   //@post input is retrieved
   //@param input
   //@param rhsKey
   //@usage cin >> key;  
   friend istream& operator>>(istream& input, Ckey& rhsKey);

   //@outputs a integer to a file or the screen
   //@pre rhsKey exists. output is open.
   //@post contents of rhsKey have been output
   //@param output
   //@param rhsKey
   //@usage cout << rhsKey << endl;   
   friend ostream& operator<< (ostream& output, const Ckey& rhsKey);

public:
   
   //@creates an empty integer 
   //@post an empty integer 
   //@usage Ckey key;
   Ckey();
   
   //@destroys a integer 
   //@pre integer  exists
   //@post integer  does not exist
   //@usage key.~Ckey(), where key is an instance of Ckey
   ~Ckey();
   
   //@copies an existing integer 
   //@pre rhsKey is assigned
   //@post integer  is a copy of rhsKey
   //@param rhsKey
   //@usage Ckey key(mykey); or passing a Ckey  by value
   Ckey(const Ckey& rhsKey);
   
   //@copies the integer
   //@pre rhsKey exists. 
   //@post Ckey  is a copy of rhsKey
   //@param rhsKey
   //@usage key = key2, where key and key2 are instances of Ckey
   Ckey& operator=(const Ckey& rhsKey);

   //@checks whether two integers are the same
   //@pre: rhsKey is assigned
   //@post: returns true if two integers are the same, false otherwise
   //@param rhsKey
   //@usage key == key2, where key and key2 are instances of Ckey
   bool operator==(const Ckey& rhsKey) const;
   
   //@checks whether a integer is less than rhsKey
   //@pre rhsKey is assigned
   //@post returns true if integer is less than rhsKey, false otherwise
   //@param rhsKey
   //@usage key < key2, where key and key2 are instances of Ckey
   bool operator<(const Ckey& rhsKey) const;
   
protected:
   int mkey;
};
#endif
