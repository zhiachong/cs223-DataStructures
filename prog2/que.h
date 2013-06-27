//@author Zhia chong
//@date Jan 27, 2011
//@file que.h

//@Specification for ADT Queue
//@   data object: a queue which is a First In First Out List
//@   operations/methods: create, destroy, check if empty, copy
//@               insert at end (enqueue), delete at front (dequeue)
//@               copy the front, get the size
//@   friend: print as operator<<

#ifndef QUE_H
#define QUE_H

#include <iostream>
#include "itemtype.h"
using namespace std;
struct Node;

class Que
{
   //@outputs a queue to a file or the screen
   //@pre rhsq exists. output is open.
   //@post contents of rhsq have been output
   //@param output
   //@param rhsq
   //@usage cout << rhsq << endl;   
   friend ostream& operator<< (ostream& output, const Que& rhsq);
   
public:

   //@creates an empty queue of default memory size
   //@post an empty queue
   //@usage Que q;
   Que();
   
   //@copies an existing queue
   //@pre rhsq exists
   //@post queue object is a copy of rhsq
   //@usage Que q(anotherq); or passing a Que object by value
   Que(const Que& rhsq);
   
   //@destroys a queue
   //@pre queue object exists
   //@post queue object does not exist
   ~Que();
   
   //@finds the size of a queue object
   //@pre queue object exists
   //@post returns the size of the queue object
   //@usage cout << q.GetSize();
   int GetSize() const;
   
   //@checks to see if a queue object is empty
   //@pre queue object exists
   //@post if queue is empty returns true else returns false
   //@usage if (q.IsEmpty())
   bool IsEmpty() const;
   
   //@inserts a new item at the rear of the queue
   //@pre newItem has an assigned value; queue exists
   //@post if queue object is not full, newItem is added
   //@      at the rear of the queue and ok is true else ok is false
   //@param newItem
   //@param ok
   //@usage q.Enqueue(newguy, ok);
   void Enqueue(const ItemType& newItem, bool& ok);
   
   //@deletes item from the front of the queue after copying it
   //@pre queue exists
   //@post if queue is nonempty, front of queue has been removed
   //@         and ok is true else ok is false
   //@param frontItem
   //@param ok
   //@usage q.Dequeue(iceCream);
   void Dequeue(bool& ok);
   
   //@copies the front item
   //@pre queue exists and is not empty
   //@post the front item in the queue is copied into frontItem
   //@param frontItem
   //@usage q.GetFront(frontItem);
   void GetFront(ItemType& frontItem) const;
   
   //@copies the queue
   //@pre rhsq exists. queue object exists with same amount of memory
   //@post queue object is a copy of rhsq
   //@param rhsq
   //@usage cpyq.operator=(rhsq);
   //@      or        cpyq = rhsq;
   Que& operator=(const Que& rhsq);
   
protected: //will not let a client access directly and allows child class to access directly
   Node* mbackptr;

};
#endif
