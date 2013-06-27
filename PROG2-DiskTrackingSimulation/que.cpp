//@Implementation for ADT Queue
//@   data object: a queue which is a First In First Out List


//@   operations/methods: create, destroy, make empty, check if empty,
//@               check if full, 
//@               insert at the rear (enqueue), delete from the front (dequeue)
//@               copy the front, get the size
//@   friend: print as operator<<

//@author Zhia Chong
//@date January, 2010
//@file que.cpp
//@available on barney.gonzaga.edu: cp /home/faculty/cps/yerion/public_html/c223s10/ADTQueue/que.cpp que.cpp

#include "que.h"

struct Node
{
   ItemType item;
   Node* next;
};

//@creates an empty queue
//@post an empty queue
//@usage Que q;
Que::Que()
{
   mbackptr = NULL;
}

//@copies an existing queue
//@pre rhsq exists
//@post queue object is a copy of rhsq
//@usage Que q(anotherq); or passing a Que object by value
Que::Que(const Que& rhsq)
{
   //need to do something first
   mbackptr = NULL;
   //now use copy
   operator=(rhsq);
}   
   
//@destroys a queue
//@pre queue object exists
//@post queue object does not exist
Que:: ~Que()
{
   bool ok;
   while (mbackptr != NULL)
   {
      Dequeue(ok); 
   } 
}
     
//@finds the size of a queue object
//@pre queue object exists
//@post returns the size of the queue object
//@usage cout << q.GetSize();
int Que::GetSize() const
{
   int sum = 1;
   if (!IsEmpty())
   {
      Node* newptr = mbackptr -> next;
      while (newptr != mbackptr)
      {
         newptr = newptr -> next;
         sum++;
      }
   } else {
      sum = sum - 1;
   }
   return sum;
}
   
//@checks to see if a queue object is empty
//@pre queue object exists
//@post if queue is empty returns true else returns false
//@usage if (q.IsEmpty())
bool Que::IsEmpty() const
{
   return (mbackptr == NULL);
}
   
//@inserts a new item at the rear of the queue
//@pre newItem has an assigned value; queue exists
//@post if queue object is not full, newItem is added
//@      at the rear of the queue and ok is true else ok is false
//@param newItem
//@param ok
//@usage q.Enqueue(newguy, ok);
void Que::Enqueue(const ItemType& newItem, bool& ok)
{
   Node* newptr = new (nothrow) Node;
   ok = (newptr != NULL);
   if (ok)
   {
      newptr->item = newItem;
      if (IsEmpty())
      {
         newptr->next = newptr;    // makes it circular
      } else {
         newptr->next = mbackptr->next; // connects new node to front
         mbackptr->next = newptr;       // connects old back to new node
      }
      mbackptr = newptr;
   }
}
   
//@deletes item from the front of the queue
//@pre queue exists
//@post if queue is nonempty, front of the queue has been deleted from queue
//@         and ok is true else ok is false
//@param ok
//@usage q.Dequeue(iceCream);
void Que::Dequeue(bool& ok)
{
   int checknode;
   checknode = GetSize();
   if (!IsEmpty() && (checknode != 1) )
   {
      Node* newptr;
      newptr = mbackptr -> next;
      mbackptr -> next = newptr -> next;
      newptr -> next = NULL;
      delete newptr;
      ok = true;
   } else if (checknode == 1)
   {
      Node* newptr;
      mbackptr -> next = NULL;
      delete mbackptr;
      mbackptr = NULL;
      ok = true;
   } else {
      ok = false;
   }
}
   
//@copies the front item
//@pre queue exists and is not empty
//@post the front item in the queue is copied into frontItem
//@param frontItem
//@usage q.GetFront(frontItem);
void Que::GetFront(ItemType& frontItem) const
{
   Node* frontptr = mbackptr->next;
   frontItem = frontptr->item;
}

//@copies the queue
//@pre rhsq exists. queue object exists with same amount of memory
//@post queue object is a copy of rhsq
//@param rhsq
//@usage cpyq.operator=(rhsq);
//@      or        cpyq = rhsq;
Que& Que::operator=(const Que& rhsq)
{
   if (this != &rhsq)
   {
       bool ok;
       while (!IsEmpty())
       {
          Dequeue(ok);
       }
       if (rhsq.IsEmpty())
          mbackptr = NULL;
       else
       {
          Node* rhsqptr;
          Node* tempptr;
          rhsqptr = rhsq.mbackptr->next;
          tempptr = rhsqptr;
          Enqueue (rhsqptr -> item, ok);
          rhsqptr = rhsqptr -> next;
          while (rhsqptr != tempptr)
          {
             Enqueue (rhsqptr -> item, ok);
             rhsqptr = rhsqptr -> next;
          }
       }
   }
   return *this;
}

//@outputs to a file or the monitor a queue object
//@pre rhsq exists. output is open.
//@post contents of rhsq have been output
//@param output
//@param rhsq
//@usage cout << rhsq << endl;   
ostream& operator<< (ostream& output, const Que& rhsq)
{
   output << "The Queue: ";
   if (rhsq.IsEmpty())
   {
      output << "Empty" << endl;
   } else {
      Node* newptr = rhsq.mbackptr -> next;
      Node* tempptr = newptr;
      for (int i = 0; i < rhsq.GetSize() ; i++)
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
