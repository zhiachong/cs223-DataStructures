//@Implementation for SSTF
//@   data object: an item which contains currentTrack
//@   operations/methods: create, destroy, copy, dequeue, get next record
//@                       copy =
//@   friend: print as operator<<

//@author Zhia Chong
//@date January 26, 2010
//@file sstf.cpp

#include "sstf.h"

struct Node
{
   ItemType item;
   Node* next;
};


//***************HELPER FUNCTION******************

//@this is a helper function for dequeue
//@pre frontptr, backptr, quesize, currentTrack and ok are assigned
//@post returns the pointers 
//@usage DequeueHelper(frontptr, backptr, quesize, currentTrack, ok);
void DequeueHelper(Node*& frontptr, Node*& backptr, int quesize, int currentTrack, bool& ok)
{
   ItemType it;
   int trackNumber, size;
   
   size = 0;
   it = frontptr -> item;
   trackNumber = it.GetTrack();

   if (currentTrack == trackNumber)
   {
      while ((size < (quesize - 1)) && (frontptr -> next != backptr))
      {
         frontptr = frontptr -> next;
         if (backptr -> next != frontptr)
         {
            backptr = backptr -> next;
         }
         size++;
      }
   } else {
      while ((size < (quesize - 1)) && (currentTrack != trackNumber))
      {
         frontptr = frontptr -> next;
         it = frontptr -> item;
         trackNumber = it.GetTrack();
         if (backptr -> next != frontptr)
         {
            backptr = backptr -> next;
         }
         size++;
      }
   }
}

//@creates an empty queue
//@post an empty queue
//@usage Que q;
SSTF::SSTF()
{
   mcurrentTrack = -1;
}

//@copies an existing queue
//@pre rhsq exists
//@post queue object is a copy of rhsq
//@usage Que q(anotherq); or passing a Que object by value
SSTF::SSTF(const SSTF& rhsSeek)
{
   //need to do something first
   mcurrentTrack = -1;
   //now use copy
   operator=(rhsSeek);
}   
   
//@destroys a queue
//@pre queue object exists
//@post queue object does not exist
SSTF:: ~SSTF()
{
   mcurrentTrack = -1;
}
   
//@deletes item from the front of the queue
//@pre queue exists
//@post if queue is nonempty, front of the queue has been deleted from queue
//@         and ok is true else ok is false
//@param ok
//@usage q.Dequeue(iceCream);
void SSTF::Dequeue(bool& ok)
{
   Node* frontptr;
   Node* backptr;
   ItemType it;
   int currentTrack, quesize, tracknum;
     
   it = mbackptr -> item;
   tracknum = it.GetTrack();
   quesize = GetSize();
   currentTrack = mcurrentTrack;
   frontptr = mbackptr;
   backptr = mbackptr;
  
   DequeueHelper(frontptr, backptr, quesize, currentTrack, ok);
  
   if (!IsEmpty())
   {
      if (currentTrack == tracknum) 
      {
         if (quesize != 1)
         {
            backptr = frontptr -> next;
            frontptr -> next = mbackptr -> next;
            mbackptr = frontptr;
            backptr -> next = NULL;
            delete backptr; 
            backptr = NULL;
         } else {
            mbackptr -> next = NULL;
            delete mbackptr;
            mbackptr = NULL;
         }
         ok = true;
      } else { 
         backptr -> next = frontptr -> next;
         frontptr -> next = NULL;
         delete frontptr;
         frontptr = NULL;
         ok = true;
      }
   } else {
      ok = false;
   }
}
 
//@gets the next record to do "read/write" on the disk
//@pre que exists
//@post returns ItemType it to be serviced
//@param it
//@usage seek.GetNextRecord(it);
void SSTF::GetNextRecord(ItemType& it) 
{
   ItemType newItem;
   Node* curptr = mbackptr -> next;
   int curTrack, curDiff, newDiff;
   
   it = mbackptr -> item;
   
   while (curptr != mbackptr)
   {
      newItem = curptr -> item;
      curTrack = newItem.GetTrack();
      newDiff = mcurrentTrack - curTrack; //difference between new track and currenttrack
      if (newDiff < 0)
      {
         newDiff = newDiff * (-1);
      }
      curTrack = it.GetTrack();
      curDiff = mcurrentTrack - curTrack; //difference between track in last node and current track
      if (curDiff < 0)
      {
         curDiff = curDiff * (-1);
      }
      if (newDiff < curDiff)
      {
         it = newItem;
      }
      curptr = curptr -> next;
   }
    mcurrentTrack = it.GetTrack();
}

//@copies the queue
//@pre rhsq exists. queue object exists with same amount of memory
//@post queue object is a copy of rhsq
//@param rhsq
//@usage cpyq.operator=(rhsq);
//@      or        cpyq = rhsq;
SSTF& SSTF::operator=(const SSTF& rhsSeek)
{
   if (this != &rhsSeek)
   {
      bool ok;
      while (!IsEmpty())
      {
         Dequeue(ok);
      }
      if (rhsSeek.IsEmpty())
         mbackptr = NULL;
      else
      {
         Node* rhsSeekptr;
         Node* tempptr;
         rhsSeekptr = rhsSeek.mbackptr->next;
         tempptr = rhsSeekptr;
         Enqueue (rhsSeekptr -> item, ok);
         rhsSeekptr = rhsSeekptr -> next;
         while (rhsSeekptr != tempptr)
         {
            Enqueue (rhsSeekptr -> item, ok);
            rhsSeekptr = rhsSeekptr -> next;
         }
      }
      mcurrentTrack = rhsSeek.mcurrentTrack;
   }
   return *this;
}

//@outputs to a file or the monitor a queue object
//@pre rhsq exists. output is open.
//@post contents of rhsq have been output
//@param output
//@param rhsq
//@usage cout << rhsq << endl;   
ostream& operator<< (ostream& output, const SSTF& rhsSeek)
{
   output << "CurrentTrack: " <<  rhsSeek.mcurrentTrack << " ";
   if (rhsSeek.IsEmpty())
   {
      output << "Empty" << endl;
   } else {
      Node* newptr = rhsSeek.mbackptr -> next;
      Node* tempptr = newptr;
      for (int i = 0; i < rhsSeek.GetSize() ; i++)
      {
         output << newptr -> item;
         if (newptr -> next != tempptr)
         {
            output << " -> ";
         }
         newptr = newptr -> next;
      }  
   }
   return output;
}    
