//@ Zhia Chong
//@ 2/20/2011
//@ file: cbstree.cpp
//@description:

// Implementation of ADT Binary Search Tree
//Data object: A binary search tree T is-a binary tree that is either empty or in the form
//                            r
//                          /   \
//                         TL    TR
//            where r is called the root and left and right subtrees, the data are arranged 
//            in order, where keys in TL < key in r < keys in TR and
//            TL and TR are binary search trees
//Data structure: A linked binary search tree that has a root and 
//                left and right subtrees
// Operations: (a scaled-down version)
//       create, destroy, retrieve, insert, remove
// Contract: Assumes the this class can access private data members of class cnode and public 
//           methods of cbintree.
//    Those data members are: citem mitem, ckey key, cnode* mleftptr, cnode* mrightptr for cnode.
//    Those methods for cbintree are: bool isEmpty, void prettyDisplay,void makeTree
//       void traversals (preorder, inorder, postorder)

#include "cbstree.h"
#include "cexception.h"

// creates a new binary search tree
// post: an empty binary search tree object exists
// usage: cbinsrchtree bst;
cbstree:: cbstree(): cbintree()
{
   itemCount = 0;
}

// releases memory for a binary search tree
// pre: binary search tree object exists
// post: binary search tree object does not exist
// usage: automatically done at end of score
cbstree:: ~cbstree()
{
   itemCount = 0;
}

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   // searches for a key in a binary search tree object and
   //    retrieves the corresponding Cnodeitem
   // pre: key has been assigned.
   // post: rest contains the key with rest of the item if
   //    the key is found in the binary search tree object
   //    else an exception is thrown
   // usage: bst.retrieve (key, rest);
void cbstree::retrieve (const Ckey& tkey, Citem& rest) const
      throw (cexception)
{
   retrieveHelper (mroot, tkey, rest);
}

   // inserts a new item into the binary search tree
   // pre: newItem has been assigned
   // post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   // usage: bst.insert(newItem);
void cbstree::insert (const Citem& newItem) throw (cexception)
{
   insertHelper (mroot, newItem);
}

   // removes an item from a binary search tree
   // pre: tkey has been assigned
   // post: if tkey is found in the tree, its corresponding item
   //       is removed otherwise an exception is thrown
   // usage: bst.remove(tkey);
void cbstree::remove(const Ckey& tkey) throw (cexception)
{
   removeHelper (mroot, tkey);
}

   // recursive helper functions
 
   // recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. tkey and rest are assigned.
   // post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   // usage: retrieveHelper (mroot, key, rest);
void cbstree::retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception)
{
   if (treeptr == NULL)
   {
      throw cexception ("in retrieve: key has not been found! " );
   } else if (tkey == treeptr-> mitem) {
      rest = treeptr -> mitem; 
   } else if (tkey < treeptr -> mitem) {
      retrieveHelper (treeptr -> mleftptr, tkey, rest); 
   } else {
      retrieveHelper (treeptr -> mrightptr, tkey, rest);
   }
}
   
   // recursively inserts (modeling on binary search) a key
   // pre: treeptr is assigned. newItem is assigned.
   // post: inserts the key in the tree with treeptr's root.
   //    If an empty position is found in the tree, key is inserted
   //    into that position. Else an exception is thrown.
   // usage: insertHelper (mroot, newItem);
void cbstree::insertHelper (Cnode*& treeptr, const Citem& newItem)
      throw (cexception)
{
   if (treeptr == NULL)
   {
      treeptr = new Cnode(newItem, NULL, NULL);
      if (treeptr == NULL)
      {
         throw cexception("Insert: no memory for newItem! ");
      } 
   } else if (newItem == treeptr -> mitem)
   {
      throw cexception ("Insert: an item with that key already exists in the tree! ");
   } else if (newItem < treeptr -> mitem)
   {
      insertHelper(treeptr -> mleftptr, newItem);
   } else {
      insertHelper(treeptr -> mrightptr, newItem);
   }
   itemCount++;  
}

// recursively removes (modeling on binary search) a key
// pre: treeptr is assigned. tkey is assigned.
// post: removes the key in the tree with treeptr's root.
//       if the key to be removed is found, removeHelper deletes
//       the key. Else an exception is thrown
// usage: removeHelper (mroot, tkey);
void cbstree::removeHelper(Cnode*& treeptr, const Ckey& tkey)
{
   
   if (treeptr == NULL)
   {
      throw cexception ("Delete: key was not found!");
   } else if (tkey == treeptr -> mitem)
   {
      removeNode(treeptr);
   } else if (tkey < treeptr -> mitem)
   {
      removeHelper(treeptr -> mleftptr, tkey);
   } else {
      removeHelper(treeptr -> mrightptr, tkey);
   }
}
   
// recursively removes (modeling on binary search) a node
// pre: treeptr is assigned. 
// post: removes a node in the tree with treeptr's root.
//       if the node is a leaf, it will be removed. else it runs recursively
//       until the node is removed
// usage: removeNode(mroot);
void cbstree::removeNode(Cnode*& treeptr)
{
   if (treeptr -> mleftptr== NULL && treeptr -> mrightptr == NULL) // a leaf
   {
      delete treeptr;
      treeptr = NULL;
   } else if ( treeptr -> mleftptr== NULL)
   {
      Cnode* delptr;
      delptr = treeptr;
      treeptr = treeptr -> mrightptr;
      delptr -> mrightptr = NULL;
      delete delptr;
      delptr = NULL;
   } else if (treeptr -> mrightptr == NULL)
   {
      Cnode* delptr;
      delptr = treeptr;
      treeptr = treeptr -> mleftptr;
      delptr -> mleftptr= NULL;
      delete delptr;
      delptr = NULL;
   } else {
      Citem replacementItem;
      processLeftMost(treeptr, replacementItem);
      treeptr -> mitem = replacementItem;
   }
}      
   
// recursively processes (modeling on binary search) the leftmost side of 
// a tree
// pre: treeptr is assigned. 
// post: goes through the lefthand side of a tree until it reaches the bottom of the
//       tree. Then the key is assigned to replacementItem. And the Cnodeis deleted.
// usage: processLeftMost (mroot, replacementItem);
void cbstree::processLeftMost(Cnode*& treeptr, Citem& replacementItem)
{
   if (treeptr -> mleftptr == NULL)
   {
      replacementItem = treeptr -> mitem;
      Cnode* delptr = treeptr;
      treeptr = treeptr -> mrightptr;
      delptr -> mrightptr = NULL;
      delete delptr;
   } else {
      processLeftMost(treeptr -> mleftptr, replacementItem);
   }
}



