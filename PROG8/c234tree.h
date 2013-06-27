//@author Zhia Chong
//@date 4/20/2011
//@file c234tree.h
//@description

// Specification of ADT 2-3-4 Tree
// Data object: A 2-3-4 T that is either empty or of the form
//                r              r                r     
//              /   \         /  |  \      /   /     |   \
//             TL    TR ,    TL TM  TR ,  TL  TML   TMR  TR
//            where r is called the root and TL, TM, TML, TMR, and TR are subtrees
//            1-node, 2- node, 3-node, and 4-node subtrees each have a height of 
//            height - 1. The keys obey the property that is a generalization of 
//            a 2-3-4 search tree
// Operations: (a scaled-down version)
//       create, destroy, copy, operator=, isEmpty, prettyDisplay, Insert

#ifndef C234TREE_H
#define C234TREE_H

#include "c234node.h"
#include "cexception.h"
#include <fstream>

class c234tree
{
public:
   //@creates an empty 2-3-4 tree
   //@post: object is an empty 2-3-4 tree
   //@usage: c234tree zags;
   c234tree();

   //@creates a new 2-3-4 tree that is a copy of an existing tree
   //@post: object is a copy of rhstree
   //@param rhstree
   //@usage: c234tree zags (bulldog);
   c234tree(const c234tree& rhstree);

   //@releases the memory of a 2-3-4 tree
   //@pre: object exists
   //@post: memory for the object has been released. object theoretically does not exist
   //       but in practice, it is empty.
   ~c234tree();

   // ******************** member functions ********************************************
   //@pre: 2-3-4 tree object exists
   // **********************************************************************************
   //@checks for an empty tree
   //@post: returns true if the object is empty; else returns false
   //@return: true if object is empty; false if object is not
   //@usage: if (tree.isEmpty())
   bool isEmpty() const;

   //@copies one tree to another
   //@pre: rhstree is an assigned tree.
   //@post: object is a copy of rhstree
   //@param rhstree
   //@usage: atree = btree = ctree;
   c234tree& operator=(const c234tree& rhstree);

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
   void prettyDisplay(ofstream& outfile);
   
   //@inserts a new item into the 2-3-4 tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: tree.Insert(newItem);
   void Insert (const Citem& newItem) throw (cexception);

protected:   // helper functions for coding member functions

   //@checks whether a node is a leaf
   //@pre: treep is assigned
   //@post: returns true if pointer points to a 4-node, else false
   //@param treep
   //@usage: if (HasNoChild(mroot));
   bool HasNoChild(C234node*& treep);
   
   //@checks whether the pointer points to a 4-node
   //@pre: treep is assigned
   //@post: returns true if pointer points to a 4-node, else false
   //@param treep
   //@usage: if (IsFourNode(mroot));
   bool IsFourNode(C234node*& treep);
   
   //@inserts an item from the child node into parent node
   //@pre: treep, parent and index are assigned
   //@post: item from child node is inserted into parent node
   //@param treep
   //@param parent
   //@param index
   //@usage: InsertIntoParent(treep, treep -> mkids[index], index);
   void InsertIntoParent(C234node*& treep, C234node*& parent, int index);
   
   //@Pushes the pointers to the kids back several spots 
   //@pre: treep and spot are assigned
   //@post: the kids are now moved back by a number of spot positions
   //@param treep
   //@param spot
   //@usage PushKidsBack(treep, index);
   void PushKidsBack(C234node*& treep, int spot);
   
   //@splits the 4-node apart during insertion
   //@pre: the current node is a 3-node
   //@post: 1 new parent node contains middle item of recycled node and
   //       1 new right node contains right item of recycled node. recycled node
   //       is now new parent node's left kid, and the other newly created node is 
   //       new parent root's right kid.
   //@param treep
   //@usage SplitNode(mroot);
   void SplitNode(C234node*& treep);
    
   //@a helper for Insert function. Inserts newItem into a split node
   //@pre: treep exists and newItem is assigned
   //@post: inserts newItem into the position that it should be, else throws an exception if
   //       the item to insert already exists
   //@param treep
   //@param newItem
   //@usage InsertIntoSplitNode(mroot, newItem);
   void InsertIntoSplitNode(C234node*& treep, C234node*& prevptr, const Citem& newItem);   

   //@a helper for Insert inserts item into the node
   //@pre treep is assigned and newItem is assigned
   //@post inserts the item into the tree
   //@param treep
   //@param newItem
   //@usage InsertIntoNode(mroot, newItem);
   void InsertIntoNode(C234node*& treep, C234node*& prevptr, const Citem& newItem);
   
   //@Copies one 2-3-4 tree to another
   //@pre: oldtreep points to the root of a 2-3-4 tree
   //@post: newtreep points to the root of a 2-3-4 tree
   //  that has copies of the nodes of oldtreep's tree
   //@param oldtreep
   //@param newtreep
   //@usage: copyTree (newptr, oldptr);
   void copyTree (C234node*& newtreep, C234node* oldtreep); 

   //@Releases memory for a 2-3-4 tree
   //@pre: treep points to the root of a 2-3-4 tree
   //@post: releases all of the nodes in the tree pointed to by treep
   //    and leaves treep empty.
   //@param treep
   //@usage: destroyTree (mroot);
   void destroyTree (C234node*& treep);

   //@recursive helper for prettyDisplay()
   //@pre: treep and level are assigned, treep points to root of 2-3-4 tree
   //@post: 2-3-4 tree is printed out from right-handside most first
   //@param treep
   //@param level
   //@usage writePretty(treep, 3);
   void writePretty (ofstream& outfile, C234node* treep, int level);
   
   //@a helper to push the items in a node back
   //@pre treep and spot are assigned
   //@post pushes back the items in the node backwards, 
   //      spot indicates which item to push back
   //@param treep
   //@param spot
   //@usage PushBack(mroot, 1);
   void PushBack (C234node*& treep, int spot);
   
   // data member
   C234node* mroot;
};
#endif
