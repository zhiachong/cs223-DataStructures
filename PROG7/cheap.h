//@author Zhia Chong
//@cheap.h
//@date 4/4/2011

//@description
//@ Specification of ADT Heap
//@    Data object: A heap which is-a complete binary tree that is either
//@                  empty or of form
//@                            r  
//@                          /   \
//@                         TL    TR
//@            where key in r >= the keys in TL and TR and
//@            TL and TR are heaps
//@    Operations:
//@       create, destroy, copy, operator=, IsEmpty, IsFull, Insert, Delete

#ifndef CHEAP_H
#define CHEAP_H

#include "cnode.h"
#include "cexception.h"
#include <iostream>
using namespace std;

const int MAX_HEAP = 20;

class Cheap
{
public:

   //initializes heap
   //@ post: heap is initialized
   //@ usage: Cheap heap;
   Cheap();
    
   //destroys the heap and clears the memory 
   //@pre: heap exists
   //@post: heap does not exist
   ~Cheap();
    
   //creates a copy of the heap
   //@pre: rhsheap is assigned
   //@post: a copy of rhsheap is created
   //@param rhsheap
   //@usage: Cheap heap (rhsheap);
   Cheap(const Cheap& rhsheap);
    
   // ******************** member functions **********************************
   //@pre: heap object exists
   // ************************************************************************
   
   
   //@copies one heap to another
   //@pre: rhsheap is assigned 
   //@post: makes a copy of rhsheap
   //@param rhsheap
   //@usage: heap1 = heap2;
   Cheap& operator=(const Cheap& rhsheap);
   
   //@checks to see if heap is empty
   //@post: returns true if the heap is empty; else returns false
   //@usage: if (heap.IsEmpty())
   //           do something
   bool IsEmpty();
   
   //@checks to see if heap is full
   //@post: returns true if the object is full; else returns false
   //@return: true if object is full; false if object is not
   //@usage: if (heap1.IsFull())
   //           do something
   bool IsFull();
   
   //@Inserts an item into the heap
   //@pre newItem is defined
   //@post newItem is inserted into heap
   //@param newitem
   //@usage heap.Insert(zags);
   void Insert(const Citem& newItem) throw (cexception);
   
   //@Copies the root item, deletes the root and fixes the heap by trickling down 
   //@pre heap exists
   //@post root item is passed through maxitem by reference and heap is fixed
   //@param maxItems
   //@usage heap.Delete(maxitem);    
   void Delete(Citem& maxItems) throw (cexception);
   
   //@Sorts the heap in an order such that integers are in ascending order
   //@pre heap exists
   //@post items in heap are sorted in ascending order, prints out the graphical 
   //@     representation of the heap
   //@usage heap.HeapSort();
   void HeapSort();
   
   //@prints the heap
   //@pre: heap exists and last is assigned 
   //@post: prints out the graphical illustration of heap
   //@param last
   //@usage heap.PrintHeap(last);
   void PrintHeap(int last);
   
   //@prints out the binary tree for heap
   //@pre: heap exists
   //@post: prints on screen a beautiful binary tree representation of heap
   //@usage heap.PrintTree();
   void PrintTree();
    
protected:
   //a helper function that swaps two items
   //@pre itema and itemb are assigned
   //@post itema takes the value of itemb, and vice versa
   //@param litem
   //@param ritem
   //@usage Swap(itemA, itemB);
   void Swap(Citem& litem, Citem& ritem);
    
   //recursively fixes the heap after a delete
   //@pre index is assigned and delete occurs successfully
   //@post heap is successfully rebuilt 
   //@param root
   //@usage RebuildHeap(0);
   void RebuildHeap(int root, int last);
   
   //@recursive helper for PrintTree()
   //@pre: index and level are assigned, list exists
   //@post: tree is printed out from right-handside most first
   //@param list
   //@param index
   //@param level
   //@usage writePretty(mitem, 0, 0);
   void writePretty (Citem list[], int index, int level);
   
   Citem mitems[MAX_HEAP];
   int msize; //no. of items in the heap
};
#endif 
