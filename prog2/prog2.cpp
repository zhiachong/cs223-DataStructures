//@author Zhia Chong
//@date 25 Jan 2011
//@file prog2.cpp
//@description this is a simulation file 

#include <iostream>
#include <fstream>
#include <iomanip>
#include "que.h"
#include "itemtype.h"
#include "sstf.h"
using namespace std;

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@prints header for the simulation program
//@post a header is printed
//@usage PrintHeader();
void PrintHeader();

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@this function read items from a file and inserts it
//@into a que 
//@pre infile, and myque are assigned
//@post generates a list of length size
//@param infile
//@param myque
//@usage GetInputFromFile(infile, myque);
void GetInputFromFile(ifstream& infile, ItemType& item);

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile);

//@prints out underlines
//@pre lines are assigned
//@post prints out lines
//@param lines
//@usage UnderLines(1);
void UnderLines(int lines);

//@runs a simulation program
//@post a series of numbers is printed on screen
//@usage RunSimulation();
void RunSimulation();

//@prints a snapshot of queue
//@pre myseek, track, id, read and sector are assigned
//@post prints out the numbers if queue is not empty, else prints empty
//@param myseek
//@param track
//@param id
//@param read
//@param sector
//@usage SnapShotOfQueue(seekTime, track, id, read, sector)
void SnapShotOfQueue(const SSTF& myseek, int& track, int& id, char& read, int& sector);

//@inserts an event into que
//@pre item, myseek and ok are assigned
//@post an event is inserted into queue
//@param item 
//@param myseek
//@param ok
//@usage EnqueueEvent(item, seekTime, ok);
void EnqueueEvent(ItemType item, SSTF& myseek, bool& ok);

//@retrieves the current track being serviced
//@pre item is assigned
//@post returns the track being serviced
//@param item
//@usage currentTrack = GetCurrentTrack(item);
int GetCurrentTrack(const ItemType& item);

//@retrieves the next record to be serviced
//@pre myseek is assigned
//@post retrieves the next record to be serviced
//@param it
//@param myseek
//@usage GetRecord(item, seekTime)
void GetRecord(ItemType& it, SSTF& myseek);

//@retrieves the sector number for the current record
//@pre item is assigned
//@post returns the sector number
//@param item
//@usage sector = GetSector(item)
int GetSector(const ItemType& item);

//@retrieves the read/write status of the record
//@pre item is assigned
//@post returns a r if read, w if write
//@param item
//@usage ch = GetReadWrite(item);
char GetReadWrite(const ItemType& item);

//@retrieves record's unique ID
//@pre item is assigned
//@post returns the id
//@param item
//@usage id = GetUniqueID(item);
int GetUniqueID(const ItemType& item);

int main()
{
   PrintHeader();
   RunSimulation();
   return 0;
}

//@runs a simulation program
//@post a series of numbers is printed on screen
//@usage RunSimulation();
void RunSimulation()
{
   ifstream infile;
   bool ok;
   ItemType item;
   SSTF seekTime;
   int currentTrack, id, sector;
   char readwrite;
   
   OpenInputFile(infile, ok);
   GetInputFromFile(infile, item);
   
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   GetInputFromFile(infile, item);
   EnqueueEvent(item, seekTime, ok);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);
   
   GetRecord(item, seekTime);
   currentTrack = GetCurrentTrack(item);
   id = GetUniqueID(item);
   readwrite = GetReadWrite(item);
   sector = GetSector(item);
   seekTime.Dequeue(ok);
   
   SnapShotOfQueue(seekTime, currentTrack, id, readwrite, sector);

   CloseInputFile(infile);
   PrintLines(3);
}

