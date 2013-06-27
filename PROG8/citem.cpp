//@author Zhia Chong
//@file citem.cpp
//@date 2/15/2011
//@description 
//@data object: an integer
//@data structure: an integer
//@operations: constructor, copy constructor, destructor, operator=, operator<, operator>,
//             operator==, EmptyOut, IsEmptyItem
//@friends:    operator<<, operator>>

#include <iostream>
#include "citem.h"
using namespace std;

//@creates an item
//@post an empty item is created
//@usage Citem item;
Citem::Citem() 
{
   mItem = -1;
}

//@destroys an item
//@pre item exists
//@post item does not exist
//@usage item.~Citem(), where item is an instance of Citem
Citem::~Citem()
{
   mItem = -1;
}

//@copies an existing item
//@pre rhsItem is assigned
//@post item is a copy of rhsItem
//@param rhsItem
//@usage Citem item(myitem); or passing a Citem object by value
Citem::Citem(const Citem& rhsItem)
{
   mItem = -1;
   operator=(rhsItem);
}

//@copies the item
//@pre rhsItem exists. 
//@post Citem object is a copy of rhsItem
//@param rhsItem
//@usage item = item2, where item and item2 are instances of Citem
Citem& Citem::operator=(const Citem& rhsItem)
{
   if (this != &rhsItem)
   {
      mItem = -1;
      mItem = rhsItem.mItem;
   }
   return *this;
}

//@checks whether an item is less than rhsItem
//@pre rhsitem exists and assigned. 
//@post returns true is item is less than rhsItem, false otherwise
//@param rhsitem
//@usage item < item2, where item and item2 are instances of Citem
bool Citem::operator<(const Citem& rhsItem) const
{
   return (mItem < rhsItem.mItem);
}
   
//@checks whether an item is more than rhsItem
//@pre rhsitem exists and assigned. 
//@post returns true is item is more than rhsItem, false otherwise
//@param rhsitem
//@usage item > item2, where item and item2 are instances of Citem
bool Citem::operator>(const Citem& rhsItem) const
{
   return (mItem > rhsItem.mItem);
}
   
//@checks whether an item is equal to rhsItem
//@pre rhsitem exists and is assigned. 
//@post returns true is item is equal to rhsItem, false otherwise
//@param rhsitem
//@usage item == item2, where item and item2 are instances of Citem
bool Citem::operator==(const Citem& rhsItem) const
{
   return (mItem == rhsItem.mItem);
}

//deletes the data in the item
//@pre item contains a data
//@post data within the item is deleted
//@usage item.EmptyOut();
void Citem::EmptyOut()
{
   mItem = -1;
}
  
//checks whether an item is empty
//@pre item exists
//@post returns true if item is empty, false othewise
//@usage item.IsEmptyItem();  
bool Citem::IsEmptyItem() const
{
   return (mItem == -1);
}

//@gets input from user
//@pre rhsItem exists. input is open.
//@post input is retrieved
//@param input
//@param rhsItem
//@usage cin >> item;  
istream& operator>>(istream& input, Citem& rhsItem)
{   
   input >> rhsItem.mItem;
}

//@outputs a string to a file or the screen
//@pre rhsItem exists. output is open.
//@post contents of rhsItem have been output
//@param output
//@param rhsItem
//@usage cout << rhsItem << endl;   
ostream& operator<< (ostream& output, const Citem& rhsItem)
{
   output << rhsItem.mItem;
   return output;
}

