//@author Zhia Chong
//@file citem.h
//@date 4/15/2011
//@description 
//@data object: an integer
//@operations: constructor, copy constructor, destructor, operator=, operator<, operator>,
//             operator==, EmptyOut, IsEmptyItem
//@friends:    operator<<, operator>>


#ifndef CITEM_H
#define CITEM_H
#include <iostream>
using namespace std;
class Citem 
{
   //@gets input from either a user or a file
   //@pre rhsItem exists. input is open.
   //@post input is retrieved and inserted into rhsItem
   //@param input
   //@param rhsItem
   //@usage cin >> item;  
   friend istream& operator>>(istream& input, Citem& rhsItem);

   //@outputs the content to a file or the screen
   //@pre rhsItem exists. output is open.
   //@post contents of rhsItem have been printed on screen
   //@param output
   //@param rhsItem
   //@usage cout << rhsItem << endl;   
   friend ostream& operator<< (ostream& output, const Citem& rhsItem);

public:
   
   //@creates an empty item
   //@post an empty item exists
   //@usage Citem item;
   Citem();
   
   //@destroys an item
   //@pre item exists
   //@post item is deleted
   //@usage item.~Citem(), where item is an instance of Citem
   ~Citem();
   
   //@copies an existing item
   //@pre rhsitem is assigned
   //@post item is a copy of rhsitem
   //@param rhsitem
   //@usage Citem item(myitem); or passing a Citem object by value
   Citem(const Citem& rhsItem);
   
   //@copies the item
   //@pre rhsitem exists. 
   //@post Citem object is a copy of rhsitem
   //@param rhsitem
   //@usage item = item2, where item and item2 are instances of Citem
   Citem& operator=(const Citem& rhsItem);
   
   //@checks whether an item is less than rhsItem
   //@pre rhsitem exists and assigned. 
   //@post returns true is item is less than rhsItem, false otherwise
   //@param rhsitem
   //@usage item < item2, where item and item2 are instances of Citem
   bool operator<(const Citem& rhsItem) const;
   
   //@checks whether an item is more than rhsItem
   //@pre rhsitem exists and assigned. 
   //@post returns true is item is more than rhsItem, false otherwise
   //@param rhsitem
   //@usage item > item2, where item and item2 are instances of Citem
   bool operator>(const Citem& rhsItem) const;
   
   //@checks whether an item is equal to rhsItem
   //@pre rhsitem exists and is assigned. 
   //@post returns true is item is equal to rhsItem, false otherwise
   //@param rhsitem
   //@usage item == item2, where item and item2 are instances of Citem
   bool operator==(const Citem& rhsItem) const;
   
   //checks whether an item is empty
   //@pre item exists
   //@post returns true if item is empty, false othewise
   //@usage item.IsEmptyItem(); 
   bool IsEmptyItem() const;
   
   //deletes the data in the item
   //@pre item contains a data
   //@post data within the item is deleted
   //@usage item.EmptyOut();
   void EmptyOut();
   
private:
   int mItem;
};
#endif
