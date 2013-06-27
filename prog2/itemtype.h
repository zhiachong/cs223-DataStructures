//@file itemtype.h
//@author Zhia Chong
//@date 1/15/2011
//@description this file is a specification file for itemtype.
//@Specification ItemType
//@   data object: an item which contains sector, track, id and read/write
//@   operations/methods: create, destroy, get track number, get sector,
//@               get id, get read/write, copy,           
//@   friend: print as operator<<, input as operator>>  

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

class ItemType
{
   //@outputs an item to a file or the screen
   //@pre rhsitem exists. output is open.
   //@post contents of rhsitem have been output
   //@param output
   //@param rhsitem
   //@usage cout << item << endl;  
   friend ostream& operator<< (ostream& output, const ItemType& rhsitem);
   
   //@gets input from user
   //@pre rhsitem exists. input is open.
   //@post input is retrieved
   //@param input
   //@param rhsitem
   //@usage cin >> item;  
   friend istream& operator>> (istream& input, ItemType& rhsitem);
   
public:

   //@creates an item of default size
   //@post an empty item
   //@usage 
   ItemType();
   
   //@copies an existing item 
   //@post item object is a copy of rhsitem
   //@usage 
   ItemType(const ItemType& rhsitem);
   
   //@destroys an item 
   //@pre item exists
   //@post item is destroyed 
   ~ItemType();
   
   //@retrieves the read/write from itemtype
   //@pre item object has been assigned
   //@post returns the true/false condition of mreadwrite
   //@usage item.GetReadWrite()
   bool GetReadWrite() const;
   
   //@finds the sector number
   //@pre item object has been assigned
   //@post returns the msector 
   //@usage item.GetSector()
   int GetSector() const;
   
   //@finds the track number of item
   //@pre item object has been assigned
   //@post returns mtrack
   //@usage item.GetTrack()
   int GetTrack() const;
   
   //@finds the ID number of item
   //@pre item object has been assigned
   //@post returns mid
   //@usage item.GetId();
   int GetId() const;
   
   //@copies the item
   //@pre rhsitem exists. item exists with same amount of memory
   //@post item object is a copy of rhsitem
   //@param rhsitem
   //@usage item2 = item;
   ItemType& operator=(const ItemType& rhsitem);
   
private:
   int msector;
   int mtrack;
   int mid;
   bool mreadwrite;   
};
#endif
