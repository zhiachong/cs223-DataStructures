//author Zhia Chong
//date 4/14/2011
//filename: c234node.h
//description:

// ADT 2-3-4 Tree Node:
// Specification file
//    data object: a node for a 2-3-4 tree
//    operations: two constructors and a public method, recycleNode
// Contract: the items for the node are defined in class Citem
//           and citem has a GOOD copy constructor

#include <cstddef>
#include "citem.h"
#include "cexception.h"
#ifndef C234NODE_H
#define C234NODE_H

class C234node
{
public:

   // creates a node with a given item but no kids
   // pre: newItem is assigned
   // post: the newItem is inserted into the node and the kids are NULL
   // param: newItem
   // usage: C234node node = new C234node(newitem);
   C234node(const Citem& newItem);
   
   //releases memory of a node
   // pre: node exists
   // post: node does not exist
   // usage: node.~C234node();
   ~C234node();
   
   // creates a node with a given item and kids
   // pre: newItem, leftKid, rightKid are assigned
   // post: the item of the node is newItem, the kids are left and right
   // param: newItem
   // param: leftKid
   // param: rightKid
   // usage: aptr = new C234node (thisone, NULL, NULL);
   C234node (const Citem& newItem, C234node* leftKid, C234node* rightKid);
   
   // copies one node to another
   // pre: rhsnode is assigned and node exists
   // post: copies rhsnode to another node
   // param rhsnode
   // usage: node = rhsnode;
   C234node& operator= (const C234node& rhsnode);
   
   // empties the two rightmost items in node
   //@pre two rightmost positions on node are occupied
   //@post two rightmost positions on node are cleared
   //@usage node.recycleNode();
   void recycleNode();

   C234node* mkids[4]; //the kids for the node
   Citem mitem[3];   //the items that are stored in the node
};
#endif
