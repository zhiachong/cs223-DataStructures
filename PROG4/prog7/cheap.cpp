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
//@    Data structure: An array of Citems
//@    Operations:
//@       create, destroy, copy, operator=, IsEmpty, IsFull, Insert, Delete
#include "cheap.h"
#include <fstream>
#include <iostream>
using namespace std;

const char RED[] = "\033[22;31m";
const char RESET[] = "\033[0m";
const char GREEN[] = "\033[22;32m";

//@prints a number of new lines
//@pre num is assigned a positive number
//@post outputs num new lines
//@param num is the number of new lines to output
//@usage PrintLines(2);
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
      cout << endl;
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void Continue()
{
   char ch;
   PrintNewLines(2);
   cout << "                     Hit <Enter> to continue -> ";
   cin.get(ch);
}

//initializes heap
//@ post: heap is initialized
//@ usage: Cheap heap;
Cheap::Cheap()
{
   ifstream infile;
   infile.open("in7.txt");
   Ckey key;
   infile >> key;
   for (int i = 0; i < MAX_HEAP; i++)
      mitems[i] = key;
    msize = 0;
}

//destroys the heap and clears the memory 
//@pre: heap exists
//@post: heap does not exist
Cheap::~Cheap()
{
   msize = 0;
}

//creates a copy of the heap
//@pre: rhsheap is assigned
//@post: a copy of rhsheap is created
//@param rhsheap
//@usage: Cheap heap (rhsheap);
Cheap::Cheap(const Cheap& rhsheap)
{
    msize = rhsheap.msize;
    for (int i = 0; i < msize; i++) {
        mitems[i] = rhsheap.mitems[i];
    }
}

   // ******************** member functions **********************************
   //@pre: heap object exists
   // ************************************************************************

   
//@copies one heap to another
//@pre: rhsheap is assigned 
//@post: makes a copy of rhsheap   
//@param rhsheap
//@usage: heap1 = heap2;
Cheap& Cheap::operator=(const Cheap& rhsheap)
{
    if (this != &rhsheap) {
        msize = rhsheap.msize;
        for (int i = 0; i < msize; i++) 
            mitems[i] = rhsheap.mitems[i];
    } 
    return *this;
}



//@checks to see if heap is empty
//@post: returns true if the heap is empty; else returns false
//@usage: if (heap.IsEmpty())
//           do something
bool Cheap::IsEmpty()
{
    return (msize == 0);
}

//@checks to see if heap is full
//@post: returns true if the object is full; else returns false
//@return: true if object is full; false if object is not
//@usage: if (heap1.IsFull())
//           do something
bool Cheap::IsFull()
{
    return (msize == MAX_HEAP);
}

//@Inserts an item into the heap
//@pre newItem is defined
//@post newItem is inserted into heap
//@param newitem
//@usage heap.Insert(zags);
void Cheap::Insert(const Citem& newitem) throw (cexception)
{
    if (IsFull()) {
        throw cexception("Cheap::Insert - Error!Operation failed due to insufficient memory");
    } else {
       
        mitems[msize] = newitem;
       
        //trickle up
        int place = msize;
        int parent = (place - 1) / 2;
        while ((parent >= 0) && (mitems[parent] < mitems[place])) 
        {
            Swap(mitems[parent], mitems[place]);
            place = parent;
            parent = (place - 1) / 2;
        } 
       
        msize++;
    }
}

//@Copies the root item, deletes the root and fixes the heap by trickling down 
//@pre heap exists
//@post root item is passed through maxitem by reference and heap is fixed
//@param maxitem
//@usage heap.Delete(maxitem);     
void Cheap::Delete(Citem& maxItems) throw (cexception)
{
    if (IsEmpty()) {
        throw cexception("Cheap::Delete - Error!Operation failed due to empty heap");
    } else {
        maxItems = mitems[0];
        mitems[0] = mitems[msize-1];
        RebuildHeap(0, msize);
        msize--;
    }
}

