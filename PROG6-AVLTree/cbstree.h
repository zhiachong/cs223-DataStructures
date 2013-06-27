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
// Operations: (a scaled-down version)
//       create, destroy, retrieve, insert, remove
// Contract: Assumes the this class can access private data members of class cnode and public
//           methods of cbintree.
//    Those data members for cnode are: citem mitem, ckey mkey, cnode* mleftptr, cnode* mrightptr.
//    Those methods for cbintree are: bool isEmpty, void prettyDisplay,void makeTree
//       void traversals (preorder, inorder, postorder)


#ifndef CBSTREE_H
#define CBSTREE_H 

#include "cbintree.h"
#include "ckey.h"
#include "cexception.h"
typedef Ckey Citem;


class cbstree: public cbintree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: cbstree bst;
   cbstree();

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of score
   ~cbstree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding node item
   //@pre: key has been assigned.
   //@post: rest contains the key with rest of the item if
   //    the key is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.retrieve (key, rest);
   void retrieve (const Ckey& tkey, Citem& rest) const
      throw (cexception);
   
   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: bst.insert(newItem);
   void insert (const Citem& newItem) throw (cexception);
   
   //@builds a balanced tree
   //@pre: items are assigned
   //@post: puts items into tree to build a balanced tree
   //@usage: bst.rebuildTree();
   void rebalanceTree(ifstream& infile);
   
   //@ removes an item from a binary search tree
   //@ pre: tkey has been assigned
   //@ post: if tkey is found in the tree, its corresponding item
   //       is removed otherwise an exception is thrown
   //@ usage: bst.remove(tkey);
   void remove(const Ckey& tkey) throw (cexception);
   
   //@uses: operator<< from citem
   //@post: writes the objects in the tree in special order specified
   //@      to a file
   //@param outfile
   //@usage: bst.inorderTraverser(outfile);  
   void inorderTraverser(ofstream& outfile);

protected:  // recursive helper functions

   //@pre: treep points to the root of a binary tree to be traversed
   //@post: writes the objects of the nodes to a file
   //@param treep
   //@param outfile
   //@usage: preorder (mroot, outfile);
   void inorder (Cnode* treep, ofstream& outfile);

   //@recursively inserts items from a file into binary search tree
   //@pre: treeptr and data are assigned
   //@post: gets items from a file, and inserts into binary search tree
   //@      using treeptr's root.
   //@usage: readTree(mroot, itemCount);
   void readTree(Cnode*& treeptr, ifstream& infile, int data);
   
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. tkey and rest are assigned.
   //@post: searches for the key in the tree with treeptr's root.
   //    If the key is found, rest is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: retrieveItem (mroot, key, rest);
   void retrieveHelper (Cnode* treeptr, const Ckey& tkey,
                      Citem& rest) const throw (cexception);

   // recursively inserts (modeling on binary search) a key
   // pre: treeptr is assigned. newItem is assigned.
   // post: inserts the key in the tree with treeptr's root.
   //    If an empty position is found in the tree, key is inserted
   //    into that position. Else an exception is thrown.
   // usage: insertHelper (mroot, newItem);
   void insertHelper (Cnode*& treeptr, const Citem& newItem)
      throw (cexception);

   // recursively removes (modeling on binary search) a key
   // pre: treeptr is assigned. tkey is assigned.
   // post: removes the key in the tree with treeptr's root.
   //       if the key to be removed is found, removeHelper deletes
   //       the key. Else an exception is thrown
   // usage: removeHelper (mroot, tkey);
   void removeHelper(Cnode*& treeptr, const Ckey& tkey);
   
   // recursively removes (modeling on binary search) a node
   // pre: treeptr is assigned. 
   // post: removes a node in the tree with treeptr's root.
   //       if the node is a leaf, it will be removed. else if
   //       it has a right handside child, the node will be removed and 
   //       treeptr points to the child. else if it has a left hand
   //       side child, the node will be removed and treeptr points to the
   //       child. if node has 2 children, processLeftMost will be called
   // usage: removeNode (mroot);
   void removeNode(Cnode*& treeptr);
   
   // recursively processes (modeling on binary search) the leftmost side of 
   // a tree
   // pre: treeptr is assigned. 
   // post: goes through the lefthand side of a tree until it reaches the bottom of the
   //       tree. Then the key is assigned to replacementItem. And the node is deleted.
   // usage: processLeftMost (mroot, replacementItem);
   void processLeftMost(Cnode*& treeptr, Citem& replacementItem); 
   
   //data member
   int itemCount;
};
#endif
