//@author Zhia chong
//@date Jan 25, 2011
//@file sstf.h

//@Specification for SSTF
//@   data object: an item which contains currentTrack
//@   operations/methods: create, destroy, copy, dequeue, get next record
//@                       copy =
//@   friend: print as operator<<

#ifndef SSTF_H
#define SSTF_H

#include <iostream>
#include "que.h"
using namespace std;
struct Node;

class SSTF : public Que
{
   //@outputs a sstf to a file or the screen
   //@pre rhsseek exists. output is open.
   //@post contents of rhsseek have been output
   //@param output
   //@param rhsseek
   //@usage cout << rhsseek << endl;   
   friend ostream& operator<< (ostream& output, const SSTF& rhsSeek);
   
public:

   //@creates an empty queue of default memory size
   //@post an empty queue
   //@usage Que q;
   SSTF();
   
   //@copies an existing queue
   //@pre rhsq exists
   //@post queue object is a copy of rhsq
   //@usage Que q(anotherq); or passing a Que object by value
   SSTF(const SSTF& rhsSeek);
   
   //@destroys a sstf
   //@pre sstf object exists
   //@post sstf object does not exist
   ~SSTF();
      
   //@deletes item from the front of the queue after copying it
   //@pre queue exists
   //@post if queue is nonempty, front of queue has been removed
   //@         and ok is true else ok is false
   //@param ok
   //@usage q.Dequeue(iceCream);
   void Dequeue(bool& ok);
   
   //@gets the next record to do "read/write" on the disk
   //@pre itemtype it exists
   //@post returns ItemType it to be serviced
   //@param it
   //@usage seek.GetNextRecord(it);
   void GetNextRecord(ItemType& it);                                                                                             
   
   //@copies the queue
   //@pre rhsq exists. queue object exists with same amount of memory
   //@post queue object is a copy of rhsq
   //@param rhsq
   //@usage cpyq.operator=(rhsq);
   //@      or        cpyq = rhsq;
   SSTF& operator=(const SSTF& rhsSeek);
   
private: //will not let a client access directly and allows child class to access directly
   int mcurrentTrack;

};
#endif