//@Sorts the heap in an order such that integers are in ascending order
//@pre heap exists
//@post items in heap are sorted in ascending order, prints out the graphical 
//@     representation of the heap
//@usage heap.HeapSort();
void Cheap::HeapSort()
{
   int last = msize - 1;
   
   for (int i = last; i >= 0; i--)
   {
      RebuildHeap(i, msize);
   } 
   for (int i = 1; i <= msize; i++)
   {
      Swap(mitems[0], mitems[last]);
      cout << "-----------------------------------------------" << endl;
      PrintHeap(last);
      cout << endl;
      PrintTree();
      cout << endl;
      cout << "Swapped " << GREEN << mitems[0] << RESET << " with ";
      cout << GREEN << mitems[last] << RESET << endl;
      Continue();
      cout << endl;
      RebuildHeap(0, last);
      cout << "-----------------------------------------------" << endl;
      Continue();
      cout << endl;
      last --;
      
   } 
}

//@prints out the binary tree for heap
//@pre: heap exists
//@post: prints on screen a beautiful binary tree representation of heap
//@usage heap.PrintTree();
void Cheap::PrintTree()
{
   writePretty(mitems, 0, 0);
}

//@prints the heap
//@pre: heap exists and last is assigned 
//@post: prints out the graphical illustration of heap
//@param last
//@usage heap.PrintHeap(last);
void Cheap::PrintHeap(int last)
{
   for (int i = 0; i < 7; i++)
   {
	   cout << "|";
      if (i >= last)
         cout << RED;
      cout << mitems[i] << RESET;
   }
	cout << "|" << endl;
}

//**************************************
//**********HELPER FUNCTIONS************
//**************************************


//recursively fixes the heap after a delete
//@pre index is assigned and delete occurs successfully
//@post heap is successfully rebuilt 
//@param root
//@usage RebuildHeap(0);
void Cheap::RebuildHeap(int root, int last)
{
    int leftchild, rightchild, maxchild;
    leftchild = (2 * root) + 1;
    if (leftchild < msize && leftchild < last && last != 0) 
    {
        rightchild = leftchild + 1;
        maxchild = leftchild;
        if (rightchild < msize && rightchild < last) 
        {
            if (mitems[leftchild] < mitems[rightchild]) 
            {
               maxchild = rightchild; 
            } 
        }
        PrintHeap(last);
        PrintTree();
        cout << "Comparing " << GREEN << mitems[root] << RESET;
        cout <<  " with " << GREEN << mitems[maxchild] << RESET;
        if (mitems[root] < mitems[maxchild] && last != 0) 
        {
           cout << ", " << GREEEN << mitems[root] << RESET << " is smaller, so swap with ";
           cout << GREEN << mitems[maxchild] << RESET << endl;
           Swap(mitems[root], mitems[maxchild]);
           Continue();
           RebuildHeap(maxchild, last);
        }
     }
}

//a helper function that swaps two items
//@pre itema and itemb are assigned
//@post itema takes the value of itemb, and vice versa
//@param litem
//@param ritem
//@usage Swap(itemA, itemB);
void Cheap::Swap(Citem& itema, Citem& itemb)
{
    Citem temp = itemb;
    itemb = itema;
    itema = temp;
}

//@recursive helper for PrintTree()
//@pre: index and level are assigned, list exists
//@post: tree is printed out from right-handside most first
//@param list
//@param index
//@param level
//@usage writePretty(mitem, 0, 0);
void Cheap::writePretty (Citem list[], int index, int level)
{
   if (index < msize)
   {
      level++;
      writePretty (list, (2 * index) + 2, level);
    	
      if((2 * index) + 2 < msize)
      {
         for(int i = 0; i < level; i++)
      {
         cout << "         ";
      }
         cout << " / " << endl;
      }
    	
      if(level == 1)
      {
         cout << "mroot -> ";
      }
      else
      {
         for(int i = 1; i < level + 1; i++)
         {
            cout << " 	";
         }
      }
      
      cout << list[index] << endl;
    	
      if((2 * index) + 1 < msize)
      {
         for(int i = 0; i < level; i++)
      {
         cout << "         ";
      }
         cout << " \\ " << endl;
      }
      writePretty (list, (2 * index) + 1, level);
   }
}





