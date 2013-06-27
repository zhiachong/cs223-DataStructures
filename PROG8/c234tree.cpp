//@author Zhia Chong
//@date 2/20/2011
//@file c234tree.cpp
//@description

// Implementation of ADT 2-3-4 Tree
// Data object: A 2-3-4 T that is either empty or in the form
//                r              r                r     
//              /   \         /  |  \      /   /     |   \
//             TL    TR ,    TL TM  TR ,  TL  TML   TMR  TR
//            where r is called the root and TL, TM, TML, TMR, and TR are subtrees
//            1-node, 2- node, 3-node, and 4-node subtrees each have a height of 
//            height - 1. The keys obey the property that is a generalization of 
//            a binary search tree
// Data structure: A balanced search tree with a root and a counter to keep track of number of items
//                 in the tree 
// Operations: (a scaled-down version)
//       create, destroy, copy, operator=, isEmpty, prettyDisplay, Insert


#include <fstream>
#include "c234tree.h"
#include <iostream>
using namespace std;

// creates an empty 2-3-4 tree
// post: object is an empty 2-3-4 tree
// usage: c234tree zags;
c234tree::c234tree()
{ 
   mroot = NULL;
}

// creates a new binary tree that is a copy of an existing tree
// post: object is a copy of rhstree
// usage: c234tree zags (bulldog);
c234tree::c234tree(const c234tree& rhstree)
{
   mroot = NULL;
   copyTree (mroot, rhstree.mroot);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
c234tree:: ~c234tree()
{
   mroot = NULL;
   destroyTree (mroot);
}

// ******************** member functions ********************************************
// pre: binary tree object exists
// **********************************************************************************
// post: returns true if the object is empty; else returns false
// usage: if (tree.isEmpty())
bool c234tree::isEmpty() const
{
   return (mroot == NULL);
}
   
//@prints the tree to look like a computer science tree
//@post: outputs the tree as in the example below
//                    Z
//                  /    
//                    R
//                  /          
//  root ->  J P T         D
//                  \    /
//                    L 
//                  \    \
//                    G    C
//
//@nodes at the same level are indented the same.
//@Viewer must rotate head 90 degrees in order to look like a cs tree
//@usage: tree.prettyDisplay();
void c234tree::prettyDisplay(ofstream& outfile)
{
   writePretty(outfile, mroot, 0);
}

//@inserts a new item into the 2-3-4 tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: tree.Insert(newItem);
void c234tree::Insert (const Citem& newItem) throw (cexception)
{
   C234node* prevptr = mroot;
   InsertIntoNode(mroot, prevptr, newItem);
}

//@a helper for Insert function. Inserts newItem into a split node
//@pre: treep exists and newItem is assigned
//@post: inserts newItem into the position that it should be, else throws an exception if
//       the item to insert already exists
//@param treep
//@param newItem
//@usage InsertIntoSplitNode(mroot, newItem);
void c234tree::InsertIntoSplitNode(C234node*& treep, C234node*& prevptr, const Citem& newItem)
{
   int index = 0;
   while (newItem > treep -> mitem[index] && !(treep -> mitem[index].IsEmptyItem()) && index < 3)
   {
      index++;
   }
  
   if (treep -> mkids[index] == NULL)
   {
      if (newItem < treep -> mitem[0])
      {
         PushBack(treep, 0);
         treep -> mitem[0] = newItem;
      } else if (newItem < treep -> mitem[1] && newItem > treep -> mitem[0]) {
         PushBack(treep, 1);
         treep -> mitem[1] = newItem;
      } else if (newItem < treep -> mitem[0]){
         PushBack(treep, 0);
         treep -> mitem[0] = newItem;
      } else {
         treep -> mitem[2] = newItem;
     }
   } else if (IsFourNode(treep -> mkids[index])) {
      SplitNode(treep -> mkids[index]);
      InsertIntoSplitNode(treep -> mkids[index], prevptr, newItem);
      PushBack(treep, index);
      InsertIntoParent(treep -> mkids[index], treep, index);
   } else {
      InsertIntoNode(treep -> mkids[index], treep, newItem);
   }
	   
}

//@a helper for Insert inserts item into the node
//@pre treep is assigned and newItem is assigned
//@post inserts the item into the tree
//@param treep
//@param newItem
//@usage InsertIntoNode(mroot, newItem);
void c234tree::InsertIntoNode(C234node*& treep, C234node*& prevptr, const Citem& newItem)
{
   if (treep == NULL) //insert into empty root node
   {
      treep = new C234node (newItem);
      if (treep == NULL)
         throw cexception ("Memory full! Insertion failed!");
   } else if (IsFourNode(treep) && HasNoChild(treep) && IsFourNode(prevptr))
   {
      SplitNode(treep);
      InsertIntoSplitNode(treep, treep, newItem);
     
   } else {
   
      int index = 0;
      while (newItem > treep -> mitem[index] && !(treep -> mitem[index].IsEmptyItem()) && index < 3)
      {
         index++;
      }
   
      if (treep -> mkids[index] == NULL) 
      {
         PushBack(treep, index);
         treep -> mitem[index] = newItem;
         
      } else if (treep -> mkids[index] != NULL && !IsFourNode(treep -> mkids[index]))
      {
         InsertIntoSplitNode(treep -> mkids[index], treep, newItem);
      } else if (!IsFourNode(treep -> mkids[index]))
      {
         PushBack(treep, index);
         treep -> mitem[index] = newItem;
      } else if (IsFourNode(treep)) {
         SplitNode(treep);
         InsertIntoSplitNode(treep, treep, newItem);
      } else {
         SplitNode(treep -> mkids[index]);
         InsertIntoSplitNode(treep -> mkids[index], prevptr, newItem);
         PushBack(treep, index);
         InsertIntoParent(treep -> mkids[index], treep, index);
      }
   }

}

//@checks whether a node is a leaf
//@pre: treep is assigned
//@post: returns true if pointer points to a 4-node, else false
//@param treep
//@usage: if (HasNoChild(mroot));
bool c234tree::HasNoChild(C234node*& treep)
{
   return((treep -> mkids[0] == NULL) && (treep -> mkids[1] == NULL) 
   && (treep -> mkids[2] == NULL) && treep -> mkids[3] == NULL);
}

//@inserts an item from the child node into parent nod
//@pre: treep, parent and index are assigned
//@post: item from child node is inserted into parent node
//@param treep
//@param parent
//@param index
//@usage: InsertIntoParent(treep, treep -> mkids[index], index);
void c234tree::InsertIntoParent(C234node*& treep, C234node*& parent, int index)
{
   parent -> mitem[index] = treep -> mitem[0];
   PushKidsBack(parent, index);
   if (index == 0)
   {
      parent -> mkids[1] = treep -> mkids[1];
      parent -> mkids[0] = treep -> mkids[0];
   } else if (index == 1)
   { 
      parent -> mkids[2] = treep -> mkids[1];
      parent -> mkids[1] = treep -> mkids[0];
   } else if (index == 2)
   {
      parent -> mkids[3] = treep -> mkids[1];
      parent -> mkids[2] = treep -> mkids[0];
   }
}

//@Pushes the pointers to the kids back several spots 
//@pre: treep and spot are assigned
//@post: the kids are now moved back by a number of spot positions
//@param treep
//@param spot
//@usage PushKidsBack(treep, index);
void c234tree::PushKidsBack(C234node*& treep, int spot)
{
   int i;
   C234node* temp_ptr = treep;
   if (spot == 0)
   {
      temp_ptr -> mkids[3] = temp_ptr -> mkids[2];
      temp_ptr -> mkids[2] = temp_ptr -> mkids[1];
      temp_ptr -> mkids[1] = temp_ptr -> mkids[0];
   } else if (spot == 1)
   {
      temp_ptr -> mkids[3] = temp_ptr -> mkids[2];
      temp_ptr -> mkids[2] = temp_ptr -> mkids[1];
   } 
   treep = temp_ptr;
}

//@checks whether the pointer points to a 4-node
//@pre: treep is assigned
//@post: returns true if pointer points to a 4-node, else false
//@param treep
//@usage: if (IsFourNode(mroot));
bool c234tree::IsFourNode(C234node*& treep)
{
   return (!(treep -> mitem[0].IsEmptyItem()) && !(treep -> mitem[1].IsEmptyItem()) && !(treep -> mitem[2].IsEmptyItem()));
}

//@splits the 4-node apart during insertion
//@pre: the node is full while inserting
//@post: the node is split into either a root, have a 2-node parent or have
//       a 3-node parent
//@param treep
//@usage SplitNode(mroot);
void c234tree::SplitNode(C234node*& treep)
{
   C234node* newrightnode = new C234node(treep -> mitem[2]);
   C234node* newroot = new C234node(treep -> mitem[1], treep, newrightnode);
   newrightnode -> mkids[0] = treep -> mkids[2];
   newrightnode -> mkids[1] = treep -> mkids[3];
   treep -> mkids[2] = NULL;
   treep -> mkids[3] = NULL;
   treep -> recycleNode();
   treep = newroot;
}

// pre: rhstree is an assigned tree.
// post: object is a copy of rhstree
// usage: atree = btree = ctree;
c234tree& c234tree::operator=(const c234tree& rhstree)
{
   if (this != &rhstree)
   {
      destroyTree (mroot);
      copyTree (mroot, rhstree.mroot);
   }
   return *this;
}  



// helper functions for coding member functions
// Copies one binary tree to another
// pre: oldtreep points to the root of a binary tree
// post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
// usage: copyTree (newptr, oldptr);
void c234tree::copyTree (C234node*& newtreep, C234node* oldtreep) 
{
   if (oldtreep == NULL)
      newtreep = NULL;
   else
   {
      // preorder traversal
      newtreep = new C234node(oldtreep -> mitem[0]);
      newtreep -> mitem[1] = oldtreep -> mitem[1];
      newtreep -> mitem[2] = oldtreep -> mitem[2];
      copyTree (newtreep -> mkids[0], oldtreep -> mkids[0]);
      copyTree (newtreep -> mkids[1], oldtreep -> mkids[1]);
      copyTree (newtreep -> mkids[2], oldtreep -> mkids[2]);
      copyTree (newtreep -> mkids[3], oldtreep -> mkids[3]);
   }
}

// Releases memory for a binary tree
// pre: treep points to the root of a binary tree
// post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
// usage: destroyTree (mroot);
void c234tree::destroyTree (C234node*& treep)
{
   // do a postorder traversal
   if (treep != NULL)
   {
      destroyTree (treep -> mkids[0]);
      destroyTree (treep -> mkids[1]);
      destroyTree (treep -> mkids[2]);
      destroyTree (treep -> mkids[3]);
      delete treep;
      treep = NULL;
   }
}

//@recursive helper for prettyDisplay()
//@pre: treep and level are assigned, treep points to root of binary tree
//@post: binary tree is printed out from right-handside most first
//@param treep
//@param outfile
//@param level
//@usage writePretty(treep, 0);
void c234tree::writePretty (ofstream& outfile, C234node* treep, int level)
{
   if (treep != NULL)
   {
      level++;
      writePretty(outfile, treep -> mkids[3], level);
      writePretty(outfile, treep -> mkids[2], level);
      
      
      if (level == 1)
      {
         outfile << endl << endl;
         outfile << "mroot -> ";
      } else {
         for (int i = 0; i < level; i++)
         {
            outfile << "        ";
         }
      }
         
      for (int i = 0; i < 3; i++)
      { 
         if (!treep -> mitem[i].IsEmptyItem())
         {
            outfile << treep -> mitem[i] << "|";
         }
      }
      outfile << endl << endl << endl;
      
      writePretty(outfile, treep -> mkids[1], level);
      writePretty(outfile, treep -> mkids[0], level);
   }
}

    
//@a helper to push the items in a node back
//@pre treep and spot are assigned
//@post pushes back the items in the node backwards, 
//      spot indicates which item to push back
//@param treep
//@param spot
//@usage PushBack(mroot, 1);
void c234tree::PushBack(C234node*& treep, int spot)
{
   C234node* temp_ptr = treep;
   if (spot == 0)
   {
      temp_ptr -> mitem[2] = temp_ptr -> mitem[1];
      temp_ptr -> mitem[1] = temp_ptr -> mitem [0];
   } else if (spot == 1)
   {
      temp_ptr -> mitem[2] = temp_ptr -> mitem[1];
   } 
   treep = temp_ptr;
}

