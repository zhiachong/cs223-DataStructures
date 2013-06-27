//@file itemtype.cpp
//@author Zhia Chong
//@date 1/15/2011
//@description this file is an implementation file for itemtype.
//@Specification ItemType
//@   data object: an item which contains sector, track, id and read/write
//@   data structure: an int for msector
//@                   an int for mtrack
//@                   an int for mid
//@                   a bool for mreadwrite 
//@   operations/methods: create, destroy, get track number, get sector,
//@               get id, get read/write, copy,           
//@   friend: print as operator<<, input as operator>>          

#include <iostream>
#include "itemtype.h"
using namespace std;

//@creates an empty itemtype
//@post empty itemtype
//@usage ItemType item; 
ItemType::ItemType()
{
   msector = -1;
   mtrack = -1;
   mid = -1;
   mreadwrite = true;
}

//@copies an existing itemtype
//@pre rhsq exists
//@post itemtype object is a copy of rhsq
//@param rhsq
//@usage ItemType item(anotheritem); / or passing an ItemType by value
ItemType::ItemType(const ItemType& rhsq)
{
   msector = -1;
   mtrack = -1;
   mid = -1;
   mreadwrite = true;
   operator= (rhsq);
}

//@destroys an existing Itemtype 
//@pre itemtype exists
//@post itemtype destroyed
ItemType::~ItemType()
{
   msector = -1;
   mtrack = -1;
   mid = -1;
   mreadwrite = false;
}

//@retrieves the read/write from itemtype
//@pre item object has been assigned
//@post returns the true/false condition of mreadwrite
//@usage item.GetReadWrite()
bool ItemType::GetReadWrite()
{
   return (mreadwrite == true);
}

//@finds the sector number
//@pre item object has been assigned
//@post returns the msector 
//@usage item.GetSector()
int ItemType::GetSector()
{
   return msector;
}

//@finds the track number of item
//@pre item object has been assigned
//@post returns mtrack
//@usage item.GetTrack()
int ItemType::GetTrack()
{
   return mtrack;
}

//@finds the ID number of item
//@pre item object has been assigned
//@post returns mid
//@usage item.GetId();
int ItemType::GetId()
{
   return mid;
}

//@copies the item
//@pre rhsq exists. item exists with same amount of memory
//@post item object is a copy of rhsq
//@param rhsq
//@usage item2 = item;
ItemType& ItemType::operator=(const ItemType& rhsq)
{
   if (this != &rhsq)
   {
      msector = rhsq.msector;
      mtrack = rhsq.mtrack;
      mid = rhsq.mid;
      mreadwrite = rhsq.mreadwrite;
   }
   return *this;
} 
 
//@outputs to a file or the monitor a item object
//@pre rhsq exists. output is open.
//@post contents of rhsq have been output
//@param output
//@param rhsq
//@usage cout << rhsq << endl;
ostream& operator<< (ostream& output, const ItemType& rhsq)
{
   bool ok;
   output << "Disk sector: " << rhsq.msector << endl;
   output << "Disk track: " << rhsq.mtrack << endl;
   output << "Disk ID: " << rhsq.mid << endl;
   output << "Disk(r/w): ";
   ok = (rhsq.mreadwrite == true);
   if (ok)
   {
	   output << "Read" << endl;
   } else {
	   output << "Write" << endl;
   }
}

//@inputs to a file or a disk of item object
//@pre rhsitem exists. output is open.
//@post contents are inputed into rhsitem
//@param input
//@param rhsitem
//@usage cin >> item >> endl;
istream& operator>>(istream& input, ItemType& rhsitem)
{
   char minput;
   int sector, track, id;
   if (&input == &cin)
   {
	  input >> sector;
      if (sector >= 0 && sector <= 200)
      {
	      rhsitem.msector = sector;
      } else {
	      rhsitem.msector = -1;
      }
      cout << "Enter track no.(0-100 inclusive) -> ";
     
      input >> track;
      if (track >= 0 && track <= 100)
      {
	      rhsitem.mtrack = track;
      } else {
	      rhsitem.mtrack = -1;
      }
      cout << "Enter ID no. -> ";
      input >> rhsitem.mid;
      cout << "Enter R/W -> ";
      input >> minput;
   } else {
      input >> sector;
      if (sector >= 0 && sector <= 200)
      {
	      rhsitem.msector = sector;
      } else {
	      rhsitem.msector = -1;
      }
      input >> track;
      if (track >= 0 && track <= 100)
      {
	      rhsitem.mtrack = track;
      } else {
	      rhsitem.mtrack = -1;
      }
      input >> rhsitem.mid;
      input >> minput;

   }
   
   if (minput == 'r'|| minput == 'R')
   {
      rhsitem.mreadwrite = true;
   } else if (minput == 'w'|| minput == 'W')
   {
      rhsitem.mreadwrite = false;
   } 
      
}