//@prints a snapshot of queue
//@pre myseek, track, id, read and sector are assigned
//@post prints out the numbers if queue is not empty, else prints empty
//@param myseek
//@param track
//@param id
//@param read
//@param sector
//@usage SnapShotOfQueue(seekTime, track, id, read, sector)
void SnapShotOfQueue(const SSTF& myseek, int& track, int& id, char& read, int& sector)
{  
   cout << setw(18) << left;
   cout << track;
   cout << setw(21) << left;
   cout << id;
   cout << setw(11) <<  left;
   cout << sector;
   cout << setw(19) << left;
   cout << read; 
   cout << setw(2) <<  left;
   cout << myseek;
   
   if (myseek.IsEmpty())
   {
      cout << "-1";
      cout << "                -1";
      cout << "                   -1";
      cout << "         X";
      cout << "                  Empty";
      track = -1;
      id = -1;
      read = 'X';
      sector = -1;
   }
   PrintLines(1);
}

//@retrieves record's unique ID
//@pre item is assigned
//@post returns the id
//@param item
//@usage id = GetUniqueID(item);
int GetUniqueID(const ItemType& item)
{
   return (item.GetId());
}

//@retrieves the read/write status of the record
//@pre item is assigned
//@post returns a r if read, w if write
//@param item
//@usage ch = GetReadWrite(item);
char GetReadWrite(const ItemType& item)
{
   if (item.GetReadWrite())
   {
      return 'R';
   } else {
      return 'W';
   }
   
}

//@retrieves the next record to be serviced
//@pre myseek is assigned
//@post retrieves the next record to be serviced
//@param it
//@param myseek
//@usage GetRecord(item, seekTime)
void GetRecord(ItemType& it, SSTF& myseek)
{
   myseek.GetNextRecord(it);
}

//@retrieves the current track being serviced
//@pre item is assigned
//@post returns the track being serviced
//@param item
//@usage currentTrack = GetCurrentTrack(item);
int GetCurrentTrack(const ItemType& item)
{
   return (item.GetTrack());
}

//@retrieves the sector number for the current record
//@pre item is assigned
//@post returns the sector number
//@param item
//@usage sector = GetSector(item)
int GetSector(const ItemType& item)
{
   return (item.GetSector());
}    

//@inserts an event into que
//@pre item, myseek and ok are assigned
//@post an event is inserted into queue
//@param item 
//@param myseek
//@param ok
//@usage EnqueueEvent(item, seekTime, ok);
void EnqueueEvent(ItemType item, SSTF& myseek, bool& ok)
{
   myseek.Enqueue(item, ok);
}

//@prints header for the simulation program
//@post a header is printed
//@usage PrintHeader();
void PrintHeader()
{
   PrintLines(2);
   cout << "*****THIS PROGRAM IS A SIMULATION*****";
   PrintLines(2);
   cout << "Current Track";
   cout << "     Request Serviced";
   cout << "     Sector";
   cout << "     Read(R)/Write(W)";
   cout << "   Queue";
   cout << endl;
   UnderLines(13);
   cout << "     ";
   UnderLines(16);
   cout << "     ";
   UnderLines(5);
   cout << "      ";
   UnderLines(16);
   cout << "   ";
   UnderLines(5);
   PrintLines(1);
   cout << "-1";
   cout << "                -1";
   cout << "                   -1";
   cout << "         X";
   cout << "                  Empty";
   PrintLines(1);
}

//@prints out underlines
//@pre lines are assigned
//@post prints out lines
//@param lines
//@usage UnderLines(1);
void UnderLines(int lines)
{
   for (int i = 0; i < lines; i++)
   {
      cout << "-";
   }
}

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("in2.txt");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@this function read items from a file and inserts it
//@into a que 
//@pre infile, and myque are assigned
//@post generates a list of length size
//@param infile
//@param myque
//@usage GetInputFromFile(infile, myque);
void GetInputFromFile(ifstream& infile, ItemType& item)
{
   infile >> item;      
}

//@this function closes the textfile
//@post textfile is closed
//@param infile
//@usage CloseInputFile(infile);
void CloseInputFile(ifstream& infile)
{
   infile.close();
}
